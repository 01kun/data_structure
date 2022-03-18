#include "AvlNode.h"
#include <iostream>

AvlNode::AvlNode() : data_(0), height_(0), left_(nullptr), right_(nullptr) {
  std::cout << "TreeNode默认构造函数的调用" << std::endl;
}

AvlNode::AvlNode(int key) : data_(0), height_(0), left_(nullptr), right_(nullptr) {
  std::cout << "TreeNode有参构造函数的调用" << std::endl;
}

AvlNode::AvlNode(int key, AvlNode& left, AvlNode& right)
  : data_(0), height_(0), left_(nullptr), right_(nullptr) {
  std::cout << "TreeNOde(int key, TreeNode* left, TreeNode* right) 函数的调用" << std::endl;
}
