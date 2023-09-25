package tut2;


public class Circle {
	private double radius;						 //radius of circle
	private static final double PI = 3.14159;	 //constant
	
	//constructor
	public Circle(double rad) {
		this.radius = rad;
	}
	
	//mutator method
	public void setRadius(double rad) {
		this.radius = rad;
	}
	
	//accessor method
	public double getRadius() {
		return radius;
	}
	
	public double area() {
		return PI*radius*radius;
	}
	
	public double circumference() {
		return 2*PI*radius;
	}
	
	public void printArea() {
		System.out.println("Area: " + area());
	}
	
	public void printCircumference() {
		System.out.println("Circumference: " + circumference());
	}
	
}
