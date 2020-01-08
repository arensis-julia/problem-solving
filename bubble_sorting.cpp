#include <iostream>
#include <vector>
#include <ctime>
#include <stdio.h>
using namespace std;

int main() {
    vector<int> v;
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
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-1;j++) {
            if(v[j] > v[j+1]) {
                swap(v[j], v[j+1]);
            }
        }
    }

    for(int i=0; i<n; i++)
        printf("%d ", v[i]);

    printf("\n");

    return 0;
}