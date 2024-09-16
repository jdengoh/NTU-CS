package lab4_2;

public class Sphere extends Circle{
		
	public Sphere(double radius) {
		super(radius);
		this.name = "Sphere";
	}
	
	public double calcArea() {
		return 4*super.calcArea();
	}

	public double calcPerimeter() {
		return 0;
	}
	
}
