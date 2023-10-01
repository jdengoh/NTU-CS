package lab3;
import java.util.Scanner;

public class PlaneApp {
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int option, seatId, custId;
		Plane myplane = new Plane();
		
		System.out.println("(1) Show number of empty seats\n"
				+ "(2) Show the list of empty seats\n"
				+ "(3) Show the list of seat assignments by seat ID\n"
				+ "(4) Show the list of seat assignments by customer ID\n"
				+ "(5) Assign a customer to a seat\n"
				+ "(6) Remove a seat assignment\n"
				+ "(7) Exit");
		
		do {
			System.out.print("Enter the number of your choice: ");
			option = sc.nextInt();
			
			switch (option) {
			case 1:
				myplane.showNumEmptySeats();
				break;
			case 2:
				myplane.showEmptySeats();
				break;
			case 3:
				myplane.showAssignedSeats(false);
				break;
			case 4:
				myplane.showAssignedSeats(true);
				break;
			case 5:
				System.out.println("Assigning Seat...");
				System.out.print("Please enter SeatID: ");
				seatId = sc.nextInt();
				System.out.print("Please enter customer ID: ");
				custId = sc.nextInt();
				
				myplane.assignSeat(seatId, custId);
				break;
			case 6:
				System.out.print("Enter SeatID to unassign customer from: ");
				seatId = sc.nextInt();
				myplane.unAssignSeat(seatId);
				break;
			case 7:
				System.out.println("Goodbye!");
				break;
			}
			
			
		}while (option<=7);
		
		sc.close();
	}
	
}
