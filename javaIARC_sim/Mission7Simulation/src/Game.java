import java.util.ArrayList;
import java.util.Random;

import org.encog.ml.CalculateScore;
import org.encog.ml.MLMethod;
import org.encog.neural.neat.NEATNetwork;

import com.sun.javafx.geom.Vec2d;

import processing.core.PApplet;
import processing.core.PConstants;

public class Game {
	
	PApplet parent;
	Arena arena;
	
	static final double LOCALXMIN = -1d;
	static final double LOCALXMAX = 1d;
	static final double LOCALYMIN = -1d;
	static final double LOCALYMAX = 1d;
	static final float TIME_STEP = 0.1f;
	static final float COLLISION_MAX = (float)Math.PI / 2f;
	static final float COLLISION_RANGE = 0.035f;
	static final float BOUNCE_FACTOR = 0.005f;
	static final float MAX_TIME = 720f;
	
	Random rand = new Random();
	float turnTimer = 0;
	private float fitness = 0;
	private float gameTimer = 0;
	private boolean gameOver = false;
	
	//the robots
	private ArrayList<Roomba> roombas = new ArrayList<Roomba>(10);
	private ArrayList<Obstacle> obstacles = new ArrayList<Obstacle>(4);
	
	//the collided robot indexes
	private ArrayList<Integer> collidedRoombas = new ArrayList<Integer>(4);
	private ArrayList<Integer> collidedObstacles = new ArrayList<Integer>(2);
	
	private ArrayList<Integer> OOBRoombas = new ArrayList<Integer>(10);
	
	private Quad quad;
	MLMethod phentotype;
	
	//logging data
	private int roombasTriggered = 0;
	
	/**
	 * Give me that activator plox
	 * @param _parent
	 * @param _activator
	 */
	public Game(PApplet _parent, MLMethod phenotype)
	{
		this.phentotype = phenotype;
		parent = _parent;
		rand.setSeed(System.currentTimeMillis());
		arena = new Arena(parent, parent.width, parent.height);
		this.initializeRobotPositions();
	}
	
	/**
	 * is game over or not
	 * @return
	 */
	public boolean isGameOver()
	{
		return gameOver;
	}
	
	/**
	 * gets the game time
	 * @return
	 */
	public float getGameTime()
	{
		return gameTimer;
	}
	
	/**
	 * calculates a value which represents how many times the quadcopter repeat selects a single roomba in a row
	 * @return
	 */
	public double calculateSelectionBias()
	{
		int selectionCount = 0;
		int selections = 0;
		int aggregatedSelectionCount = 0;
		
		for(int i = 0; i < quad.getRoombaSelectionList().size(); i++)
		{
			if(i == 0)
			{
				selectionCount++;
				selections++;
			}
			else
			{
				//if the current selection is the same as the last selection
				if(quad.getRoombaSelectionList().get(i).intValue() == quad.getRoombaSelectionList().get(i -1).intValue())
				{
					selectionCount++;
				}
				else
				{
					aggregatedSelectionCount += selectionCount;
					selectionCount = 0;
					selectionCount++;
					selections++;
				}
			}
		}
		
		//System.out.println(quad.getRoombaSelectionList().size());
		
		return (double)aggregatedSelectionCount / (double)selections;
	}
	
	public double aggregateYvals()
	{
		double sum = 0;
		for(int i = 0; i < roombas.size(); i++)
		{
			double y = roombas.get(i).position().y + 1;
			sum += y * y;
		}
		return sum;
	}
	
	/**
	 * returns the fitness at the current time
	 * @return
	 */
	public double getFitness()
	{
		//returns the fitness plus the timer penalty
		
		//System.out.printf("NN Size: %d Fitness: %f\n", ((NEATNetwork)phentotype).getLinks().length ,50000f + fitness + (gameTimer / 60) * -100);
		double y = this.aggregateYvals();
		return y * 1000d;
	}
	
	public Quad getQuad()
	{
		return quad;
	}
	/**
	 * runs the robots and neural network fitness function
	 */
	public void run()
	{
		//increment timer
		gameTimer += Game.TIME_STEP;
		if(gameTimer >= Game.MAX_TIME)
		{
			gameOver = true;
		}
		//System.out.println("run1");
		//quad.overrideRestingPos(mapfloat(parent.mouseX, 0, 800, -1, 1), mapfloat(parent.mouseY, 0, 800, 1, -1));
		//update the quad's state estimate
		updateQuadState();
		updateGroundRobotStates(Game.TIME_STEP);
		//this basically calls the onBlock function of all robots that have collided
		this.informRobotsAboutCollision();
		this.bounceRobots();
		for(int i = 0; i < roombas.size(); i++)
		{
			roombas.get(i).run(Game.TIME_STEP);
		}
		for(int i = 0; i < obstacles.size(); i++)
		{
			obstacles.get(i).run(Game.TIME_STEP);
		}
		//run quad
		quad.run(Game.TIME_STEP);
		this.touchRobots();
		this.OOBFitnessAdder();
		//check to see if nn fucked up
		if(quad.hasNNTouchedOOB())
		{
			//game over and fitness is 0
			gameOver = true;
		}
		
	}
	
