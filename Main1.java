//2019112151_김태형
package java_week3;

import java.text.SimpleDateFormat;
import java.util.Scanner; 

public class Main1 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		SimpleDateFormat form1 = new SimpleDateFormat("HH:mm:ss");
		int select_mode = 0;
	
		while(true) {
			System.out.println("select menu");
			System.out.println("1: current time");
			System.out.println("2: timer");
			System.out.println("3: exit");
			select_mode = sc.nextInt(); // 메뉴 선택
			
			
			switch(select_mode) {
			case 1: // 현재시간을 출력
				System.out.println("현재 시간은 " + form1.format(System.currentTimeMillis()));
				break;
			case 2: // 타이머 기능
				
				long time1 = System.currentTimeMillis(); //타이머 누른 시간
				System.out.println("타이머를 종료하려면 숫자 5를 입력해주세요");
				int x = 0;
				x = sc.nextInt();
				while(x!=5) { //숫자 5를 입력받기 전까지 sleep
					try {
						Thread.sleep(1000);
					}catch(InterruptedException e) { //예외처리
					}
				}
				long time2 = System.currentTimeMillis(); //타이머 끈 시간
				
				System.out.println("걸린 시간은 " + (time2-time1)/10000.000 + "초 입니다."); // 걸린시간을 출력
				break;
			case 3: // 프로그램 종료
				System.out.println("Program exit");
				System.exit(0);
				break;
				
			}
		}
		
	
	}

}
