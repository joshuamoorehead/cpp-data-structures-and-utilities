// Copyright Joshua Moorehead2023
#include <iostream>

class Node {
 public:
    int value;
    Node* left;
    Node* right;

    explicit Node(int val) {
        value =  val;
        left = nullptr;
        right = nullptr;
    }
};




class BST {
 private:
    Node *root;

    Node* empty(Node* node) {
        if (node == NULL)
            return NULL;
        {
            empty(node->left);
            empty(node->right);
            delete node;
        }
        return NULL;
    }
    Node* insert(int val, Node* nd) {
        if (nd == NULL) {
            nd = new Node(val);
            std::cout << "Node " << val << " has been inserted." << std::endl;
        } else if (val < nd->value) {
            nd->left = insert(val, nd->left);
        } else if (val > nd->value) {
            nd->right = insert(val, nd->right);
        } else {
            std::cout << "Node " << val
            << " is a duplicate node. Cannot insert Node " <<
            val << " again." << std::endl;
        }
        return nd;
    }
    Node* remove(int val, Node* nd) {
        Node* temp;
        if (nd == NULL) {
            std::cout << "Node " << val << " not found." << std::endl;
            return NULL;
        } else if (val < nd->value) {  // going down the left side of tree recursively
            nd->left = remove(val, nd->left);
        } else if (val > nd->value) {  // going right recursively
            nd->right = remove(val, nd->right);
        } else if (nd->left && nd->right) {
            temp = findMin(nd->right);
            nd->value = temp->value;
            nd->right = remove(nd->value, nd->right);
        } else {
            temp = nd;
            if (nd->left == NULL)
                nd = nd->right;
            else if (nd->right == NULL)
                nd = nd->left;
            std::cout << "Node " << val << " has been deleted." << std::endl;
            delete temp;
        }

        return nd;
    }
    Node* findMin(Node* nd) {
        if (nd == NULL)
            return NULL;
        else if (nd->left == NULL)
            return nd;
        else
            return findMin(nd->left);
    }
    Node* findMax(Node* nd) {
        if (nd == NULL)
            return NULL;
        else if (nd->right == NULL)
            return nd;
        else
            return findMax(nd->right);
    }
    void inorderTraversal(Node* nd) {
        if (nd == NULL)
            return;
        inorderTraversal(nd->left);
        std::cout << nd->value << ", ";
        inorderTraversal(nd->right);
    }
    Node* find(int val, Node* nd) {
        if (nd == NULL)
            return NULL;
        std::cout << nd->value << " -> ";

        if (val < nd->value)
            return find(val, nd->left);
        else if (val > nd->value)
            return find(val, nd->right);
        else
            return nd;
    }

 public:
    BST() {
        root = nullptr;
    }
    ~BST() {
        root = empty(root);
    }
    void insert(int val) {
        root = insert(val, root);
        /*if (root != NULL) {
            std::cout << "Node " << val << " has been inserted." << std::endl;
        }*/
        printBST();
    }
    void remove(int val) {
        root = remove(val, root);
        /*if (root != NULL) {
            std::cout << "Node " << val << " has been deleted." << std::endl;
        }*/
        printBST();
    }
    void search(int val) {
        std::cout << "Searching for value " << val << " in the tree.\n";
        Node* result = find(val, root);
        if (result != NULL) {
            std::cout << std::endl;
            std::cout << val << " found in the tree." << std::endl;
        } else {
            std::cout << "search key not found" << std::endl;
        }
        printBST();
    }
    void printMin() {
        Node *result = findMin(root);
        std::cout << "Minimum Value: " << result->value << std::endl;
        printBST();
    }
    void printMax() {
        Node *result = findMax(root);
        std::cout << "Maximum Value: " << result->value << std::endl;
        printBST();
    }
    void printBST() {
        std::cout << "~~~~~~Binary Search Tree~~~~~~" << std::endl;
        inorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    BST bst;

    while (true) {
        std::cout << "Choose an operation:\n";
        std::cout << "1. Insert(int val)\n";
        std::cout << "2. Search(int val)\n";
        std::cout << "3. Delete(int val)\n";
        std::cout << "4. Print Max()\n";
        std::cout << "5. Print Min()\n";
        std::cout << "6. Quit()\n";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int val;
                std::cout << "Enter the value to insert: ";
                std::cin >> val;
                bst.insert(val);
                break;
            }
            case 2: {
                int val;
                std::cout << "Enter the value to search: ";
                std::cin >> val;
                bst.search(val);
                break;
            }
            case 3: {
                int val;
                std::cout << "Enter the value to delete: ";
                std::cin >> val;
                bst.remove(val);
                break;
            }
            case 4: {
                bst.printMax();
                break;
            }
            case 5: {
                bst.printMin();
                break;
            }
            case 6: {
                bst.~BST();  // Gives back allocated memory
                return 0;  // Quits the program.
            }
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }


    return 0;
}
