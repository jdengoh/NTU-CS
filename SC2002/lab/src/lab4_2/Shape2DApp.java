package lab4_2;
import java.util.Scanner;

public class Shape2DApp {
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);

		int num;
		int choice;
		Shape[] shapeList;
				
		System.out.println("Enter the number of shapes:");
		num = sc.nextInt();
		
		shapeList = new Shape[num];
		
		System.out.println("Shapes:\n1. Square\n2. Rectangle\n3. Circle\n4. Triangle");
		
		for (int i=0; i<num; i++) {
			System.out.println("Enter your choice:");
			choice = sc.nextInt();
			
			switch(choice) {
			
			case 1:
				System.out.println("Enter length of Square: ");
				double side = sc.nextInt();
				shapeList[i] = new Square(side);
				break;
				
			case 2:
	            System.out.println("Enter the lenght and breadth of the rectangle: ");
	            double length = sc.nextDouble();
	            double width = sc.nextDouble();
	            shapeList[i] = new Rectangle(length, width);
	            break;
	        case 3:
	            System.out.println("Enter the radius of the circle: ");
	            double radius = sc.nextDouble();
	            shapeList[i] = new Circle(radius);
	            break;
	        case 4:
	            System.out.println("Enter the base and height of the triangle: ");
	            double base = sc.nextDouble();
	            double height = sc.nextDouble();
	            shapeList[i]= new Triangle(base, height);
	            break;
	        case 5:
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
	        //print total area
	        double totalArea = 0;
	        for (int i = 0; i < num; i++) {
	            totalArea += shapeList[i].calcArea();
	        }
	        System.out.println("Total area: " + totalArea);
	        break;
	    default:
	        System.out.println("Invalid choice. Try again.");
	        break;
	    }
	    sc.close();
				
				
		}
	}
		
