#include <iostream>
//#include "tree.hpp"
//#include "writer.hpp"
//#include "tree/node.hpp"
#include "tree.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
	/*
	Node<int> n;

	cout << "Knoten:" << endl << "===" << endl;
	cout << " lehr:      " << n << endl;

	n.add(1);
	
	cout << " 1 element: " << n << endl;


	n.add(2);
	n.add(3);

	cout << " voll:      " << n << endl;


	n.split();

	cout << " geteilt:   " << n << endl;
	*/
	Tree<int> baum;

	baum.add(1);
	baum.add(1);
	baum.add(1);	

	return 0;
}