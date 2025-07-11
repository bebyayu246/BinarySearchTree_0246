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

        void insert()
        {
            int x;
            cout << " Masukkan Nilai :";
            cin >> x;

            //Step 1 : Allocate memory for the new node
            Node *newNode = new Node();

            //Step  2 : Assign value to the data field of the new node
            newNode->info = x;

            //Step 3 : Make the left and right child of the new node point to null
            newNode->leftchild = nullptr;
            newNode->rightchild = nullptr;

            //Step 4 : Locate the node wich will be the parent of the node to be inserted
            Node *parent = nullptr;
            Node *currentNode = nullptr;
            search(x, parent, currentNode);

            //Step 5 : if parent the NULL, tree is empty
            if (parent == nullptr){
                //5a : Mark the new nood as ROOT
                ROOT = newNode;
                //5b : exit
                return;
            }
             //step 6: if the value in the data filed of new node is less than taht of parent
            if (x < parent->info)
            {
                //6a: make the left child of parent point to the new node 
                parent->leftchild = newNode;

                //6b : exit
                return;
            }
            //step 7: if the value in the data filed of the new node is greater than tahat of the parent 
            else if(x > parent->info){
                //7a:make the right child of parent point the new node
                parent->rightchild = newNode;

                //7b: exit
                return;
            }
        }
        void search (int element, Node *&parent, Node *&currentNode){
            //This function searches the current Node of the specific node as well as the current node of its parents
            currentNode = ROOT;
            parent = nullptr;

            while((currentNode !=nullptr) && (currentNode->info != element)) 
            {
                parent = currentNode;
                if (element < currentNode -> info)
                    currentNode = currentNode -> leftchild;
                else
                    currentNode = currentNode-> rightchild;
            }
        }

        void inorder (Node *ptr) {
            if(isEmpty()) {
                cout << " Tree is empty " << endl;
                return;
            }
            if(ptr == nullptr)
            return;

            inorder (ptr->leftchild);
            cout << ptr->info << "";
            inorder (ptr ->rightchild);
        }

            void preorder (Node *ptr) {
            if(isEmpty()) {
                cout << " Tree is empty " << endl;
                return;
            }
            if(ptr == nullptr)
            return;

            cout << ptr->info << "";
            inorder (ptr->leftchild);
            inorder (ptr ->rightchild);
        }

              void postorder (Node *ptr) {
            if(isEmpty()) {
                cout << " Tree is empty " << endl;
                return;
            }
            if(ptr == nullptr)
            return;

            inorder (ptr->leftchild);
            inorder (ptr ->rightchild);
            cout << ptr->info << "";
        }

        