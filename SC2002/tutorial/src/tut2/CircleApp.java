package tut2;
import java.util.Scanner;

public class CircleApp {
	
	public static void main(String[] args) {
		
		int option = -1;
		double radius = 0;
		Circle circle = null;
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("==== Circle Computation ====\n"
				+ "|1. Create a new cricle	   |\n"
				+ "|2. Print Area 		   |\n"
				+ "|3. Print Circumference	   |\n"
				+ "|4. Quit		   |\n"
				+ "=============================\n");
		
		do {
			System.out.println("Choose option (1-3)");
			option = sc.nextInt();
			
			switch(option) {
			case 1:
				
				System.out.println("Enter the radius to compute the area and circumference");
				radius = sc.nextDouble();
				circle = new Circle(radius);
				System.out.println("A new circle has been created");
				break;
				
			case 2:
				System.out.println("Area of circle\n:"
						+ "Radius: " + radius);
				
				circle.printArea();
				break;
				
			case 3:
				System.out.println("Circumference of circle\n:"
						+ "Radius: " + radius);
				
				circle.printCircumference();		
				break;
			case 4:
				System.out.println("Thank you!");
				break;
			default:
				break;
			}
					
			
		}while(option<4);
		
	}
	
	
}
