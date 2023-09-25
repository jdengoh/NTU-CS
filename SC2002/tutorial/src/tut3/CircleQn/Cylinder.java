package tut3.CircleQn;

// UNTESTED
public class Cylinder extends Circle {
	private double height;
	private static final double PI = 3.14159;
	
	public Cylinder() {
		height = 1;
	}
	
	public Cylinder(double height) {
		this.height = height;
	}
	
	public Cylinder(double radius, double height) {
		super(radius);
		this.height = height;
	}
	
	public Cylinder(int x, int y, double radius, double height) {
		super(x,y,radius);
		this.height = height;
	}
	
	public void setHeight(double height) {
		this.height = height;
	}
	
	public double getHeight() {
		return this.height;
	}
	
	public double area() {
		return (2*super.area() + 2*PI*super.getRadius()*height);
	}
	
	public double volume() {
		return(super.area()*height);
	}
	
	public String toString() {
		return String.format("Cylinder of height %.2f, radius %.2f at point [ %d, %d ]", height, super.getRadius(), x, y);
	}
	
	
}
