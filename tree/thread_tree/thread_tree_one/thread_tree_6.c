#include <stdio.h>
#include <stdlib.h>

typedef struct ThreadTree {
  int data;
  struct ThreadTree *left, *right;
  int left_type, right_type;
}Node;
Node* prev_node = NULL;
void InOrderThreadTree(Node* root) {
  if (root == NULL) {
    return;
  }
  InOrderThreadTree(root->left);
  if (root != NULL && root->left == NULL) {
    root->left_type = 1;
    root->left = prev_node;
  }
  if (prev_node != NULL && prev_node->right == NULL) {
    prev_node->right_type = 1;
    prev_node->right = root;
  }
  prev_node = root;
  InOrderThreadTree(root->right);
}

void InOrderTraverse(Node* root) {
  if (root == NULL) {
    return;
  }
  Node* temp =root;
  while (temp != NULL && temp->left_type == 0) {
    temp = temp->left;
  }
  while (temp != NULL) {
    printf("%d", temp->data);
    temp = temp->right;
  }
}
