package tut3.VendingMachineQn;
import java.util.Scanner;


public class VendingMachine {
	public VendingMachine() {
		
	}
	
	public double selectDrink() {
		int option = 0;
		Scanner sc = new Scanner(System.in);
		System.out.println("===== Vending Machine =====\n"
				+ "|1. Buy Beer ($3.00)	 |\n"
				+ "|2. Buy Coke ($1.00)	 |\n"
				+ "|3. Buy Green Tea ($5.00)|	\n");
		System.out.println("Please enter the selection:");
		while (option<1 || option > 3) {
			option = sc.nextInt();
		}
		
		switch(option) {
		case 1:
			return 3.00;
		case 2:
			return 1.00;
		case 3:
			return 5.00;
		}
		
		return 0;
	}
	
	public double insertCoins(double drinkCost) {
		double amountIn = 0.0;
		char coin;
		Scanner sc = new Scanner(System.in);
		
		System.out.println("========= Coin Input =========\n"
				+ "|Enter 'Q' for ten cents input |\n"
				+ "|Enter 'T' for twenty cents input |\n"
				+ "|Enter 'F' for fifty cents input |\n"
				+ "|Enter 'N' for a dollar input |");
		
		System.out.println("Please enter the selection:");
		
		while(amountIn < drinkCost) {
			coin = sc.next().charAt(0);
			switch(coin) {
				case 'Q':
				case 'q':
					amountIn += 0.10;
					break;
				case 'T': case 't':
					amountIn += 0.20;
					break;
				case 'F': case 'f':
					amountIn += 0.50;
					break;
				case 'N': case 'n':
					amountIn += 1.00;
					break;
			}
			System.out.printf("Coins inserted so far: %.2f \n", amountIn);

		}
						
			return amountIn;

	}
	
	public void checkChange(double amount, double drinkCost) {
		double change;
		change = amount-drinkCost;
		if (change>0) {
			System.out.printf("Change: $%.2f\n", change);
		}
	}
	
	public void printReceipt() {
		System.out.println("Please collect your drink\nThank you !!");
	}
}
