package lab4;

public class SalePerson implements Comparable<SalePerson>{
	
	private String firstName;
	private String lastName;
	private int totalSales;
	
	public SalePerson(String firstName, String lastName, int totalSales) {
		this.firstName = firstName;
		this.lastName = lastName;
		this.totalSales = totalSales;
	}
	
	public String getFirstName() {
		return this.firstName;
	}
	
	public String getLastName() {
		return this.lastName;
	}
	
	public int getTotalSales() {
		return this.totalSales;
	}
	
	public String toString() {
		return "<"+firstName+"> , <"+lastName+"> , <"+totalSales+">";
	}
	
	public boolean equals(SalePerson person) {
		if ( (person.firstName).equals(this.firstName) && (person.lastName.equals(this.lastName)) )
				return true;
		else
			return false;
	}
	
	public int compareTo(SalePerson person) {
		if (this.totalSales < person.totalSales)
			return -1;
		
		else if (this.totalSales > person.totalSales)
			return 1;
		
		else {
			
			if (this.lastName.compareTo(person.lastName) < 0)
				return 1;
			else return 0;
			
		}
		
	}
	
}
