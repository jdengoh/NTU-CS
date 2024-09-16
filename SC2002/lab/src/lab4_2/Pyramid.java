package lab4_2;

// square base
public class Pyramid extends Shape{
	double height;
	double length;
	
	public Pyramid(double length, double height) {
		super("Pyramid");
		this.length = length;
		this.height = height;
	}
	
	public double calcArea() {
		double triangle_area = 4* 0.5 * this.length * Math.sqrt(Math.pow(length/2, 2) + Math.pow(this.height, height));
		double base_area = Math.pow(this.length, 2);
		return (triangle_area + base_area);

	}

	public double calcPerimeter() {
		return 0;
	}

}