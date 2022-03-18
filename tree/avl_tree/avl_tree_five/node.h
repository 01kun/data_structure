#pragma once
class Node{
 public:
  Node();
  Node(int key);
  Node(int key, Node* left, Node* right);
  ~Node();
 
 public:
  int data_;
  int height_;
  Node* right_;
  Node* left_;

 private:
  Node( const Node& node);
};

