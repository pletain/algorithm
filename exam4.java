package java_week2;

import java.util.Scanner; //입력값을 읽기위해 java.util의 Scanner 클래스를 임포트한다.

public class exam4 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in); //스캐너 객체 생성
		int size; //정수형 변수 size 선언
		
		System.out.print("배열 크기를 입력해주세요 :");
		size = sc.nextInt(); //배열의 크기를 입력받는다.
		
		int A[] = new int[size]; //size크기의 배열 A를 생성
		int B[] = new int[size]; //size크기의 배열 B를 생성
		int C[] = new int[size*2]; //size*2크기의 배열 C를 생성

		System.out.print("배열 A:"); //배열 A를 출력
		
		for(int i = 0; i< A.length; i++) {
			A[i] = (i+1)*2; //배열 A에 짝수를 넣는다.
			System.out.print(A[i] + " "); // 배열방에 있는 값을 출력
		}
		System.out.println(); //개행
		
		System.out.print("배열 B:"); //배열 B를 출력
		
		for(int i = 0; i< A.length; i++) {
			B[i] = (i+1)*2-1; //배열 B에 홀수를 넣는다.
			System.out.print(B[i] + " "); // 배열방에 있는 값을 출력
		}
		System.out.println(); //개행
		
		System.out.print("배열 C:"); //배열 C를 출력
		
		for(int i = 0; i< size; i++) {
			C[A[i]-1] = A[i]; //배열의 짝수번방에는 배열 A에 있는값을 넣는다.
			C[B[i]-1] = B[i]; //배열의 홀수번방에는 배열 B에 있는값을 넣는다.
		}
		for(int i = 0; i< C.length; i++) {
			System.out.print(C[i] + " "); //배열방에 있는 값을 출력
		}

	}

}
