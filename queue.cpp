#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main() {
    vector<int> queue;
    int n, option;
    int data;

    while(1) {
        printf("\n===== QUEUE =====\n");
        printf("[0] exit\n");
        printf("[1] enqueue\n");
        printf("[2] dequeue\n");
        printf("=================\n");
        scanf("%d", &option);

        // EXIT
        if(!option)
            break;
        
        // ENQUEUE
        else if(option == 1) {
            printf("Type number to push: ");
            scanf("%d", &data);
            queue.push_back(data);
        }

        // DEQUEUE
        else if(option == 2) {
            if(queue.empty()) {
                printf("ERROR: queue is empty!\n\n");
                continue;
            }
            printf("Popped data: %d\n", queue.front());
            queue.erase(queue.begin());
        }

        else {
            printf("ERROR: wrong option!\n\n");
            continue;
        }

        printf("\nQUEUE: ");
        for(int i=0; i<queue.size(); i++)
            printf("%d ", queue[i]);
        printf("\n\n");
    }
}