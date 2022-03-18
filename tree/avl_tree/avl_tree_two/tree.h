#pragma once
#include "Node.h"
class Tree
{
 public:
  Tree();
  Tree();
  ~Tree();
 public:
  void PrintAvlTree();
  void InsertAvlNode(int key);
  void DeleteAvlNode(int key);
 private:
  Node* GetNewNode(int key);
  Node* InsertAvlNode(Node* root, int key);
  Node* LLRotation(Node* root);
  Node* RRRotation(Node* root);
  Node* LRRotation(Node* root);
  Node* RLRotation(Node* root);
  Node* DeleteAvlNode(Node* root, int key);
  void  PrintAvlNode(Node* root);
  Node* DeleteAllNode(Node* root);
  int Height(Node* root);
  int Max(int a, int b); //返回较大值
 private:
  Node* root_;
};

