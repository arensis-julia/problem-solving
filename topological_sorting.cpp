#include <iostream>
#include <vector>
#include <ctime>
#include <stdio.h>
using namespace std;

vector<int> vert;
vector<int> list[1010];
vector<int> stack;
int chk[1010];

void dfs(int cur) {
    chk[cur] = 1;
    for(int i=0; i<list[cur].size(); i++) {
        if(chk[i] == 0)
            dfs(i);
    }
    stack.push_back(cur);
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
            printf("%d %d\n", a, b);
        }
    }
    else {
        for(int i=0; i<e; i++) {
            scanf("%d%d", &a, &b);
            list[a].push_back(b);
        }
    }

    for(int i=0; i<v; i++) {
        if(chk[i] == 0)
            dfs(i);
    }

    printf("\n===== TOPOLOGICAL SORTING =====\n");
    for(int i=0; i<stack.size(); i++)
        printf("%d ", vert[stack[i]]);
    printf("\n");

    return 0;
}