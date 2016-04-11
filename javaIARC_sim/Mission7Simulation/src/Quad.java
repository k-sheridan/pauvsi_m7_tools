

import java.sql.Array;
import java.util.ArrayList;
import java.util.Random;

import org.encog.ml.MLMethod;
import org.encog.ml.data.MLData;
import org.encog.ml.data.basic.BasicMLData;
import org.encog.neural.neat.NEATNetwork;

import com.sun.javafx.geom.Vec2d;

import jdk.internal.org.objectweb.asm.tree.IntInsnNode;



class Quad implements Robot {
	
	public static final double MAX_ACCELERATION = 1; // .1 = 1 meter
	public static final double MAX_VELOCITY = 0.5; // .1 = 1 meter
	public static final double CRUISING_ALTITUDE = 0.25;
	public static final double OBSERVATION_ALTITUDE = 0.25;
	public static final double STARTING_OBSERVATION_ALTITUDE = 0.25;
	public static final float INITIALIZATION_TIMER_THRESHOLD = 5f;
	public static final double POS_KP = 2;
	public static final double ACCEL_KP = 0.2;
	public static final double ALTITUDE_NOISE = 0.004;
	public static final double POSITION_NOISE = 0.01;
	public static final double POSITION_LOCK_THRESHOLD = 0.015;
	public static final double ROBOT_POSITION_NOISE = 0.03;
	public static final int TAP = 1;
	public static final int BLOCK = 2;
	public static final double TAP_ALTITUDE = 0.025;
	public static final double SWOOP_DISTANCE = 0.3;
	public static final float TRIGGER_DELAY = 0.5f;
	public static final double PREDICTION_CONST = 1d;
	public static final double MAX_TRIGGERS = 5.0;
	
	
	private Vec2d myPosition;
	private Vec2d myVelocity;
	private double myAlt;
	private double myAltRate;
	public float dT = 0;
	public float initializationTimer = 0f;
	
	//bools
	//if the quad is "attacking" or not
	private boolean attacking = false;
	private boolean initializing = true;
	
	//the target and its last position
	private int targetIndex = 0;
	private Vec2d restingPos;
	
	//the magnetic trigger
	private Random rand;
	private int triggerCount = 0;
	private float triggerCounter = Quad.TRIGGER_DELAY;
	private boolean trigger = false;
	
	//nn
	MLMethod phenotype;
	private boolean nnTouchedOOB = false;
	
	//the roomba and obstacle and quad states
	public ArrayList<RoombaState> roombaStates = new ArrayList<RoombaState>();
	public ArrayList<RoombaState> obstacleStates = new ArrayList<RoombaState>();
	public QuadState quadState = new QuadState();
	
	//The list of selected roombas in order of their selection
	private ArrayList<Integer> roombaSelection = new ArrayList<Integer>(100);
	
	public Quad(double x, double y, double z, MLMethod phenotype)
	{
		//this is the neural network
		this.phenotype = phenotype;
		rand = new Random(System.currentTimeMillis());
		altitude(z);
		position(new Vec2d(x, y));
		velocity(new Vec2d(0, 0));
		restingPos = new Vec2d(x, y);
		
		//initialize the state estamation classes of roomba and obstacles
		for(int i = 0; i < 10; i++)
		{
			roombaStates.add(new RoombaState());
		}
		for(int i = 0; i < 4; i++)
		{
			obstacleStates.add(new RoombaState());
		}
	}
	

	public void run(float deltaTime){
		dT = deltaTime;
		if(initializing)
		{
			if(hoverAtStartingObservationAltitude(deltaTime))
			{
				if(initializeSystem(deltaTime))
				{
					initializing = false;
				}
			}
		}
		else
		{
			if(attacking)
			{
				if(triggerCount <= 0)
				{
					trigger = false;
				}
				//generates and follows waypoint
				//System.out.printf("calling waypoint generator, with target %d\n", targetIndex);
				followWaypoint(generateWaypoint(targetIndex, deltaTime), deltaTime);
				if(triggerCount <= 0)
				{
					attacking = false;
					restingPos = quadState.getPosition();
				}
			}
			else
			{
				//trigger is false if not attacking
				trigger = false;
				if(hoverAtObservationAltitude(deltaTime))
				{
					//run the neural net to determine the next target
					chooseNextTarget(phenotype, deltaTime);
				}
			}
		}
		//System.out.printf("Magnet is: %b trigger count is: %d\n", trigger, triggerCount);
		drive(deltaTime);
	}
	
