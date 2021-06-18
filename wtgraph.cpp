//--------------------------------------------------------------------
//
//  Laboratory 14                                          wtgraph.cpp
//
//  Implementation of the Weighted Graph ADT
//
//--------------------------------------------------------------------
#include <iostream>
#include <cstring>
#include "wtgraph.h"
using namespace std;
//--------------------------------------------------------------------

WtGraph::WtGraph(int maxNumber) throw (bad_alloc)
{
	size = 0;
	maxSize = maxNumber;
	vertexList = new Vertex[maxSize];
	adjMatrix = new int[maxSize*maxSize];

	for (int i = 0; i < maxSize; i++){ //초기화
		for (int j = 0; j < maxSize; j++){
			adjMatrix[i*maxSize + j] = infiniteEdgeWt;
		}
	}
}

WtGraph::~WtGraph()
{
	delete[] vertexList;
	delete[] adjMatrix;
}

//--------------------------------------------------------------------

int WtGraph::getIndex(char* v)
{
	int j; 
	for (j = 0; j < size  &&  strcmp(vertexList[j].label, v) != 0; j++);
	return j;
}

int WtGraph::getEdge(int row, int col) { return adjMatrix[row*maxSize + col]; }

void WtGraph::setEdge(int row, int col, int wt) { adjMatrix[row*maxSize + col] = wt; }

//--------------------------------------------------------------------

void WtGraph::insertVertex(Vertex newVertex) throw (logic_error)
{
	if (isFull()) { cout << "Graph is full" << endl; }
	else
	{
		vertexList[size] = newVertex;
		size++;
	}
}

void WtGraph::insertEdge(char* v1, char* v2, int wt) throw (logic_error)
{
	setEdge(getIndex(v1), getIndex(v2), wt);
	setEdge(getIndex(v2), getIndex(v1), wt);
}

//--------------------------------------------------------------------

bool WtGraph::retrieveVertex(char* v, Vertex& vData)
{
	if (getIndex(v) == size) { return false; }  // 해당하는 문자 없을 시
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (vertexList[i].label == v)
			{
				cout << "Vertex " << v << " exists" << endl;
				return true;
			}
		}
	}
}

bool WtGraph::getEdgeWeight(char* v1, char* v2, int& wt) throw (logic_error)
{
	wt = getEdge(getIndex(v1), getIndex(v2));
	if (getIndex(v1) == size || getIndex(v2) == size) { return false; }
	else
	{
		cout << wt << endl;
		return true;
	}
}

//--------------------------------------------------------------------

void WtGraph::removeVertex(char* v) throw (logic_error)
{
	int index = getIndex(v);
	int i, j;
	if (getIndex(v) == size)
	{
		cout << "Graph doesn't include vertex " << v << endl;
	}
	else
	{
		for (i = index; i < size - 1; i++)
		{
			vertexList[i] = vertexList[i + 1];   //값을 하나씩 땡긴다
		}
		for (i = index; i < size; i++)          //왼쪽으로 열 이동
		{
			for (j = 0; j < size; j++)
			{
				setEdge(j, i, getEdge(j, i + 1));
			}
		}
		for (j = index; j < size; j++)          //위로 행 이동
		{
			for (i = 0; i < size; i++)
			{
				setEdge(j, i, getEdge((j + 1), i));
			}
		}
		size--;
	}
}

void WtGraph::removeEdge(char* v1, char* v2) throw (logic_error)
{
	if (getIndex(v1) == size || getIndex(v2) == size)
	{
		cout << "Graph doesn't include vertices v1 and v2" << endl;
	}
	else
	{
		setEdge(getIndex(v1), getIndex(v2), infiniteEdgeWt);       // 초기화
		setEdge(getIndex(v2), getIndex(v1), infiniteEdgeWt);
	}
}

//--------------------------------------------------------------------

void WtGraph::clear()
{
	size = 0;
}

bool WtGraph::isEmpty() const
{
	if (size == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool WtGraph::isFull() const
{
	if (size == maxSize)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//--------------------------------------------------------------------

void WtGraph::showStructure()

// Outputs a graph's vertex list (w/ color) and adjacency matrix.
// This operation is intended for testing/debugging purposes only.

{
	int wt,         // Edge weight
		row, col;   // Loop counters

	if (size == 0)
		cout << "Empty graph" << endl;
	else
	{
		cout << endl << "Vertex list : " << endl;
		for (row = 0; row < size; row++)
			cout << row << '\t' << vertexList[row].label << endl;

		cout << endl << "Edge matrix : " << endl << '\t';
		for (col = 0; col < size; col++)
			cout << col << '\t';
		cout << endl;
		for (row = 0; row < size; row++)
		{
			cout << row << '\t';
			for (col = 0; col < size; col++)
			{
				wt = getEdge(row, col);
				if (wt == infiniteEdgeWt)
					cout << "- \t";
				else
					cout << wt << '\t';
			}
			cout << endl;
		}
	}
}

//--------------------------------------------------------------------


// int WtGraph::getPath(int row, int col)
// {

// }

// void WtGraph::setPath(int row, int col, int wt) {

// }

// void WtGraph::computePaths() 
// {

// }