/*
	Author: Bill Tong
*/
#include "CSquareMatrix.h"

CSquareMatrix::CSquareMatrix(const char * cFilepath)
{
	ifstream iFile;
	iFile.open(cFilepath);
	if (!iFile)
	{
		cout << "ERROR: cannot open file" << endl;
		exit(1);
	}
	iFile >> m_nLength;
	m_gData = (int **)operator new(m_nLength * sizeof(int *));
	for (int i = 0; i < m_nLength; i++) {
		m_gData[i] = (int *)operator new(m_nLength * sizeof(int));
		for (int j = 0; j < m_nLength; j++)
			iFile >> m_gData[i][j];
	}
	iFile.close();
}

CSquareMatrix::~CSquareMatrix()
{
	for (int i = 0; i < m_nLength; i++)
		delete m_gData[i];
	delete m_gData;
}

void CSquareMatrix::print()
{
	cout << "start print the square matrix:" << endl;
	for (int i = 0; i < m_nLength; i++)
	{
		for (int j = 0; j < m_nLength; j++)
		{
			cout << "\t" << m_gData[i][j];
		}
		cout << endl;
	}
	cout << "end print the square matrix" << endl;
}
