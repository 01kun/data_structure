#include <stdio.h>
#include <stdlib.h>

int uset[100];

void MakeSet(int size) {
  for (int i = 0; i < size; i++) {
    uset[i] = i;
  }
}

int Find(int i) {
  if (i == uset[i]) {
    return i;
  }
  return Find(uset[i]);
}

void Unite(int i, int j) {
  int i = Find(i);
  int j = Find(j);
  if (i == j) {
    printf("i和j在同一个集合中\n");
  }
  else {
    uset[i] = j;
  }
  return;
}
