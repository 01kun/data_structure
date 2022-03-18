#include <stdio.h>
#include <stdlib.h>
int uset[100];
//size为元素的个数
void MakeSet(int size) {
  for (int i = 0; i < size; i++) {
    uset[i] = i;
  }
}
//并查集的查询操作, 
//查询到的是并查集的根节点
int Find(int i) {
  if (i == uset[i]) return i;
  Find(uset[i]);
}
//并查集的并操作
//把x串到y上
//下标代表的是真实数据元素, 
//下标的值代表的是父节点
void Unite(int x, int y) {
  int a = Find(x);
  int b = Find(y);
  if (a == b) {
    printf("两个值所在的集合相同\n");
    return ;
  }
  else {
    uset[a] = b;
  }
}
