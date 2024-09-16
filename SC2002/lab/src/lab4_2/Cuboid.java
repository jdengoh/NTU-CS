package lab4_2;

public class Cuboid extends Rectangle{
	double height;
	public Cuboid(double length, double breadth, double height) {
		super(length, breadth);
		this.name = "Cuboid";
		this.height = height;
	}
	
	public double calcVolume() {
		return height * super.calcArea();
	}
	
	public double calcArea() {
		return 2 * (super.calcArea() + length*height + breadth * height);
	}
	
}
