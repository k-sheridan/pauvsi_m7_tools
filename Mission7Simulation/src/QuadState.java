import com.sun.javafx.geom.Vec2d;

public class QuadState {
	
	Vec2d lastPos, pos;
	double lastAlt, alt;
	
	public QuadState()
	{
		lastPos = null;
		pos = null;
		alt = Double.MIN_VALUE;
		lastAlt = Double.MIN_VALUE;
	}
	
	public void setPosition(Vec2d _pos)
	{
		if(pos == null || lastPos == null)
		{
			pos = _pos;
			lastPos = _pos;
		}
		else
		{
			lastPos = pos;
			pos = _pos;
		}
	}
	
	public void setAltitude(double _alt)
	{
		if(alt == Double.MIN_VALUE || lastAlt == Double.MIN_VALUE)
		{
			alt = _alt;
			lastAlt = _alt;
		}
		else
		{
			lastAlt = alt;
			alt = _alt;
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
	
	public double getAltitude()
	{
		return alt;
	}
	
	public double getAltitudeRate() {
		return alt - lastAlt;
	}
	
}
