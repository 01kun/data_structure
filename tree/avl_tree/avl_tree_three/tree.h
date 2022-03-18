#ifndef avltree_AvlTree_H_
#define avltree_AvlTree_H_
#include "AvlNode.h"
class AvlTree
{
 public:
  void InsertAvlNode(int key);
  void DeleteAvlNode(int key);
  void PrintAvlNode ();
 
 private:
  AvlNode& GetNewAvlNode(int key);
  AvlNode& GetNewAvlNode(int key, AvlNode& left, AvlNode& right);
  AvlNode& InsertAvlNode(AvlNode& root, int key);
  AvlNode& DeleteAvlNode(AvlNode& root, int key);
  

 private:
  AvlNode* root_;

};

#endif

