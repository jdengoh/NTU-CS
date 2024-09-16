package lab4_2;

public class Square extends Shape{
	private double length;
	
	public Square(double length) {
		super("Square");
		this.length = length;
	}
	
	public double calcArea() {
		return length*length;
	}
	
	public double calcPerimeter() {
		return 4*length;
	}
	
}