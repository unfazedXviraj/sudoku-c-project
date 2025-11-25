#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>

#define N 9 
extern int grid[N][N];
int findEmpty(int *row, int *col);
int safeRow(int row, int num);
int safeCol(int col, int num);
int safeBox(int startRow, int startCol, int num);
int isSafe(int row, int col, int num);
int solve();
void printGrid();
#endif
