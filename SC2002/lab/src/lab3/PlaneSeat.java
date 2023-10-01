package lab3;

public class PlaneSeat {
	
	private int seatId;
	private boolean assigned;
	private int customerId;
	
	public PlaneSeat(int seatId) {
		this.seatId = seatId;
		this.assigned = false;
		this.customerId = 0;
		
	}
	
//	public PlaneSeat(int seatId, boolean assigned, int customerId)  {
//		this.seatId = seatId;
//		this.assigned = assigned;
//		this.customerId = customerId;
//	}
	
	public int getSeatID() {
		return seatId;
	}
	
	public int getCustomerID() {
		return customerId;
	}
	
	public boolean isOccupied() {
		return assigned;
	}
	
	public void assign(int cust_id) {
		this.customerId = cust_id;
		this.assigned = true;
	}
	
	public void unAssign() {
		this.assigned = false;
		this.customerId = 0;
	}
}
