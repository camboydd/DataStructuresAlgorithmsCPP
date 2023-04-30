#include <iostream>

using namespace std;

class Node{
    public:
        int value;
        Node* left;
        Node* right;

        Node(int value){
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};

class BinarySearchTree{
    private:
        Node* root;

    public:
        BinarySearchTree() {
            root = nullptr;
        }
        bool insert(int value){
            Node* newNode = new Node(value);
            if (root == nullptr){
                root = newNode;
                return true;
            }
            Node* temp = root;
            while (true){
                if (newNode->value ==temp->value) return false;
                if (newNode->value < temp->value){
                    if (temp->left == nullptr){
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left;
                } else {
                    // If the nest slot is not empty
                    if (temp->right == nullptr){
                        temp->right = newNode;
                        return true;
                    }
                    // then we move down the right branch
                    temp = temp->right;
                }
            }
        }
        bool contains(int value){
            Node* temp = root;
            // while temp is pointing to a node
            while (temp){
                // if value is less than, move left / move right if larger
                if (value < temp->value){
                    temp = temp->left;
                } else if (value > temp->value){
                    temp = temp->right;
                } else {
                    return true;
                }
            }
            return false;
        }
};      
