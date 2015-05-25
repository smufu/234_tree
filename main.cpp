#include <iostream>
#include <fstream>
//#include "tree.hpp"
#include "writer.hpp"
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

	baum.add(42);
	baum.add(43);
	baum.add(44);
	cout << baum << endl;
	for(int i=45; i<=64; i++)
		baum.add(i);
	cout << baum << endl;
	
	Writer w(baum);
	ofstream dot("tree.dot");
	cout << endl << "writer dump:" << endl << "===" << endl;
	w.dump();
	w.writeDot(dot);
	system("dot -Tpng tree.dot -o tree.png");

	return 0;
}