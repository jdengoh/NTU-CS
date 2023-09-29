package phone;

public class SixGPhone extends MobilePhone{
	
	public SixGPhone(String owner, String color, double screenSize, int num) {
		super(owner, color, screenSize, num);
	}
	
	public void ring() {
		System.out.println("Play a video");
	}

}
