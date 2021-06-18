package java_week2;

import java.util.Scanner; //입력값을 읽기위해 java.util의 Scanner 클래스를 임포트한다.

public class exam3 {

	public static void main(String[] args) {
		int x, y;
		
		Scanner sc = new Scanner(System.in);
		System.out.print("정수 x를 입력해주세요 :");
		x = sc.nextInt();
		System.out.print("정수 y를 입력해주세요 :");
		y = sc.nextInt();
		
		System.out.println("\"" + x + "/" + y + "의 몫은" + x/y +" 이고 나머지는" +x%y + "입니다.\"");
		double x2 = x;
		System.out.println("\"" + x + "/" + y + "의 값은" + x2/y + "입니다.\"");
	}

}
