#include <stdio.h>
#include <stdlib.h>
int node[100];
int rank[100];
//构建路径压缩并查集
void MakeSet(int size) {
  for (int i = 0; i < size; i++) {
    node[i] = i;
    rank[i] = 0;
  }
}
//路径压缩的查询操作
//其中return node[i] = Find(node[i])这个很巧妙
int Find(int i) {
  if (i == node[i]) {
    return i;
  }
  else {
    return node[i] = Find(node[i]);
  }
}
//路径压缩的合并操作
void Unist(int i, int j) {
  int i = Find(i);
  int j = Find(j);
  if (i == j) {
    printf("i和j在同一个集合当中\n");
    return;
  }
  if (rank[i] < rank[j]) {
    node[i] = j;
  } 
  else {
    node[j] = i;
  }
  rank[j]++;
  return;

}
