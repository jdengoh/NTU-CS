package phone;

import java.util.ArrayList;

// inheritence
public class FiveGPhone extends MobilePhone{
	
	private double dataRate;
	private double credit;
	
	public FiveGPhone() {
		super();
		dataRate = 0;
		credit = 0;
	}
	
	public FiveGPhone(String owner, String color, double screenSize, int num, App app, ArrayList<App> appStore, double dataRate, double credit) {
		super(owner, color, screenSize, num, app, appStore);
		this.dataRate = dataRate;
		this.credit = credit;
	}
	
	public double getDataRate() {
		return dataRate;
	}
	
	public double getCredit() {
		return credit;
	}
	
	public void setDataRate(double dataRate) {
		this.dataRate = dataRate;
	}
	
	public void addCredit(double credit) {
		this.credit = this.credit + credit;
	}
	
	// abstract method RING
	public void ring() {
		System.out.println("play a music");
	}
	
	public String sendSMS(String receiver) {
		this.credit = this.credit - dataRate;
		System.out.println("hi " + receiver);
		return "successfully sent";
	}
	
	public String sendSMS(String receiver, String message) {
		this.credit = this.credit - dataRate;
		return super.sendSMS(receiver, message);
	}
	
	public void printContent() {
		super.printContent();
		System.out.println("the data rate is " + dataRate + "; the available credit is " + credit);
	}
	
}
