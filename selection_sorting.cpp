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
            scanf("%d", tmp);
            v.push_back(tmp);
        }
    }

    // SORTING
    for(int i=0; i<n; i++) {
        min = v[i];
        pos = i;

        for(int j=i; j<n; j++) {
            if(v[j] < min) {
                min = v[j];
                pos = j;
            }
        }
        
        swap(v[pos], v[i]);
    }

    for(int i=0; i<n; i++)
        printf("%d ", v[i]);

    printf("\n");

    return 0;
}