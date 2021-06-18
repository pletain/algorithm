//2019112151_±èÅÂÇü
#include <stdexcept>
#include <iostream>
#include "Birthday_Records.h"
using namespace std;

int main(void)
{
	List testList;

	char cmd;

	do
	{
		cout << endl << "Commands:" << endl;
		cout << "\tR : read from a file " << endl;
		cout << "\t+ : add a new entry " << endl;
		cout << "\t- : remove an entry" << endl;
		cout << "\tW : write to a file" << endl;
		cout << "\tM : select a month" << endl;
		cout << "\tQ : quit the program  " << endl;
		cout << "\nCommand >> ";
		cin >> cmd;

		switch (cmd)
		{
		case '+':
			cout << "Add an entry:" << endl;
			testList.insert();

			break;

		case '-':
			cout << "Remove entry:" << endl;
			testList.remove();

			break;

		case 'R': case 'r':
			testList.read();
			break;

		case 'W': case 'w':
			testList.write();
			break;

		case 'M': case 'm':
			testList.Selected_Month();
			break;

		case 'Q': case 'q':
			break;

		default:
			cout << "Invalid Command." << endl;
		}
	} while (cmd != 'Q'  &&  cmd != 'q');
}
