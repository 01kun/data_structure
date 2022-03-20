#include <stdio.h>
#include <stdlib.h>
int uset[100];//并查集数组
//构建并查集数组
void MakeSet(int size) {
  for (int i = 0; i < size; i++) {
    uset[i] = i;
  }
}
//并查集的查询操作
int Find(int i) {
  if (i == uset[i]) {
    return i;
  }
  else {
     return Find(uset[i]);
  }
}
//并查集的合并操作
void Unite(int i, int j) {
  int i = Find(i);
  int j = Find(j);
  if (i == j) {
    pritnf("i和j在同一个集合中\n");
  }
  else {
    uset[i] = j; //i合并到j集合中
  }
}
