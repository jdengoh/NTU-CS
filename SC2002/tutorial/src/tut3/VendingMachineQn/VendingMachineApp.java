package tut3.VendingMachineQn;

public class VendingMachineApp {
	
	public static void main(String[] args) {
		
		VendingMachine vm = new VendingMachine();

		double cost;
		double amountIn;
				
		cost = vm.selectDrink();
		
		amountIn = vm.insertCoins(cost);
		
		vm.checkChange(amountIn, cost);
		
		vm.printReceipt();
		
	}
	
}
