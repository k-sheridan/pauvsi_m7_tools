import com.sun.javafx.geom.Vec2d;

public class RoombaState {
	
	private Vec2d lastPos;
	private Vec2d pos;
	private long timeAtLastTurn = 0;
	private int actualIndex = 0;
	private boolean OOB = false;
	
	public RoombaState()
	{
		lastPos = null;
		pos = null;
		timeAtLastTurn = System.currentTimeMillis();
	}
	
	public void setOOB(boolean bool)
	{
		OOB = bool;
	}
	
	public boolean getOOB()
	{
		return OOB;
	}
	
	public void setIndex(int in)
	{
		actualIndex = in;
	}
	
	public int getIndex()
	{
		return actualIndex;
	}
	
	public void setPosition(Vec2d _pos)
	{
		if(pos == null || lastPos == null)
		{
			pos = _pos;
			lastPos = pos;
		}
		else
		{
			lastPos = pos;
			pos = _pos;
		}
	}
	
	public Vec2d getPosition()
	{
		return pos;
	}
	
	public Vec2d getVelocity()
	{
		return new Vec2d(pos.x - lastPos.x, pos.y - lastPos.y);
	}
	
	public double getYaw()
	{
		Vec2d temp = getVelocity();
		return Math.atan2(temp.y, temp.x);
	}
	
	public void resetTurnTimer()
	{
		timeAtLastTurn = System.currentTimeMillis();
	}
	
	public float getTimeToTurn()
	{
		//TODO
		//check to see if this works as expected 
		return (float)(System.currentTimeMillis() - timeAtLastTurn) / 1000f;
	}
	
}
