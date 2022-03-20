#include <stdio.h>
#include <stdlib.h>
//路径压缩
int node[100];
int rank[100];
void MakeSet(int size) {
  for (int i = 0; i < size; i++) {
    node[i] = i;
    rank[i] = 0;
  }
}
int Find(int i) {
  if (i == node[i]) {
    return i;
  }
  else {
    return node[i] = Find(node[i]);
  }
}

void Unite(int i, int j) {
  int i = Find(i);
  int j = Find(j);
  if (i == j) {
    printf("i和j在同一个集合当中\n");
    return;
  }
  else if (rank[i] < rank[j]) {
    node[i] = j;
  } 
  else if( rank[i] > rank[j]) {
    node[j] = i;
  }
  else {
    node[i] = j;
    rank[j]++;
  }
  return;
}
