#include "Node.h"


/* CONSTRUCTORS */

Node::Node() {}
Node::Node(int data) {
    this->data = data;
}
Node::Node(int data, Node * parent) {
    this->data = data; // not sure which data this will refer to...
    this->parent = parent;
}

/* - - - - - - - - */

/* DESTRUCTORS */

Node::~Node(){
    delete left;
    delete right;
}

/* - - - - - - - - */

/* ACCESSORS */

int Node::getData() const {
    return this->data;
}

Node *Node::getLeftChild() const {
    return this->left;
}
Node *Node::getRightChild() const {
    return this->right;
}

Node *& Node::getLeft() {
    return this->left;
}
Node *& Node::getRight() {
    return this->right;
}
Node *& Node::getParent() {
    return this->parent;
}

/* - - - - - - - - */

/* MUTATORS */

void Node::setData(int data) {
    this->data = data;
}

/* - - - - - - - - */

/* OTHER */

bool Node::isEmpty() const { return this == NULL; }

void Node::loseChildren() {
    left = NULL;
    right = NULL;
}

/* - - - - - - - - */