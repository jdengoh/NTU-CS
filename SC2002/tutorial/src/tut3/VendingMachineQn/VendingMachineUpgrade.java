package tut3.VendingMachineQn;
import java.util.Scanner;

public class VendingMachineUpgrade extends VendingMachine {
	private Drink[] drinks;
	
	
	public VendingMachineUpgrade() {
		drinks = new Drink[3];
		
		drinks[0] = new Drink("Beer", 3.00);
		drinks[1] = new Drink("Coke", 1.00);
		drinks[2] = new Drink("Green Tea", 5.00);
		
	}
	
	public void start() {
		
		while(true) {
			
			double cost;
			double amountIn;

			cost = this.selectDrink();
			amountIn = this.insertCoins(cost);
			this.checkChange(amountIn, cost);
			this.printReceipt();
		}
		
	}
	
	public double selectDrink() {
		Scanner sc = new Scanner(System.in);
		int option=0;
		
		System.out.println("===== Vending Machine =====");
		
		for (int i=0; i<drinks.length; i++) {
			System.out.println("|" + (i+1) + " Buy " + drinks[i].getName() +
					String.format("( %.2f )",drinks[i].getCost()) + "|\n" );
		}
		
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
	
}
