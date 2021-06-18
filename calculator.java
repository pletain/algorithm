//2019112151_김태형
package java_week3;


import java.util.Scanner;

public class calculator {
	int num1, num2; // 정수형 입력 변수 두개 선언
	double num3, num4; //실수형 입력 변수 두개 선언
	int result; // 정수형 결과 변수 선언
	double result1; // 실수형 결과 변수 선언
	Scanner sc = new Scanner(System.in);
	public calculator() {// 생성자
	}
	
	public void addtion() { //더하기 연산
		System.out.printf("숫자1을 입력해주세요 :");
		num1 = sc.nextInt(); //숫자 1 입력받음
		System.out.printf("숫자2을 입력해주세요 :");
		num2 = sc.nextInt(); //숫자 2 입력받음 
		System.out.printf("num1 + num2 = ");
		result = num1 + num2; //더한 값을  result에 저장
		System.out.println(result); //result를 출력
	}
	
	public void subtraction() { // 빼기 연산
		System.out.printf("숫자1을 입력해주세요 :");
		num1 = sc.nextInt(); //숫자 1 입력받음
		System.out.printf("숫자2을 입력해주세요 :");
		num2 = sc.nextInt();//숫자 2 입력받음 
		System.out.printf("num1 - num2 = ");
		result = num1 - num2;//뺸 값을  result에 저장
		System.out.println(result);//result를 출력
	}
	
	public void multiply() {
		System.out.printf("숫자1을 입력해주세요 :");
		num1 = sc.nextInt();//숫자 1 입력받음
		System.out.printf("숫자2을 입력해주세요 :");
		num2 = sc.nextInt();//숫자 2 입력받음 
		System.out.printf("num1 * num2 = ");
		result1 = num1 * num2;//곱한 값을  result에 저장
		System.out.println(result);//result를 출력
	}

	
	public void disvision() {
		System.out.printf("숫자1을 입력해주세요 :");
		num1 = sc.nextInt();//숫자 1 입력받음
		System.out.printf("숫자2을 입력해주세요 :");
		num2 = sc.nextInt();//숫자 2 입력받음 
		try {
			result1 = num1 / num2; //나눈 값을  result에 저장
			System.out.printf("num1 / num2 = ");
			System.out.println(result1);//result를 출력
		}catch(ArithmeticException e) { //0으로 나눌려고 할때 예외처리
			System.out.println("잘못된 입력입니다.");
		}
		
		
	}
}
