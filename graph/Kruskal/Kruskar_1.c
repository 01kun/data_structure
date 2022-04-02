#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define MAXDATA 2132314
//克鲁斯卡尔算法
typedef struct {
  int vertex[MAX];
  int edge[MAX][MAX];
  int num_edge;
  int num_vertex;
}Graph;

typedef struct {
  int head;
  int tail;
  int weight;
}Node;//边集数组

int FinkUniteKey(int* parent, int i) {
  //i是下标
  while (parent[i] > 0) {
    i = parent[i];
  } //迭代去查询并查集
  return i;
}

void Kruskal(Graph G) {
  Node node[MAX];  //边集数组
  int parent[MAX]; //父亲数组, 并查集
  
  int k;
  //用整个边集数组接收边的信息
  for (int i = 0; i < G.num_vertex; i++) {
    for (int j = 0; j < G.num_vertex; j++) {
      //判断是否有边
      if (G.edge[i][j] < MAXDATA) {
        //如果有边
        node[k].head = i;
        node[k].tail = j;
        node[k].weight = G.edge[i][j];
        k++;
      }
    }
  }
  //排序好整个边集数组
  //开始克鲁斯卡尔算法, 构建最小生成树
  for (int i = 0; i < G.num_vertex; i++) {
    parent[i] = 0;
  }//森林的状态
  //开始构建生成树,是针对于边来的
  //循环每一条边
  for (int i = 0; i < G.num_edge; i++) {
    int b = FinkUniteKey(parent, node[i].head);
    int e = FinkUniteKey(parent, node[i].tail);
    //如果不成环, 如果都是指向自身的节点树也不成环
    if (b != e  || b == e == 0) {
      parent[b] = e; //b树连接到e树上


      printf("这个点属于最小生成树的一部分%d%d%d",
        node[i].head, node[i].tail, node[i].weight);
      //至此结束
    }
  }

  
}
