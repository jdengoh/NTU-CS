package phone;

public class TwoGPhone extends MobilePhone implements IntPhone{
	
	public TwoGPhone(String owner, String color, double screenSize, int num) {
		super(owner, color, screenSize, num);
	}
	
	public void ring() {
		System.out.println("ring, ring, ring");
	}
		
}
