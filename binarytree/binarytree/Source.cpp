#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "BST.h"

using namespace std;

int main(int argc, char** argv)
{
	BST tree = BST();
	char* path = argv[1];
	char str[100];
	int i;

	/// overeni argumentu
	if (argc <= 1)
	{
		cout << "Nedostatek argumentu";
		return 1;
	}

	
	FILE* soubor = fopen(path, "r");

	///overeni jestli se poradilo otevrit soubor
	if (soubor == NULL) {
		cout  << "Soubor nelze otevrit!";
		return 1;
	}

	///nacita hodnoty ze souboru
	while (fscanf(soubor, "%d,", &i) > 0) tree.Insert(i);

	///zjisti jestli je strom symetricky nebo ne
	if (tree.isSymmetric(tree.GetRoot()))
	{
		cout << "[1] Strom je symetricky";

	}
	else {
		cout << "[0] Strom neni symetricky";
	}
	return 0;
}
