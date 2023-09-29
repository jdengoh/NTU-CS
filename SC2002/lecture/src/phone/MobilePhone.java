package phone;

import java.util.*;

public class MobilePhone implements IntPhone{
	
	//constant
	public static final double MAX_SCREEN_SIZE = 8;
	
	// instance variable

	protected int num; //protected variable
	private String owner;
	private String color; //protected variable;
	private double screenSize;
//	private App app;
//	
//	//ArrayList is an imported class (..?)
//	private ArrayList<App> appStore;
	
	private static int numOfSMS;
	
	//constructors
	public MobilePhone() {
		//owner = "defaultOwner";
		//color = "white";
		//screenSize = 5.0;
		
		//using 'this' constructor
		//this("defaultOwner", "white", 5.0, 0, new App("default", 0.0), null);
		this("defaultOwner", "white", 5.0, 0);

	}
	
	public MobilePhone(String owner, String color, double screenSize, int num) {
		//use keyword 'this' to differentiate instance/local variable
		this.owner = owner;
		this.color = color;
		this.screenSize = screenSize;
		this.num = num;
//		this.app = app;
//		this.appStore = appStore;
	}
	
	// all instance method
	
	public void ring() {
		System.out.println("ring, ring, ring");
	}
	
	public String sendSMS(String receiver, String message) {
		System.out.println("hi "+receiver+" "+message);
		numOfSMS++;
		num++;
		return "successful";
	}
	
	public void printContent() {
		System.out.println("the owner is " + owner + "; the color is " + color + "; the screenSize is " + screenSize);
	}
	
	//---------------------------------------------------
	
//	public App getApp() {
//		return app;
//	}
//	
//	public void setApp(App app) {
//		this.app = app;
//	}
//	
//	public ArrayList<App> getAppStore() {
//		return appStore;
//	}
//	
//	public void setAppStore(ArrayList<App> appStore) {
//		this.appStore = appStore;
//	}
//	
	
	//---------------------------------------------------

	
	//get methods
	public String getOwner() {
		return owner;
	}
	
	public String getColor() {
		return color;
	}
	
	public double getSize() {
		return screenSize;
	}
	
	public int getNum() {
		return num;
	}

	
	public static int getNumOfSMS() {
		return numOfSMS;
	}
	
	//set methods
	public void setOwner(String owner) {
		this.owner = owner;
	}
	
	public void setColor(String color) {
		this.color = color;
	}
	
	public void setSize(double screenSize) {
		if (screenSize > MAX_SCREEN_SIZE) {
			this.screenSize = IntPhone.MAX_SCREEN_SIZE;
		}
		else {
			this.screenSize = screenSize;
		}
	}
	
	public void changeOwner() {
		this.owner = "Tom";
	}
	
	// copy method
	public MobilePhone clonePhone() {
		//return new MobilePhone(owner,color,screenSize,num, app, appStore);
		return new MobilePhone(owner,color,screenSize,num);
	}
	
}
