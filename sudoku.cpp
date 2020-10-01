#include"datasudoku.h"
#include"constraint.h"
#include <bits/stdc++.h>

using namespace std;


#define UNASSIGNED 0
#define N 9

/*bool FindUnassignedLocation(int grid[N][N],int &row, int &col);
bool isSafe(int grid[N][N], int row,int col, int num);*/

template<typename T>
sudoku<T>::sudoku():m_row(0),m_col(0){}
template<class T>
T sudoku<T> :: getrow()
{
    return m_row;
}

template<class T>
T sudoku<T> :: getcol()
{
    return m_col;
}
constraint::constraint(){}

template<typename T>
bool sudoku<T>::isSafe(T grid[N][N],T row,T col,T num)
{
    return !UsedInRow(grid, row, num) &&
    	   !UsedInCol(grid, col, num) &&
    	   !UsedInBox(grid, row - row % 3,col - col % 3, num)&&
           grid[row][col] == UNASSIGNED;
}

template<typename T>
bool sudoku<T>::SolveSudoku(T grid[N][N])
{
    T row, col;

    if (!FindUnassignedLocation(grid, row, col))
    return true;


    for (T num = 1; num <= 9; num++)
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
template<typename T>
bool sudoku<T>::FindUnassignedLocation(T grid[N][N],T &row, T &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}
//template<typename T>
bool constraint::UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}
//template<typename T>
bool constraint::UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}
//template<typename T>
bool constraint::UsedInBox(int grid[N][N],int boxStartRow,int boxStartCol,int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow][col + boxStartCol] == num)
                return true;
    return false;
}

template<typename T>
void sudoku<T>::printGrid(T  grid[N][N])
{
    cout<<"    0 1 2 3 4 5 6 7 8"<<endl<<endl;
    for (T row = 0; row < N; row++)
    {
        cout<<row<<"   ";
    for (T col = 0; col < N; col++)
            cout << grid[row][col] <<" ";
        cout << endl;
    }
}

template<typename T>
bool sudoku<T> :: operator == (const sudoku &ref)
{
    T row,col;
    if(ref.row>9 && ref.col>9)	
   	return false;
}


int main()
{
    sudoku<int> s; //template passing
    constraint *p;//dynamic binding
    p=&s;//upcasting

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
    cout<<"------------------------------------------------------"<<endl;
    cout<<"Unsolved Sudoku Problem"<<endl; 
    cout<<"    0 1 2 3 4 5 6 7 8"<<endl<<endl;
    vector<vector<int> > vec;
    vector<int>::iterator x;
    vector<int>::iterator y;
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
    cout<<"Solved Sudoku Problem"<<endl;
    if (s.SolveSudoku(grid) == true)
        p->printGrid(grid);
    else
        cout << "No solution exists";
    cout<<"------------------------------------------------------"<<endl;
    return 0;
}
