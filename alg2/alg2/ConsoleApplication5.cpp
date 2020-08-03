#include <iostream>
#include "BST.h"
int main()
{
	BST tree = BST();

	tree.Insert(50);
	tree.Insert(70);
	tree.Insert(17);
	tree.Insert(66);
	tree.Insert(44);
	tree.Insert(15); 

	tree.PrintInOrder(tree.GetRoot());
}

