#include "llist.h"

class slist : public llist
{

public:
	slist();

	int search(el_t);

	void replace(el_t, int);
}; 