//2019112151_������
package java_week3;


import java.util.Scanner;

public class calculator {
	int num1, num2; // ������ �Է� ���� �ΰ� ����
	double num3, num4; //�Ǽ��� �Է� ���� �ΰ� ����
	int result; // ������ ��� ���� ����
	double result1; // �Ǽ��� ��� ���� ����
	Scanner sc = new Scanner(System.in);
	public calculator() {// ������
	}
	
	public void addtion() { //���ϱ� ����
		System.out.printf("����1�� �Է����ּ��� :");
		num1 = sc.nextInt(); //���� 1 �Է¹���
		System.out.printf("����2�� �Է����ּ��� :");
		num2 = sc.nextInt(); //���� 2 �Է¹��� 
		System.out.printf("num1 + num2 = ");
		result = num1 + num2; //���� ����  result�� ����
		System.out.println(result); //result�� ���
	}
	
	public void subtraction() { // ���� ����
		System.out.printf("����1�� �Է����ּ��� :");
		num1 = sc.nextInt(); //���� 1 �Է¹���
		System.out.printf("����2�� �Է����ּ��� :");
		num2 = sc.nextInt();//���� 2 �Է¹��� 
		System.out.printf("num1 - num2 = ");
		result = num1 - num2;//�A ����  result�� ����
		System.out.println(result);//result�� ���
	}
	
	public void multiply() {
		System.out.printf("����1�� �Է����ּ��� :");
		num1 = sc.nextInt();//���� 1 �Է¹���
		System.out.printf("����2�� �Է����ּ��� :");
		num2 = sc.nextInt();//���� 2 �Է¹��� 
		System.out.printf("num1 * num2 = ");
		result1 = num1 * num2;//���� ����  result�� ����
		System.out.println(result);//result�� ���
	}

	
	public void disvision() {
		System.out.printf("����1�� �Է����ּ��� :");
		num1 = sc.nextInt();//���� 1 �Է¹���
		System.out.printf("����2�� �Է����ּ��� :");
		num2 = sc.nextInt();//���� 2 �Է¹��� 
		try {
			result1 = num1 / num2; //���� ����  result�� ����
			System.out.printf("num1 / num2 = ");
			System.out.println(result1);//result�� ���
		}catch(ArithmeticException e) { //0���� �������� �Ҷ� ����ó��
			System.out.println("�߸��� �Է��Դϴ�.");
		}
		
		
	}
}