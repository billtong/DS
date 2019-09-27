/*
	Author: Bill Tong
*/
#pragma once

#include<iostream>
#include<fstream>

using std::ifstream;
using std::cout;
using std::endl;

class CSquareMatrix
{
public:
	int ** m_gData;
	int m_nLength;
	
public:
	CSquareMatrix(const char * cFilepath);
	~CSquareMatrix();
	void print();
};

