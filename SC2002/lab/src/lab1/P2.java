package lab1;

import java.util.Scanner;

public class P2 {
	public static void main(String[] args) {
		String grade = null;
		Scanner userIn = new Scanner(System.in);
		
		System.out.print("salary: ");
		int salary = userIn.nextInt();
		
		System.out.print("merit: ");
		int merit = userIn.nextInt();
		
		if(500<=salary && salary<600) {
			grade = "C";
		}
		else if(600<=salary && salary<650) {
			if(merit<10) grade = "C";
			else grade = "B";
		}
		else if(650<=salary && salary<700) {
			grade = "B";
		}
		else if(700<=salary && salary<800) {
			if(merit<20) grade = "B";
			else grade = "A";
		}
		else if(800<=salary) {
			grade = "A";
		}
		
		System.out.println("salary: "+salary+", merit: "+merit+" - Grade "+grade+";");
		
	}

}
