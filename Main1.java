//2019112151_������
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
			select_mode = sc.nextInt(); // �޴� ����
			
			
			switch(select_mode) {
			case 1: // ����ð��� ���
				System.out.println("���� �ð��� " + form1.format(System.currentTimeMillis()));
				break;
			case 2: // Ÿ�̸� ���
				
				long time1 = System.currentTimeMillis(); //Ÿ�̸� ���� �ð�
				System.out.println("Ÿ�̸Ӹ� �����Ϸ��� ���� 5�� �Է����ּ���");
				int x = 0;
				x = sc.nextInt();
				while(x!=5) { //���� 5�� �Է¹ޱ� ������ sleep
					try {
						Thread.sleep(1000);
					}catch(InterruptedException e) { //����ó��
					}
				}
				long time2 = System.currentTimeMillis(); //Ÿ�̸� �� �ð�
				
				System.out.println("�ɸ� �ð��� " + (time2-time1)/10000.000 + "�� �Դϴ�."); // �ɸ��ð��� ���
				break;
			case 3: // ���α׷� ����
				System.out.println("Program exit");
				System.exit(0);
				break;
				
			}
		}
		
	
	}

}