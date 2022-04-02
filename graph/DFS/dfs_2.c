#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct {
  int vertex[MAX];
  int edge[MAX][MAX];
  int num_vex;
  int num_edge;
}Graph;

int visit[MAX] = {0};
//递归遍历所有的顶点
void DFSTraverse(Graph *G, int i) {
  for (int j = 0; j < G->num_vex; j++) {
    if (G->edge[i][j] == 1 && visit[j] == 0) {  
      visit[j] = 1;
      DFSTraverse(G,j);
    }
  }
}


void DFS(Graph* G) {
  for (int i = 0; i < G->num_vex; i++) {
    if (!visit[i]) { //如果i没有被访问过
      visit[i] = 1;
      DFSTraverse(G, i); //深度遍历i的连通分量
    }
  }
}
