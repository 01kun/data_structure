#include "Tree.h"
#include <iostream>
//睡醒后记得写注释和Debug
Node* Tree::GetNewNode(int key) {
  Node* new_node = new Node(key, nullptr, nullptr);
  if (new_node == nullptr) {
    std::cout << "新节点new_node内存申请失败,准备退出"<<std::endl;
    exit(0);
  }
  std::cout <<"新节点new_node内存申请成功"<<std::endl;
  return new_node;
}
Node* Tree::LLRotation(Node* root) {
  Node* temp = root->left_;
  root->left_ = temp->right_;
  temp->right_ = root;
  temp->height_ = Max(Height(temp->left_),Height(temp->right_));
  root->height_ = Max(Height(root->left_),Height(root->right_));
  return temp;
}
Node* Tree::RRRotation(Node* root) {
  Node* temp = root->right_;
  root->right_ = temp->left_;
  temp->left_ = root;
  temp->height_ = Max(Height(temp->left_), Height(temp->right_));
  root->height_ = Max(Height(root->left_), Height(root->right_));
  return temp;
}
Node* Tree::RLRotation(Node* root) {
  root->right_ = LLRotation(root->right_);
  root = RRRotation(root);
  root->right_->height_ = Max(Height(root->right_->left_),Height(root->right_->right_));
  root->height_ = Max(Height(root->right_), Height(root->left_));
  return root;
}
Node* Tree::LRRotation(Node* root) {
  root->left_ = RRRotation(root->right_);
  root = LLRotation(root);
  root->left_->height_ = Max(Height(root->left_->left_), Height(root->left_->right_));
  root->height_ = Max(Height(root->right_), Height(root->left_));
  return root;
}
void  Tree::DeleteAvlNode(int key) {
  root_ = DeleteAvlNode(root_,key);
  return;
}
void  Tree::InsertAvlNode(int key) {
  root_ = InsertAvlNode(root_,key);
}
Node* Tree::InsertAvlNode(Node* root, int key) {
  if (root == nullptr) {
    root = GetNewNode(key);
  }
  else if (key < root->data_) {
    root->left_ = InsertAvlNode(root->left_, key);
    if (Height(root->left_) - Height(root->right_) == 2) {
      if (key < root->left_->data_) {
        root = LLRotation(root);
      }
      else {
        root = LRRotation(root);
      }
    }
  }
  else if (key > root->data_) {
    root->right_ = InsertAvlNode(root->right_, key);
    if (Height(root->right_) - Height(root->left_)) {
      if (key > root->data_) {
        root = RRRotation(root);
      }
      else {
        root = RLRotation(root);
      }
    }
  }
  root->height_ = Max(Height(root->left_), Height(root->right_));
  return root;
}
Node* Tree::DeleteAvlNode(Node* root, int key) {
  if (root == nullptr) {
    return root; //这个节点高度要不要更新
  }
  else if (key > root->data_) {
    root->right_ = DeleteAvlNode(root->right_, key);
    if (Height(root->left_) - Height(root->right_) == 2) {
      if (root->left_->left_ != nullptr) {
        root == LLRotation(root);
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
  else if (key == root->data_) {
    if (root->left_ == nullptr && root->right_ == nullptr) {
      delete root;
      root = nullptr;
    }
    else if (root->left_ == nullptr) {
      Node* temp = root;
      root = root->right_;
      delete temp;
      temp = nullptr;
    }
    else if (root->right_ == nullptr) {
      Node* temp= root;
      root = root->left_;
      delete temp;
      temp = nullptr;
    }
    else {
      Node* temp = root->right_;
      while (temp->left_ != nullptr) {
        temp = temp->left_;
      }
      root->data_ = temp->data_;
      root->right_ = DeleteAvlNode(root->right_, temp->data_);
    }
  }
  root->height_ = Max(Height(root->left_), Height(root->right_));
  return root;
}
Tree::Tree() : root_(nullptr) {
  std::cout <<"Tree默认构造函数的调用" <<std::endl;
}
Tree::~Tree() {
  root_ = DeleteAllNode(root_);
  delete root_;
  root_ = nullptr;
  std::cout <<"Tree析构函数的调用" <<std::endl;
}
Node* Tree::DeleteAllNode(Node* root) {
  if (root == nullptr) {
    return;
  }
  else if (root->left_ == nullptr && root->right_ == nullptr) {
    delete root;
    root = nullptr;
  }
  DeleteAllNode(root->left_);
  DeleteAllNode(root->right_);
}
void Tree::PrintAvlTree() {
  PrintAvlNode(root_);
  std::cout <<root_->data_ <<std::endl;
  std::cout <<"打印树中所有节点完成" <<std::endl;
}
void Tree::PrintAvlNode(Node* root) {
  if (root == nullptr) {
     return;
  }
  PrintAvlNode(root->left_);
  std::cout << root->data_<<" ";
  PrintAvlNode(root->right_);
  
}
//睡醒后记得写注释和Debug
