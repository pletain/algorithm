package java_week2;

import java.util.Scanner; //�Է°��� �б����� java.util�� Scanner Ŭ������ ����Ʈ�Ѵ�.

public class exam3 {

	public static void main(String[] args) {
		int x, y;
		
		Scanner sc = new Scanner(System.in);
		System.out.print("���� x�� �Է����ּ��� :");
		x = sc.nextInt();
		System.out.print("���� y�� �Է����ּ��� :");
		y = sc.nextInt();
		
		System.out.println("\"" + x + "/" + y + "�� ����" + x/y +" �̰� ��������" +x%y + "�Դϴ�.\"");
		double x2 = x;
		System.out.println("\"" + x + "/" + y + "�� ����" + x2/y + "�Դϴ�.\"");
	}

}