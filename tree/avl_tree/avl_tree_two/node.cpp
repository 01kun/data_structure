#include "Node.h"
#include <iostream>
Node::Node(): Data_(0), height_(0), left_(nullptr), right_(nullptr) {
  std::cout << "Node默认构造函数的调用" <<std::endl;
}

Node::Node(int key) : Data_(key), height_(0), left_(nullptr), right_(nullptr) {
  std::cout << "Node默认构造函数的调用" << std::endl;
}

Node::Node(int key, Node* left, Node* right) : Data_(key), height_(0), left_(left), right_(right) {
  std::cout << "Node默认构造函数的调用" << std::endl;
}

Node::~Node() {
  std::cout << "Node析构函数的调用" <<std::endl;
}


