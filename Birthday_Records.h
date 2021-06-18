//2019112151_김태형
#include <iostream>
#include<fstream>
#include<string>
using namespace std;

class DataType //객체의 이름, 전화번호, 생일을 저장할 배열 생성.
{
private:
	char name[256], phone[256], birthday[256];

public:
	DataType() {}
	~DataType() {}

	friend class List; //List 클래스에서 DataType 클래스의 멤버변수를 접근 가능하게 함.
};

class List
{
private:
	DataType* add; // 데이터 저장 객체 생성.
	string filename;
	int size, maxSize;
	// 해당 월별 인덱스이자, 크기를 카운트하는 변수
	int Jan, Feb, Mar, Apr, May, Jun;
	int Jul, Aug, Sep, Oct, Nov, Dec;

	//해당 월별 객체를 저장할 배열
	int jan[256], feb[256], mar[256], apr[256], may[256], jun[256], jul[256], aug[256], sep[256], oct[256], nov[256], dec[256];

public:
	List()
	{
		//동적 할당.
		add = new DataType[256];
		//모든 변수 초기화.
		maxSize = 256;
		size = 0;
		Jan = 0, Feb = 0, Mar = 0, Apr = 0, May = 0, Jun = 0;
		Jul = 0, Aug = 0, Sep = 0, Oct = 0, Nov = 0, Dec = 0;
	}

	~List() //소멸자.
	{
		delete[] add;
	}

	void insert()
	{
		if (!isFull())
		{
			cout << "Name : ";
			cin.ignore(); //버퍼 저장.
			cin.getline(add[size].name, 256); //리스트에 입력

			cout << "Phone number : ";
			cin.getline(add[size].phone, 256);

			cout << "Birthday : ";
			cin.getline(add[size].birthday, 256);

			size++;
			cnt_month();
			show();
		}
		else cout << "list is full now." << endl;


	}
	void remove()
	{
		if (!isEmpty()) {
			char r_name[256];
			cout << "Name : ";
			cin.ignore();
			cin.getline(r_name, 256);
			int cursor = -1;
			int i = 0;
			while (i < size)
			{
				if (strcmp(add[i].name, r_name) == 0) // 문자열 비교
				{
					cursor = i;
					break;
				}
				i++;
			}
			cout << "* ";

			if (cursor != -1)
			{
				if (size - 1 == cursor) // 리스트 마지막에 커서가 존재.
				{
					size--;
				}
				else
				{
					for (int k = 0; k < size - 1 - cursor; k++)
					{
						strcpy(add[cursor + k].name, add[cursor + k + 1].name);
						strcpy(add[cursor + k].phone, add[cursor + k + 1].phone);
						strcpy(add[cursor + k].birthday, add[cursor + k + 1].birthday);
					}
					size--;
				}

				cnt_month();
				show();
			}
			else
				cout << "Name does not exist." << endl;
		}
		else cout << "list is empty now." << endl; //리스트가 빈 경우

	}
	void read()
	{
		ifstream File;
		cout << "Enter the name of the file : ";
		cin >> filename;
		File.open(filename);
		if (File.is_open())
		{
			while (!File.eof()) // 파일 읽어오기
			{
				File.getline(add[size].name, 1000);
				File.getline(add[size].phone, 1000);
				File.getline(add[size].birthday, 1000);
				size++;

			}
			cnt_month();
			show();
		}
		else
		{
			cout << "This file does not exist." << endl;
		}

		File.close();
	}
	void write() // 파일저장
	{
		int i;
		string updatefilename;
		cout << "Enter the name of the file : ";
		cin.ignore();
		cin >> updatefilename;
		ofstream Wfile;
		ofstream ofs(updatefilename);

		for (i = 0; i < size; i++) // 텍스트파일에 저장
		{
			ofs << add[i].name << endl;
			ofs << add[i].phone << endl;
			ofs << add[i].birthday << endl;
		}
		cout << "The list is written into FriendFileUpdate";
		ofs.close();
	}
	void Selected_Month()
	{

		string month;
		cout << "Enter the selected month: ";
		cin >> month;
		cnt_month(); //생일인 달 카운트
		// 월별 출력
		if (month == "January")
		{
			cout << "Total number of birthdays in January : " << Jan << endl;
			people_list(jan, Jan);
		}
		else if (month == "Febuary")
		{
			cout << "Total number of birthdays in Febuary: " << Feb << endl;
			people_list(feb, Feb);
		}
		else if (month == "March")
		{
			cout << "Total number of birthdays in March: " << Mar << endl;
			people_list(mar, Mar);
		}
		else if (month == "April")
		{
			cout << "Total number of birthdays in April:" << Apr << endl;
			people_list(apr, Apr);
		}
		else if (month == "May")
		{
			cout << "Total number of birthdays in May:" << May << endl;
			people_list(may, May);
		}
		else if (month == "June")
		{
			cout << "Total number of birthdays in June:" << Jun << endl;
			people_list(jun, Jun);
		}
		else if (month == "July")
		{
			cout << "Total number of birthdays in July:" << Jul << endl;
			people_list(jul, Jul);
		}
		else if (month == "August")
		{
			cout << "Total number of birthdays in August:" << Aug << endl;
			people_list(aug, Aug);
		}
		else if (month == "September")
		{
			cout << "Total number of birthdays in September:" << Sep << endl;
			people_list(sep, Sep);
		}
		else if (month == "October")
		{
			cout << "Total number of birthdays in October:" << Oct << endl;
			people_list(oct, Oct);
		}
		else if (month == "November")
		{
			cout << "Total number of birthdays in November:" << Nov << endl;
			people_list(nov, Nov);
		}
		else if (month == "December")
		{
			cout << "Total number of birthdays in December:" << Dec << endl;
			people_list(dec, Dec);
		}


	}
	void people_list(int Month[], int cnt)
	{
		for (int i = 0; i < cnt; i++)
		{
			cout << "\n" << endl;
			cout << "\t" << add[Month[i]].name << endl;
			cout << "\t" << add[Month[i]].phone << endl;
			cout << "\t" << add[Month[i]].birthday << endl;
			cout << "\n" << endl;
		}
	}
	void cnt_month()
	{
		//cnt 초기화
		Jan = 0, Feb = 0, Mar = 0, Apr = 0, May = 0, Jun = 0;
		Jul = 0, Aug = 0, Sep = 0, Oct = 0, Nov = 0, Dec = 0;

		for (int i = 0; i < size; i++) // 각 월별 생일 횟수 카운트
		{
			if (add[i].birthday[0] == '0')
			{
				if (add[i].birthday[1] == '1')
				{
					jan[Jan] = i; // 해당 인덱스 삽입
					Jan++;
				}
				else if (add[i].birthday[1] == '2')
				{
					feb[Feb] = i;
					Feb++;
				}
				else if (add[i].birthday[1] == '3')
				{
					mar[Mar] = i;
					Mar++;
				}
				else if (add[i].birthday[1] == '4')
				{
					apr[Apr] = i;
					Apr++;
				}
				else if (add[i].birthday[1] == '5')
				{
					may[May] = i;
					May++;
				}
				else if (add[i].birthday[1] == '6')
				{
					jun[Jun] = i;
					Jun++;
				}
				else if (add[i].birthday[1] == '7')
				{
					jul[Jul] = i;
					Jul++;
				}
				else if (add[i].birthday[1] == '8')
				{
					aug[Aug] = i;
					Aug++;
				}
				else if (add[i].birthday[1] == '9')
				{
					sep[Sep] = i;
					Sep++;
				}
			}
			else
			{
				if (add[i].birthday[1] == '0')
				{
					oct[Oct] = i;
					Oct++;
				}
				else if (add[i].birthday[1] == '1')
				{
					nov[Nov] = i;
					Nov++;
				}
				else if (add[i].birthday[1] == '2')
				{
					dec[Dec] = i;
					Dec++;
				}
			}
		}
	}

