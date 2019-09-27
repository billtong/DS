/*
	Author: Bill Tong
*/
#include"CDijkstra.h"

using CDIJKSTRA::CDijkstra;

CDijkstra::CDijkstra(CSquareMatrix cSquareMatrix, int nStartIndex)
{
	m_nSize = cSquareMatrix.m_nLength;
	bool* gCandidate = new bool[m_nSize];
	int* gEstimate = new int[m_nSize];
	m_gReached = new bool[m_nSize];
	m_gCost = new int[m_nSize];
	for (int i = 0; i < m_nSize; i++)
	{
		if (i == nStartIndex)
		{
			gCandidate[i] = false;
			gEstimate[i] = INT_MAX;
			m_gReached[i] = true;
			m_gCost[i] = 0;
		}
		else if(cSquareMatrix.m_gData[nStartIndex][i] > 0)
		{
			gCandidate[i] = true;
			gEstimate[i] = cSquareMatrix.m_gData[nStartIndex][i];
			m_gReached[i] = false;
			m_gCost[i] = INT_MAX;
		}
		else {
			gCandidate[i] = false;
			gEstimate[i] = INT_MAX;
			m_gReached[i] = false;
			m_gCost[i] = INT_MAX;
		}
	}
	while (true)
	{
		int nBestCandidate = -1;
		int nBestCandidateCost = INT_MAX;
		for (int i = 0; i < m_nSize; i++)
		{
			if (gCandidate[i] && nBestCandidateCost > gEstimate[i])
			{
				nBestCandidate = i;
				nBestCandidateCost = gEstimate[i];
			}
		}
		if (nBestCandidate == -1)
			break;
		m_gReached[nBestCandidate] = true;
		m_gCost[nBestCandidate] = gEstimate[nBestCandidate];
		gCandidate[nBestCandidate] = false;
		for (int i = 0; i < m_nSize; i++)
		{
			if (cSquareMatrix.m_gData[nBestCandidate][i] > 0 && !m_gReached[i] && m_gCost[nBestCandidate] + cSquareMatrix.m_gData[nBestCandidate][i] < gEstimate[i])
			{
				gEstimate[i] = m_gCost[nBestCandidate] + cSquareMatrix.m_gData[nBestCandidate][i];
				gCandidate[i] = true;
			}
		}
	}
	delete[] gCandidate;
	delete[] gEstimate;
}

CDijkstra::~CDijkstra()
{
	delete[] m_gCost;
	delete[] m_gReached;
}

void CDijkstra::printResult()
{
	cout << "start display the result of dijkstra algorithm:" << endl;
	for (int i = 0; i < m_nSize; i++) 
	{
		cout << "vertex(" << i << "): ";
		if (m_gReached[i])
			cout << m_gCost[i] << "\t";
		else
			cout << "n/a\t";
	}
	cout << "\nend display the result of dijkstra algorithm" << endl;
}
