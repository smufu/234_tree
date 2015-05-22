#ifndef TREE_HPP
#define TREE_HPP
#include "tree/node.hpp"

template <typename T>
class Tree {
private:
	Node<T>* root;
public:
	Tree() {
		root = nullptr;
	}
	~Tree() {
		delete root;
	}
	add(const T& d) {
		if(root == nullptr)
			root = new Node(d);
		else {
			
		}
	}
};

#endif