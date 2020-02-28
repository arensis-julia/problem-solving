#include <iostream>
#include <vector>
#include <ctime>
#include <stdio.h>
using namespace std;

vector<int> heap;

// INSERT DATA INTO HEAP
void insert() {
    int s = heap.size();

    while(s > 1) {
        if(heap[s-1] > heap[s/2-1]) {
            swap(heap[s-1], heap[s/2-1]);
            s /= 2;
        }
        else    break;
    }

    printf("INSERT: ");
    for(int i=0; i<heap.size(); i++)
        printf("%d ", heap[i]);
    printf("\n");
}

// HEAP SORTING (HEAPIFY)
void heapify(int s) {
    int i = 0;
    while(i < s/2) {
        // compare with left child (left > right || right > s)
        if(heap[i] < heap[2*i+1] && (heap[2*i+1] > heap[2*i+2] || 2*i+2 >= s) && 2*i+1 < s) {
            swap(heap[i], heap[2*i+1]);
            i = 2 * i + 1;
        }
        
        // compare with right child (2*i+2 for i = 0)
        else if(heap[i] < heap[2*i+2] && 2*i+2 < s) {
            swap(heap[i], heap[2*i+2]);
            i = 2 * i + 2;
        }
        
        else    break;
    }
}

int main() {
    int n, option, tmp;

    srand((unsigned int)time(0));
    
    printf("How many numbers? ");
    scanf("%d", &n);
    printf("\n");

    printf("[0] Auto input\n");
    printf("[1] Manual input\n");
    scanf("%d", &option);
    printf("\n");

    printf("===== INSERTING =====\n");
    if(!option) {
        for(int i=0; i<n; i++) {
            heap.push_back(rand());
            insert();
        }
    }
    else {
        for(int i=0; i<n; i++) {
            scanf("%d", &tmp);
            heap.push_back(tmp);
            insert();
        }
    }

    printf("\n====== SORTING ======\n");
    for(int i=heap.size()-1; i>0; i--) {
        swap(heap[i], heap[0]);
        heapify(i);

        printf("HEAPIFY: ");
        for(int j=0; j<heap.size(); j++)
            printf("%d ", heap[j]);
        printf("\n");
    }

    printf("\n====== RESULT ======\n");
    for(int i=0; i<heap.size(); i++)
        printf("%d ", heap[i]);
    printf("\n");

    return 0;
}