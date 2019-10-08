#ifndef _AVLTREE_H
#define _AVLTREE_H

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdlib.h>
using namespace std;

#include "AVLNode.h"

#define INDENT 3
#define CHARACTER_WIDTH 3
class AVLTree
{
	int m_count;
	int m_height;
	AVLNODE *m_root;

	void print(AVLNODE* node, int depth = 0);
	void insert(AVLNODE*& parent, AVLNODE *child);
	int height(AVLNODE *node);
	void balance(AVLNODE*& node);
	void rotateWithLeftChild(AVLNODE*& node);
	void rotateWithRightChild(AVLNODE*& node);
	void doubleWithLeftChild(AVLNODE*& node);
	void doubleWithRightChild(AVLNODE*& node);
	int max(int a, int b);
public:
	void insert(int val);
	void print();
	AVLTree();
	~AVLTree();
};

#endif // !_AVLTREE_H
