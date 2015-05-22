#ifndef _WRITER
#define _WRITER
#include <iostream>
#include "plotable.hpp"
using namespace std;

class Writer {
private:
	Plotable* tree;
	void dot(ostream&,void*);
public:
	Writer();
	Writer(Plotable&);
	~Writer();
	Plotable& getPlotable();
	void setPlotable(Plotable&);
	void writeDot(ostream& o=cout);
	void dump(ostream& o=cout, unsigned int force_stop=25);
	/*void writeJson(ostream& o=cout);
	void writeInOrder(ostream& o=cout);
	void writePreOrder(ostream& o=cout);
	void writePostOrder(ostream& o=cout);
	void writeLevelOrder(ostream& o=cout);*/
};
#endif