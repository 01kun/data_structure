#include <iostream>
#include "Tree.h"

void test() {
  int a = 0;
  Tree tree;
  tree.InsertAvlNode(1000);
  tree.PrintAvlTree();
  tree.GetAvlTreeHeight();
  tree.GetAvlTreeData();
  std::cout << std::endl;
  tree.InsertAvlNode(1100);
  tree.PrintAvlTree();
  tree.GetAvlTreeHeight();
  tree.GetAvlTreeData();
  std::cout << std::endl;
  tree.InsertAvlNode(1200);
  tree.PrintAvlTree();
  tree.GetAvlTreeHeight();
  tree.GetAvlTreeData();
  std::cout << std::endl;
  tree.InsertAvlNode(1300);
  tree.PrintAvlTree();
  tree.GetAvlTreeHeight();
  tree.GetAvlTreeData();
  std::cout << std::endl;
  tree.InsertAvlNode(1400);
  tree.PrintAvlTree();
  tree.GetAvlTreeHeight();
  tree.GetAvlTreeData();

  tree.InsertAvlNode(1500);
  tree.PrintAvlTree();
  tree.GetAvlTreeHeight();
  tree.GetAvlTreeData();
  int b = 0;
}

int main() {
  test();
  std::cin.get();
  return 0;
}
