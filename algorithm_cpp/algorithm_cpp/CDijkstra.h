/*
	Author: Bill Tong
*/
#pragma once
#include<vector>
#include"CSquareMatrix.h"

#define DIJKSTRA_DATA_6 "./data/Dijkstra_Data_6.txt"
#define DIJKSTRA_DATA_100 "./data/Dijkstra_Data_100.txt"
#define DIJKSTRA_DATA_200 "./data/Dijkstra_Data_200.txt"
#define DIJKSTRA_DATA_400 "./data/Dijkstra_Data_400.txt"
#define DIJKSTRA_DATA_800 "./data/Dijkstra_Data_800.txt"
#define DIJKSTRA_DATA_1600 "./data/Dijkstra_Data_1600.txt"

using std::vector;

namespace CDIJKSTRA
{
	class CDijkstra
	{
	public:
		bool* m_gReached;
		int* m_gCost;
		int m_nSize;

	public:
		CDijkstra(CSquareMatrix cSquareMatrix, int nStartIndex);
		~CDijkstra();
		void printResult();
	};
}

