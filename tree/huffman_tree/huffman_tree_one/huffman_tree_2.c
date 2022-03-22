#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int left_child;
  int right_child;
  int parent;
  int weight;
}Node, *HuffmanTree;
typedef char* HuffmanCode;
void Select(HuffmanTree* huffman_tree, int n, int* s1, int* s2) {
  int min = -1; // -1为默认值
  for (int i = 0; i < n; i++) {
    if ((*huffman_tree)[i].parent == 0) {
      min = i;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if ((*huffman_tree)[i].parent == 0) {
      if ((*huffman_tree)[i].weight < (*huffman_tree)[min].weight) {
        min = i;
      }
    }
  }
  *s1 = min;
  for (int i = 0; i < n; i++) {
    if ((*huffman_tree)[i].parent == 0 && i != (*s1)) {
      min = i;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if ((*huffman_tree)[i].parent == 0 && i != (*s1)) {
      if ((*huffman_tree)[i].weight < (*huffman_tree)[min].weight) {
        min = i;
      }
    }
  }
 *s2 = min;
}//huffman_tree构建哈夫曼树, int w[]字符数组,  int n节点的个数
void CreateHuffmanTree(HuffmanTree* huffman_tree, int w[], int n) {
  int m = 2 * n - 1;
  *huffman_tree = (HuffmanTree)malloc(sizeof(Node) * (m + 1));
  for (int i = 1; i <= n; i++) {
    (*huffman_tree)[i].weight = w[i];
    (*huffman_tree)[i].parent = 0;
    (*huffman_tree)[i].left_child = 0;
    (*huffman_tree)[i].right_child = 0;
  }
  for (int i = n + 1; i <= m; i++) {
    (*huffman_tree)[i].weight = 0;
    (*huffman_tree)[i].parent = 0;
    (*huffman_tree)[i].left_child = 0;
    (*huffman_tree)[i].right_child = 0;
  }
  int s1 = -1;
  int s2 = -1;//默认值
  for (int i = n + 1; i <= m; i++) {  
    Select(huffman_tree, n, &s1, &s2); //这个传参n很巧妙,刚好把新构建的节点加进去了
    (*huffman_tree)[s1].parent = i;
    (*huffman_tree)[s2].parent = i;
    (*huffman_tree)[i].left_child = s1;
    (*huffman_tree)[i].right_child = s2;
    (*huffman_tree)[i].weight = (*huffman_tree)[s1].weight + (*huffman_tree)[s2].weight;
  }
  return ;
}

void CreateHuffmanCode(HuffmanTree* huffman_tree, HuffmanCode *huffman_code, int n) {
  int p; //指向父节点
  int c; // 指向当前节点
  int start; //开始编码的位置
  char* cd = (char*)malloc(sizeof(char) * n); //辅助编码数组和start连用
  cd[n] = '\0';
  //有n个节点,最多有n-1个编码, 所以n个数组存刚刚好, 
  //从右往左编码,再用start指示,刚好不会有数组元素为空的情况
  huffman_code = (HuffmanCode*)malloc(sizeof(char *) * (n + 1));
  for (int i = 1; i <= n; i++) {
    start = n - 1;//从n-1位置开始,从右往左开始编码, 并且用start复制数组
    //根节点的父节点是0
    for (c = i, p = (*huffman_tree)[i].parent; p != 0; c = p, p = (*huffman_tree)[p].parent) {
      if ((*huffman_tree)[i].left_child == c) {
        cd[--start] = '0';
      }
      else {
        cd[--start] = '1';
      }
    }
    //每次编码构建完成
    huffman_code[i] = (char * )malloc(sizeof(char) * (n - start));//构建n-start个char空间,没有一丝的空间浪费
    strcpy(huffman_code[i], &cd[start]); //从cd的start开始复制,然后直到cd的'\0'
   }
  return ;
}
