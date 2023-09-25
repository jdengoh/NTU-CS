package tut2;
import java.util.Scanner;

public class DiceApp {
	
	public static void main(String[] args) {
		
		Dice d1,d2 = null;
		Scanner sc = new Scanner(System.in);
		String first, second;
		
		System.out.println("Press <key> to roll the first dice");
		first = sc.next();
		d1 = new Dice();
		d1.setDiceValue();
		d1.printDiceValue();
			
		System.out.println("Press <key> to roll the second dice");
		second = sc.next();
		d2 = new Dice();
		d2.setDiceValue();
		d2.printDiceValue();
			
		System.out.println("Your total number is:" + (d1.getDiceValue()+d2.getDiceValue()));
	}
	
}