	/**
	 * draws the arena and all robots
	 */
	public void draw()
	{
		arena.draw(parent.width, parent.height);
		
		//draw roombas
		for(int i = 0; i < roombas.size(); i++)
		{
			if(i < 5)
			{
				parent.fill(255, 0, 0);
			}
			else
			{
				parent.fill(0, 255, 0);
			}
			for(int j = 0; j < collidedRoombas.size(); j++)
			{
				if(i == collidedRoombas.get(j).intValue())
				{
					parent.fill(255, 255, 0);
				}
			}
			
			parent.stroke(255);
			/*parent.line(this.localToRealXCoordinates(roombas.get(i).position().x), this.localToRealYCoordinates(roombas.get(i).position().y), 
					this.localToRealXCoordinates(roombas.get(i).position().x) + (15f * (float)Math.cos(roombas.get(i).yaw())), 
					this.localToRealYCoordinates(roombas.get(i).position().y) + (15f * (float)Math.sin(roombas.get(i).yaw())));*/
			parent.strokeWeight(1);
			parent.ellipseMode(PConstants.CENTER);
			parent.ellipse(this.localToRealXCoordinates(roombas.get(i).position().x), this.localToRealYCoordinates(roombas.get(i).position().y), 
					this.mapfloat((float)Roomba.DIAMETER, 0f, 2.0f, 0f, Arena.WIDTH), this.mapfloat((float)Roomba.DIAMETER, 0f, 2.0f, 0f, Arena.HEIGHT));
			
			//debug method
			//parent.text(i, this.localToRealXCoordinates(roombas.get(i).position().x) - 10, this.localToRealYCoordinates(roombas.get(i).position().y) - 10);
			
			
			
		}
		
		for(int i = 0; i < obstacles.size(); i++)
		{
			//draw obstacles
			parent.fill(70);
			for(int j = 0; j < collidedObstacles.size(); j++)
			{
				if(i == collidedObstacles.get(j).intValue())
				{
					parent.fill(255, 255, 0);
				}
			}
			parent.stroke(255);
			/*parent.line(this.localToRealXCoordinates(obstacles.get(i).position().x), this.localToRealYCoordinates(obstacles.get(i).position().y), 
					this.localToRealXCoordinates(obstacles.get(i).position().x) + (15f * (float)Math.cos(obstacles.get(i).yaw())), 
					this.localToRealYCoordinates(obstacles.get(i).position().y) + (15f * (float)Math.sin(obstacles.get(i).yaw())));*/
		
			parent.ellipse(this.localToRealXCoordinates(obstacles.get(i).position().x), this.localToRealYCoordinates(obstacles.get(i).position().y), 
					this.mapfloat((float)Obstacle.DIAMETER, 0f, 2.0f, 0f, Arena.WIDTH), this.mapfloat((float)Obstacle.DIAMETER, 0f, 2.0f, 0f, Arena.HEIGHT));
		}
		
		float temp = mapfloat((float)quad.altitude(), 0f, .3f, mapfloat(0.07f, 0f, 2.0f, 0f, Arena.WIDTH), mapfloat(0.15f, 0f, 2.0f, 0f, Arena.WIDTH));
		drawQuad(localToRealXCoordinates(quad.position().x), localToRealYCoordinates(quad.position().y), temp, temp);
	}
	
	private void touchRobots()
	{
		if(quad.getMagnetTrigger())
		{
			//System.out.println("Roomba is triggered");
			roombasTriggered++;
			roombas.get(quad.getTarget()).rotate((float)Math.PI / -4f);
			roombas.get(quad.getTarget()).dontDrive = true;
		}
	}
	
