#ifndef __DATASUDOKU_H
#define __DATASUDOKU_H
#include "constraint.h"

#define UNASSIGNED 0
#define N 9
template<typename T>
class sudoku : public constraint 
{
	public:
	sudoku<T>(); 
	bool FindUnassignedLocation(T grid[N][N], T &row, T &col);
	bool isSafe(T grid[N][N], T row,T col, T num);
	bool SolveSudoku(T grid[N][N]);
	void printGrid(T grid[N][N]);
};
#endif
