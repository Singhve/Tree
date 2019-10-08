#ifndef _NODE_H
#define _NODE_H

class NODE
{
public:

	int value;
	struct NODE *lNode;
	struct NODE *rNode;
	
	NODE(int v, NODE *l, NODE *r)
	{
		value = v;
		lNode = l;
		rNode = r;
		
	}
	~NODE()
	{
		if (lNode)
			delete lNode;
		if (rNode)
			delete rNode;
	}
};

#endif // !_NODE_H

