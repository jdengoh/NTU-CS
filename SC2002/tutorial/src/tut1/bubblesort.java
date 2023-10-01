package tut1;

import java.util.Scanner;

public class bubblesort {
	
	private static int[] bubble (int a[], int n) {
		int i, j, t;
		for (i=n-2; i>=0; i--) {
			for (j=0; j<=i; j++) {
				if (a[j]>a[j+1]) {
					t=a[j];
					a[j]=a[j+1];
					a[j+1] = t;
				}
			}
		}
		return a;
	}
	
	public static void main (String args[]) {
		
		int n,i;
		
		int a[] = new int[100];
		
		Scanner userIn = new Scanner(System.in);
		
		System.out.println("\n\n Enter the number of Integer elements to be sorted: ");
		
		n = userIn.nextInt();
		
		for (i=0; i<=n-1; i++) {
			System.out.println("\n\n Enter the integer value for the element no."+(i+1));
			a[i] = userIn.nextInt();
		}
		
		a = bubble(a, n);
		
		System.out.println("\n\n Fiinally sorted array is :");
		
		for (i=0; i<=n-1; i++) {
			System.out.print(a[i]+" ");
			
		}
		
		
	}
			
}
