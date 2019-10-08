#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

#include "Node.h"

#define INDENT 3
#define CHARACTER_WIDTH 3
class BinaryTree
{
	int m_count;
	int m_height;
	NODE *m_root;
	
	void print(NODE* node, int depth = 0);
	void insert(NODE*& parent, NODE *child);
public:
	void insert(int val);
	void print();
	BinaryTree();
	~BinaryTree();
};

#endif // !_BINARYTREE_H