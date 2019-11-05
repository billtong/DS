/*
	Author: Bill Tong
*/
#pragma once
#include<vector>
#include<iostream>
#include<fstream>

using std::ifstream, std::cout, std::endl, std::vector;

#define DIJKSTRA_DATA_1600 "../../data/Dijkstra_Data_1600.txt"

class CSquareMatrix
{
public:
	int** m_gData;
	int m_nLength;

public:
	CSquareMatrix(const char* cFilepath);
	void print();
};

class CDijkstra
{
public:
	bool* m_gReached;
	int* m_gCost;
	int m_nSize;

public:
	CDijkstra(CSquareMatrix cSquareMatrix, int nStartIndex);
	void printResult();
};