	void show()
	{
		cout << "Total number of entries in the list : " << size << endl;
		cout << "Number of birthdays in " << endl;

		if (Jan != 0) //월별 cnt 출력
		{
			cout << "	January: " << Jan << endl;
		}
		if (Feb != 0)
		{
			cout << "	Febuary: " << Feb << endl;
		}
		if (Mar != 0)
		{
			cout << "	March: " << Mar << endl;
		}
		if (Apr != 0)
		{
			cout << "	April:" << Apr << endl;
		}
		if (May != 0)
		{
			cout << "	May:" << May << endl;
		}
		if (Jun != 0)
		{
			cout << "	June:" << Jun << endl;
		}
		if (Jul != 0)
		{
			cout << "	July:" << Jul << endl;
		}
		if (Aug != 0)
		{
			cout << "	August:" << Aug << endl;
		}
		if (Sep != 0)
		{
			cout << "	September:" << Sep << endl;
		}
		if (Oct != 0)
		{
			cout << "	October:" << Oct << endl;
		}
		if (Nov != 0)
		{
			cout << "	November:" << Nov << endl;
		}
		if (Dec != 0)
		{
			cout << "	December:" << Dec << endl;
		}


	}

	bool isEmpty() const
	{
		if (size == 0) return true; //비어있다면 true를 반환
		else return false;
	}

	bool isFull() const
	{
		if (size == maxSize) return true; //꽉 차 있다면 true를 반환
		else return false;

	}

};
