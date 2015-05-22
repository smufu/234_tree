#include <iostream>
//#include "tree.hpp"
//#include "writer.hpp"
#include "tree/node.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
	Node<int> n;

	n.add(1);
	n.add(2);
	n.add(3);

	n.split();

	cout << n << endl;
	return 0;
}