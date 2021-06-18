#include <climits> 
#include <new>
#include <stdexcept>
using namespace std;

const int MaxVSize = 100, //���� ����
L_Length = 21, // ���� �� ����
M_Edge = INT_MAX;

class Vertex{
public:
	char label[L_Length];// label
	int h; // height
};


class OrganizationTree
{
public:
	OrganizationTree(int maxNumber = MaxVSize)
		throw (bad_alloc);
	~OrganizationTree();

	void insert_ceo(Vertex ceo) //ceo ����
		throw (logic_error);
	void insert_emp(Vertex subordinate, char* superior) //������ ��� ����
		throw (logic_error);
	void fire(char* v) //�ذ��� ����� ù��° ���� ���ϸ� ����
		throw (logic_error);
	void remove_V(char R_index)
		throw (logic_error);
	void clear();

	bool isEmpty() const;
	bool isFull() const;
	void showStructure();
	void print();
	void subprint(int i);


private:
	int get_Index(char* v);
	int get_Edge(int row, int col);
	void set_Edge(int row, int col, int wt);

	int maxSize,
		size;
	Vertex* List_V;
	int* adjMatrix;

};