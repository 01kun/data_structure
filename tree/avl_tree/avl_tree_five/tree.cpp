#include "Tree.h"
#include <iostream>
//Tree默认构造函数, 初始化成员变量
Tree::Tree() : root_(nullptr) {
  std::cout << "Tree默认构造函数的调用" << std::endl;
}

//~Tree析构函数, 释放掉AvlTree中的所有Node内存块
Tree::~Tree() {
  DeleteAllNode(root_);
  root_ = nullptr;
  std::cout << "Tree析构函数的调用" << std::endl;
}
//GetNewNode函数, 在堆区申请一个Node内存块, 并初始化Node内存块
//int key待插入内存块中的数据
//
Node* Tree::GetNewNode(int key) {
  Node* new_node = new Node(key, nullptr, nullptr);
  if (new_node == nullptr) {
    std::cout << "新节点new_node内存申请失败, 准备退出, 函数GetNewNode()" << std::endl;
    exit(0);
  }
  return new_node;
}
//Max函数, 返回a和b中的较大值, 用于判断更新树的高度
int Tree::Max(int a, int b) {
  if (a > b) {
    return a;
  }
  else {
    return b;
  }
}
//Height函数,用于得到节点的高度
//Node* root待判断的节点(高度)
int Tree::Height(Node* root) {
  if (root == nullptr) {
    return 0;
  }
  else {
    return root->height_;
  }
}
//LLInsertRotation函数, 对于LL型插入操作引起的失衡,进行旋转
//Node* root 失衡的节点
Node* Tree::LLInsertRotation(Node* root) {
  Node* temp = root->left_;
  root->left_ = temp->right_;
  temp->right_ = root;
  root->height_ = Max(Height(root->left_), Height(root->right_)) + 1;
  temp->height_ = Max(Height(temp->left_), Height(root->right_)) + 1;
  return temp;
}
//RRInsertRotation函数, 对于RR型插入操作引起的失衡,进行旋转
//Node* root 失衡的节点
Node* Tree::RRInsertRotation(Node* root) {
  Node* temp = root->right_;
  root->right_ = temp->left_;
  temp->left_ = root;
  root->height_ = Max(Height(root->left_), Height(root->right_)) + 1;
  temp->height_ = Max(Height(temp->left_), Height(temp->right_)) + 1;
  return temp;
}
//LRInsertRotation函数, 对于LR型插入操作引起的失衡,进行旋转
//Node* root 失衡的节点
Node* Tree::LRInsertRotation(Node* root) {
  root->left_ = RRInsertRotation(root->left_);
  root = LLInsertRotation(root);
  root->left_->height_ = Max(Height(root->left_->left_), Height(root->left_->right_));
  root->height_ = Max(Height(root->left_), Height(root->right_));
  return root;
}
//RLInsertRotation函数, 对于RL型插入操作引起的失衡,进行旋转
//Node* root 失衡的节点
Node* Tree::RLInsertRotation(Node* root) {
  root->right_ = LLInsertRotation(root->right_);
  root = RRInsertRotation(root);
  root->right_->height_ = Max(Height(root->right_->left_), Height(root->right_->right_));
  root->height_ = Max(Height(root->left_), Height(root->right_));
  return root;  //这里的返回值也许有问题
}
//InsertAvlNode函数, 向树中进行插入节点
//int key 待插入的数据
//Node* root 待进行插入操作的树
Node* Tree::InsertAvlNode(Node* root, int key) {
  if (root == nullptr) {
    root = GetNewNode(key);
  }
  else if (key < root->data_) {
    root->left_ = InsertAvlNode(root->left_, key);
    //判断是否失衡
    if (Height(root->left_) - Height(root->right_) == 2) {
      if (key < root->left_->data_) {
        root = LLInsertRotation(root);
      }
      else if (key > root->left_->data_) {
        root = LRInsertRotation(root);
      }
    }
  }
  else if (key > root->data_) {
    root->right_ = InsertAvlNode(root->right_, key);
    if (Height(root->right_) - Height(root->left_) == 2) {
      if (key > root->right_->data_) {
        root = RRInsertRotation(root);
      }
      else if (key < root->right_->data_) {
        root = RLInsertRotation(root);
      }
    }
  }
  root->height_ = Max(Height(root->left_),Height(root->right_)) + 1;
  return root;
}
//DeleteAvlNode函数, 删除树中指定数据的节点
//int key 待删除的节点数据
//Node* root待进行删除操作的树
Node* Tree::DeleteAvlNode(Node* root, int key) {
  if (root == nullptr) {
    return root;
  }
  else if (key > root->data_) {
    root->right_ = DeleteAvlNode(root->right_, key);
    if (Height(root->left_) - Height(root->right_) == 2) {
      if (root->left_->left_ != nullptr) {
        root = LLInsertRotation(root);
      }
      else if (root->left_->right_ != nullptr) {
        root = LRInsertRotation(root);
      }
    }
  }
  else if (key < root->data_) {
    root->left_ = DeleteAvlNode(root->left_, key);
    if (Height(root->right_) - Height(root->left_) == 2) {
      if (root->right_->right_ != nullptr) {
        root = RRInsertRotation(root);
      }
      else if (root->right_->left_ != nullptr) {
        root = RLInsertRotation(root);
      }
    }
  }
  root->height_ = Max(Height(root->left_), Height(root->right_));
  return root;
}
//DeleteAvlNode 用户可操作的删除函数
//int key待删除的数据
void Tree::DeleteAvlNode(int key) {
  root_ = DeleteAvlNode(root_, key);
  std::cout << "删除操作成功" << std::endl;
  std::cout << "删除的值是: " << key << std::endl;
  return;
  return;
}
//InsertAvlNode,用户可操作的插入函数
//int key待插入的数据
void Tree::InsertAvlNode(int key) {
  root_ = InsertAvlNode(root_, key);
  std::cout << "插入操作成功" << std::endl;
  std::cout << "插入的值是: " << key << std::endl;
  return;
}
//PrintAvlTree 用户看的打印整个树的数据
void Tree::PrintAvlTree() {
  PrintAvlTree(root_);
  std::cout << std::endl << "打印操作成功" << std::endl;
  return;
}
//PrintAvlTree 打印树中的所有数据
//Node* root 待打印的树, 使用前序遍历
void Tree::PrintAvlTree(Node* root) {
  if (root == nullptr) {
    return;
  }
  PrintAvlTree(root->left_);
  std::cout << root->data_ << " ";
  PrintAvlTree(root->right_);
  return;
}
//DeleteAllNode 释放所有的Node内存块
//用于析构函数
void  Tree::DeleteAllNode(Node* root) {
  if (root == nullptr) {
    return;
  }
  else if (root->left_ == nullptr && root->right_ == nullptr) {
    delete root;
    root = nullptr;
    return;
  }
  DeleteAllNode(root->left_);
  DeleteAllNode(root->right_);
}

void Tree::GetAvlTreeHeight() {
  std::cout <<"AvlTree的高度是: "  << root_->height_ << std::endl;
}
void Tree::GetAvlTreeData() {
  std::cout << "AvlTree的数据是: " << root_->data_ << std::endl;
}