	/**
	 * This moves robots backwards directly after a triggered collision
	 */
	private void bounceRobots()
	{
		for(int i = 0; i < collidedRoombas.size(); i++)
		{
			Vec2d temp = calculateVelocityFromAngle(Game.BOUNCE_FACTOR, roombas.get(collidedRoombas.get(i).intValue()).yaw() + Math.PI);
			roombas.get(collidedRoombas.get(i).intValue()).position().x += temp.x;
			roombas.get(collidedRoombas.get(i).intValue()).position().y += temp.y;
		}
		for(int i = 0; i < collidedObstacles.size(); i++)
		{
			Vec2d temp = calculateVelocityFromAngle(Game.BOUNCE_FACTOR, obstacles.get(collidedObstacles.get(i).intValue()).yaw() + Math.PI);
			obstacles.get(collidedObstacles.get(i).intValue()).position().x += temp.x;
			obstacles.get(collidedObstacles.get(i).intValue()).position().y += temp.y;
		}
	}
	/**
	 * how many roombas are on the green line
	 * @return
	 */
	public int getOOBGreen()
	{
		int agg = 0;
		for(int i = 0; i < roombas.size(); i++)
		{
			if(roombas.get(i).outOfBounds)
			{
				//is roomba on green line x between -1 and 1 and y > 0
				if(Math.abs(roombas.get(i).position().x) <= 1 && roombas.get(i).position().y > 0)
				{
					agg++;
				}
			}
		}
		return agg;
	}
	
	/**
	 * how many roombas are NOT!!!! on the green line
	 * @return
	 */
	public int getOOBNotGreen()
	{
		int agg = 0;
		for(int i = 0; i < roombas.size(); i++)
		{
			if(roombas.get(i).outOfBounds)
			{
				//is roomba on green line x between -1 and 1 and y > 0
				if(!(Math.abs(roombas.get(i).position().x) <= 1 && roombas.get(i).position().y > 0))
				{
					agg++;
				}
			}
		}
		return agg;
	}
	
	/**
	 * how many roombas are in the boundary
	 * @return
	 */
	public int getNotOOB()
	{
		int agg = 0;
		for(int i = 0; i < roombas.size(); i++)
		{
			if(roombas.get(i).outOfBounds == false)
			{
				agg++;
			}
		}
		return agg;
	}
	
	/**
	 * This is where the fitness is added to the fitness value when a roomba leaves the boundaries
	 */
	private void OOBFitnessAdder()
	{
		for(int i = 0; i < roombas.size(); i++)
		{
			if(roombas.get(i).isOutOfBounds())
			{
				boolean alreadyCalculated = false;
				for(int j = 0; j < OOBRoombas.size(); j++)
				{
					if(OOBRoombas.get(j).intValue() == i)
					{
						alreadyCalculated = true;
					}
				}
				
				//calculate and add fitness
				if(!alreadyCalculated)
				{
					OOBRoombas.add(i);
					//calculate fitness
					//is roomba on green line x between -1 and 1 and y > 0
					if(Math.abs(roombas.get(i).position().x) <= 1 && roombas.get(i).position().y > 0)
					{
						//rewards getting roomba over line quicker
						fitness += 2000f + (600f / gameTimer);
					}
					else
					{
						fitness -= 1000f;
					}
				}
			}
		}
		if(OOBRoombas.size() == 10)
		{
			gameOver = true;
		}
	}
	
