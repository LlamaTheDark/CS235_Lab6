#include "BST.h"

BST::BST(){}
BST::~BST(){
    delete root;
}

Node * BST::getRootNode() const { return root; }


bool BST::add(int data) {
    return add(data, root);
}
bool BST::add(int data, Node *& subroot){
    if(subroot->isEmpty()){
        subroot = new Node(data);
        return true;
    }

    if(data == subroot->getData()) {
        return false;
    }

    if(data < subroot->getData()) {
        return add(data, subroot->getLeft());
    } else {
        return add(data, subroot->getRight());
    }
}

bool BST::remove(int data) {
    return remove(data, root);
}
bool BST::remove(int data, Node *& subroot) {
    // find parent of node to be removed
    if(subroot->isEmpty()){
        return false;
    }

    // std::cout << "removing " << data << "..." << std::endl;
    // std::cout << "currently looking at node with data: " << subroot->getData() << std::endl;
    
    if(data < subroot->getData()) {
        // std::cout << "\tthe node is to the left!" << std::endl;
        return remove(data, subroot->getLeft());
    } else if(subroot->getData() < data) {
        // std::cout << "\tthe node is to the right!" << std::endl;
        return remove(data, subroot->getRight());
    } else {
        // std::cout << "\t\tFOUND THE NODE!!" << std::endl;

        // std::cout << "- - - - - - - -" << std::endl;
        // std::cout << "does it have empty children?" << std::endl;
        if (subroot->getLeft()->isEmpty()) {
            // std::cout << "\tyes! we know at least the left child is empty." << std::endl;
            // std::cout << "\tnow replacing this node with node @" << subroot->getRight() << std::endl;
            Node * tmp = subroot;
            subroot = subroot->getRight();
            tmp->loseChildren();
            delete tmp;

            // std::cout << "new address for subroot: " << subroot << std::endl;
            // std::cout << "sucess!" << std::endl;
        } else if(subroot->getRight()->isEmpty()) {
            // std::cout << "\tyes! we know at least the right child is empty." << std::endl;
            Node * tmp = subroot;
            subroot = subroot->getLeft();
            tmp->loseChildren();
            delete tmp;
            // std::cout << "sucess!" << std::endl;

        } else {
            // std::cout << "\tnope, both children full. Replacing the parents now." << std::endl;
            // std::cout << "we'll start by searching the left subtree with root " << subroot->getLeft()->getData() << std::endl;
            // std::cout << "- - - - - - - -" << std::endl;
            // Node * oldroot = subroot;

            replaceParent(subroot, subroot->getLeft());

            // oldroot->loseChildren();
            // delete oldroot;

        }

        return true;
    }
}

void BST::replaceParent(Node *& oldRoot, Node *& localRoot) {
    // find the rightmost local root that does not have a right child and call it localRoot
    // replace the data in oldRoot with the data in localRoot
    // call remove on the left subtree of oldRoot to delete the local root node.
    if(!localRoot->getRight()->isEmpty()){
        replaceParent(oldRoot, localRoot->getRight());
    } else {
        oldRoot->setData(localRoot->getData());
        remove(localRoot->getData(), oldRoot->getLeft());

        // delete localRoot;
    }
}



void BST::clear() {
    delete root;
    root = NULL;
}

void BST::traverse() {
    // std::cout << "###########################################" << std::endl;
    // std::cout << "###########################################" << std::endl;
    // std::cout << "###########################################" << std::endl;

    traverse(root);
}

void BST::traverse(Node *& subroot) {
    
    // std::cout << "subroot: " << subroot << std::endl;
    if(!subroot->isEmpty()){
        // std::cout << "\t\tdata: " << subroot->getData() << std::endl;
        // std::cout << "left-";
        traverse(subroot->getLeft());
        std::cout << subroot->getData() << std::endl;
        // std::cout << "right-";
        traverse(subroot->getRight());
    }
}