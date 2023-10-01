package lab1;

import java.util.Scanner;

public class P3 {
	
	public static void main(String[] args) {
		
		Scanner userIn = new Scanner(System.in);
		
		double factor = 1.82;
		
		//table 1
		int start = userIn.nextInt();
		int end = userIn.nextInt();
		int inc = userIn.nextInt();

		System.out.println("US$	S$");
		System.out.println("--------------");
		for (int i=start; i<=end; i+=inc) {
			System.out.println(i+"	"+factor*i);
		}
		
		
		//table 2
		start = userIn.nextInt();
		end = userIn.nextInt();
		inc = userIn.nextInt();

		System.out.println("US$	S$");
		System.out.println("--------------");
		
		while (start != end+inc) {
			System.out.println(start+"	"+factor*start);
			start+=inc;
		}
		
		
		//table 3
		start = userIn.nextInt();
		end = userIn.nextInt();
		inc = userIn.nextInt();
		System.out.println("US$	S$");
		System.out.println("--------------");
		if (start>end) System.out.println("Error input!");
		else {
			do {
				System.out.println(start+"	"+factor*start);
				start+=inc;
			}while (start!=end+inc);
		}
		
	}
	
}
