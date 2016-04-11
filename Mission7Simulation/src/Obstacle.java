

class Obstacle extends Roomba {
	
	public static final float OBSTACLE_ANGULAR_RATE = 0.084f;
	
	private float dT = 0.1f;
	public boolean firstRun = true;
	public float stopTimer = 3f;
	
	public Obstacle()
	{
		
	}
	
	public void run(float deltaTime)
	{
		if(firstRun)
		{
			setTheta = (float)yaw();
			firstRun = false;
		}
		dT = deltaTime;
		stopTimer(deltaTime);
		if(!dontDrive)
		{
			rotate(-Obstacle.OBSTACLE_ANGULAR_RATE * deltaTime);
			drive(deltaTime);
			rotate();
		}
	}
	
	public void onTap(){
		
	}
	public void onBlock(){
		//System.out.println("Obstacle collision detected.");
		resetStopTimer();
	}
	
	public void stopTimer(float deltaTime)
	{
		stopTimer += deltaTime;
		if(stopTimer >= 3f)
		{
			dontDrive = false;
		}
	}
	
	public void resetStopTimer()
	{
		stopTimer = 0;
		dontDrive = true;
	}
	
}
