#include <stdio.h>
#include <stdlib.h>

typedef struct ThreadTree {
  struct ThreadTree *left, *right;
  int data;
  int left_type, right_type;
}Node;
Node* prev_node = NULL;
//线索化
void InOrderThreadTree(Node* node){
  if (node == NULL) {
    return;
  }
  InOrderThreadTree(node->left);
  //左子树
  if (node != NULL && node->left == NULL) {
    node->left_type = 1;
    node->left = prev_node;
  }
  //右子树
  if (prev_node != NULL && prev_node->right == NULL) {
    prev_node->right_type = 1;
    prev_node->right = node;
  }
  prev_node = node;
  InOrderThreadTree(node->right);
}

//遍历
void InOrderTraverse(Node* node) {
  if (node == NULL) {
    return;
  }
  while (node != NULL && node->left_type == 0) {
    node = node->left;
  }
  //已经到了最左边
  while (node != NULL) {
    printf("%d", node->data);
    node = node->right;
  }
}
