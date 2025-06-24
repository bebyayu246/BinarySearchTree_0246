#include <iostream>
using namespace std;

class Node {
    public :
        int info;
        Node* leftchild;
        Node* rightchild;

        //Construktor for the node class
        Node()
        {
            leftchild = nullptr; //intialize left child to null
            rightchild = nullptr; //intialize right child to null
        }
};

class BinaryTree
{
    public :
        Node *ROOT;

        BinaryTree()
        {
            ROOT = nullptr; //intialize root to null
        }

       