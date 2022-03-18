#include <stdio.h>
#include <stdlib.h>
int uset[100]; //并查集数组
//建立并查集数组
//size代表元素的个数大小
void MakeSet(int size) {
  for (int i = 0; i < size; i++) {
    uset[i] = i;//下标代表真实数据元素, 下标的值代表父节点的坐标, 参考双亲表示法
  }
}
//并查集的查询操作
//查询key在树中的代表元素
int Find(int i) {
  if (i == uset[i]) {
    return i;
  }
  else{
    return Find(uset[i]);
  }
}
//并查集的合并操作
//把X树合并到Y树上面
void Unite(int x, int y) {
  int a = Find(x);
  int b = Find(y);
  if (a == b) {
    printf("x和y在同一个集合\n");
  }
  else {
    //a是X的代表元素, 则a = uset[a]
    //a合并到b树上, 则uset[a] = b;
    uset[a] = b;
  }
}
