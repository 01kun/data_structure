#include <stdio.h>
#include <stdlib.h>
typedef struct ThreadTree {
  struct ThreadTree *left, *right;
  int data;
  int left_tag, right_tag; //0代表孩子, 1代表线索
}Node;

Node* pre = NULL;// 设定一个跟随的指针
//节点在前面跑,
//线索化的过程,是一个什么样的过程呢
//是在插入的过程中
//线索化建立在遍历一遍的基础上
void InOredeThreadTree(Node* node){
  if (node == NULL) {
    return;
  }
  InOredeThreadTree(node->left);
  //线索化过程,先处理前驱节点
  //如何去找我的前驱,可以通过当前节点来找
  if (node->left == NULL) {
    node->left_tag = 1;
    node->left = pre;
  }
  //如果右子节点为NULL,处理前驱的右指针
  //找后继只能通过前驱节点来找
  if (pre != NULL && pre->right == NULL) {
    pre->right_tag = 1;
    pre->right = pre;
  }
  pre = node;

  //最后处理右子树
  InOredeThreadTree(node->right);
}

//遍历
//找到我的最左边然后持续往后访问就好了

void InOrederTraverse(Node* node) {
  if (node == NULL) {
     return;
  }
  while (node != NULL && node->left_tag == 0) {
    node = node->left;
  }
  //然后再向右不断遍历
  //线索化就是解决递归遍历需要占用系统栈
  
}
