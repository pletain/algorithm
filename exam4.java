package java_week2;

import java.util.Scanner; //�Է°��� �б����� java.util�� Scanner Ŭ������ ����Ʈ�Ѵ�.

public class exam4 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in); //��ĳ�� ��ü ����
		int size; //������ ���� size ����
		
		System.out.print("�迭 ũ�⸦ �Է����ּ��� :");
		size = sc.nextInt(); //�迭�� ũ�⸦ �Է¹޴´�.
		
		int A[] = new int[size]; //sizeũ���� �迭 A�� ����
		int B[] = new int[size]; //sizeũ���� �迭 B�� ����
		int C[] = new int[size*2]; //size*2ũ���� �迭 C�� ����

		System.out.print("�迭 A:"); //�迭 A�� ���
		
		for(int i = 0; i< A.length; i++) {
			A[i] = (i+1)*2; //�迭 A�� ¦���� �ִ´�.
			System.out.print(A[i] + " "); // �迭�濡 �ִ� ���� ���
		}
		System.out.println(); //����
		
		System.out.print("�迭 B:"); //�迭 B�� ���
		
		for(int i = 0; i< A.length; i++) {
			B[i] = (i+1)*2-1; //�迭 B�� Ȧ���� �ִ´�.
			System.out.print(B[i] + " "); // �迭�濡 �ִ� ���� ���
		}
		System.out.println(); //����
		
		System.out.print("�迭 C:"); //�迭 C�� ���
		
		for(int i = 0; i< size; i++) {
			C[A[i]-1] = A[i]; //�迭�� ¦�����濡�� �迭 A�� �ִ°��� �ִ´�.
			C[B[i]-1] = B[i]; //�迭�� Ȧ�����濡�� �迭 B�� �ִ°��� �ִ´�.
		}
		for(int i = 0; i< C.length; i++) {
			System.out.print(C[i] + " "); //�迭�濡 �ִ� ���� ���
		}

	}

}