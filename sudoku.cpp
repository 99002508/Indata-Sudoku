#include"datasudoku.h"
#include"constraint.h"
#include <bits/stdc++.h>

using namespace std;


#define UNASSIGNED 0


#define N 9

//bool FindUnassignedLocation(int grid[N][N],
//                            int &row, int &col);

//bool isSafe(int grid[N][N], int row,
//                   int col, int num);
sudoku::sudoku(){}
constraint::constraint(){}

bool sudoku::SolveSudoku(int grid[N][N])
{
    int row, col;

    if (!FindUnassignedLocation(grid, row, col))
    return true;


    for (int num = 1; num <= 9; num++)
    {

        if (isSafe(grid, row, col, num))
        {

            grid[row][col] = num;

            if (SolveSudoku(grid))
                return true;

            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}
bool sudoku::FindUnassignedLocation(int grid[N][N],
                            int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}

bool constraint::UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}
bool constraint::UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}
bool constraint::UsedInBox(int grid[N][N], int boxStartRow,
               int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow]
                    [col + boxStartCol] == num)
                return true;
    return false;
}

bool sudoku::isSafe(int grid[N][N], int row,
                   int col, int num)
{
    return !UsedInRow(grid, row, num) &&
           !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row % 3 ,
                      col - col % 3, num) &&
            grid[row][col] == UNASSIGNED;
}
void sudoku::printGrid(int grid[N][N])
{
    cout<<"    0 1 2 3 4 5 6 7 8"<<endl<<endl;
    for (int row = 0; row < N; row++)
    {
        cout<<row<<"   ";
    for (int col = 0; col < N; col++)
            cout << grid[row][col] <<" ";
        cout << endl;
    }
}

int main()
{
	sudoku s;
	constraint c;
	
    int grid[N][N]={0},i,j;
    ifstream file("Input_Clue.txt");
    if(file.is_open())
    {
        while(!file.eof())
        {
            i=0;j=0;
            file>>i;
            file>>j;
            file>>grid[i][j];
        }
    }
    cout<<"    0 1 2 3 4 5 6 7 8"<<endl<<endl;
    for(int x=0;x<9;x++)
    {
        cout<<x<<"   ";
        for(int y=0;y<9;y++)
        {
            if(grid[x][y]==0)
            {
                cout<<"_ ";
            }
            else
            {
                cout<<grid[x][y]<<" ";
            }

        }
        cout<<endl;
    }
    cout<<"------------------------------------------------------"<<endl;
    if (s.SolveSudoku(grid) == true)
        s.printGrid(grid);
    else
        cout << "No solution exists";

    return 0;
}
