#include <iostream>
#include <vector>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

vector<int> v, tmpv;

void merge(int left, int right, int mid) {
    int l = left, m = mid + 1;
    int cnt = 0;

    while(l <= mid && m <= right) {
        if(v[l] < v[m]) {
            tmpv[cnt] = v[l];
            l++;
        }
        else {
            tmpv[cnt] = v[m];
            m++;
        }
        cnt++;
    }

    while(l <= mid) {
        tmpv[cnt] = v[l];
        l++;
        cnt++;
    }

    while(m <= right) {
        tmpv[cnt] = v[m];
        m++;
        cnt++;
    }

    for(int i=0; i<right-left+1; i++)
        v[left+i] = tmpv[i];
}

void msort(int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        msort(left, mid);
        msort(mid+1, right);
        merge(left, right, mid);
    }
}

int main() {
    int n, option, tmp;
    int pos, min;

    srand((unsigned int)time(0));
    
    printf("How many numbers? ");
    scanf("%d", &n);
    printf("\n");

    tmpv.assign(n, 0);

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
    msort(0, n-1);

    for(int i=0; i<n; i++)
        printf("%d ", v[i]);

    printf("\n");

    return 0;
}