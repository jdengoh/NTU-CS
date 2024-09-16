package lab4_2;

public abstract class Shape {
	
//	double perimeter;
//	double area;
	String name;
	
	public Shape(String name) {
		this.name = name;
	}
	
	public abstract double calcArea();
	
	public abstract double calcPerimeter();
	
	public String getName() {
		return this.name;
	}
	
	public String toString() {
		return (this.name + "'s Area is " + calcArea() +", Perimeter is " + calcPerimeter() + ".");
	}
	
	

}
