package tut3.CircleQn;

public class CircleBetter {
	protected Point centre;
	protected double radius;
	private static final double PI = 3.14159;

	
	public CircleBetter(int x, int y, double radius) {
		centre = new Point(x,y);
		this.radius  = radius;
	}
	
	public void setRadius (double radius) {
		this.radius = radius;
	}
	
	public double getRadius() {
		return this.radius;
	}
	
	public String toString() {
		return String.format("Circle of Radius %.2f at point [ %d, %d ]", radius, centre.x, centre.y);
	}
	
	public double area() {
		return PI*radius*radius;
	}
}
	
