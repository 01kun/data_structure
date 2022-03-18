#include <stdio.h>
#include <stdlib.h>

//二叉线索树的结构体
typedef struct ThreadTree {
  int data;
  struct TreadTree *left, *right;
  int left_type,right_type;  //标记,如果是孩子标记为0, 如果是线索标记为1
}Node;
Node* prev_node = NULL;
//将二叉排序树线索化,二叉树需要遍历一遍才能够线索化
void InOrderThreadTree(Node* root) {
  if (root == NULL) {
    return ;
  }
  InOrderThreadTree(root->left);
  //处理左子树, 用root指向前驱prev
  if (root->left == NULL) {
    root->left_type = 1; //标记为线索
    root->left = prev_node;
  }
  //处理右子树, 用prev指向后继(root)
  if (prev_node != NULL && prev_node->right == NULL) {
    prev_node->right_type = 1; //标记为线索
    prev_node->right = root;  
  }
  prev_node = root;   //更新前驱
  InOrderThreadTree(root->right);
}
