#include <assert.h>
#include <stdio.h>

#include "helper.h"


int main(int argc, char const *argv[])
{
	/* create an empty/zero element list*/
	list *eineliste = newList(0);
	assert(0 == eineliste->length);

	/* create and add an elemet to it */
	addElement(eineliste, newElement("First element of the list!", sizeof("First element of the list!")));
	assert(1 == eineliste->length);
	assert('F' == ((char *)eineliste->start->data)[0]);

	/* add two more elements and remove the second one. */
	addElement(eineliste, newElement("Second element of the list!", sizeof("Second element of the list!")));
	addElement(eineliste, newElement("Third element of the list!", sizeof("Third element of the list!")));
	assert('S' == ((char *)eineliste->start->next->data)[0]); // second element
	assert('T' == ((char *)findLastElm(eineliste)->data)[0]); // last element
	removeElement(eineliste, nextElement(eineliste->start)); // remove the second element
	assert('T' == ((char *)eineliste->start->next->data)[0]); // "Third" is now the second element


	return 0;
}
