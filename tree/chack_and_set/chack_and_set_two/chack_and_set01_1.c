#include <stdio.h>
#include <stdlib.h>
//并查集的路径压缩
//把树低的集合加到树高的集合上面

int node[100]; //节点
int rank[100]; //高度
//一开始大家的高度都是0
//并查集的建立
void MakeSet(int size) {
  for (int i = 0; i < size; i++) {
    node[i] = i;
    rank[i] = 0;
  }
}

//并查集的查询操作
//查询某个元素在哪一个集合
//i == node[i]
//下标代表真实数据元素, 下标的值代表父节点
//返回的是真实数据元素, 
int Find(int i) {
  if (i == node[i]) {
    return i;
  }
  else { 
    return node[i] = Find(node[i]); //在第一次查找时,就将节点直接连接到根节点
        //画一下图
  }
}

//返回的
void Uinte(int x, int y) {
  int a = Find(x);
  int b = Find(y);
  if (a == b) {
    printf("x和y在同一集合,合并操作失败\n");
  }
  //判断两棵树的高度,决定谁是谁的子树
  if (rank[a] < rank[b]) {
    node[a] = b; 
  }
  else if (rank[a] < rank[b]) {
    node[b] = a;
  } 
  else if (rank[a] == rank[b]) {
    node[a] = b;
    rank[a]++;
    //如果两棵树的高度相同,合并后更新树的高度
  }
  
}

