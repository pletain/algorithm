package java_week2;

import java.util.Scanner;

public class Snack {

	public String name;
	public int price;
	public int numberofsnack;
	Scanner ac = new Scanner(System.in);
	
	public void Setinfo() {
		System.out.print("Snack name:");
		name = ac.nextLine();
		System.out.print("Snack price :");
		price = ac.nextInt();
		System.out.print("Number of snacks :");
		numberofsnack = ac.nextInt();
	}
	public void printinfo() {
		System.out.println("Snack name is " + name);
		System.out.println("Snack price is " + price);
		System.out.println("There is " + numberofsnack + "snack");

	}

}
