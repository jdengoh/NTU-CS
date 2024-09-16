package lab4_2;

import java.util.Scanner;
public class Shape3DApp {
	
	public static void main(String[] args) {
		Shape[] shapes3D;
		Scanner sc = new Scanner(System.in);
		
		int num;
		int choice;
		
		System.out.println("Enter the number of shapes");
		num = sc.nextInt();

		shapes3D = new Shape[num];

		System.out.println("Choose your shape:");
		System.out.println("1. Sphere");
		System.out.println("2. Pyramid");
		System.out.println("3. Cuboid");
		
		for (int i=0; i<num; i++) {
			System.out.println("Enter your choice:");
			choice = sc.nextInt();
			
			switch(choice) {
			
			case 1:
				System.out.println("Enter the radius of the sphere: ");
				double radius = sc.nextDouble();
				shapes3D[i] = new Sphere(radius);
				break;
				
			case 2:
	            System.out.println("Enter the length and height of the pyramid: ");
	            double length = sc.nextDouble();
	            double height = sc.nextDouble();
	            shapes3D[i] = new Pyramid(length, height);
	            break;
	        case 3:
	            System.out.println("Enter the length, width and height of the cuboid: ");
	            double length_C = sc.nextDouble();
	            double width = sc.nextDouble();
	            double heightC = sc.nextDouble();
	            shapes3D[i] = new Cuboid(length_C, width, heightC);
	            break;
	        case 4:
	            System.out.println("Exiting...");
	            System.exit(0);
	            break;
	        default:
	            System.out.println("Invalid choice. Try again.");
	            break;
	        }
		}

		System.out.println("Choose the calculation type: ");
	    System.out.println("1. Area");
	    choice = sc.nextInt();
	    switch (choice) {
			case 1:
				double totalArea = 0;
				for (int i=0; i<num; i++) {
					System.out.println("Shape: " + shapes3D[i].getName());
					System.out.println("Area: " + shapes3D[i].calcArea());
					totalArea += shapes3D[i].calcArea();
				}
				System.out.println("Total Area: " + totalArea);
				break;

		}

		sc.close();
		
	}
}
