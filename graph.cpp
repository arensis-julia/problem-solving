#include <iostream>
#include <vector>
#include <ctime>
#include <stdio.h>
using namespace std;

vector<int> vert;
vector<int> list[1010];

void printGraph(int v) {
    printf("\n===== GRAPH =====\n");
    for(int i=0; i<v; i++) {
        printf("%d: ", vert[i]);
        for(int j=0; j<list[i].size(); j++) {
            printf("%d ", list[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int v, e, option, tmp;
    int a, b;

    srand((unsigned int)time(0));
    
    printf("How many vertices? ");
    scanf("%d", &v);
    printf("\n");

    printf("How many edges? ");
    scanf("%d", &e);
    printf("\n");

    printf("[0] Auto input\n");
    printf("[1] Manual input\n");
    scanf("%d", &option);
    printf("\n");

    printf("===== INSERTING VERTICES =====\n");
    if(!option) {
        for(int i=0; i<v; i++)
            vert.push_back(i);
        printf("vertices: ");
        for(int i=0; i<v; i++)
            printf("%d ", vert[i]);
        printf("\n\n");
    }
    else {
        for(int i=0; i<v; i++) {
            scanf("%d", &tmp);
            vert.push_back(tmp);
        }
    }


    printf("===== INSERTING EDGES =====\n");
    if(!option) {
        for(int i=0; i<e; i++) {
            a = rand() % e;
            b = rand() % e;
            list[a].push_back(b);
            list[b].push_back(a);
            printf("%d %d\n", a, b);
        }
    }
    else {
        for(int i=0; i<v; i++) {
            scanf("%d%d", &a, &b);
            list[a].push_back(b);
            list[b].push_back(a);
        }
    }

    printGraph(v);

    return 0;
}