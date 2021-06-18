package java_week2;

import java.util.Scanner; //입력값을 읽기위해 java.util의 Scanner 클래스를 임포트한다.

public class Pyramid {
	public char ss = '*';
	public int num =3;
	
	public Scanner sc = new Scanner(System.in);
	
	public void printStar() {
		for(int i=0; i<num; i++) {
			for(int j=1; j<num-i; j++) {
				System.out.print(" ");
			}
			for(int k=0; k<i * 2+1; k++) {
				System.out.print(ss);
			}
			System.out.println();
		}
	}
	public void SetInfo() {
		System.out.print("Input Character :");
		ss = sc.nextLine().charAt(0);
		System.out.print("Input line number : ");
		num = sc.nextInt();
	}

}