	/**
	 * moves the quadcopter according to its accel and velo
	 */
	public void drive(float deltaTime)
	{
		//System.out.println(velocity());
		myPosition.x += velocity().x * deltaTime;
		myPosition.y += velocity().y * deltaTime;
		myAlt += altitudeRate() * deltaTime;
	}
	
	/**
	 * has th nn chosen an oob roomba
	 * @return
	 */
	public boolean hasNNTouchedOOB()
	{
		return nnTouchedOOB;
	}
	
	/**
	 * does what the function name says it does
	 * @return whether the observation altitude has been met
	 */
	public boolean hoverAtObservationAltitude(float deltaTime)
	{
		lockPosition(restingPos.x, restingPos.y, Quad.OBSERVATION_ALTITUDE, deltaTime);

		//System.out.format("POS X,Y,Z: %.4f, %.4f, %.4f\n", quadState.getPosition().x, quadState.getPosition().y, quadState.getAltitude());

		if(Math.abs(quadState.getPosition().x - restingPos.x) <= Quad.POSITION_LOCK_THRESHOLD &&
				Math.abs(quadState.getPosition().y - restingPos.y) <= Quad.POSITION_LOCK_THRESHOLD && 
				Math.abs(quadState.getAltitude() - Quad.OBSERVATION_ALTITUDE) <= Quad.POSITION_LOCK_THRESHOLD)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	/**
	 * does what the function name says it does
	 * the quadstate must be initialized before running
	 * @return whether the observation altitude has been met
	 */
	public void overrideRestingPos(double x, double y)
	{
		restingPos.x = x;
		restingPos.y = y;
	}
	
	/**
	 * will lock at a position using accelerations
	 * @param x
	 * @param y
	 * @param z
	 */
	public void lockPosition(double x, double y, double z, float deltaTime)
	{
		double altRateLock = constrain(Quad.POS_KP * (z - quadState.alt), Quad.MAX_VELOCITY);
		double XRateLock = constrain(Quad.POS_KP * (x - quadState.getPosition().x), Quad.MAX_VELOCITY);
		double YRateLock =  constrain(Quad.POS_KP * (y - quadState.getPosition().y), Quad.MAX_VELOCITY);
		
		myAltRate += constrain(altRateLock - altitudeRate(), Quad.MAX_ACCELERATION * deltaTime);
		myVelocity.x += constrain(XRateLock - velocity().x, Quad.MAX_ACCELERATION * deltaTime);
		myVelocity.y += constrain(YRateLock - velocity().y, Quad.MAX_ACCELERATION * deltaTime);
	}
	
	public boolean hoverAtStartingObservationAltitude(float deltaTime)
	{
		lockPosition(restingPos.x, restingPos.y, Quad.STARTING_OBSERVATION_ALTITUDE, deltaTime);
		
		//System.out.format("POS X,Y,Z: %.4f, %.4f, %.4f\n", quadState.getPosition().x, quadState.getPosition().y, quadState.getAltitude());
		
		if(Math.abs(quadState.getPosition().x - restingPos.x) <= Quad.POSITION_LOCK_THRESHOLD &&
				Math.abs(quadState.getPosition().y - restingPos.y) <= Quad.POSITION_LOCK_THRESHOLD && 
				Math.abs(quadState.getAltitude() - Quad.STARTING_OBSERVATION_ALTITUDE) <= Quad.POSITION_LOCK_THRESHOLD)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	private boolean triggerMagnet(float deltaTime, boolean now)
	{
		triggerCounter += deltaTime;
		
		if(triggerCount > 0)
		{
			if(triggerCounter >= Quad.TRIGGER_DELAY && now)
			{
				triggerCount--;
				triggerCounter = 0;
				return true;
			}
		}
		return false;
	}
	
	public void followWaypoint(Waypoint wp, float deltaTime)
	{
		//calculates the rates depending on the waypoint type
		double xRateLock, yRateLock, altRateLock;
		//x vel
		if(wp.getXType() == Waypoint.LOCK)
		{
			xRateLock = constrain(Quad.POS_KP * (wp.getPosition().x - quadState.getPosition().x), Quad.MAX_VELOCITY);
		}
		else
		{
			xRateLock = Quad.MAX_VELOCITY * Math.cos(Math.atan2(wp.getPosition().y - quadState.getPosition().y, wp.getPosition().x - quadState.getPosition().x));
		}
		// y vel
		if(wp.getYType() == Waypoint.LOCK)
		{
			yRateLock = constrain(Quad.POS_KP * (wp.getPosition().y - quadState.getPosition().y), Quad.MAX_VELOCITY);
		}
		else
		{
			yRateLock = Quad.MAX_VELOCITY * Math.sin(Math.atan2(wp.getPosition().y - quadState.getPosition().y, wp.getPosition().x - quadState.getPosition().x));
		}
		// z vel
		if(wp.getZType() == Waypoint.LOCK)
		{
			altRateLock = constrain(Quad.POS_KP * (wp.getPosition().z - quadState.getAltitude()), Quad.MAX_VELOCITY);
		}
		else
		{
			if(wp.getPosition().z < quadState.getAltitude())
			{
				altRateLock = -Quad.MAX_VELOCITY;
			}
			else
			{
				altRateLock = Quad.MAX_VELOCITY;
			}
		}
		
		//System.out.println(wp.getPosition());
		
		//apply the rates with acceleration constraint
		myAltRate += constrain(altRateLock - altitudeRate(), Quad.MAX_ACCELERATION * deltaTime);
		myVelocity.x += constrain(xRateLock - velocity().x, Quad.MAX_ACCELERATION * deltaTime);
		myVelocity.y += constrain(yRateLock - velocity().y, Quad.MAX_ACCELERATION * deltaTime);
		
		//this triggers the magnet if it is a magnet point
		//System.out.println("Calling trigger stuff");
		if(wp.isTrigger() && triggerCount > 0)
		{
			if(Math.abs(myPosition.x - wp.getPosition().x) <= Quad.POSITION_LOCK_THRESHOLD &&
					Math.abs(myPosition.y - wp.getPosition().y) <= Quad.POSITION_LOCK_THRESHOLD &&
					Math.abs(myAlt - wp.getPosition().z) <= Quad.POSITION_LOCK_THRESHOLD)
			{
				//trigger function
				trigger = triggerMagnet(deltaTime, true);
			}
			else
			{
				//trigger function
				trigger = triggerMagnet(deltaTime, false);
			}
		}
		else
		{
			trigger = false;
		}
	}
	
	/**
	 * does what it does lol
	 * @param targetIndex
	 * @param TIME_STEP
	 * @return
	 */
	public Waypoint generateWaypoint(int targetIndex, float TIME_STEP)
	{
		Waypoint waypoint;
		
		/*
		 * this creates a point of intercept, but it is 
		 * stupidly simple
		 * . therefore i don't think we will use this on the full robot 
		 */
		
		double roombaYaw = roombaStates.get(targetIndex).getYaw();
		Vec2d interceptPoint = predictIntercept(quadState.getPosition(), new Vec2d(quadState.getVelocity().x / TIME_STEP, quadState.getVelocity().y / TIME_STEP),
				roombaStates.get(targetIndex).getPosition(),
				new Vec2d(Roomba.LINEAR_RATE * TIME_STEP * Math.cos(roombaYaw), Roomba.LINEAR_RATE * TIME_STEP * Math.sin(roombaYaw)), TIME_STEP);
		
		
		/*
		 * logic for generating the path of the quad 
		 */
		
		if(euclideanDist(quadState.getPosition(), roombaStates.get(targetIndex).getPosition()) <= Quad.SWOOP_DISTANCE) //if the quad is in the range of swooping
		{
			//this creates a waypoint at the intercept point which triggers the roomba
			waypoint = new Waypoint(interceptPoint.x, interceptPoint.y, Quad.TAP_ALTITUDE, Waypoint.LOCK, Waypoint.LOCK,
					Waypoint.LOCK, true);
		}
		else
		{
			if(quadState.getAltitude() <= Quad.CRUISING_ALTITUDE - Quad.POSITION_LOCK_THRESHOLD || 
					quadState.getAltitude() >= Quad.CRUISING_ALTITUDE + Quad.POSITION_LOCK_THRESHOLD) //determines if the quad is not at cruising alt
			{
				//sets the way point to lock at current pos and cruising altitude
				waypoint = new Waypoint(quadState.getPosition().x, quadState.getPosition().y,
						Quad.CRUISING_ALTITUDE, Waypoint.LOCK, Waypoint.LOCK, Waypoint.LOCK, false);
				
			}
			else
			{
				
				//angle between intercept point and quad
				double angle = Math.atan2(quadState.getPosition().y - interceptPoint.y, quadState.getPosition().x - interceptPoint.x);
				Vec2d goal = new Vec2d(interceptPoint.x + (Quad.SWOOP_DISTANCE * Math.cos(angle)),
						interceptPoint.y + (Quad.SWOOP_DISTANCE * Math.sin(angle)));
				
				/*
				 * This sets the waypoint to a passthrough waypoint at a predict swoop starting point
				 * the way point is set to lock altitude at cruising alt.
				 */
				waypoint = new Waypoint(goal.x, goal.y, Quad.CRUISING_ALTITUDE, Waypoint.PASSTHROUGH, Waypoint.PASSTHROUGH, Waypoint.LOCK, false);
			}
		}
		
		//System.out.printf("Predicted Intercept Point of Roomba %d: %.4f, %.4f\n", targetIndex, interceptPoint.x, interceptPoint.y);
		//System.out.printf("Waypoint: %.4f, %.4f, %.4f\n", waypoint.getPosition().x, waypoint.getPosition().y, waypoint.getPosition().z);
		
		return waypoint;
	}
	
	/**
	 * predicts the intercept point of roomba and quadrotor. (rudimentary)
	 * @return
	 */
	private Vec2d predictIntercept(Vec2d quadPos, Vec2d quadVel, Vec2d roombaPos, Vec2d roombaVel, float TIME_STEP)
	{
		double D = euclideanDist(quadPos, roombaPos);
		double T = D * Quad.PREDICTION_CONST;
		
		//if the roomba is stationary
		if(euclideanDist(roombaVel, new Vec2d(0, 0)) < Roomba.LINEAR_RATE * TIME_STEP)
		{
			T = 0;
		}
		
		return new Vec2d(roombaPos.x + (roombaVel.x * T), roombaPos.y + (roombaVel.y * T));
	}
	
	private double speed(Vec2d vec)
	{
		return Math.sqrt(vec.x * vec.x + vec.y * vec.y);
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
	 * simulates the time it would take for our vehicle to orient itself
	 * @param deltaTime time steps
	 * @return whether the timer threshold has been reached
	 */
	public boolean initializeSystem(float deltaTime)
	{
		initializationTimer += deltaTime;
		if(initializationTimer >= Quad.INITIALIZATION_TIMER_THRESHOLD)
		{
			//System.out.println("System Initialized");
			return true;
		}
		else
		{
			return false;
		}
	}
	
	public int getTarget()
	{
		return targetIndex;
	}
	
	public boolean getMagnetTrigger()
	{
		return trigger;
	}
	
	/**
	 * gets the list of roombas selected
	 * @return
	 */
	public ArrayList<Integer> getRoombaSelectionList()
	{
		return roombaSelection;
	}
	
	/**
	 * runs through the neural network and determines the best robot to choose 
	 * and the best method to touch it with
	 * this is based of the current state estimate that we are simulating(it is not perfect like in the real world)
	 */
	public void chooseNextTarget(MLMethod phenotype, float deltaTime)
	{
		ArrayList<Double> output1 = new ArrayList<Double>(10);
		ArrayList<Double> output2 = new ArrayList<Double>(10);
		
		//cycle through and try each roomba
		for(int i = 0; i < roombaStates.size(); i++)
		{
			if(!roombaStates.get(i).getOOB()) // if the roomba is not out of bounds
			{
				//create the neural netwok inputs
				double[] inputs = new double[Mission_7_Simulation.INPUTS + 1];
				//set the bias
				inputs[Mission_7_Simulation.INPUTS] = 1.0;
				//set up quad variable distance
				inputs[0] = mapDouble(euclideanDist(quadState.getPosition(), roombaStates.get(i).getPosition()), 0.0, Math.sqrt(8.0), 0.0, 1.0);
				//time to turn
				inputs[1] = mapDouble(roombaStates.get(i).getTimeToTurn(), 0.0, 20.0, 0.0, 1.0);
				
				//add the roombas
				inputs[2] = mapDouble(roombaStates.get(i).getPosition().x, -1.0, 1.0, 0.0, 1.0);
				
				inputs[3] = mapDouble(roombaStates.get(i).getPosition().y, -1.0, 1.0, 0.0, 1.0);
				
				inputs[4] = mapDouble(1.0 * Math.cos(roombaStates.get(i).getYaw()), -1.0, 1.0, 0.0, 1.0); // dx
				
				inputs[5] = mapDouble(1.0 * Math.sin(roombaStates.get(i).getYaw()), -1.0, 1.0, 0.0, 1.0); // dy
				
				//find the closest obstacle robot
				int closestObstacleIndex = 0;
				for(int j = 0; j < obstacleStates.size(); j++)
				{
					//if this obstacle is closer than the other obstacles
					if(euclideanDist(roombaStates.get(i).getPosition(), obstacleStates.get(j).getPosition()) < 
							euclideanDist(roombaStates.get(i).getPosition(), obstacleStates.get(closestObstacleIndex).getPosition()))
					{
						closestObstacleIndex = j;
					}
				}
				
				//add the normalized position of the closest obstacle to the inputs and velos
				inputs[6] = mapDouble(obstacleStates.get(closestObstacleIndex).getPosition().x, -1.0, 1.0, 0.0, 1.0);
				
				inputs[7] = mapDouble(obstacleStates.get(closestObstacleIndex).getPosition().y, -1.0, 1.0, 0.0, 1.0);

				inputs[8] = mapDouble(1.0 * Math.cos(obstacleStates.get(closestObstacleIndex).getYaw()), -1.0, 1.0, 0.0, 1.0); // dx
				
				inputs[9] = mapDouble(1.0 * Math.sin(obstacleStates.get(closestObstacleIndex).getYaw()), -1.0, 1.0, 0.0, 1.0); // dy

				//here is a nice wrapped up net input waiting for its duty
				MLData netInput = new BasicMLData(inputs);

				//run the network
				MLData netOutput = ((NEATNetwork)phenotype).compute(netInput);
				
				//add the outputs
				output1.add(netOutput.getData(0));
				output2.add(netOutput.getData(1));
			}
			else
			{
				output1.add(0.0);
				output2.add(0.0);
			}
		}
		
		int mostDesiredRoombaIndex = 0;
		for(int i = 0; i < output1.size(); i++)
		{
			if(output1.get(i).doubleValue() > output1.get(mostDesiredRoombaIndex).doubleValue())
			{
				mostDesiredRoombaIndex = i;
			}
		}
		
		
		
		//set the variables which tell the game what to do
		targetIndex = roombaStates.get(mostDesiredRoombaIndex).getIndex();
		triggerCount = (int) Math.round(mapDouble(output2.get(mostDesiredRoombaIndex).doubleValue(), 0, 1, 0, Quad.MAX_TRIGGERS));
		attacking = true;
		//targetIndex = rand.nextInt(10);
		//triggerCount = rand.nextInt(4);
		//attacking = true;
		
		//add the selected roomba to the list
		roombaSelection.add(roombaStates.get(mostDesiredRoombaIndex).getIndex());
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
	
	public double mapDouble(double x, double in_min, double in_max, double out_min, double out_max)
	{
		//System.out.println("input: " + x + " in min: " + in_min + " in max: " + in_max + " out min: " + out_min + " out Max: " + out_max);
		return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
	}
	
	
	/**
	 * Keeps a value within +/- a constrainer
	 * @param in
	 * @param contrainer
	 * @return
	 */
	public double constrain(double in, double contrainer)
	{
		if(in > contrainer)
		{
			in = contrainer;
		}
		else if(in < -contrainer)
		{
			in = -contrainer;
		}
		return in;
	}
	
	public Vec2d position(){ return myPosition; }
	public Vec2d velocity(){ return myVelocity; }
	public double altitude(){ return myAlt; }
	public double altitudeRate(){ return myAltRate; }
	public boolean trigger(){ return trigger; }

	public void position(Vec2d set){ myPosition = set; }
	public void velocity(Vec2d set){ myVelocity = set; }
	public void altitude(double set){ myAlt = set; }
	public void altitudeRate(double set){ myAltRate = set; }
	public void trigger(boolean _trig){ trigger = _trig; }
}
