#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INITMAX 3242191
typedef struct {
  int vertex[MAX];
  int edge[MAX][MAX];
  int num_edge;
  int num_vertex;
}Graph;//这就是图

//Prim算法的核心是什么呀, 是顶点为核心
//两个辅助数组, 一个顶点数组, 一个最低权值数组

void Prim(Graph G) {
  int adj[MAX];  //记录顶点信息
  int low_cast[MAX];
  //随便选一个顶点作为起始顶点
  low_cast[0] = 0;
  adj[0] = 0;  //
  for (int i = 1; i < G.num_vertex; i++) {
    low_cast[i] = G.edge[0][i];
    adj[i] = 0;
  }
  //开始构建Prim算法
  
  for (int i = 0; i < G.num_vertex; i++) {
    int min = INITMAX; //记录权值最小的东西
    int k = 0;         //k记录下标
    int j =1;        
    //开始在第一个顶点相邻的所有顶点中选取有边且权值最小的
    //而且没有被标记的
    //low_cast[i] = 0; 是已经被标记的,最小生成树里面的顶i但
    //low_cast[i] < INITMAX 是有边的
    while (j < G.num_vertex) {
      if ( low_cast[j] != 0 && low_cast[j] < min) {
        min = low_cast[j];
        k = j;  //k就是与所有顶点相连的权值最小的顶点的下标
      }
      j++;
    } 
    //再次挑选k顶点和0顶点项链的所有的边中权值最小的, 更新low_cast数组
    for (int i = 0; i < G.num_vertex; i++) {
      if (low_cast[i] != 0 && G.edge[k][i] < low_cast[i]) {
        low_cast[i] = G.edge[k][i];
        //至此结束
        adj[i] = k; //在更新顶点数组
      }
    }
    
  }
}
