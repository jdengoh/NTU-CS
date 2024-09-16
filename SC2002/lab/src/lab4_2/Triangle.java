package lab4_2;

public class Triangle extends Shape{
	private double length, height;
	
	public Triangle(double length, double height) {
		super("Triangle");
		this.length = length;
		this.height = height;
		
	}
	
	public double calcArea() {
		return 0.5*length*height;
	}
	
	public double calcPerimeter() {
		return -1;
	}
	
}
