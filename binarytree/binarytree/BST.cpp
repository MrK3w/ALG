#include "BST.h"


void BST::DeleteTree(Node* root) 
{
	
	if (root == nullptr) 
	{
		return;
	}
	
	DeleteTree(root->GetLeft());
	DeleteTree(root->GetRight());
	delete root;
}

Node* BST::Insert(int value)
{
Node* node = new Node(value);

 if (!_root)
{
	this->_root = node;
	return node;
}
Node* current = this->_root;

while (value != current->GetValue())
{
	
	if (value < current->GetValue())
	{
		if (current->GetLeft() == nullptr)
		{
			current->SetLeft(node);
			return node;
		}
		current = current->GetLeft();
	}
	else
	{
		if (current->GetRight() == nullptr)
		{
			current->SetRight(node);
			return node;
		}
		current = current->GetRight();
	}
}
}

bool BST::isMirror(Node* root1, Node* root2)
{
	
	if (root1 == NULL && root2 == NULL) {
		return true;
	}	
	if (root1 == NULL || root2 == NULL) return false;

	else return isMirror(root1->GetLeft(), root2->GetRight()) && isMirror(root1->GetRight(), root2->GetLeft()); 
}


bool BST::isSymmetric(Node* root)
{
	if (!root) return true;
	return isMirror(root, root);
}