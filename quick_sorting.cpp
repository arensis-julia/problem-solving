#include <iostream>
#include <vector>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

vector<int> v;

int partition(int left, int right) {
    int pivot = v[right];
    int l = left, r = right-1;

    while(l <= r) {
        while(v[l] <= pivot && l < right)   l++;
        while(v[r] > pivot && r >= left)    r--;

        if(l < r) {
            swap(v[l], v[r]);
            l++;
            r--;
        }
    }

    swap(v[l], v[right]);
    return l;
}

void qsort(int left, int right) {
    if(left < right) {
        int p = partition(left, right);
        qsort(left, p-1);
        qsort(p+1, right);
    }
}

int main() {
    int n, option, tmp;
    int pos, min;

    srand((unsigned int)time(0));
    
    printf("How many numbers? ");
    scanf("%d", &n);
    printf("\n");

    printf("[0] Auto input\n");
    printf("[1] Manual input\n");
    scanf("%d", &option);
    printf("\n");


    // CREATE SET OF NUMBERS
    if(!option) {
        for(int i=0; i<n; i++)
            v.push_back(rand());
    }
    else {
        for(int i=0; i<n; i++) {
            scanf("%d", &tmp);
            v.push_back(tmp);
        }
    }

    // SORTING
    qsort(0, n-1);

    for(int i=0; i<n; i++)
        printf("%d ", v[i]);

    printf("\n");

    return 0;
}