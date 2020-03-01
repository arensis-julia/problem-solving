/* MST */
// Total weight of edges should be minimum
// Should only use n-1 edges for graph with n vertices
// Should have no cycle

/* KRUSKAL MST */
// sort edges in ascending order of each weights
// from the sorted list, choose edge which does not form a cycle

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <stdio.h>
using namespace std;

typedef struct NODE {
    int v1;
    int v2;
    int w;
}node;

int tree[100100];
vector<node> list;

bool compare(node a, node b) {      // sorting method
    return a.w < b.w;
}

int find(int p) {
    if(tree[p] == -1)
        return p;
    tree[p] = find(tree[p]);
    return tree[p];
}

bool isCycle(int a, int b) {        // check if edge forms cycle
    a = find(a);
    b = find(b);
    if(a == b)
        return true;
    tree[b] = a;
    return false;
}

int main() {
    int v, e, option, sum = 0;
    node tmp;

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

    printf("===== GRAPH INFO =====\n");
    printf("(e.g. v1 v2 weight)\n");
    if(!option) {
        for(int i=0; i<e; i++) {
            tmp.v1 = rand() % v;
            tmp.v2 = rand() % v;
            tmp.w = rand();
            printf("%d %d : %d\n", tmp.v1, tmp.v2, tmp.w);
            list.push_back(tmp);
        }
    }
    else {
        for(int i=0; i<e; i++) {
            scanf("%d %d %d", &tmp.v1, &tmp.v2, &tmp.w);
            list.push_back(tmp);
        }
    }

    /* SORTING */
    sort(list.begin(), list.end(), compare);

    /* MAKING TREE */
    for(int i=0;i<=v;i++)   tree[i] = -1;           // initialize

    printf("\n===== MST =====\n");
    for(int i=0, cnt=0; i < e && cnt < v-1; i++) {
        tmp = list[i];
        bool c = isCycle(tmp.v1, tmp.v2);
        if(!c) {
            printf("%d %d : %d\n", tmp.v1, tmp.v2, tmp.w);
            sum += tmp.w;
            cnt++;
        }
    }

    printf("\nSUM: %d\n", sum);

    return 0;
}