package java_week2;

import java.util.Scanner; //�Է°��� �б����� java.util�� Scanner Ŭ������ ����Ʈ�Ѵ�.

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