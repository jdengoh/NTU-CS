package phone;

public class App {
	
	private String name;
	private double price;
	
	public App(String name, double price) {
		this.name = name;
		this.price = price;
	}
	
	public String getName() {
		return name;
	}
	
	public double getPrice() {
		return price;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public void setPrice(double price) {
		this.price = price;
	}
	
	public void print() {
		System.out.println("the name of the app is: "+name+"; the price is: "+price);
	}

}
