#include <stdio.h>
#include <set>
#pragma once

class Node
{
public:
	Node(int value) {
		this->_value = value;
		this->_left = nullptr;
		this->_right = nullptr;
	};

	Node* GetLeft() {
		return this->_left;
	};

	Node* GetRight() {
		return this->_right;
	};

	int GetValue() {
		return this->_value;
	};

	void SetValue(int value) {
		this->_value = value;
	};
	void SetLeft(Node* left) {
		this->_left = left;
	};
	void SetRight(Node* right) {
		this->_right = right;
	};
private:
	int _value;
	Node* _left;
	Node* _right;
};

class BST
{
private:
	Node* _root;
public:
	BST();
	~BST();
	void DeleteTree(Node* root);
	Node* Search(int value);
	Node* SearchRecursive(Node* root, int value);
	bool IsValueInTree(int value);
	Node* Insert(int value);
	bool IsEmpty();
	void PrintPreOrder(Node* root);
	void PrintInOrder(Node* root);
	void PrintPostOrder(Node* root);

	Node* GetRoot() {
		return this->_root;
	};
};