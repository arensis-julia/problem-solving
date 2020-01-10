#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main() {
    vector<int> stack;
    int n, option;
    int data;

    while(1) {
        printf("\n===== STACK =====\n");
        printf("[0] exit\n");
        printf("[1] push\n");
        printf("[2] pop\n");
        printf("=================\n");
        scanf("%d", &option);

        // EXIT
        if(!option)
            break;
        
        // PUSH
        else if(option == 1) {
            printf("Type number to push: ");
            scanf("%d", &data);
            stack.push_back(data);
        }

        // POP
        else if(option == 2) {
            if(stack.empty()) {
                printf("ERROR: stack is empty!\n\n");
                continue;
            }
            printf("Popped data: %d\n", stack.back());
            stack.pop_back();
        }

        else {
            printf("ERROR: wrong option!\n\n");
            continue;
        }

        printf("\nSTACK: ");
        for(int i=0; i<stack.size(); i++)
            printf("%d ", stack[i]);
        printf("\n\n");
    }
}