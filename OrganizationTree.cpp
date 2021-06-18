//2019112151_김태형
#include <iostream>
#include <cstring>
#include "OrganizationTree.h"
using namespace std;

OrganizationTree::OrganizationTree(int maxNumber) throw (bad_alloc)
{
	maxSize = maxNumber;
	size = 0;
	adjMatrix = new int[maxSize * maxSize];
	List_V = new Vertex[maxSize];
	for (int i = 0; i < maxSize * maxSize; i++) {
		adjMatrix[i] = M_Edge;
	}
}

OrganizationTree::~OrganizationTree()
{
	delete[] List_V;
	delete[] adjMatrix;
}

void OrganizationTree::insert_ceo(Vertex ceo) throw (logic_error)
{
	if (!isFull()) {
		List_V[size] = ceo;
		List_V[size].h = 0;     // level 0
		size++;
	}
}

void OrganizationTree::insert_emp(Vertex subordinate, char* superior) throw (logic_error)
{
	if (!isFull()) {
		List_V[size] = subordinate;
		List_V[size].h = List_V[get_Index(superior)].h + 1;   //고용한 사원높이 + 1
		set_Edge(get_Index(superior), get_Index(List_V[size].label), 1); //상사와 부하직원의 관계 지정
		size++;
	}
}

void OrganizationTree::fire(char* v) throw (logic_error)
{
	int i = get_Index(v);
	bool leaf = false;

	while (!leaf)//신입 찾을 때까지
	{
		int j = 0;
		while ((j != size) && (get_Edge(i, j) == M_Edge))
		{
			j++;
		}

		if (get_Edge(i, j) == 1) //첫번째 직속부하일 때
		{
			List_V[i] = List_V[j];
			List_V[i].h--;
			i = j; //직속부하의 부하 검색
		}
		else if (j == size) //신입일 때
		{
			remove_V(i);
			leaf = true;
		}
	}
}


void OrganizationTree::remove_V(char R_index) throw (logic_error)
{

	for (int i = R_index; i < size - 1; i++) {
		List_V[i] = List_V[i + 1];
		for (int j = 0; j < size; j++) {
			adjMatrix[i * maxSize + j] = adjMatrix[(i + 1) * maxSize + j];
		}
	}

	for (int j = R_index; j < size - 1; j++) {
		for (int i = 0; i < size - 1; i++) {
			adjMatrix[i * maxSize + j] = adjMatrix[i * maxSize + j + 1];
		}
	}

	for (int a = 0; a < size; a++) {
		set_Edge(size - 1, a, M_Edge);
	}

	size--;
}

void OrganizationTree::print()
{
	int count = 0;
	cout << "----------------------------" << endl;
	cout << List_V[0].label << endl;   //ceo print
	subprint(0);
	cout << "----------------------------" << endl;
}

void OrganizationTree::subprint(int i) //preorder 사용
{
	for (int j = 0; j < size; j++)
	{
		if (get_Edge(i, j) == 1)
		{
			int a = 0;
			for (a = 0; a < List_V[j].h; a++) //level당 +
				cout << "+";
			cout << List_V[j].label << endl;
			subprint(j);
		}
	}
}

void OrganizationTree::clear()
{
	size = 0;
}

bool OrganizationTree::isEmpty() const
{
	return (size == 0);
}

bool OrganizationTree::isFull() const
{
	return (size == maxSize);
}

int OrganizationTree::get_Index(char* v)
{
	int j;
	for (j = 0;	j < size && strcmp(List_V[j].label, v) != 0; j++);
	return j;
}

int OrganizationTree::get_Edge(int row, int col)
{
	return adjMatrix[row * maxSize + col];
}

void OrganizationTree::set_Edge(int row, int col, int wt)
{
	adjMatrix[row * maxSize + col] = wt;
}

void OrganizationTree::showStructure()
{
	int wt, row, col;

	if (size == 0)
		cout << "Empty graph" << endl;
	else
	{
		cout << endl << "Vertex list : " << endl;

		for (row = 0; row < size; row++)
		{
			cout << row << '\t';
			for (int a = 0; a < List_V[row].h; a++)
				cout << "+";
			cout << List_V[row].label << endl;
		}

		cout << "\n" << "Edge matrix : " << "\n" << '\t';
		for (col = 0; col < size; col++)
		{
			cout << col << '\t';
		}
		cout << endl;

		for (row = 0; row < size; row++)
		{
			cout << row << '\t';
			for (col = 0; col < size; col++)
			{
				wt = get_Edge(row, col);
				if (wt == M_Edge)
				{
					cout << "- \t";
				}
				else
				{
					cout << wt << '\t';
				}
			}
			cout << endl;
		}
	}
}
