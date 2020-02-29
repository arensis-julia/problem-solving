#include <iostream>
#include <vector>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n;
int cnt;                    // number of valid sets of n-queen
int col[1010];              // col[i] == column index of i-th row of queens

bool isValid(int row) {     // check if it is valid to put queen on the row
    for(int i=0; i<row; i++) {
        if(col[row] == col[i] || abs(col[row] - col[i]) == abs(row - i))
            return false;
    }
    return true;
}

void nqueen(int row) {
    if(row == n) {
        cnt++;
        return;
    }
    for(int i=0; i<n; i++) {
        col[row] = i;
        if(isValid(row)) {
            nqueen(row+1);
        }
    }
}

int main() {
    printf("n? ");
    scanf("%d", &n);

    nqueen(0);

    printf("Number of valid cases: %d\n", cnt);

    return 0;
}