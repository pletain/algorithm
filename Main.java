//2019112151_������
package java_week3;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		calculator cc = new calculator();
		int select_mode = 0; 
		
		while(true) {
			System.out.println("select menu");
			System.out.println("1: addiction");
			System.out.println("2: subtraction");
			System.out.println("3: multiply");
			System.out.println("4: division");
			System.out.println("5: exit");
			select_mode = sc.nextInt(); //�޴� ���� �Է�
			
			switch(select_mode) {
			case 1://���ϱ�
				cc.addtion();
				break;
			case 2://����
				cc.subtraction();
				break;
			case 3://���ϱ�
				cc.multiply();
				break;
			case 4://������
				cc.disvision();
				break;
			case 5://���α׷� ����
				System.out.println("Program exit");
				System.exit(0);
				break;
				
			}
		}
	}

}