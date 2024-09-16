package lab4_2;

public class Rectangle extends Shape {
	
	double length, breadth;
	
	public Rectangle(double length, double breadth) {
		super("Rectangle");
		this.length = length;
		this.breadth = breadth;
	}
	
	public double calcArea(){
		return length*breadth;
	}
	
	public double calcPerimeter() {
		return 2*length + 2*breadth;
	}
}
