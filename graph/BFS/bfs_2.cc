#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#define MAX 100

typedef struct {
  int vertex[MAX];
  int edge [MAX][MAX];
  int num_vertex;
  int num_edge;
}Graph;
int visit[MAX];

int LocateVex(Graph* G, int u) {
  for (int i = 0; i < G->num_vertex; i++) {
    if (G->vertex[i] == u) {
      return i;
    }
  }
  return -1;
}

int FirstVex(Graph* G, int u) {
  for (int i = 0; i < G->num_vertex; i++) {
    if (G->edge[u][i] == 1) {
      return i;
    }
  }
  return -1;
}
//第二个相邻节点从w开始, 因为w是第一个相邻节点, 
//w之前的顶点全部都被访问过了
int NextVex(Graph* G, int u, int w) {
  for (int i = w + 1; i < G->num_vertex; i++) {
    if (G->edge[u][i] == 1) {
      return i;
    }
  }
  return -1;
}
void BFS(Graph* G) {
  std::queue<int> que;
  for (int i = 0; i < G->num_vertex; i++) {
    //如果节点没有被访问, 就把他加入队列当中, 然后出队, 所有相邻顶点入队
    //如果节点已经被访问, 那就退出
    if (!visit[i]) {
      visit[i] = 1;
      que.push(G->vertex[i]);
      while (!que.empty()) {
        que.pop(); //弹出来然后把它的子节点全部加入到当中当中去
        int u;    //u就当是弹出来的元素把
        int u = LocateVex(G, u); //u就是下标
        //现在是要把顶点u(下标)所相邻的所有元素全部添加到队列当中昂

        //FIrst访问的是相邻的第一个节点, NextVex是访问的相邻的第二个顶点

        for (int  w = FirstVex(G, u); w > 0; w = NextVex(G, u, w)) {
          //还要判断是否被访问过
          if (!visit[w]) {
            visit[w] = 1;
            que.push(G->vertex[w]);

          }
        }
      }
    }
    //如果队列不为空
    
  }
}
