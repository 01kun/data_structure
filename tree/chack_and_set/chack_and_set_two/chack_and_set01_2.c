#include <stdio.h>
#include <stdlib.h>

//并查集路径压缩
node[100];
rank[100];
//构建并查集数组
void MakeSet(int size) {
  for (int i = 0; i < size; i++) {
    node[i] = i;
    rank[i] = 0;
  }
}
//并查集查询操作(路径压缩)
//查询i的代表元素
int Find(int i){
  if (i == node[i]) {
    return i;
  }
  else {
    return node[i] = Find(node[i]); //再一次查询的时候, 就把节点连接到根节点上
                                    //路径也压缩了
  }
}

void Unite(int i, int j) {
  int i = Find(i);
  int j = Find(j);//是X和Y又被重新赋值?还是这两个i和j互不相干?
  if (i == j) {
    printf("i和j在同一棵树上\n");
    return;
  }
  //如果i树比j树高
  else if (rank[i] > rank[j]) {
    node[j] = i;
  }
  //如果i树没有j树高
  else if (rank[i] < rank[j]) {
    node[i] = j;
  }
  //如果i树和j树一样高, 把i树连到j树上
  //并增加树的高度
  else if (rank[i] == rank[j]) {
    node[i] = j;
    rank[j]++;
  }
}
