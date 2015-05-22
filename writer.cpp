#include "writer.hpp"
#include <iostream>
#include <vector>
using namespace std;

Writer::Writer() {
	tree = nullptr;
}
Writer::Writer(Plotable& p) {
	tree = &p;
}
Writer::~Writer() {}
Plotable& Writer::getPlotable() {
	return *tree;
}
void Writer::setPlotable(Plotable& p) {
	tree = &p;
}
void Writer::writeDot(ostream& o) {
	void* n = tree->getRootNode();
	if(n==nullptr)
			return;
	
	o << "digraph tree {" << endl;
	dot(o,n);
	o << "}" << endl;
}
void Writer::dot(ostream& o,void* n) {
	o << " "
		<< tree->getNodeName(n) << " -> {" << endl;
	vector<void*> nodes = tree->getNodes(n);
	for(void* ni:nodes) {
		o << "  " << tree->getNodeName(ni) << endl;
	}
	o << " " << "}" << endl;
	for(void* ni:nodes) {
		dot(o,ni);
	}
}
void Writer::dump(ostream& o, unsigned int stop) {
	void* n = tree->getRootNode();
	if(n == nullptr) {
		o << "root is empty" << endl;
		return;
	}
	o << "root: " << tree->getNodeName(n) << "=>" << tree->getNodeValue(n) << endl;
	vector<void*> nodes = tree->getNodes(n);
	unsigned int count = 0;
	while(!nodes.empty()) {
		vector<void*> nodesi;
		for(void* in:nodes) {
			o << tree->getNodeName(in) << "=>" << tree->getNodeValue(in) << "; ";
			for(void* iin:tree->getNodes(in))
				nodesi.push_back(iin);
		}
		o << endl;
		nodes = nodesi;
		if(stop != 0 && ++count >= stop) {
			o << "tree is to deep you may want to disable force_stop by setting it to zero" << endl;
			o << "or you maybe have build an loop. stoping now" << endl;
			break;
		}
	}
}