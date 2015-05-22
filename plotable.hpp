#ifndef _PLOTABLE
#define _PLOTABLE
#include <string>
#include <vector>
using std::string;
using std::vector;

/* /class Plotable
 * /brief Plotable is a interface alowing tree like strutures to be plotet by graphviz dot
 /*/
class Plotable {
public:
	virtual ~Plotable() {}
	virtual void* getRootNode()=0;
	virtual string getNodeName(void*)=0;
	virtual string getNodeValue(void*)=0;
	virtual bool hasNodeValue(void*)=0;
	virtual vector<void*> getNodes(void*)=0;
};
#endif