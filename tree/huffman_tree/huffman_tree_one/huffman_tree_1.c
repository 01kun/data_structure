#include <stdio.h>
#include <stdlib.h>
//先构建哈夫曼树,再编出哈夫曼编码
typedef struct {
  int left_child;
  int right_child;
  int parent;
  int weight;
}Node, *HuffmanTree;
//HuffmanTree是一个指针,指向结构体, Node是一个结构体
typedef char* HuffmanCode;
void Select(HuffmanTree* huffman_tree, int n, int* s1, int* s2) {
  int min;
  for (int i = 1; i <= n; i++) {
    if ((*huffman_tree)[i].parent == 0) {
      min = i;
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    if ((*huffman_tree)[i].parent == 0) {
      if ((*huffman_tree)[i].weight < (*huffman_tree)[i].weight) {
        min = i;
      }
    }
  }
  *s1 = min;
  for (int i = 1; i <= n; i++) {
    if ((*huffman_tree)[i].parent == 0 && (*s1) != i) {
      min = i;
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    if ((*huffman_tree)[i].parent == 0 && (*s1) != i)  {
      if ((*huffman_tree)[i].weight < (*huffman_tree)[i].weight) {
        min = i;
      }
    }
  }
  *s2 = min;
  return;
}
//这是构建哈夫曼树
void CreateHuffmanTree(HuffmanTree *huffman_tree, int w[], int n) {
  //int n字符/叶子节点的个数, int m树中所有节点的个数
  int m = 2 * n -1;
  //使用HuffmanTree也很巧妙,使用指针的指针,避免信息丢失, 传递信息也更方便
  *huffman_tree = (Node*)malloc(sizeof(Node)*(m+1)); 
  //初始化字符节点/非叶子节点
  for (int i = 1; i <= n; i++) {
    (*huffman_tree)[i].left_child = 0;
    (*huffman_tree)[i].right_child = 0;
    (*huffman_tree)[i].parent = 0;
    (*huffman_tree)[i].weight = w[i];
  }
  //初始化非叶子节点, 
  for (int i = n + 1; i <= m; i++) {
    (*huffman_tree)[i].left_child = 0;
    (*huffman_tree)[i].right_child = 0;
    (*huffman_tree)[i].parent = 0;
    (*huffman_tree)[i].weight = 0;
  }
  int s1, s2;
  //构建树中节点的连接信息
  for (int i = n + 1; i <= m; i++) {
    Select(huffman_tree,i -1, &s1, &s2); //传入i-1很巧妙,把每次构建好的哈夫曼节点传入了进入
    (*huffman_tree)[i].left_child = s1;
    (*huffman_tree)[i].right_child = s2;
    (*huffman_tree)[s1].parent = i;
    (*huffman_tree)[s2].parent = i;
    (*huffman_tree)[i].weight = (*huffman_tree)[s1].weight + (*huffman_tree)[s2].weight;
  }
}

void CreateHuffmanCode(HuffmanTree* huffman_tree, HuffmanCode* huffman_code, int n) {
  char* cd = (char*)malloc(sizeof(char)* n);//辅助字符数组
  huffman_code = (HuffmanCode*)malloc(sizeof(char*) * (n+ 1)); //创建(n+1)个指向char*的指针区域
  cd[n-1] = '\0';
  int c; //指向当前节点
  int p;//指向父节点
  int start; //开始编码位置
  for (int i = 1; i <= n; i++) {
    start = n -1;
    for (c = i, p = (*huffman_tree)[i].parent; p != 0; c = p, p = (*huffman_tree)[p].parent) {
      if ((*huffman_tree)[p].left_child == c) {
        cd[--start] = '0';
      }
      else {
        cd[--start] = '1';
      }
    }
    huffman_code[i] = (char*)malloc(sizeof(char)*(n -start));
    strcpy(huffman_code[i], &cd[start]);
  }
}
