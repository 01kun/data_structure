#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>

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
std::queue <int> que;

int visit[MAX] = { 0};
int FindVex( Graph *G, int u) {
  for (int i = 0; i < G->num_vex; i++) {
    if (G->vertex[i] == u) {
      return i;
    }
  }
}
int FirstAdj(Graph* G, int u) {
  for (int i = 0; i < G->num_vex; i++) {
    if (G->edge[u][i] == 1) {
      return i;
    }
  }
  return -1;
}

int NextAdj(Graph* G, int u, int w) {
  for (int i = w + 1; i < G->num_vex; i++) {
    if (G->edge[u][i] == 1) {
      return i;
    }
  }
  return -1;
}
void BFS(Graph* G){
  for (int i = 0; i < G->num_vex; i++) {
    if (visit[i] == 0){  
      visit[i] = 1;           //i是顶点数组的第一个元素
      que.push(G->vertex[i]); //把元素入队
      while (!que.empty()) {  //如果队列不为空
        int u = que.front();
        que.pop(); //元素出队
        //找到元素所对应的下标
        u = FindVex( G, u); //u现在代表了这个顶点的下标
        //然后把顶点u相连的所有便全部入队
     
        //NextAdj和FirstAdj其实也就是寻找与顶点下标u相邻的所有边
        //w>=0作为判断条件是因为,找不到边返回的是-1;
        for (int w = FirstAdj(G, u); w >= 0; w = NextAdj(G, u, w)) {
          if (visit[u] == 0) {
            visit[u] = 1;
            que.push(G->vertex[w]);
          }
        }
        }

        
      }
    }
  }

}
