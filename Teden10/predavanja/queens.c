#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int queens(int column, int num_queens, int board[]) 
{
    if (column == num_queens) {
        return 1;
    }

    int solutions = 0;
    for (int r = 0; r < num_queens; r++) {
        bool conflict = false;
        for (int c = 0; c < column; c++) {
            conflict = conflict || (board[c] == r);
            conflict = conflict || (r-board[c] == column-c);
            conflict = conflict || (board[c] - r == column -c );
        }
        if (!conflict) {
            board[column] = r;
            solutions += queens(column + 1, num_queens, board);
        }
    }   
    return solutions;
}

int main(int argc, char* argsv[])
{   
    int num_queens;
    if (argc != 2)  exit(1);
    sscanf(argsv[1], "%d", &num_queens);

    int* board = malloc(num_queens*sizeof(int));
    printf("# SOLUTIONS: %d\n", queens(0, num_queens, board));
    free(board);
    return 0;
}