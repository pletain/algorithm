//2019112151_김태형
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
			select_mode = sc.nextInt(); //메뉴 선택 입력
			
			switch(select_mode) {
			case 1://더하기
				cc.addtion();
				break;
			case 2://뻬기
				cc.subtraction();
				break;
			case 3://곱하기
				cc.multiply();
				break;
			case 4://나누기
				cc.disvision();
				break;
			case 5://프로그램 종료
				System.out.println("Program exit");
				System.exit(0);
				break;
				
			}
		}
	}

}
