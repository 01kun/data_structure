#include <stdio.h>
#include <stdlib.h>

typedef struct ThreadTree {
  int data;
  struct ThreadTree *left, *right;
  int left_type, right_type;  //标志位0代表孩子, 1代表线索
}Node;
Node* pre_node ;
//线索化是在遍历一遍的基础上
//所以要先遍历
//遍历的过程中线索化
void InOrderThreadTree(Node* root) {
  if (root == NULL) {
    return;
  }
  InOrderThreadTree(root->left);
  //做线索化的事情
	//先处理左子树,然后再处理右子树
  //如果当前节点的左子树为NULL
  if (root->left == NULL) {
		root->left_type = 1;	//左子树为空就是指向线索的
	  root->left = pre_node;
  }
  if (pre_node != NULL && pre_node->right == NULL) {
    pre_node->right_type = 1;
    pre_node->right = root;
  }
  pre_node = root;
  
  InOrderThreadTree(root->right);
}

void InOrderTraverse(Node* root){
  if (root == NULL) {
    return;
  }
  while (root != NULL && root->left_type == 0) {
     root = root->left;
  }
  while (root != NULL) {
    root = root->right;
  }
}
