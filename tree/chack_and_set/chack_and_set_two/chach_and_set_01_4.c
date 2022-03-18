#include <stdio.h>
#include <stdlib.h>
//路径压缩
int node[100];
int rank[100];

//构建并查集
void MakeSet(int size) {
  for (int i = 0; i < size; i++) {
    node[i] = i;
    rank[i] = 0;
  }
}

//查询int i在并查集中的代表元素
int Find(int i) {
  if (i == node[i]) {
    return i;
  }
  else {
    return node[i] = Find(node[i]);
  }
}
//合并int i 和 int j这两个集合
void Unite(int i, int j) {
  int i = Find(i);
  int j = Find(j);
  if (i == j) {
    printf("i和j在同一个集合中\n");
    return;
  }
  else if(rank[i] > rank[j]) {
    node[j] = i;
  }
  else if (rank[i] < rank[j]) {
    node[i] = j;
  }
  else if (rank[i] == rank[j]) {
    node[i] = node[j];
    rank[j]++;
  }
}
