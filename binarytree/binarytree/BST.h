#include <stdio.h>
#include <set>
#include "node.h"
#pragma once

class BST
{
private:
	Node* _root;
public:
	///konstruktor na strom
	BST() {
		this->_root = nullptr;
	}
	///destruktor stromu

	~BST()  { 
		DeleteTree(this->_root);
	}
	
	///vymaze strom
	///@param _root
	///pokud root neni nullptr tak ho smaze
	//rekurzivni volani se postara o to aby se dalo dostat az nakonec a smazat vsechny prvky
	void DeleteTree(Node* root);

	///@brief v teto funkci se pridavaji hodnoty do stromu
	///@param  int value 
	///@returns current
	///@note vyuzito materialu ze cviceni z alg
	///prohledava strom dokud nenajde vhodnou pozici pro data 
	///porovnava data s current Node pokud je hodnota nizsi tak se strom nori doleva jinak doprava 
	///pote najde pozici a vlozi hodnotu
	Node* Insert(int value);


///@param  Node* root
///@return isMirror(root,root)
///vrati true pokud jsou stromy symetricke
	bool isSymmetric(Node* root);

///@param  Node* root1, Node* root2
///@return true or false
/// prochazi koreny pokud jeden skonci driv nez druhy tak vrati false pokud oba soucasne tak true
///@note algoritmus inspirovan geeksforgeeks prispevkem
	bool isMirror(Node* root, Node* root1);
	
	Node* GetRoot() {
		return this->_root;
	};
};