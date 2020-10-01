#ifndef __DATASUDOKU_H
#define __DATASUDOKU_H
#include "constraint.h"
#include <bits/stdc++.h>
using namespace std;

#define UNASSIGNED 0
#define N 9

template<typename T> //class template
class sudoku : public constraint 
{
	private:
	T m_row;
	T m_col;
	public:
	sudoku<T>(); 
	bool FindUnassignedLocation(T grid[N][N], T &row, T &col);
	bool isSafe(T grid[N][N], T row,T col, T num);
	bool SolveSudoku(T grid[N][N]);
	void printGrid(T grid[N][N]);
	bool operator == (const sudoku &ref);
	T getrow();
        T getcol();
};
#endif
