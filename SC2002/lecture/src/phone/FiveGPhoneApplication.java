package phone;

import java.util.ArrayList;

public class FiveGPhoneApplication {
	
	public static void main(String[] args) {
		
		App app2 = new App("whatsapp", 0.0);
		
		ArrayList<App> appStore = new ArrayList<App>();
		
		appStore.add(app2);
		
		MobilePhone myPhone;
		myPhone = new MobilePhone();
		myPhone.setOwner("Jane");
		myPhone.sendSMS("tom", "hi");
		myPhone.setSize(10.0);
		
		FiveGPhone johnPhone = new FiveGPhone("John", "white", 7.0, 0, app2, appStore, 0.1, 10.0);
		System.out.println("the owner is " + johnPhone.getOwner());

		johnPhone.sendSMS("Jane");
		johnPhone.sendSMS("Jane", "Will you go lunch with me?");
		
		
	}
}
