#include <stdio.h>
#include <stdlib.h>
//二叉线索树的结构体
typedef struct ThreadTree {
  struct ThreadTree *left, *right;
  int data;
  int left_type, right_type; //孩子标记为0, 线索标记为1
}Node;
Node* prev_node = NULL;
//线索化的过程中需要遍历一遍
void InOredeThreadTree(Node* root) {
  if (root == NULL) {
    return;
  }
  InOredeThreadTree(root->left);
  //处理左子树
  if (root->left == NULL && root != NULL) {
    root->left = prev_node;
    root->left_type = 1;
  }
  //处理右子树
  if (prev_node != NULL && prev_node->right == NULL) {
    prev_node->right = root;
    prev_node->right_type = 1;
  }
  prev_node = root;
  InOredeThreadTree(root->right);
}
//线索化之后进行遍历
void ThreadTreeTraverse(Node* root) {
  if (root == NULL) {
    return;
  }
  Node* temp = root;
  while (temp->left_type = 0 && temp != NULL) {
    temp = temp->left;
  }
  while (temp != NULL) {
    pritnf("%d", temp->data);
    temp = temp->right;
  }
}
