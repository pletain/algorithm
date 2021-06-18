//--------------------------------------------------------------------
//
//                                                       listarr.cpp
//
//  SOLUTION: Array implementation of the List ADT
//
//--------------------------------------------------------------------

#include "listarr.h"

using namespace std;

//--------------------------------------------------------------------

List::List(int maxNumber)

// Creates an empty list. Allocates enough memory for maxNumber
// data items (defaults to defMaxListSize).

	: maxSize(maxNumber),
	size(0),
	cursor(-1)
{
	// pre-lab
	dataItems = new DataType(maxNumber); // �������� ��ü ����
}

//--------------------------------------------------------------------

List:: ~List()
// Frees the memory used by a list.

{
	// pre-lab
	delete[] dataItems; //�������� ������ ��ü �Ҹ�
}

//--------------------------------------------------------------------

void List::insert(const DataType& newDataItem)
throw (logic_error)

// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) data items in the
// list. In either case, moves the cursor to newDataItem.

{
	// pre-lab
	if (!List::isFull()) {
		dataItems[size] = newDataItem; //������ ����
		cursor = size; //Ŀ���� �׻� �ڷ�
		size++; //Ŀ������ 1 �� ũ��
	}
	else cout << "list is full now." << endl; //����Ʈ�� �� �� ���

}

//--------------------------------------------------------------------

void List::remove() throw (logic_error)

// Removes the data items  marked by the cursor from a list. Moves the
// cursor to the next data item item in the list. Assumes that the
// first list data items "follows" the last list data item.
{
	// pre-lab
	if (!List::isEmpty()) {
		if ((size - cursor) > 1) { //Ŀ���� �ǵڰ� �ƴѰ��
			dataItems[cursor] = dataItems[size - 1];
			size--;
		}
		else if ((size - cursor) == 1) { //Ŀ���� �� ���� ���
			size--;
			cursor--;
		}
	}
	else cout << "list is empty now." << endl; //����Ʈ�� �� ���

}

//--------------------------------------------------------------------

void List::replace(const DataType& newDataItem)
throw (logic_error)

// Replaces the item marked by the cursor with newDataItem and
// leaves the cursor at newDataItem.
{
	// Requires that the list is not empty
	// pre-lab
	if (!List::isEmpty()) dataItems[cursor] = newDataItem; //����Ʈ�� ���� �ʾҴٸ� newDataItem���� ��ü
}
//--------------------------------------------------------------------

void List::clear()
// Removes all the data items from a list.
{
	// pre-lab
	size = 0; //����� 0���� �ʱ�ȭ
	cursor = -1; //Ŀ�� ��ġ�� -1�� �ʱ�ȭ
}

//--------------------------------------------------------------------

bool List::isEmpty() const
// Returns 1 if a list is empty. Otherwise, returns 0.
{
	// pre-lab
	if (size == 0) return true; //����ִٸ� true�� ��ȯ
	else return false;
}

//--------------------------------------------------------------------

bool List::isFull() const
// Returns 1 if a list is full. Otherwise, returns 0.
{
	// pre-lab
	if (size == maxSize) return true; //�� �� �ִٸ� true�� ��ȯ
	else return false;

}

//--------------------------------------------------------------------

bool List::gotoBeginning() throw (logic_error)
// Moves the cursor to the beginning of the list.
{
	// pre-lab
	if (!List::isEmpty()) {
		cursor = 0; //Ŀ�� ��ġ�� �� ������ �̵�
		return 1;
	}
	else return 0;
}

//--------------------------------------------------------------------

bool List::gotoEnd() throw (logic_error)

// Moves the cursor to the end of the list.

{
	// pre-lab
	if (!List::isEmpty()) {
		cursor = size - 1; //Ŀ�� ��ġ�� �� �ڷ� �̵�
		return 1;
	}
	else return 0;
}

//--------------------------------------------------------------------

bool List::gotoNext() throw (logic_error)

// If the cursor is not at the end of a list, then moves the
// cursor to the next item in the list and returns true. Otherwise,
// returns false.
{
	// pre-lab
	if (!(cursor == size - 1)) {
		cursor++; //Ŀ�� ��ġ�� �����ؼ� ���� ��ġ�� Ŀ�� �̵�
		return true;
	}
	else return false;
}

//--------------------------------------------------------------------

bool List::gotoPrior() throw (logic_error)

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding item in the list and returns true.
// Otherwise, returns false.

{
	// pre-lab
	if (!(cursor == 0)) {
		cursor--; //Ŀ�� ��ġ�� �����ؼ� ���� ��ġ�� Ŀ�� �̵�
		return true;
	}
	else return false;

}

//--------------------------------------------------------------------

DataType List::getCursor() const throw (logic_error)
// Returns the item marked by the cursor.

{
	// pre-lab
	if (!List::isEmpty()) {
		return dataItems[cursor]; //Ŀ�� ��ġ�� �ִ� ���� ��ȯ
	}
	return 0;

}

//--------------------------------------------------------------------

void List::showStructure() const
// Outputs the data items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing/debugging
// purposes only.

{
	// pre-lab
	if (!List::isEmpty()) {
		cout << "size = " << size; //����Ʈ ������ ���÷���
		cout << "   cursor = " << cursor << endl; //Ŀ�� ��ġ ���÷���
		for (int i = 0; i < maxSize; i++) { //����Ʈ �ε����� ���÷���
			cout << "[ " << i << " ]" << "\t";
		}
		cout << endl; // ����
		for (int j = 0; j < size; j++) {
			cout << "  " << dataItems[j] << "\t"; // ����Ʈ �� ���÷���
		}
	}
	else cout << "Empty List" << endl;	//�� ����Ʈ���� ���

}

//--------------------------------------------------------------------

//in-lab
void List::countBases(List& dnaSequence, int& aCount, int& cCount, int& tCount, int& gCount) {
	aCount = 0;//���⼭���� ������ 0���� �ʱ�ȭ
	cCount = 0;
	tCount = 0;
	gCount = 0;

	for (int i = 0; i < size; i++) {
		switch (dataItems[i]) // ���̽��� ������ �ش��ϴ� ���⼭���� ������ ����
		{
		case 'A':
			aCount++;
			break;
		case 'C':
			cCount++;
			break;
		case 'T':
			tCount++;
			break;
		case 'G':
			gCount++;
			break;
		}
	}
}