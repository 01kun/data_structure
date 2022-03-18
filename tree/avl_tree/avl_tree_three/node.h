#pragma once
#ifndef cppalvtree_AvlNode_H_
#define cppalvtree_AvlNode_H_

//AvlTree
class AvlNode{
 public:
  AvlNode();
  AvlNode(int key);
  AvlNode(int key, AvlNode& left, AvlNode& right);
 
 private:
  int data_;
  int height_;
  AvlNode* left_;
  AvlNode* right_;
};

#endif      
