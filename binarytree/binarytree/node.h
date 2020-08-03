#pragma once
class Node
{
public:
	///Kontstuktro nody 
	///@param nactena hodnota
	Node(int value) {
		this->_value = value;
		this->_left = nullptr;
		this->_right = nullptr;
	};
	///navraci hodnotu _left
	Node* GetLeft() {
		return this->_left;
	};
	///navraci hodnotu _right
	Node* GetRight() {
		return this->_right;
	};
	///navrati _value
	int GetValue() {
		return this->_value;
	};

	///Nastavi value
	void SetValue(int value) {
		this->_value = value;
	};
	///nastavi levou nodu
	void SetLeft(Node* left) {
		this->_left = left;
	};
	///nastavi pravou nodu
	void SetRight(Node* right) {
		this->_right = right;
	};
private:
	int _value;
	Node* _left;
	Node* _right;
};

