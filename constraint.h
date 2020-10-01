#ifndef __CONSTRAINT_H
#define __CONSTRAINT_H

#define UNASSIGNED 0
#define N 9

class constraint
{
	public:
	constraint(); 
	bool UsedInRow(int grid[N][N], int row,int num);
	bool UsedInCol(int grid[N][N], int col,  int num);
	bool UsedInBox(int grid[N][N], int boxStartRow,int boxStartCol, int num);
	virtual void printGrid(int grid[N][N])=0;		
        
};

#endif
