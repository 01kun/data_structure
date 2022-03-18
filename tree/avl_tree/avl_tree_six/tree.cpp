#include "Tree.h"
#include <iostream>
int Tree::Max(int a, int b){
  return (a>b)? a:b;
}

int Tree::Height(Node* root){
  if(root == nullptr) return 0;
  return root->height_;
}

Node* Tree::LLRotation(Node* root){
  Node* node = root->left_;
  root->left_ = node->right_;
  root->right_ = root;
  root->height_ = Max(Height(root->left_), Height(root->right_));
  node->height_ = Max(Height(node->left_), Height(root->right_));
  return node;
}

Node* Tree::RRRotation(Node* root){
  Node* node = root->right_;
  root->right_ = node->left_;
  node->left_ = root;
  root->height_ = Max(Height(root->left_), Height(root->right_));
  node->height_ = Max(Height(root->left_), Height(root->right_));
  return node;
}

Node* Tree::LRRotation(Node* root){
  root->left_ = RRRotation(root->left_);
  root = LLRotation(root);
  root->left_->height_ = Max(Height(root->left_->left_), Height(root->left_->right_));
  root->height_ = Max(Height(root->left_), Height(root->right_));
  return root;
}

Node* Tree::RLRotation(Node* root) {
  root->right_ = LLRotation(root->right_);
  root = RRRotation(root);
  root->right_->height_ = Max(Height(root->right_->left_), Height(root->right_->right_));
  root->height_ = Max(Height(root->left_), Height(root->right_));
  return root;
}

Node* Tree::GetNewNode(int key){
  Node* new_node = new Node(key, nullptr, nullptr);
  if (new_node == nullptr)  {
    std::cout <<"newnode(GetNewNode函数)新节点内存申请失败,准备退出"<<std::endl;
    exit(0);
  }
  else {
    return new_node;
  }
}

void Tree::DeleteAvlNode(int key)
{
  //这个地方再梳理
  root_ = DeleteAvlNode(root_, key);
  return;
}

void Tree::InsertAvlNode(int key) {
  root_ = InsertAvlNode(root_, key);
  return;
}

Node* Tree::InsertAvlNode(Node* root, int key) {
  if (root == nullptr) {
    root = GetNewNode(key);
  }
  else if (key < root->data_) {
    root->left_ = InsertAvlNode(root->left_, key);
    if (Height(root->left_) - Height(root->right_) == 2) {
      root = LLRotation(root);
    }
    else {
      root = LRRotation(root);
    }
  }
  else if (key > root->data_) {
    root->right_ = InsertAvlNode(root->right_, key);
    if (Height(root->right_) - Height(root->left_) == 2) {
      if (key < root->right_->data_) {
        root = RLRotation(root);
      }
      else {
        root = RRRotation(root);
      }
    }
  }
  root->height_ = Max(Height(root->left_), Height(root->right_));
  return root;
}

Node* Tree::DeleteAvlNode(Node* root, int key) {
  if (root == nullptr) {
    return root;
  }
  else if (key > root->data_) {
    root->right_ = DeleteAvlNode(root->right_, key);
    if (Height(root->left_) - Height(root->right_) == 2) {
      if (root->left_->left_ != nullptr) {
        root = LLRotation(root);
      }
      else {
        root = LRRotation(root);
      }
    }
  }
  else if (key < root->data_) {
    root->left_ = DeleteAvlNode(root->left_, key);
    if (Height(root->right_) - Height(root->left_) == 2) {
      if (root->right_->right_ != nullptr) {
        root = RRRotation(root);
      }
      else {
        root = RLRotation(root);
      }
    }
  }
  else {
    if (root->left_ == nullptr && root->right_ == nullptr) {
      delete root;
      root = nullptr;
    }
    else if (root->left_ == nullptr){
      Node* temp =root;
      root = root->right_;
      delete temp;
      temp = nullptr;
    }
    else if (root->right_ == nullptr) {
      Node* temp = root;
      root = root->left_;
      delete temp;
      temp = nullptr;
    }
    else {
      Node* temp = root->right_;
      while (temp->left_ != nullptr) {
         root= root->left_;
      }
      root->data_ = temp->data_;
      root->right_ = DeleteAvlNode(root->right_, temp->data_);
    }
  }
  root->height_ = Max(Height(root->left_), Height(root->right_));
  return root;
}

void Tree::DeleteAllNode(Node* root){
  if (root == nullptr) {
    return ;
  }
  else if (root->left_ == nullptr && root->right_ == nullptr) {
    delete root;
    root = nullptr;
  }
  DeleteAllNode(root->left_);
  DeleteAllNode(root->right_);
}

Tree::~Tree() {
  DeleteAllNode(root_);
  delete root_;
  root_  = nullptr;
  std::cout <<"Tree析构函数的调用" <<std::endl;
  return ;

}
Tree::Tree() : root_(nullptr) {}
