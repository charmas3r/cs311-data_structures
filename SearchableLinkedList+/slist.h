#include "llist.h"

class slist : public llist
{

public:
	slist();

	slist(const slist& original);

	slist& operator=(const slist& L2);

	int search(el_t);

	void replace(el_t, int);

	bool operator==(slist& L2);

};