
#include "AVLTree.h"

static const int ALLOWED_IMBALANCE = 1;
int AVLTree::height(AVLNODE *node)
{
	if (node == NULL)
		return -1;
	return node->height;
}

void AVLTree::balance(AVLNODE*& node)
{
	if(node == NULL)
		return;
	
	/*if (node->lNode == NULL || node->rNode == NULL)
		return;
	*/ 
	if (height(node->lNode) - height(node->rNode) > ALLOWED_IMBALANCE)
	{
		/*if (node->lNode->lNode == NULL || node->lNode->rNode == NULL)
			return;
		*/
		if (height(node->lNode->lNode) >= height(node->lNode->rNode))
			rotateWithLeftChild(node);
		else
			doubleWithLeftChild(node);
	}
	else
	{
		
		if (height(node->rNode) - height(node->lNode) > ALLOWED_IMBALANCE)
		{
			/*if (node->rNode->lNode == NULL || node->rNode->rNode == NULL)
				return;
			*/ 
			if (height(node->rNode->rNode) >= height(node->rNode->lNode))
				rotateWithRightChild(node);
			else
				doubleWithRightChild(node);

		}
	}
	node->height = max(height(node->lNode), height(node->rNode)) + 1;
		
}

void AVLTree::rotateWithLeftChild(AVLNODE *& k2)
{
	/*if (k2->lNode == NULL || k2->rNode == NULL)
		return;*/

	AVLNODE *k1 = k2->lNode;
	k2->lNode = k1->rNode;
	k1->rNode = k2;
	k2->height = max(height(k2->lNode), height(k2->rNode)) + 1;
	k1->height = max(height(k1->lNode), k2->height) + 1;
	k2 = k1;
}

void AVLTree::rotateWithRightChild(AVLNODE *& k2)
{
	/*if (k2->lNode == NULL || k2->rNode == NULL)
		return;*/
	AVLNODE *k1 = k2->rNode;
	k2->rNode = k1->lNode;
	k1->lNode = k2;
	k2->height = max(height(k2->rNode), height(k2->lNode)) + 1;
	k1->height = max(height(k1->rNode), k2->height) + 1;
	k2 = k1;
}

int AVLTree::max(int a, int b)
{
	return a > b ? a : b;
}
void AVLTree::doubleWithLeftChild(AVLNODE *& k3)
{
	rotateWithRightChild(k3->lNode);
	rotateWithLeftChild(k3);
}

void AVLTree::doubleWithRightChild(AVLNODE *& k3)
{
	rotateWithLeftChild(k3->rNode);
	rotateWithRightChild(k3);
}

void AVLTree::insert(AVLNODE*& parent, AVLNODE *child)
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
	balance(parent);
}

void AVLTree::insert(int val)
{
	AVLNODE *node = new AVLNODE(val, NULL, NULL);
	insert(m_root, node);
	print();
}

void AVLTree::print(AVLNODE* node, int depth)
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

void AVLTree::print()
{
	print(m_root);
	cout << endl << endl << endl;
}

AVLTree::AVLTree()
{
	m_root = NULL;
	m_count = 0;
}


AVLTree::~AVLTree()
{
	delete m_root;
}
