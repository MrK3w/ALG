#include "BST.h"

BST::BST()
{
	this->_root = nullptr;
}

BST::~BST()
{
}

void BST::DeleteTree(Node* root)
{
}

Node* BST::Search(int value)
{
	Node* current = this->_root;
	if (current == nullptr) {
		return nullptr;
	}
	while (value != current->GetValue())
	{
		if (value < current->GetValue())
		{
			current = current->GetLeft();
		}
		else {
			current = current->GetRight();
		}
		if (current == nullptr)
		{
			return nullptr;
		}
	}
	return current;
}

Node* BST::SearchRecursive(Node* root, int value)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	if (root->GetValue() == value) {
		return root;
	}
	if (value < root->GetValue())
	{
		return SearchRecursive(root->GetLeft(), value);
	}
	return SearchRecursive(root->GetRight(), value);
}

bool BST::IsValueInTree(int value) 
{
	return false;
}

Node* BST::Insert(int value)
{
	Node* node = new Node(value);

	if (this->IsEmpty())
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

bool BST::IsEmpty()
{
	return this->_root == nullptr;
}

void BST::PrintPreOrder(Node* root)
{
}

void BST::PrintInOrder(Node* root)
{
	if (root == nullptr)
	{
		return;
	}

	PrintInOrder(root->GetLeft());
	printf("%d ", root->GetValue());
	PrintInOrder(root->GetRight());
}

void BST::PrintPostOrder(Node* root)
{
}
