#include <stdio.h>
#include <stdlib.h>

//路径压缩
//在特殊情况下,这棵树会变成个长长的链表
//改进方法:把遍历过的节点全部改为根的子节点
int node[100];//每个节点
int rank[100];//树的高度


void MakeSet(int size) {
  for (int i = 0; i < size; i++) {
    node[i] = i;
    rank[i] = 0;//树的高度一开始都是0
  }
}

int Find(int x) {
  if(x == node[x]){
    return x;
  }
  else node[x] = Find(node[x]); 
  //node[x] = 最后递归回来的值
  //直接就把代表节点结果给我了
}


//并操作,先判定两棵树的高度,再决定谁是谁的子树

void Unite(int x, int y) {
  int a = Find(x);
  int b = Find(y);
  if (a == b) {
    return;
  }
  else if (rank[x] < rank[y]) {
    node[x] = y;
  }
  else {
    node[y] = x;
    if (rank[x] == rank[y]) {
      rank[x] ++;
    }
  }
  //判断两棵树的告诉, 决定谁是谁的子树
  //针对集合和集合之间你的合并
  //决定谁高谁就当子树,就可以减少我们查询的次数
  //
  //路径压缩的方法有很多,这边是根据高度写的
  
}
