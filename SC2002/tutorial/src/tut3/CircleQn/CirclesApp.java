package tut3.CircleQn;

public class CirclesApp {
	public static void main(String[] args) {
		
		Cylinder cyl = new Cylinder(1, 1, 5, 6);
		
		System.out.println(cyl.toString());
		
		
		CircleBetter cir = new CircleBetter(2,2,10);
		System.out.println(cir.toString());
		
		
	}

}
