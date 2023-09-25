package tut3.VendingMachineQn;

public class Drink {
	
	private String deDrink;
	private double deCost;
	
	public Drink(String drinkk, double costt) {
		this.deDrink = drinkk;
		this.deCost = costt;
	}
	
	public String getName() {
		return deDrink;
	}
	
	public double getCost() {
		return deCost;
	}
}
