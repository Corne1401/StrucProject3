#pragma once

// C++ program to insert a node in AVL tree
#include<bits/stdc++.h>
#include "../nodeTypes/NewAVLNode.h"

using namespace std;

class NewAVLTree {
public:

    explicit NewAVLTree(){root= nullptr;}

    int highestBoughValue;
    int lowestBoughtValue;

    bool isProdCodeOnTree(int prodCode) {
        return root->isProdCodeInTree(root, prodCode);
    }
    NewAVLNode *getNodeByProdCode(int prodCode){
        return root->getNodeByProdCode(root, prodCode);
    }

    void deleteProduct(int prodCode){
        root = deleteNodeHelper(root, prodCode);
    }

    NewAVLNode *getAVLRoot() const {
        return root;
    }

    void setAVLRoot(NewAVLNode *newRoot) {
        NewAVLTree::root = newRoot;
    }

// A utility function to get maximum
// of two integers
    int max(int a, int b){
        return (a > b)? a : b;
    }

// A utility function to get the
// height of the tree
    int height(NewAVLNode *node){
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }


// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
    NewAVLNode *rightRotate(NewAVLNode *y){
        NewAVLNode *x = y->left;
        NewAVLNode *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(height(y->left),
                        height(y->right)) + 1;
        x->height = max(height(x->left),
                        height(x->right)) + 1;

        // Return new root
        return x;
    }

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
    NewAVLNode *leftRotate(NewAVLNode *x){
        NewAVLNode *y = x->right;
        NewAVLNode *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(height(x->left),
                        height(x->right)) + 1;
        y->height = max(height(y->left),
                        height(y->right)) + 1;

        // Return new root
        return y;
    }

// Get Balance factor of node N
    int getBalance(NewAVLNode *node){
        if (node == nullptr) {
            return 0;
        }
        return height(node->left) - height(node->right);
    }


    void insert(int key, const string& name){
        setAVLRoot(insertHelper(getAVLRoot(), key, name));
    }

// Recursive function to insert a key
// in the subtree rooted with node and
// returns the new root of the subtree.
    NewAVLNode* insertHelper(NewAVLNode* node, int key, const string& name){
        /* 1. Perform the normal BST insertion */
        if (node == nullptr) {
            return (new NewAVLNode(key, name));
        }

        if (key < node->key) {
            node->left = insertHelper(node->left, key, name);
        }
        else if (key > node->key) {
            node->right = insertHelper(node->right, key, name);
        }
        else {
            // Equal keys are not allowed in BST
            return node;
        }

        /* 2. Update height of this ancestor node */
        node->height = 1 + max(height(node->left),
                               height(node->right));

        /* 3. Get the balance factor of this ancestor
            node to check whether this node became
            unbalanced */
        int balance = getBalance(node);

        // If this node becomes unbalanced, then
        // there are 4 cases

        // Left Left Case
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        /* return the (unchanged) node pointer */
        return node;
    }

// A utility function to print preorder
// traversal of the tree.
// The function also prints height
// of every node
    void preOrder(NewAVLNode *R){
        if(R != nullptr){
            cout << R->key << " ";
            preOrder(R->left);
            preOrder(R->right);
        }
    }

    string getProductsForClient() {
        string concat;
        return getProductsForClientHelper(root, concat);
    }

    void generateProd(const string &path, int aisleCode) {
        ofstream outfile (path);
        outfile << "Products List for aisle: " << aisleCode << endl;

        NewAVLNode::generateProductsList(root, outfile);

        outfile.flags();
        outfile.close();
        cout << "Report generated successfully..." << endl;
    }

    string getProductsForClientHelper(NewAVLNode *t, string &concat) {
        if (t == nullptr){
            return concat;
        } else {
            concat = getProductsForClientHelper((NewAVLNode*) t->getLeftPointer(), concat);
            concat += "Product Code:" + to_string(t->key) + ", Product Name:" + t->getName() + "\n";
            concat = getProductsForClientHelper((NewAVLNode*) t->getRightPointer(), concat);
        }
        return concat;
    }

    void show(NewAVLNode *p, int l) {
        int i;
        if (p != nullptr) {
            show((NewAVLNode*) p->getRightPointer(), l+ 1);
            cout<<" ";
            if (p == root)
                cout << "Root -> ";
            for (i = 0; i < l&& p != root; i++)
                cout << " ";
            cout << p->key;
            show((NewAVLNode*) p->getLeftPointer(), l + 1);
        }
    }

