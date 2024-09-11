/*
 * Name: William Cooper
 * Date Submitted: 4/3/2024
 * Lab Section: 001
 * Assignment Name: bstSequence
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <assert.h>
#include <random>
#include <ctime>

#include "bstSequence.h"

using namespace std;

void fix_size(Node *T)
{
  T->size = 1;
  if (T->left) T->size += T->left->size;
  if (T->right) T->size += T->right->size;
}

/*
// insert key k into tree T, returning a pointer to the resulting tree
Node *insert(Node *T, int k)
{
  if (T == nullptr) return new Node(k);
  if (k < T->key) T->left = insert(T->left, k);
  else T->right = insert(T->right, k);
  fix_size(T);
  return T;
}
*/

// insert value v at rank r
Node *insert(Node *T, int v, int r)
{
  //Implement Node *insert(Node *T, int v, int r)

  //the base return, if T is null then return null
  if (T == nullptr) {
    return new Node(v);
  }

  //I used the conditional ternary operator taken from cplusplus.com
  // the question mark tests the condition before and then picks between the two options
  int currRank = T->left ? T->left->size : 0;

  //if the size of the left is greater than or equal to the rank 
  if (currRank >= r) {
    //insert the rank to the left
    T->left = insert(T->left, v, r);
  }
  else {
    //goes to the right and root rank changes
    T->right = insert(T->right, v, (r - currRank - 1));
  }

  //fixes the size of T
  fix_size(T);

  //returns T
  return T;
}

// returns a vector of key values corresponding to the inorder traversal of T (i.e., the contents of T in sorted order)
vector<int> inorder_traversal(Node *T)
{
  vector<int> inorder;
  vector<int> rhs;
  if (T == nullptr) return inorder;
  inorder=inorder_traversal(T->left);
  inorder.push_back(T->key);
  rhs=inorder_traversal(T->right);
  inorder.insert(inorder.end(), rhs.begin(), rhs.end());
  return inorder;
}

// return pointer to node of rank r (with r'th largest key; e.g. r=0 is the minimum)
Node *select(Node *T, int r)
{
  assert(T!=nullptr && r>=0 && r<T->size);

  int rank_of_root = T->left ? T->left->size : 0;
  if (r == rank_of_root) return T;
  if (r < rank_of_root) return select(T->left, r);
  else return select(T->right, r - rank_of_root - 1);
}

// Split tree T on rank r into tree L (containing ranks < r) and 
// a tree R (containing ranks >= r)
void split(Node *T, int r, Node **L, Node **R)
{
  //Implement void split(Node *T, int r, Node **L, Node **R)

  // if T is null then 
  if (T == nullptr) {
    //set left and right to null
    *L = nullptr;
    *R = nullptr;
    return;
  }

  //I used the conditional ternary operator taken from cplusplus.com
  // the question mark tests the condition before and then picks between the two options
  int currRank = T->left ? T->left->size : 0;
  
  //if current rank is greater than or equal to r
  if (currRank >= r) {
    //recursively enters split again and inputs the left values
    split(T->left, r, L, &T->left);
    //right equals the current node
    *R = T;
  }
  else {
    //recursively enters split agian and inputs the right values with a chnage to r
    split(T->right, r - currRank - 1, &T->right, R);
    //left equals the current node
    *L = T;
  }

  //fixes the size
  fix_size(T);
}

// insert value v at rank r
Node *insert_random(Node *T, int v, int r)
{
  // If (v,r) is the Nth node inserted into T, then:
  // with probability 1/N, insert (v,r) at the root of T
  // otherwise, insert_random (v,r) recursively left or right of the root of T
  
  //Implement Node *insert_random(Node *T, int v, int r)

  //if T is a nullptr
  if (T == nullptr) {
    //declare a new node with the key value and return
    return new Node(v);
  }

  //random num generator
  int gen = rand() % (T->size + 1);

  //I used the conditional ternary operator taken from cplusplus.com
  // the question mark tests the condition before and then picks between the two options
  int currRank = T->left ? T->left->size : 0;

  //generates 0 then creates new node to be split
  if (gen == 0) {
    Node * myNode = new Node(v);

    split(T, r, &myNode->left, &myNode->right);
    
    //readjusts the size
    fix_size(myNode);

    //return statement
    return myNode;    
  }

  //gen is less than current key then the key is inserted to the left side of the tree
  if (currRank >= r) {
    T->left = insert_random(T->left, v, r);
  }
  else {
    T->right = insert_random(T->right, v, r - currRank - 1);
  }

  //adjusts the size again
  fix_size(T);

  //return statement
  return T;
}