	/**
	 * this sets the starting positions of the robots
	 */
	private void initializeRobotPositions()
	{
		for(int i = 0; i < 10; i++)
		{
			roombas.add(new Roomba());
			
			roombas.get(i).yaw(0 + (((2 * Math.PI) / 10d) * i));
			
			roombas.get(i).position(this.calculateVelocityFromAngle(0.1d, roombas.get(i).yaw()));
			
			//System.out.println(roombas.get(i).position() + " " + roombas.get(i).yaw());
		}
		
		for(int i = 0; i < 4; i++)
		{
			obstacles.add(new Obstacle());
			
			obstacles.get(i).yaw(0 + ((Math.PI / 2d) * i));
			
			obstacles.get(i).position(this.calculateVelocityFromAngle(0.5d, obstacles.get(i).yaw()));
			
			obstacles.get(i).yaw(obstacles.get(i).yaw() - (Math.PI / 2d));
			
		}
		
		//int num = rand.nextInt(4);
		quad = new Quad((double)mapfloat(rand.nextFloat(), 0.0f, 1.0f, -0.9f, 0.9f), (double)mapfloat(rand.nextFloat(), 0.0f, 1.0f, -0.9f, 0.9f), 0.0, phentotype);
	}
	/**
	 * draws the quadcopter
	 * @param x
	 * @param y
	 * @param width
	 * @param height
	 */
	public void drawQuad(float x, float y, float width, float height)
	{
		parent.rectMode(PConstants.CENTER);
		parent.fill(100);
		parent.rect(x, y, width / 3f, height / 3f);
		parent.ellipseMode(PConstants.CENTER);
		parent.ellipse(x + (width / 5f * 2), y + (height / 5f * 2), width / 4f, height / 4f);
		parent.ellipse(x - (width / 5f * 2), y + (height / 5f * 2), width / 4f, height / 4f);
		parent.ellipse(x + (width / 5f * 2), y - (height / 5f * 2), width / 4f, height / 4f);
		parent.ellipse(x - (width / 5f * 2), y - (height / 5f * 2), width / 4f, height / 4f);
		
		parent.rectMode(PConstants.CORNER);
	}
	/**
	 * updates the quad pseudo state estimate with noisy readings
	 */
	public void updateQuadState()
	{
		quad.quadState.setAltitude(quad.altitude() + mapfloat(rand.nextFloat(), 0f, 1f, (float)-Quad.ALTITUDE_NOISE, (float)Quad.ALTITUDE_NOISE));
		float posNoise = mapfloat(rand.nextFloat(), 0f, 1f, (float)-Quad.POSITION_NOISE, (float)Quad.POSITION_NOISE);
		float posNoise2 = mapfloat(rand.nextFloat(), 0f, 1f, (float)-Quad.POSITION_NOISE, (float)Quad.POSITION_NOISE);
		quad.quadState.setPosition(new Vec2d(quad.position().x + posNoise, quad.position().y + posNoise2));
		
	}
	
	/**
	 * Updates the states of the ground robots. These states have simulated noise according to a function 
	 */
	public void updateGroundRobotStates(float deltaTime)
	{
		turnTimer += deltaTime;
		for(int i = 0; i < quad.roombaStates.size(); i++)
		{
			float noise = (float)(Quad.ROBOT_POSITION_NOISE * euclideanDist(quad.position(), roombas.get(i).position()));
			double valX = (mapfloat(rand.nextFloat(), 0f, 1f, -noise, noise) + roombas.get(i).position().x);
			double valY = (mapfloat(rand.nextFloat(), 0f, 1f, -noise, noise) + roombas.get(i).position().y);
			quad.roombaStates.get(i).setPosition(new Vec2d(valX, valY));
			
			//this is a tricky part I can see many bugs stemming from this
			quad.roombaStates.get(i).setIndex(i);
			
			//System.out.format("REAL: %.4f, %.4f STATE: %.4f, %.4f\n", roombas.get(i).position().x, roombas.get(i).position().y, quad.roombaStates.get(i).getPosition().x, quad.roombaStates.get(i).getPosition().y);
		}
		for(int i = 0; i < quad.obstacleStates.size(); i++)
		{
			float noise = (float)(Quad.ROBOT_POSITION_NOISE * euclideanDist(quad.position(), obstacles.get(i).position()));
			double valX = (mapfloat(rand.nextFloat(), 0f, 1f, -noise, noise) + obstacles.get(i).position().x);
			double valY = (mapfloat(rand.nextFloat(), 0f, 1f, -noise, noise) + obstacles.get(i).position().y);
			quad.obstacleStates.get(i).setPosition(new Vec2d(valX, valY));
		}
		if(turnTimer >= 20)
		{
			//System.out.println("state timer reset");
			//reset state turn timers
			for(int i = 0; i < quad.roombaStates.size(); i++)
			{
				quad.roombaStates.get(i).resetTurnTimer();
			}
			turnTimer = 0;
		}
		//update oobs
		for(int i = 0; i < quad.roombaStates.size(); i++)
		{
			quad.roombaStates.get(i).setOOB(roombas.get(i).isOutOfBounds());
		}
	}
	
