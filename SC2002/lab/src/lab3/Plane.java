package lab3;

public class Plane {
	
	private PlaneSeat[] seat;
	private int numEmptySeat;
	
	public Plane() {
		seat = new PlaneSeat[12];
		
		for (int i = 0; i<seat.length; i++) {
			seat[i] = new PlaneSeat(i+1);
		}
		numEmptySeat = 12;
	}
	
	private PlaneSeat[] sortSeats() {
		PlaneSeat[] tempSeat = new PlaneSeat[12];
		PlaneSeat temp;

		
		for (int i=0; i<seat.length; i++) {
			tempSeat[i] = seat[i];
		}
		
		for (int i=1; i<tempSeat.length; i++) {
			for (int j=i; j>0; j--) {
				if (tempSeat[j].getCustomerID()<tempSeat[j-1].getCustomerID()) {
					temp = tempSeat[j-1];
					tempSeat[j-1] = tempSeat[j];
					tempSeat[j] = temp;
					}
				else break;
				}
		}
		
		return tempSeat;
	}
	
	public void showNumEmptySeats() {
		System.out.println("There are " + numEmptySeat + " empty seats");
	}
	
	public void showEmptySeats() {
		System.out.println("The following seats are empty:");
		
		for (int i=0; i<seat.length; i++) {
			if (!seat[i].isOccupied()) {
				System.out.println("SeatID " + seat[i].getSeatID());
			}
		}
	}
	
	public void showAssignedSeats(boolean bySeatId) {
		System.out.println("The seat assignemnts are as follow: ");
		if (bySeatId) {
			PlaneSeat[] temp = this.sortSeats(); 
			
			for (int i=0; i<temp.length; i++) {
				if (temp[i].isOccupied()) {
					System.out.println("SeatID " + temp[i].getSeatID() 
							+ " assigned to CustomerID " + temp[i].getCustomerID());
				}
			}
		}
			
		else {
			for (int i=0; i<seat.length; i++) {
				if (seat[i].isOccupied()) {
					System.out.println("SeatID " + seat[i].getSeatID()
							+ " assigned to CustomerID " + seat[i].getCustomerID());
				}
			}
		}
	}
	
	public void assignSeat(int seatId, int cust_id) {
		if (seat[seatId-1].isOccupied()) 
			System.out.println("Seat already assigned to a customer");
		else {
			seat[seatId-1].assign(cust_id);
			System.out.println("Seat Assigned!");
			numEmptySeat--;
		}

	}
	
	public void unAssignSeat(int seatId) {
		seat[seatId-1].unAssign();
		System.out.println("Seat Unassigned!");
		numEmptySeat++;
	}
	
}
