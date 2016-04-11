import processing.core.PApplet;

public class Arena {
	
	PApplet parent;
	
	final static int WIDTH = 700;
	final static int HEIGHT = 700; 
	float screenWidth;
	float screenHeight;
	
	public Arena(PApplet _parent, float _screenWidth, float _screenHeight)
	{
		parent = _parent;
		screenHeight = _screenHeight;
		screenWidth = _screenWidth;
	}
	
	/**
	 * Draws arena on field
	 */
	public void draw(float _screenWidth, float _screenHeight)
	{
		screenWidth = _screenWidth;
		screenHeight = _screenHeight;
		
		parent.fill(0, 0, 127);
		parent.strokeWeight(0);
		parent.rect((screenWidth - WIDTH) / 2f, (screenHeight - HEIGHT) / 2f, WIDTH, HEIGHT);
		
		parent.stroke(0, 255, 0);
		parent.strokeWeight(2);
		parent.line(0 + ((screenWidth - WIDTH) / 2), 0 + ((screenHeight - HEIGHT) / 2), WIDTH + ((screenWidth - WIDTH) / 2), 0 + ((screenHeight - HEIGHT) / 2));
		
		parent.stroke(170, 170, 170);
		parent.strokeWeight(2);
		for(int i = 1; i < 19; i++)
		{
			parent.line(0 + ((screenWidth - WIDTH) / 2), (i * (HEIGHT / 19f)) + ((screenHeight - HEIGHT) / 2), WIDTH + ((screenWidth - WIDTH) / 2), (i * (HEIGHT / 19f)) + ((screenHeight - HEIGHT) / 2));
		}
		
		parent.stroke(255, 0, 0);
		parent.strokeWeight(2);
		parent.line(0 + ((screenWidth - WIDTH) / 2), HEIGHT + ((screenHeight - HEIGHT) / 2), WIDTH + ((screenWidth - WIDTH) / 2), HEIGHT + ((screenHeight - HEIGHT) / 2));
		
		parent.stroke(170, 170, 170);
		for(int i = 0; i < 21; i++)
		{
			parent.line((i * (WIDTH / 20f)) + 0 + ((screenWidth - WIDTH) / 2), ((screenHeight - HEIGHT) / 2), (i * (WIDTH / 20f)) + 0 + ((screenWidth - WIDTH) / 2), HEIGHT + ((screenHeight - HEIGHT) / 2));
		}
	}
	
}
