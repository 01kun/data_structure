#ifndef cppavltree_Tree_H_
#define cppavltree_Tree_H_
#include "Node.h"
class Tree
{
 public:
  Tree();
  ~Tree();
 public:
  void InsertAvlNode(int key);
  void DeleteAvlNode(int key);
  void PrintAvlNode();
 
 private:
  Node* GetNewNode(int key);
  Node* LLRotation(Node* root);
  Node* RRRotation(Node* root);
  Node* LRRotation(Node* root);
  Node* RLRotation(Node* root);
  Node* InsertAvlNode(Node* root, int key);
  Node* DeleteAvlNode(Node* root, int key);
  Node* PrintAvlNode (Node* root);
  void DeleteAllNode(Node* root);
  int Height(Node* root);
  int Max(int a, int b);  //比较a和b的大小,返回较大值
 
 private:
  Node* root_;
};

#endif
