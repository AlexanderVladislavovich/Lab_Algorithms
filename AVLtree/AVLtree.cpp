#include "AVLtree.h"

Node* AVLtree::InsertNode(Node* curr, int val)
{
  if (curr == nullptr) { return new Node(val); }

  else if (val > curr->value) { curr->right = InsertNode(curr->right, val); }

  else if (val < curr->value) { curr->left = InsertNode(curr->left, val); }

  else return curr;

  int leftHeight = Height(curr->left); int rightHeight = Height(curr->right);

  curr->height = max(leftHeight, rightHeight) + 1;

  int Balance = leftHeight - rightHeight;

  if (Balance > 1 && (Height(curr->left->left) > Height(curr->left->right))) return right_rotation(curr);

  else if (Balance < -1 && (Height(curr->right->left) < Height(curr->right->right))) return left_rotation(curr);

  else if (Balance > 1 && (Height(curr->left->left) < Height(curr->left->right))) 
  {
    curr->left = left_rotation(curr->left);  return right_rotation(curr);
  }

  else if (Balance < -1 && (Height(curr->right->left) > Height(curr->right->right))) 
  {
    curr->right = right_rotation(curr->right); return left_rotation(curr);
  }

  return curr;
}
//void AVLtree::test() { cout << "aaa"; }
void AVLtree::print(Node* curr)
{
  if (curr != nullptr)
  {
    print(curr->left);
    cout << curr->value << " [" << curr->height << "] ";
    print(curr->right);
  }
}

Node* AVLtree::right_rotation(Node* curr)
{
  Node* tmp1 = curr->left;
  Node* tmp2 = tmp1->right;
  tmp1->right = curr;
  curr->left = tmp2;
  curr->height = max(Height(curr->left), Height(curr->right)) + 1;
  tmp1->height = max(Height(tmp1->left), Height(tmp1->right)) + 1;
  return tmp1;
}

Node* AVLtree::left_rotation(Node* curr)
{
  Node* tmp1 = curr->right;
  Node* tmp2 = tmp1->left;
  tmp1->left = curr;
  curr->right = tmp2;
  curr->height = max(Height(curr->left), Height(curr->right)) + 1;
  tmp1->height = max(Height(tmp1->left), Height(tmp1->right)) + 1;
  return tmp1;
}

void AVLtree::sort(int* arr, int size)
{
  int i = 0;
  while (i < size)
  {
    this->InsertNode(arr[i]);
    i++;
  }
  cout << "\ninsertion complete" << endl;
}


void AVLtree::clear(Node *curr)
{
  if (curr != nullptr)
  {
    clear(curr->left);
    clear(curr->right);
    delete curr;
  }
}

AVLtree::~AVLtree()
{
  clear(root);
}