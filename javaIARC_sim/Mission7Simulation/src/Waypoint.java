import com.sun.javafx.geom.Vec3d;

public class Waypoint {
	
	public static final int PASSTHROUGH = 1;
	public static final int LOCK = 2;
	
	private int X_waypointType = 2;
	private int Y_waypointType = 2;
	private int Z_waypointType = 2;
	private Vec3d position;
	private boolean trigger = false;
	
	public Waypoint(double x, double y, double z, int Xtype, int Ytype, int Ztype, boolean _trigger)
	{
		position = new Vec3d(x, y, z);
		X_waypointType = Xtype;
		Y_waypointType = Ytype;
		Z_waypointType = Ztype;
		trigger = _trigger;
	}
	
	public int getXType()
	{
		return X_waypointType;
	}
	
	public int getYType()
	{
		return Y_waypointType;
	}
	
	public int getZType()
	{
		return Z_waypointType;
	}
	
	public Vec3d getPosition()
	{
		return position;
	}
	
	public boolean isTrigger()
	{
		return trigger;
	}
	
}
