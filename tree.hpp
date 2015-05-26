#ifndef TREE_HPP
#define TREE_HPP
#include "tree/node.hpp"
#include "plotable.hpp"
#include <iostream>
using namespace std;

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
		cout << "HINUFÜGEN " << d << ":" << endl;
		if(root == nullptr) {
			cout << "FALL 0" << endl;
			root = new Node<T>(d);
			cout << "erstelle " << d << " breite is jetzt " << (int)(root->getSize()) << endl;
		} else {
			Node<T>* bkup = root;
			Node<T>* prev = nullptr;
			while(true) {
				if(bkup->isFull()) {
					cout << "FALL 1" << endl;
					//cout << "split ...";
					/*Node<T>* bkup2 = nullptr;
					bkup->split();
					if(prev == nullptr)
						root = prev = new Node<T>((*bkup)[0]);
					else
						prev->add((*bkup)[0]);
					
					(*prev)[prev->getSize()-1].left()  = (*bkup)[0].left();
					(*prev)[prev->getSize()-1].right() = (*bkup)[0].right();	
					if(d < (*bkup)[0])
						bkup2 = (*bkup)[0].left();
					else
						bkup2 = (*bkup)[0].right();
					bkup->disconnect();
					delete bkup;
					bkup = bkup2;
					if(bkup == nullptr)
						cout << "shit" << endl;
					else
						cout << "ok" << endl;
					cout << "done" << endl;*/

					bkup->split();
					if(prev == nullptr) {
						root = prev = new Node<T>((*bkup)[0]);
						(*root)[0].left() = (*bkup)[0].left();
						(*root)[0].right() = (*bkup)[0].right();
					} else {
						prev->add((*bkup)[0]);
						(*prev)[prev->getSize()-1].left() = (*bkup)[0].left();
						(*prev)[prev->getSize()-1].right() = (*bkup)[0].right();
					}
					if(d < (*bkup)[0]) {
						prev = (*bkup)[0].left();
					} else {
						prev = (*bkup)[0].right();	
					}
					//bkup->disconnect(); // bkup is still used anywhere
					//delete bkup;
				}
				else if(bkup->hasChildren()) {
					cout << "FALL 2" << endl;
					// spulen
					// wenn kleiner als bkup[0] dann bkup[0]->left();
					// ansonsten wenn größer als bkup[i{0}] und kleiner als bkup[i+1{1}]   bkup[0]->right() oder bkup[1]->left()
					//   wiederhole für alle i
					// ansonsten wenn größer als bkup[n-1{bkup->getSize()-1}] dann bkup[1]->right()
					// ansonsten nicht gefunden
					//cout << "Noch nicht implementiert" << endl;
					if(d < (*bkup)[0]) {
						prev = bkup;
						bkup = (*bkup)[0].left();
					}
					else if(d > (*bkup)[bkup->getSize()-1]) {
						prev = bkup;
						bkup = (*bkup)[bkup->getSize()-1].right();
					}
					else {
						for(char i=0; i<bkup->getSize()-1; ++i) {
							if(d > (*bkup)[i] && d < (*bkup)[i+1]) {
								prev = bkup;
								bkup = (*bkup)[i].right();
								continue;
							}
						}/*
						if(!bkup->isFull()) {
							cout << "füge zu aus verzweiflung xd" << endl;
							bkup->add(d);
						} else {
							cout << "Fehler unbehandelter Fall, weiß nicht was ich machen soll???" << endl;
							throw "error tree is inconsistent state";
						}*/
					}
					//return;
				} else {
					cout << "FALL 3" << endl;
					//einfügen
					cout << "füge zu" << endl;
					if(bkup->isFull())
						cout << "this should not happen, programm may be crash now" << endl;
					bkup->add(d);
					cout << "füge " << d << " hinzu breite is jetzt " << (int)(bkup->getSize()) << endl;
					break;
				}
			}
		}
	}
	void print(ostream& o=cout, bool endl=true) const {
		if(root != nullptr)
			root->print(o, endl, true);
	}
	virtual void* getRootNode() {
		return root;
	}
	virtual string getNodeName(void* node) {
		return getNodeValue(node);
	}
	virtual string getNodeValue(void* node) {
		string val = "\"";
		Node<T>* n = (Node<T>*) node;
		bool first=true;
		for(char i=0; i<n->getSize(); ++i) {
			if(first) first = false;
			else val+=' ';
			val = val + to_string((*n)[i]);
		}
		val+="\"";
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
		if((*n)[0].left() != nullptr)
			v.push_back((*n)[0].left());
		for(char i=0; i<n->getSize(); ++i)
			if((*n)[i].right() != nullptr)
				v.push_back((*n)[i].right());
		return v;
	}
};
template <typename T>
ostream& operator<<(ostream& o, const Tree<T>& t) {
	t.print(o,false);
	return o;
}

#endif