#include <iostream>
#include <cstring>
#include "OrganizationTree.h"
using namespace std;

void main()
{
	OrganizationTree test(100);
	Vertex V_test;
	char ceo[L_Length];

	cin >> ceo;
	strcpy_s(V_test.label, ceo);
	test.insert_ceo(V_test);  //ceo

	while (true) {
		char cmd1[L_Length];
		cin >> cmd1;

		if (strcmp(cmd1, "print") == 0)//print
		{
			test.print();
		}
		else if (strcmp(cmd1, "fire") == 0) //fire
		{
			char cmd2[L_Length];
			cin >> cmd2;
			test.fire(cmd2);
		}
		else //hire
		{
			char cmd2[L_Length], v3[L_Length];
			cin >> cmd2 >> v3;
			strcpy_s(V_test.label, v3);
			test.insert_emp(V_test, cmd1);
		}
	}
}
