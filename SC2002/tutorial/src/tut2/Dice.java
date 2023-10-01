package tut2;
import java.util.Random;

public class Dice {
	private Random rand = new Random();
	private int valueOfDice;
	
	public Dice() {
		valueOfDice = 0;
	}
	
	public void setDiceValue() {
		this.valueOfDice = rand.nextInt(6);
	}
	
	public int getDiceValue() {
		return valueOfDice;
	}
	
	public void printDiceValue() {
		System.out.println("Current value is " + getDiceValue());
	}
	
}
