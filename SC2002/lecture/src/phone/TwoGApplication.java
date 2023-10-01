package phone;

public class TwoGApplication {
	
	public static void main(String[] args) {
		
		//UPCASTING
		IntPhone phone = new TwoGPhone("Jane", "red", 5, 0);

		phone = new TwoGPhone("Tom", "black", 9, 0);
		//phone.ring();	
		call(phone);
		
		phone = new FiveGPhone("John", "White", 7.0, 0);
		//phone.ring();
		call(phone);
		
		TwoGPhone phone1 = new TwoGPhone("Tom", "black", 9, 0);
		call2(phone1);
		
		FiveGPhone phone2 = new FiveGPhone("John", "White", 7.0, 0);
		call2(phone2);
	}	
	
	public static void call(IntPhone phone) {
		phone.ring();
	}
	
	public static void call2(FiveGPhone phone) {
		phone.ring();
	}
	
	public static void call2(TwoGPhone phone) {
		phone.ring();
	}
}
