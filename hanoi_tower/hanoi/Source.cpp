#include <iostream>
using namespace std;


void move(int n, char start, char pom, char cil) { //n pocet kotoucu, start startovni jehla, cil konecna jehla, pom pomocna prenosna jehla
	if (n > 0) {
		move(n - 1, start, cil, pom); 
	cout << "Presun disk z " << start << " do " << cil << endl; 
	move(n - 1, pom, start, cil); 
	}
}



int main () {
	int N = 3;
	move(N, 'a','b', 'c');
	return 0;}