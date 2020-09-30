#ifndef __DATASUDOKU_H
#define __DATASUDOKU_H

#define UNASSIGNED 0
#include "constraint.h"

#define N 9
class sudoku : public constraint 
{
	public:
	sudoku(); 
	bool FindUnassignedLocation(int grid[N][N], int &row, int &col);
	bool isSafe(int grid[N][N], int row,int col, int num);
	bool SolveSudoku(int grid[N][N]);
	void printGrid(int grid[N][N]);
};
#endif
