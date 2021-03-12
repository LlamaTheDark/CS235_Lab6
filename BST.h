#ifndef BST_H
#define BST_H

#include "BSTInterface.h"
#include "Node.h"

class BST : BSTInterface {
private:
    Node *root = NULL;

public:
	BST();
	virtual ~BST();

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	virtual Node * getRootNode() const;

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	virtual bool add(int data);
    bool add(int data, Node *& subroot);

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	virtual bool remove(int data);
    bool remove(int data, Node *& subroot);


	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	virtual void clear();

    void replaceParent(Node *&, Node *&);

    void traverse();
    void traverse(Node *& subroot);
};

#endif /* BST_H */