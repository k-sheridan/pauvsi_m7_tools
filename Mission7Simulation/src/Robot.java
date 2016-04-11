

import com.sun.javafx.geom.Vec2d;

interface Robot {
	public void run(float deltaTime);

	public Vec2d position();
	public Vec2d velocity();

	public void position(Vec2d set);
	public void velocity(Vec2d set);
}
