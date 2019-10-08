#ifndef _AVLNODE_H
#define _AVLNODE_H

class AVLNODE
{

public:
	int value;
	struct AVLNODE *lNode;
	struct AVLNODE *rNode;
	int height;

	AVLNODE(int v, AVLNODE *l, AVLNODE *r, int h = 0)
	{
		value = v;
		lNode = l;
		rNode = r;
		height = h;
	}
	~AVLNODE()
	{
		if (lNode)
			delete lNode;
		if (rNode)
			delete rNode;
	}
};

#endif // !_AVLNODE_H

