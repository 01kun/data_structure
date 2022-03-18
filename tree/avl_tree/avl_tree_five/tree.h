#pragma once
#include "Node.h"
class Tree{
 public:
  Tree();
  ~Tree();

 public:
  void InsertAvlNode(int key);
  void DeleteAvlNode(int key);
  void PrintAvlTree();
  void  GetAvlTreeHeight();
  void GetAvlTreeData();
 private:
  Node* GetNewNode(int key);
  Node* LLInsertRotation(Node* root);
  Node* LRInsertRotation(Node* root);
  Node* RRInsertRotation(Node* root);
  Node* RLInsertRotation(Node* root);
  void  DeleteAllNode(Node* root);
  Node* DeleteAvlNode(Node* root, int key);
  Node* InsertAvlNode(Node* root, int key);
  void  PrintAvlTree(Node* root);
  int Max(int a, int b);
  int Height(Node* root)
; Tree(int key);
  Tree(const Tree& root);
 private:
  Node* root_;
};

