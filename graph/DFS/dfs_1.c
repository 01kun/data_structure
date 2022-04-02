#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct {
  int edge[MAX][MAX];
  int vertex[MAX];
  int num_vex;
  int num_edge;
}Graph;

void CreateAdjMatrix(Graph* G) {
  printf("%顶点和边的数量\n");
  scanf_s("%d%d", &G->num_vex, &G->num_edge);
  //初始化邻接矩阵
  for (int i = 0; i < G->num_vex; i++) {
    for (int j = 0; j < G->num_vex; j++) {
      if (i == j) {
        G->edge[i][j] = 1;
      }
      else {
        G->edge[i][j] = 32767;
      }
    }
  }
  //初始化顶点数组
  for (int i = 0; i < G->num_vex; i++) {
    printf("请输入顶点数据\n");
    scanf_s("%d", &G->vertex[i]);
  }
  int vi, vj;
  for (int i = 0; i < G->num_edge; i++) {
    printf("请输入边的信息\n");
    scanf_s("%d%d", &vi, &vj);
    G->edge[vi][vj] = 1;
    G->edge[vj][vi] = 1;
  }
}
int visit[MAX] = {0};

void DFSTraverse(Graph* G, int i) {
  for (int j = 0; j < G->num_vex; j++) {
    if (G->edge[i][j] == 1 && visit[j]) {
      DFSTraverse(G, j);
    }
  }
}
void DFS(Graph* G) {
  for (int i = 0; i < G->num_vex; i++) {
    //这个for循环, DFS顶点个数, 访问第一个节点, 访问第二个节点
    if (visit[i] == 0) {
      visit[i] = 1;
      DFSTraverse(G, i);
    }
  }
}
