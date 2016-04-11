import java.util.Random;

import com.sun.javafx.geom.Vec2d;

class Roomba implements Robot {
	public static double LINEAR_RATE = 0.033;
	public static final double ANGULAR_RATE = Math.PI / 5d;
	public static double DIAMETER = 0.032;
	public static final float NOISE_TIMER_THRESHOLD = 5;
	public static final float TURN_AROUND_TIMER_THRESHOLD = 20;
	public static final float NOISE = (float)Math.PI / 9f;
	public static final double LINEAR_WHEEL_SLIP_NOISE = 0.001;
	public static final double ANGULAR_WHEEL_SLIP_NOISE = 0.002;
	
	public boolean rotating = false;
	public boolean dontDrive = false;
	public boolean outOfBounds = false;
	public boolean firstRun = true;
	
	private float noiseTimer = 0;
	private float turnAroundTimer = 0;
	protected double setTheta = 0;
	private float dT = 0.1f;

	private Vec2d myPosition;
	private Vec2d myVelocity;
	private double yaw;
	
	Random rand = new Random();
	
	public Roomba()
	{
		//seed the random value
		rand.setSeed(System.currentTimeMillis());
		position(new Vec2d(0d, 0d));
		velocity(new Vec2d(0d, 0d));
		yaw(0d);
	}

	public void onTap(){
		//TODO
	}
	public void onBlock(){
		//System.out.println("I have collided!");
		this.rotate((float)Math.PI);
		dontDrive = true;
	}
	
	/**
	 * determines whether the robot is out of bounds
	 * @return boolean, in or out
	 */
	public boolean isOutOfBounds()
	{
		if(Math.abs(this.position().x) > 1)
		{
			return true;
		}
		else if(Math.abs(this.position().y) > 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	private void addNoise(float deltaTime)
	{
		noiseTimer += deltaTime;
		if(noiseTimer >= Roomba.NOISE_TIMER_THRESHOLD)
		{
			//set yaw noise
			this.rotate(this.mapfloat(rand.nextFloat(), 0.0f, 1.0f, -Roomba.NOISE, Roomba.NOISE));
			noiseTimer = 0;
		}
	}
	
	private void turnAroundTriggerer(float deltaTime)
	{
		turnAroundTimer += deltaTime;
		if(turnAroundTimer >= Roomba.TURN_AROUND_TIMER_THRESHOLD)
		{
			//System.out.println("turning 180 degrees");
			dontDrive = true;
			this.rotate((float)Math.PI);
			turnAroundTimer = 0;
		}
	}
	
	public void drive(float deltaTime)
	{
		velocity().x = Roomba.LINEAR_RATE * Math.cos(yaw());
		velocity().y = Roomba.LINEAR_RATE * Math.sin(yaw());
		
		float noise = mapfloat(rand.nextFloat(), 0f, 1f, (float)-Roomba.LINEAR_WHEEL_SLIP_NOISE, (float)Roomba.LINEAR_WHEEL_SLIP_NOISE);
		
		position().x = position().x + velocity().x * deltaTime;
		position().y = position().y + velocity().y * deltaTime;
	}

	public void rotate(float deltaTheta)
	{
		setTheta = setTheta + mapfloat(rand.nextFloat(), 0f, 1f, (float)-Roomba.ANGULAR_WHEEL_SLIP_NOISE, (float)Roomba.ANGULAR_WHEEL_SLIP_NOISE) + deltaTheta;
		rotating = true;
		this.rotate();
	}
	/**
	 * turns the robot to match the setTheta
	 * I think that it works... :)
	 * It works...
	 */
	public void rotate()
	{
		//System.out.println("My angle is: " + yaw());
		if(this.yaw() == setTheta)
		{
			//System.out.println("Achieved setTheta");
			rotating = false;
			dontDrive = false;
		}
		else
		{
			float dTheta = shrinkAngle(setTheta) - shrinkAngle(yaw());
			//System.out.println("dTheta is: " + dTheta);
			if(dTheta >= 0)
			{
				//dtheta is positive
				if(dTheta < Math.PI)
				{
					//go positively
					if(Math.abs(dTheta) > Roomba.ANGULAR_RATE * dT)
					{
						yaw(yaw() + Roomba.ANGULAR_RATE * dT);
					}
					else
					{
						yaw(setTheta);
					}
				}
				else
				{
					//go negatively
					if(Math.abs(dTheta) > Roomba.ANGULAR_RATE * dT)
					{
						yaw(yaw() - Roomba.ANGULAR_RATE * dT);
					}
					else
					{
						yaw(setTheta);
					}
				}
			}
			else
			{
				//dtheta is negative
				if(Math.abs(dTheta) < Math.PI)
				{
					//go negatively
					if(Math.abs(dTheta) > Roomba.ANGULAR_RATE * dT)
					{
						yaw(yaw() - Roomba.ANGULAR_RATE * dT);
					}
					else
					{
						yaw(setTheta);
					}
				}
				else
				{
					//go positively
					if(Math.abs(dTheta) > Roomba.ANGULAR_RATE * dT)
					{
						yaw(yaw() + Roomba.ANGULAR_RATE * dT);
					}
					else
					{
						yaw(setTheta);
					}
				}
			}
		}
	}
	
	public void run(float deltaTime)
	{
		dT = deltaTime;
		if(firstRun)
		{
			setTheta = yaw();
			firstRun = false;
		}
		outOfBounds = isOutOfBounds();
		if(!outOfBounds)
		{
			addNoise(deltaTime);
			turnAroundTriggerer(deltaTime);
			if(!dontDrive)
			{
				drive(deltaTime);
			}
			rotate();
		}
	}
	
	public Vec2d position(){ return myPosition; }
	public Vec2d velocity(){ return myVelocity; }
	public double yaw(){ return yaw; }
	public void position(Vec2d set){ myPosition = set; }
	public void velocity(Vec2d set){ myVelocity = set; }
	public void yaw(double set){ yaw = set; }
	
	public float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
	{
		//System.out.println("input: " + x + " in min: " + in_min + " in max: " + in_max + " out min: " + out_min + " out Max: " + out_max);
		return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
	}
	/**
	 * converts an angle to 0 - 2PI
	 * @param angle
	 * @return
	 */
	public float shrinkAngle(double angle)
	{
		while(angle < 0)
		{
			angle += 2 * Math.PI;
		}
		while(angle >= 2 * Math.PI)
		{
			angle -= 2 * Math.PI;
		}
		
		return (float)angle;
	}
}
