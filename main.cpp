
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include "BinaryTree.h"
#include "AVLTree.h"
#define INPUT_FILE "treenode.txt"

void processBinaryTree()
{
	std::fstream myfile(INPUT_FILE, std::ios_base::in);
	BinaryTree *binaryTree = new BinaryTree();
	string line;

	while (getline(myfile, line))
	{
		std::stringstream   linestream(line);
		std::string         value;

		while (getline(linestream, value, ','))
		{
			int v = atoi(value.c_str());
			binaryTree->insert(v);
		}


	}
}
void processAVLTree()
{
	std::fstream myfile(INPUT_FILE, std::ios_base::in);
	AVLTree *avlTree = new AVLTree();
	string line;

	while (getline(myfile, line))
	{
		std::stringstream   linestream(line);
		std::string         value;

		while (getline(linestream, value, ','))
		{
			int v = atoi(value.c_str());
			avlTree->insert(v);
		}


	}
}
int main()
{

	cout << "Binary Tree:" << endl << endl<<endl;
	processBinaryTree();

	cout << "AVL Tree:" << endl << endl << endl;
	processAVLTree();

	cout << "Finished:" << endl;
	getchar();
	return 0;

}
