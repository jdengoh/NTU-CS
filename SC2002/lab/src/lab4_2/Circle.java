package lab4_2;

public class Circle extends Shape{
	
	private double radius;
	
	public Circle(double radius) {
		super("Circle");
		this.radius = radius;
	}
	
	public double getRadius() {
		return this.radius;
	}
	
	public double calcPerimeter() {
		return Math.PI*2*radius;
	}
	
	
	public double calcArea() {
		return Math.PI*radius*radius;
	}

}
