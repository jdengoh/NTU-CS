package lab1;

import java.util.Scanner;

public class P4 {

	public static void main(String[] args) {
		
		Scanner userIn = new Scanner(System.in);
		
		int letter = 0;
		int height = userIn.nextInt();
		
		for (int i=0; i<height; i++) {
			
			if(i%2==0) letter = 0; 		//letter is A
			else letter = 1;			//letter is B
			
			for(int j=0; j<=i; j++) {
				if(letter==0) {
					System.out.print("AA");
					letter = 1;
				}
				else {
					System.out.print("BB");
					letter = 0;
				}
			}
			System.out.println();
			
		}
		
	}
}