// Returns true if team x defeated team y
// Leave this function unmodified
bool did_x_beat_y(int x, int y)
{
  assert (x != y);
  if (x > y) return !did_x_beat_y(y,x);
  unsigned long long lx = x;
  unsigned long long ly = y;
  return ((17 + 8321813 * lx + 1861 * ly) % 1299827) % 2 == 0;
}

// Binary Search the Tree
int binarySearch(Node *T, int val)    {
    //variables for the function
    bool placed = false;
    int low = 0; 
    int high = T->size - 1;
    int mid = 0;

    //while placed is false
    while(!placed)    {
      mid = floor((low + high) / 2);
      if((high - low) == 1)    {
        placed = true;
        return high;
      }
      else if( did_x_beat_y(val, select(T,mid)->key) ) {
        high = mid;
      }
      else {
        low = mid;
      }
    }

    //return statement
    return mid;

}

// Return a BST containing a valid ordering of n teams
Node *order_n_teams(int n)
{
  Node *T = nullptr;

  // start by inserting the first team
  T = insert_random(T, 0, 0);

  // now insert the other teams...
  for (int i=1; i<n; i++) {
    // insert team i so the sequence encoded by the BST remains valid
    if (did_x_beat_y(i, select(T,0)->key)) // can we insert at beginning?
      T = insert_random(T, i, 0);
    else if (did_x_beat_y(select(T,T->size-1)->key, i)) // can we insert at end?
	    T = insert_random(T, i, T->size);
    else {
      T = insert_random(T, i, binarySearch(T, i));   
	    // 7 5 4 2 0 3 1 6    (when inserting team i=8)
	    // W W W L L L W L
    }
  }
  return T;
}

void printVector(vector<int> v)
{
    for (int i=0; i<v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

// int main(void)
// {
//   vector<int> inorder;
//   Node *T = nullptr;

//   // test insert at beginning
//   for (int i=0; i<5; i++)
//     T = insert(T, i+1, 0);
//   cout << "Tree should contain 5 4 3 2 1:\n";
//   inorder=inorder_traversal(T);
//   printVector(inorder);

//   // test insert at end
//   for (int i=5; i<10; i++)
//     T = insert(T, i+1, T->size);
//   cout << "Tree should contain 5 4 3 2 1 6 7 8 9 10:\n";
//   inorder=inorder_traversal(T);
//   printVector(inorder);
  
//   // test insert at middle
//   for (int i=10; i<15; i++)
//     T = insert(T, i+1, T->size/2);
//   cout << "Tree should contain 5 4 3 2 1 12 14 15 13 11 6 7 8 9 10:\n";
//   inorder=inorder_traversal(T);
//   printVector(inorder);
    
//   // once insert is working, the next step is to build the
//   // insert_random function -- to test this, just change
//   // calls to insert above to insert_random.

//   int N = 100000; // this should run quickly even for very large N!
//   Node *S = order_n_teams(N);
//   if (S == nullptr || S->size != N)
//     cout << "Size of tree returned by order_n_teams is wrong\n";
//   else {
//     cout << "Team ordering:\n";
//     //    inorder=inorder_traversal(S);
//     //    printVector(inorder);
//     for (int i=0; i<N-1; i++) {
//       Node *x = select(S, i);
//       Node *y = select(S, i+1);
//       if (!did_x_beat_y(x->key, y->key)) {
//         cout << "Invalid sequence: team " << x->key << " (position " << i <<
// 	              ") lost to team " << y->key << " (position " << i+1 << ")\n";
//       }
//     }
//   }  
  
//   return 0;
// }
