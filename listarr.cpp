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
	dataItems = new DataType(maxNumber); // 동적으로 객체 생성
}

//--------------------------------------------------------------------

List:: ~List()
// Frees the memory used by a list.

{
	// pre-lab
	delete[] dataItems; //동적으로 생성한 객체 소멸
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
		dataItems[size] = newDataItem; //데이터 삽입
		cursor = size; //커서는 항상 뒤로
		size++; //커서보다 1 더 크게
	}
	else cout << "list is full now." << endl; //리스트가 꽉 찬 경우

}

//--------------------------------------------------------------------

void List::remove() throw (logic_error)

// Removes the data items  marked by the cursor from a list. Moves the
// cursor to the next data item item in the list. Assumes that the
// first list data items "follows" the last list data item.
{
	// pre-lab
	if (!List::isEmpty()) {
		if ((size - cursor) > 1) { //커서가 맨뒤가 아닌경우
			dataItems[cursor] = dataItems[size - 1];
			size--;
		}
		else if ((size - cursor) == 1) { //커서가 맨 뒤인 경우
			size--;
			cursor--;
		}
	}
	else cout << "list is empty now." << endl; //리스트가 빈 경우

}

//--------------------------------------------------------------------

void List::replace(const DataType& newDataItem)
throw (logic_error)

// Replaces the item marked by the cursor with newDataItem and
// leaves the cursor at newDataItem.
{
	// Requires that the list is not empty
	// pre-lab
	if (!List::isEmpty()) dataItems[cursor] = newDataItem; //리스트가 비지 않았다면 newDataItem으로 교체
}
//--------------------------------------------------------------------

void List::clear()
// Removes all the data items from a list.
{
	// pre-lab
	size = 0; //사이즈를 0으로 초기화
	cursor = -1; //커서 위치를 -1로 초기화
}

//--------------------------------------------------------------------

bool List::isEmpty() const
// Returns 1 if a list is empty. Otherwise, returns 0.
{
	// pre-lab
	if (size == 0) return true; //비어있다면 true를 반환
	else return false;
}

//--------------------------------------------------------------------

bool List::isFull() const
// Returns 1 if a list is full. Otherwise, returns 0.
{
	// pre-lab
	if (size == maxSize) return true; //꽉 차 있다면 true를 반환
	else return false;

}

//--------------------------------------------------------------------

bool List::gotoBeginning() throw (logic_error)
// Moves the cursor to the beginning of the list.
{
	// pre-lab
	if (!List::isEmpty()) {
		cursor = 0; //커서 위치를 맨 앞으로 이동
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
		cursor = size - 1; //커서 위치를 맨 뒤로 이동
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
		cursor++; //커서 위치를 증가해서 다음 위치로 커서 이동
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
		cursor--; //커서 위치를 증감해서 이전 위치로 커서 이동
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
		return dataItems[cursor]; //커서 위치에 있는 값을 반환
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
		cout << "size = " << size; //리스트 사이즈 디스플레이
		cout << "   cursor = " << cursor << endl; //커서 위치 디스플레이
		for (int i = 0; i < maxSize; i++) { //리스트 인덱스를 디스플레이
			cout << "[ " << i << " ]" << "\t";
		}
		cout << endl; // 개행
		for (int j = 0; j < size; j++) {
			cout << "  " << dataItems[j] << "\t"; // 리스트 값 디스플레이
		}
	}
	else cout << "Empty List" << endl;	//빈 리스트임을 출력

}

//--------------------------------------------------------------------

//in-lab
void List::countBases(List& dnaSequence, int& aCount, int& cCount, int& tCount, int& gCount) {
	aCount = 0;//염기서열의 개수를 0으로 초기화
	cCount = 0;
	tCount = 0;
	gCount = 0;

	for (int i = 0; i < size; i++) {
		switch (dataItems[i]) // 케이스로 나눠서 해당하는 염기서열의 개수를 증가
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