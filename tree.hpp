#ifndef TREE_HPP
#define TREE_HPP
#include "tree/node.hpp"
#include "plotable.hpp"

template <typename T>
class Tree: public Plotable {
private:
	Node<T>* root;
public:
	Tree() {
		root = nullptr;
	}
	~Tree() {
		delete root;
	}
	void add(const T& d) {
		if(root == nullptr)
			root = new Node<T>(d);
		else {
			Node<T>* bkup = root;
			while(true) {
				if(bkup->isFull()) {
					root->split();
				}
				if(bkup->hasChildren()) {
					// spulen
					cout << "Noch nicht implementiert" << endl;
					return;
				} else {
					//einfügen
					bkup->add(d);
					break;
				}
			}
		}
	}
	virtual void* getRootNode() {
		return root;
	}
	virtual string getNodeName(void* node) {
		return getNodeValue(node);
	}
	virtual string getNodeValue(void* node) {
		string val = "";
		Node<T>* n = (Node<T>*) node;
		for(char i=0; i<n.getSize(); ++i) {
			val = val + to_string(n[i]);
		}
		return val;
	}
	virtual bool hasNodeValue(void* node) {
		Node<T>* n = (Node<T>*) node;
		return !n->isEmpty();
	}
	virtual vector<void*> getNodes(void* node) {
		Node<T>* n = (Node<T>*) node;
		vector<void*> v;
		if(n->isEmpty())
			return v;
		v.push_back(n[0].left());
		for(char i=0; i<n.getSize(); ++i)
			v.push_back(n[i].right());
		return v;
	}
};

#endif