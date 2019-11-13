#pragma once
#include <fstream>
// C++ program for B-Tree insertion
#include "../nodeTypes/BNodeClient.h"

using namespace std;



// A BTreeClients
class BTreeClients{
    BTreeNode *root; // Pointer to root node
    int t; // Minimum degree
public:
    // Constructor (Initializes tree as empty)
    explicit BTreeClients(){ root = nullptr; t = 3;highestBoughtValue=0.0;mostBoughtValue=0;}

    // function to traverse the tree
    void traverse(){
        if (root != nullptr){
            root->traverse();
        }
    }

    bool generateMostExpensiveBill(const string &path) {
        try {
            ofstream outfile (path);
            outfile << "Most expensive bill report. " << endl;

            root->getHighestBoughtValue(highestBoughtValue);
            root->generateMostExpensiveBill(highestBoughtValue, outfile);

            outfile.flags();
            outfile.close();
            cout << "Report generated successfully..." << endl;
            return true;
        } catch (...) {
            return false;
        }
    }
    bool generateMostBilledClient(const string &path){
        try {
            ofstream outfile (path);
            outfile << "Most billed client report. " << endl;

            root->getMostBoughtValue(mostBoughtValue);
            root->generateMostBilledClient(mostBoughtValue, outfile);

            outfile.flags();
            outfile.close();
            cout << "Report generated successfully..." << endl;
            return true;
        } catch (...) {
            return false;
        }
    }
    bool generateLeastExpensiveBill(const string &path) {
        try {
            ofstream outfile (path);
            outfile << "Least expensive bill report. " << endl;

            highestBoughtValue = root->searchClient(root->keys[0]).getAmountSpent();
            root->getLowestBoughtValue(highestBoughtValue);
            root->generateLeastExpensiveBill(highestBoughtValue, outfile);

            outfile.flags();
            outfile.close();
            cout << "Report generated successfully..." << endl;
            return true;
        } catch (...) {
            return false;
        }
    }
    bool generateLeastBilledClient(const string &path) {
        try {
            ofstream outfile (path);
            outfile << "Least expensive bill report. " << endl;

            mostBoughtValue = root->searchClient(root->keys[0]).getAmountSpent();
            root->getLeastBoughtValue(mostBoughtValue);
            root->generateLeastBilledClient(mostBoughtValue, outfile);

            outfile.flags();
            outfile.close();
            cout << "Report generated successfully..." << endl;
            return true;
        } catch (...) {
            return false;
        }
    }
    bool generateClients(const string &path) {
        try {
            ofstream outfile (path);
            outfile << "Clients List. " << endl;

            root->generateClients(outfile);

            outfile.flags();
            outfile.close();
            cout << "Report generated successfully..." << endl;
            return true;
        } catch (...) {
            return false;
        }
    }

    string getClientsForServer(){
        string concat;
        return root->generateClientsAsString(concat);
    }

    // function to search a key in this tree
    BTreeNode* search(int k){
        return (root == nullptr)? nullptr : root->search(k);
    }

    ClientData searchClient(int k) {
        return root->searchClient(k);
    }

    // The main function that inserts a new key in this B-Tree
    void insert(int k, const ClientData& clientData)
    {
        // If tree is empty
        if (root == nullptr)
        {
            // Allocate memory for root
            root = new BTreeNode(t, true);
            root->keys[0] = k; // Insert key
            root->clientDataArray[0]=clientData;
            root->n = 1; // Update number of keys in root
        }
        else // If tree is not empty
        {
            // If root is full, then tree grows in height
            if (root->n == 2*t-1)
            {
                // Allocate memory for new root
                auto *s = new BTreeNode(t, false);

                // Make old root as child of new root
                s->C[0] = root;

                // Split the old root and move 1 key to the new root
                s->splitChild(0, root);

                // New root has two children now. Decide which of the
                // two children is going to have new key
                int i = 0;
                if (s->keys[0] < k)
                    i++;
                s->C[i]->insertNonFull(k, clientData);

                // Change root
                root = s;
            }
            else // If root is not full, call insertNonFull for root
                root->insertNonFull(k, clientData);
        }
    }

    float highestBoughtValue;
    int mostBoughtValue;

    void remove(int k)
    {
        if (!root)
        {
            cout << "The tree is empty\n";
            return;
        }

        // Call the remove function for root
        root->remove(k);

        // If the root node has 0 keys, make its first child as the new root
        //  if it has a child, otherwise set root as NULL
        if (root->n==0)
        {
            BTreeNode *tmp = root;
            if (root->leaf)
                root = nullptr;
            else
                root = root->C[0];

            // Free the old root
            delete tmp;
        }
        return;
    }
};
