package lab1;

import java.util.Scanner;

public class P1 {
	public static void main(String[] args) {
		// scanner object
		Scanner userIn = new Scanner(System.in);
		
		String input = userIn.nextLine();
		
//		while(True) {
			
			switch(input) {
			case "A":
			case "a":
				System.out.println("Action movie fan");
				break;
			case "C":
			case "c":
				System.out.println("Comedy movie fan");
				break;
			case "D":
			case "d":
				System.out.println("Drama movie fan");
				break;
			default:
				System.out.println("Invalid choice");
				break;
			}
			
			
//			input = userIn.nextLine();
//		}
//		System.out.println("end");
	}
}