	/**
	 * triggers the robots "onBlock" function for
	 * a given robot. This function ensures that all robots will only be triggered once per run
	 */
	public void informRobotsAboutCollision()
	{
		//clear the collided robots list
		collidedObstacles.clear();
		collidedRoombas.clear();
		for(int i = 0; i < roombas.size(); i++)
		{
			if(!roombas.get(i).dontDrive)
			{
				boolean roombaTriggered  = false;
				for(int j = 0; j < roombas.size(); j++)
				{
					if(i != j && !roombaTriggered)
					{
						//also checks if the robots are in bounds
						if(detectCollision(roombas.get(i).position(), roombas.get(i).yaw(), roombas.get(j).position()) && !roombas.get(i).outOfBounds && !roombas.get(j).outOfBounds)
						{
							roombaTriggered = true;
							//trigger the on block command
							roombas.get(i).onBlock();
							collidedRoombas.add(i);
							//System.out.println("Colliding Roomba: " + i);
						}
					}
				}
				for(int j = 0; j < obstacles.size(); j++)
				{
					if(!roombaTriggered)
					{
						if(detectCollision(roombas.get(i).position(), roombas.get(i).yaw(), obstacles.get(j).position()))
						{
							roombaTriggered = true;
							roombas.get(i).onBlock();
							collidedRoombas.add(i);
							//System.out.println("Colliding Roomba: " + i);
						}
					}
				}
			}
		}
		
		for(int i = 0; i < obstacles.size(); i++)
		{
			if(!obstacles.get(i).dontDrive)
			{
				boolean obstacleTriggered = false;
				for(int j = 0; j < roombas.size(); j++)
				{
					if(!obstacleTriggered)
					{
						if(detectCollision(obstacles.get(i).position(), obstacles.get(i).yaw(), roombas.get(j).position()))
						{
							obstacleTriggered = true;
							obstacles.get(i).onBlock();
							collidedObstacles.add(i);
							//System.out.println("Colliding Obstacle: " + i);
						}
					}
				}
				for(int j = 0; j < obstacles.size(); j++)
				{
					if(i != j && !obstacleTriggered)
					{
						if(detectCollision(obstacles.get(i).position(), obstacles.get(i).yaw(), obstacles.get(j).position()))
						{
							obstacleTriggered = true;
							obstacles.get(i).onBlock();
							collidedObstacles.add(i);
							//System.out.println("Colliding Obstacle: " + i);
						}
					}
				}
			}
		}
	}
	
	/**
	 * detects whether a robot has collided with another robot
	 * @param thisRobotPos
	 * @param thisRobotYaw
	 * @param otherRobotPos
	 * @return false if not true if 
	 */
	public boolean detectCollision(Vec2d thisRobotPos, double thisRobotYaw, Vec2d otherRobotPos)
	{
		
		if(this.euclideanDist(thisRobotPos, otherRobotPos) <= Game.COLLISION_RANGE)
		{
			double relativeAngle = shrinkAngle(Math.atan2(otherRobotPos.y - thisRobotPos.y, otherRobotPos.x - thisRobotPos.x));
			//System.out.println("The relative angle between the robots is: " + relativeAngle);
			//screw it just return true
			if(Math.abs(shrinkAngle(thisRobotYaw) - relativeAngle) <= Game.COLLISION_MAX)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	
	/**
	 * takes in radius, theta
	 * @return velocity
	 */
	public Vec2d calculateVelocityFromAngle(double radius, double _angle)
	{
		double angle = _angle;
		Vec2d vec = new Vec2d();
		while(angle > 2d * Math.PI)
		{
			angle -= 2d * Math.PI;
		}
		
		//-----------
		vec.x = radius * Math.cos(angle);
		vec.y = radius * Math.sin(angle);
		
		return vec;
	}
	
	/**
	 * converts an angle to 0 - 2PI
	 * @param angle
	 * @return
	 */
	public double shrinkAngle(double angle)
	{
		while(angle < 0)
		{
			angle += 2 * Math.PI;
		}
		while(angle >= 2 * Math.PI)
		{
			angle -= 2 * Math.PI;
		}
		
		return angle;
	}
	
	/**
	 * calculates the distance between two points
	 * @param pos1
	 * @param pos2
	 * @return distance
	 */
	public double euclideanDist(Vec2d pos1, Vec2d pos2)
	{
		return Math.sqrt(Math.pow(pos2.x - pos1.x, 2) + Math.pow(pos2.y - pos1.y, 2));
	}
	/**
	 * converts the -1, 1 coordinates to pixel coordinates, X
	 * @param x
	 * @return
	 */
	public float localToRealXCoordinates(double x)
	{
		return this.mapfloat((float)x, -1f, 1f, (parent.width - Arena.WIDTH) / 2f, Arena.WIDTH + (parent.width - Arena.WIDTH) / 2f);
	}
	/**
	 * converts the -1, 1 coordinates to pixel coordinates, Y
	 * @param y
	 * @return
	 */
	public float localToRealYCoordinates(double y)
	{
		return this.mapfloat((float)y, 1f, -1f, (parent.height - Arena.HEIGHT) / 2f, Arena.HEIGHT + (parent.height - Arena.HEIGHT) / 2f);
	}
	
	public float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
	{
		//System.out.println("input: " + x + " in min: " + in_min + " in max: " + in_max + " out min: " + out_min + " out Max: " + out_max);
		return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
	}
}
