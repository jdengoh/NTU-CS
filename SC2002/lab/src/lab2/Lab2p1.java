package lab2;
import java.util.Random;
import java.util.Scanner;


public class Lab2p1 {
		
	public static void main(String[] args)
	{
		int choice;
		int m, n, ans;
		long finalans;
		Scanner sc = new Scanner(System.in);
		do {
			System.out.println("Perform the following methods:");
			System.out.println("1: miltiplication test");
			System.out.println("2: quotient using division by subtraction");
			System.out.println("3: remainder using division by subtraction");
			System.out.println("4: count the number of digits");
			System.out.println("5: position of a digit");
			System.out.println("6: extract all odd digits");
			System.out.println("7: quit");
			choice = sc.nextInt();
			
			switch (choice) {
				case 1: mulTest(); /* add mulTest() call */
					break;
				case 2: /* add divide() call */
					System.out.println("m = ");
					m = sc.nextInt();
					System.out.println("n = ");
					n = sc.nextInt();
					ans = divide(m, n);
					System.out.println(m+"/"+n+" = "+ans);
					break;
				case 3: /* add modulus() call */
					System.out.println("m = ");
					m = sc.nextInt();
					System.out.println("n = ");
					n = sc.nextInt();
					ans = modulus(m, n);
					System.out.println(m+" % "+n+" = "+ans);
					break;
				case 4: /* add countDigits() call */
					System.out.println("n : ");
					n = sc.nextInt();
					ans = countDigits(n);
					if (ans == -1) System.out.println("Error input");
					else System.out.println("count = " + ans);
					break;
				case 5: /* add position() call */
					System.out.println("n : ");
					n = sc.nextInt();
					System.out.println("digit : ");
					m = sc.nextInt();
					ans = position(n, m);
					System.out.println("position = " + ans);
					break;
				case 6: /* add extractOddDigits() call */
					System.out.println("n : ");
					n = sc.nextInt();
					finalans = extractOddDigits(n);
					if (finalans == -2) System.out.println("Error input!");
					else System.out.println("oddDigits = " + finalans);
					break;
				case 7: System.out.println("Program terminating ….");
				}
			} while (choice < 7);
		} 
	
	public static void mulTest() {
		int score, num1, num2, ans;
		Scanner userin = new Scanner(System.in);
		score = 0;
		
		for (int i=0; i<5; i++) {
			num1 = (int) (1 + Math.random() * 9);
			num2 = (int) (Math.random() * 9);
			
			System.out.println("How much is " + num1 + " times "+ num2 + "? ");
			ans = userin.nextInt();
			
			if (ans == num1*num2) {score++;}
		}
		System.out.println(score+" answers out of 5 are correct");
	}
	
	public static int divide(int m, int n) {
		int count = 0;
		while (m>=n) {
			m -= n;
			count++;
		}
		return count;
	}
	
	public static int modulus(int m, int n) {
		
		while (m>=n) {
			m -= n;
		}
		return m;
		
	}
	
	public static int countDigits(int n) {
		if (n<=0) return -1;
		
		else {
		int counter=0;
		
		while (n>=1) {
			n = divide(n, 10);
			counter++;
		}
		return counter;
		}
	}
	
	public static int position(int n, int digit) {
		int check;
		int index = 1;
		
		while (n>=1) {
			check = modulus(n, 10);
			if (check == digit) 
				return index;
			index ++;
			n = divide(n, 10);
		}
		return -1;
	}
		
	public static long extractOddDigits(long n) {
		int check;
		long ans = 0;
		int pos = 1;
		
		if (n<=0) return -2;
		
		while (n>=1) {
			check = (int)n%10;
			if (modulus(check,2) == 1) {
				ans += pos*check;
				pos *= 10;
			}
			n = n/10;
		}
		if (ans==0) return -1;
		
		return ans;
	}
	
	}
	
