#pragma once
#include <iostream>
#include <math.h>
using namespace std;


struct Node
{
  int value;
  Node* right;
  Node* left;
  int height;

  Node(int val)
  {
    right = nullptr;
    left = nullptr;
    value = val;
    height = 1; 
  }
};

class AVLtree
{
  Node* root;

protected:

  int Height(Node* curr) { if (curr == nullptr) return 0; return curr->height; }

  Node* InsertNode(Node* curr, int val);
 
  Node* right_rotation(Node* curr);

  Node* left_rotation(Node* curr);

  void print(Node* curr);

  void clear(Node * curr);
 
public:

  AVLtree() { root = nullptr; }
  
  void InsertNode(int val) { root = InsertNode(root, val); }

  void print() { this->print(root); }

  void sort(int* arr, int size);

  ~AVLtree();
};