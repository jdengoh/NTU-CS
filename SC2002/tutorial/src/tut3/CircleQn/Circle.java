package tut3.CircleQn;

// UNTESTED
public class Circle extends Point{
	private double radius;
	private static final double PI = 3.14159;
	
	public Circle() {
		radius = 1;
	}
	public Circle(double radius) {
		this.radius = radius;
	}
	public Circle(int x, int y, double radius) {
		super(x, y);
		this.radius = radius;
	}
	
	public void setRadius(double radius) {
		this.radius = radius;
	}
	
	public double getRadius() {
		return this.radius;
	}
	
	public String toString() {
		return String.format("Circle of Radius %.2f at point [ %d, %d ]", radius, x,y);
	}
	
	public double area() {
		return PI*radius*radius;
	}
}
