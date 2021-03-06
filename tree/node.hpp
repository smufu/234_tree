#ifndef NODE_HPP
#define NODE_HPP
#define width 3
#include <iostream>
using namespace std;

template <typename T> class Node;

template <typename T>
class Item {
private:
	T* data;
	Node<T>** _left;
	Node<T>** _right;
public:
	Item(Node<T>** l,Node<T>** r,T* d) {
		_left  = l;
		_right = r;
		data  = d;
	}
	Node<T>*& left() {
		return *_left;
	}
	Node<T>*& right() {
		return *_right;
	}
	T operator=(const T& d) {
		*data = d;
		return d;
	}
	operator T() {
		return *data;
	}
};

template <typename T>
class Node {
private:
	T* data;
	Node<T>** children;
	//const char width;
	char filled;
public:
	/**
	 * @brief creates node in forbiden state
	 * @details note that every note musst habe at least 1 value entry
	 */
	Node(/*+char width*/) {
		/*+this->width = width;*/
	 	data = new T[width];
	 	children = new Node<T>*[width+1];
	 	filled = 0;
	}
	Node(const T& data/*+, char width*/) {
		/*+this->width = width;*/
	 	this->data = new T[width];
	 	children = new Node<T>*[width+1];
	 	filled = 0;
	 	add(data);
	}
	~Node() {
		if(filled > 0)
			for(char i=0; i<=filled; i++)
				delete children[(int)i];
		delete[] children;
		delete[] data;
	}
	void disconnect() {
		for(char i=0; i<filled; i++)
			children[(int)i] = nullptr;
	}
	Item<T> operator[](char index) {
		//if(isEmpty())
		//	throw "Node is Empty can't access item";
		Item<T> i(
			&children[(int)index],
			&children[(int)(index+1)],
			&data[(int)index]
		);
		return i;
	}
	void add(const int& data) {
		if(data == 3)
			cout << "DREI GEFUNDEN!!!" << endl;
		if(filled >= width)
			throw "Node is full";
		if(filled == 0)
			for(char i=0;i<width+1;i++)
				children[(int)i] = nullptr;
		this->data[(int)filled++] = data;
	}/*
	void add(const T& data) {
		if(filled >= width)
			throw "Node is full";
		if(filled == 0)
			for(char i=0;i<width+1;i++)
				children[(int)i] = nullptr;
		this->data[(int)filled++] = data;
	}*/

	/**
	 * @brief adds nodes T values to current node
	 * @details it does not add children nodes!
	 */
	/*void add(const Node<T>& n) {
		for(char i=0; i<n.filled; i++) {
			add(n[i]);
		}
	}*/
	bool isFull() const {
		return filled >= width;
	}
	bool isEmpty() const {
		return !filled;
	}
	void setSize(char s) {
		filled = s;
	}
	char getSize() const {
		return filled;
	}
	char getCapacity() const {
		return width;
	}
	bool hasChildren() const {
		if(isEmpty())
			return false;
		if(children[0] != nullptr)
			return true;
		for(char i=0; i<filled+1; ++i) {
			if(children[(int)i] != nullptr) {
				return true;
			}
		}
		return false;
	}
	void split(/*Node<T>* parent=nullptr*/) {
		Node<T>* center = new Node<T>;
		Node<T>* left   = new Node<T>;
		Node<T>* right  = new Node<T>;
		char half = width/2;

		(*center)[0]         = data[(int)half];
		(*center)[0].left()  = left;
		(*center)[0].right() = right;
		center->setSize(1);

		(*left)[0].left() = children[0];
		for(char i=0; i<half; i++) {
			(*left)[i]         = data[(int)i];
			(*left)[i].right() = children[(int)(i+1)];
		}
		left->setSize(half);

		(*right)[0].left() = children[half+1];
		for(char i=0, i2=half+1; i<half; i++, i2++) {
			(*right)[i]         = data[(int)i2];
			(*right)[i].right() = children[(int)(i2+1)];
		}
		right->setSize(half);

		delete[] data;
		delete[] children;

		//if(parent == nullptr) {
			data     = center->data;
			children = center->children;
			filled   = center->filled;
		/*} else {
			parent->add((*center)[0]);
			(*parent)[parent->getSize()-1].left()  = left;
			(*parent)[parent->getSize()-1].right() = right;	
		}*/
	}
	char findPath(const T& d) {
		if(filled == 1)
			return d < data[0];
		
	}
	void print(ostream& o=cout, bool endl=true, bool follow=true) const {
		o << "{\"data\":[";
		for(char i=0; i<filled; i++)
			o << data[(int)i] << (i<filled-1?",":"");
		o << "],\"size\":" << ((int)filled) << ",\"children\":[";
		if(filled)
			for(char i=0; i<filled+1; i++) {
				if(follow && children[(int)i] != nullptr)
					children[(int)i]->print(o, false, true);
				else
					o << children[(int)i];
				o << (i<filled?",":"");
			}
		o << "]}";
		if(endl)
			o << std::endl;
	}
};

template <typename T>
ostream& operator<<(ostream& o, const Node<T>& n) {
	n.print(o,false,true);
	return o;
}

#endif