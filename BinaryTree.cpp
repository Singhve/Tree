
#include "BinaryTree.h"

void BinaryTree::insert(NODE*& parent, NODE *child)
{
	if (parent == NULL)
	{
		parent = child;
		m_count++;
		return;
	}
	if (parent->value == child->value)
		return;

	if (parent->value > child->value)
		insert(parent->lNode, child);
	if (parent->value < child->value)
		insert(parent->rNode, child);
}

void BinaryTree::insert(int val)
{
	NODE *node = new NODE(val, NULL, NULL);
	insert(m_root, node);
	print();
}

void BinaryTree::print(NODE* node, int depth)
{
	int i;
	string s = "";
	if (node == NULL)
		return;
	if (node->lNode)
		print(node->lNode, depth + 1);
	if (depth != 0)
	{
		for (i = 0; i < INDENT * (depth - 1); i++)
			s += " ";
		for (i = 0; i < CHARACTER_WIDTH * depth; i++)
			s += " ";
		for (i = 0; i < INDENT; i++)
			s += "-";
	}
	std::stringstream ss;
	ss << std::setw(CHARACTER_WIDTH) << std::setfill(' ') << node->value;
	s += ss.str();
	cout << s << endl;

	if (node->rNode)
		print(node->rNode, depth + 1);
}

void BinaryTree::print()
{
	print(m_root);
	cout << endl << endl<<endl;
}
BinaryTree::BinaryTree()
{
	m_root = NULL;
	m_count = 0;
}
BinaryTree::~BinaryTree()
{
	delete m_root;
}