    void fullInorder(NewAVLNode *t) {
        if (t == nullptr)
            return;
        fullInorder((NewAVLNode*) t->getLeftPointer());
        cout << "(" <<t->key << ", " << t->getName()  << ", " << t->getTimesSold() << " ) -";
        if(t->getProductAisleBrandTreePointer()!= nullptr){
            cout << "Third tree inorder for: " << t->key << endl;
            t->getProductAisleBrandTreePointer()->inorder();
            cout << "End of Second Tree Inorder" << endl;
        }
        fullInorder((NewAVLNode*) t->getRightPointer());
    }

    void inorder(NewAVLNode *t) {
        if (t == nullptr)
            return;
        inorder((NewAVLNode*) t->getLeftPointer());
        cout << "(" <<t->key << ", " << t->getName()  << ", " << t->getTimesSold() << " ) -";
        inorder((NewAVLNode*) t->getRightPointer());
    }
    void postorder(NewAVLNode *t) {
        if (t == nullptr)
            return;
        postorder( (NewAVLNode*) t ->getLeftPointer());
        postorder((NewAVLNode*) t ->getRightPointer());
        cout << t->key << " ";
    }

    void printProductsForPurchaseHelper(NewAVLNode *t) {
        if (t == nullptr)
            return;
        printProductsForPurchaseHelper((NewAVLNode *) t->getLeftPointer());
        cout << "Product Code:" <<t->key << ", Product Name:" << t->getName() << endl;
        printProductsForPurchaseHelper((NewAVLNode *) t->getRightPointer());
    }

    void generateMostBoughtProd(const string &path, int aisleCode){
        ofstream outfile (path);
        outfile << "Most bought prod on aisle: " << aisleCode << endl;

        NewAVLNode::getMostBoughtValue(root, highestBoughValue);
        NewAVLNode::generateMostBoughtProd(root, highestBoughValue, outfile);

        outfile.flags();
        outfile.close();
        cout << "Report generated successfully..." << endl;
    }

    NewAVLNode *minValueNode(NewAVLNode *node)
    {
        NewAVLNode* current = node;

        /* loop down to find the leftmost leaf */
        while (current->left != nullptr)
            current = current->left;

        return current;
    }

    void deleteNode(int key){
        root = deleteNodeHelper(root, key);
    }


    NewAVLNode *deleteNodeHelper(NewAVLNode *root, int key)
    {

        // STEP 1: PERFORM STANDARD BST DELETE
        if (root == nullptr)
            return root;

        // If the key to be deleted is smaller
        // than the root's key, then it lies
        // in left subtree
        if ( key < root->key )
            root->left = deleteNodeHelper(root->left, key);

        // If the key to be deleted is greater
        // than the root's key, then it lies
        // in right subtree
        else if( key > root->key )
            root->right = deleteNodeHelper(root->right, key);

        // if key is same as root's key, then
        // This is the node to be deleted
        else
        {
            // node with only one child or no child
            if( (root->left == nullptr) ||
                    (root->right == nullptr) )
            {
                NewAVLNode *temp = root->left ?
                            root->left :
                            root->right;

                // No child case
                if (temp == nullptr)
                {
                    temp = root;
                    root = nullptr;
                }
                else // One child case
                    *root = *temp; // Copy the contents of
                // the non-empty child
                free(temp);
            }
            else
            {
                // node with two children: Get the inorder
                // successor (smallest in the right subtree)
                NewAVLNode* temp = minValueNode(root->right);

                // Copy the inorder successor's
                // data to this node
                root->key = temp->key;
                root->name = temp->name;
                root->timesSold = temp->timesSold;
                root->productAisleBrandTreePointer = temp->productAisleBrandTreePointer;

                // Delete the inorder successor
                root->right = deleteNodeHelper(root->right,
                                         temp->key);
            }
        }

        // If the tree had only one node
        // then return
        if (root == nullptr)
            return root;

        // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
        root->height = 1 + max(height(root->left),
                               height(root->right));

        // STEP 3: GET THE BALANCE FACTOR OF
        // THIS NODE (to check whether this
        // node became unbalanced)
        int balance = getBalance(root);

        // If this node becomes unbalanced,
        // then there are 4 cases

        // Left Left Case
        if (balance > 1 &&
                getBalance(root->left) >= 0)
            return rightRotate(root);

        // Left Right Case
        if (balance > 1 &&
                getBalance(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 &&
                getBalance(root->right) <= 0)
            return leftRotate(root);

        // Right Left Case
        if (balance < -1 &&
                getBalance(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void printProductsForPurchase(){
        printProductsForPurchaseHelper(root);
    }

private:
    NewAVLNode *root;



};
