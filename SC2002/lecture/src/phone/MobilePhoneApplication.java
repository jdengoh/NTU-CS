package phone;

import java.util.*;

public class MobilePhoneApplication {
	
	public static void main(String[] args) {
		
		MobilePhone myPhone;
		myPhone = new MobilePhone();
		
		App app = new App("Facebook", 0.0);
		App app1 = new App("wehat", 0.0);
		App app2 = new App("whatsapp", 0.0);
		App app3 = new App("Angry Bird", 2.0) ;
		
		ArrayList<App> appStore= new ArrayList<App>();
		
		appStore.add(app);
		appStore.add(app1);
		appStore.add(app2);
		appStore.add(app3);
		
		MobilePhone johnPhone = new MobilePhone("John", "Red", 7.0, 0);
		//yourPhone.printContent();
		
//		johnPhone.getApp().print();
//		johnPhone.getAppStore().get(2).print();
		
		//print current owner
		System.out.println("the current owner is " + myPhone.getOwner());
		
		//change owner
		myPhone.setOwner("Jane");
		System.out.println("the new owner is " + myPhone.getOwner());
		
		//try to change screenSize beyond MAX_SCREEN_SIZE
		myPhone.setSize(11);
		System.out.println("the size of my phone is: "+myPhone.getSize());
		
		//make a copy
		MobilePhone copyPhone = myPhone.clonePhone();
		myPhone.changeOwner();
		
		System.out.println("myPhone:");
		myPhone.printContent();
		System.out.println("copyPhone:");
		copyPhone.printContent();
		
		//send SMS
		myPhone.sendSMS("Tom", "hi");
		System.out.println("the number of SMS sent on this phone: " + myPhone.getNum());
		System.out.println("Number of SMS sent so far is: " + MobilePhone.getNumOfSMS());
		
		johnPhone.sendSMS("Tom", "hello");
		System.out.println("the number of SMS sent on this phone: " + johnPhone.getNum());
		System.out.println("Number of SMS sent so far is: " + MobilePhone.getNumOfSMS());

	}
}
