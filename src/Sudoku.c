#include <stdio.h>
#define N 9
int grid[N][N] = {
    {5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}
};

int findEmpty(int *row, int *col) {
    for(*row=0;*row<N;(*row)++)
        for(*col=0;*col<N;(*col)++)
            if(grid[*row][*col]==0)
                return 1;
    return 0;
}

int safeRow(int row, int num) {
    for(int col=0;col<N;col++)
        if(grid[row][col]==num)
            return 0;
    return 1;
}

int safeCol(int col, int num) {
    for(int row=0;row<N;row++)
        if(grid[row][col]==num)
            return 0;
    return 1;
}

int safeBox(int startRow, int startCol, int num) {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(grid[i+startRow][j+startCol]==num)
                return 0;
    return 1;
}

int isSafe(int row,int col,int num) {
    return safeRow(row,num) && safeCol(col,num) && safeBox(row-row%3,col-col%3,num);
}

int solve() {
    int row, col;
    if(!findEmpty(&row, &col))
        return 1;
    for(int num=1; num<=9; num++) {
        if(isSafe(row,col,num)) {
            grid[row][col]=num;
            if(solve())
                return 1;
            grid[row][col]=0;
        }
    }
    return 0;
}

void printGrid() {
    for(int r=0;r<N;r++) {
        for(int d=0;d<N;d++)
            printf("%d ",grid[r][d]);
        printf("\n");
    }
}

int main() {
    if(solve())
        printGrid();
    else
        printf("No solution exists");
    return 0;
}
