#include <stdio.h>

#include "helper.h"


int main(int argc, char const *argv[])
{
	list *eineliste = newList(4);
	printf("%d\n",eineliste->length);

	fillList(eineliste, "Bennet");
	printf("%d\n",eineliste->length);
	printf("%c\n", eineliste->start->next->ch);
	//addElement(eineliste,newElement(NULL));
	//printf("%d\n",eineliste->length);
	//addElement(eineliste,newElement(NULL));
	//printf("%d\n",eineliste->length);
	//addElement(eineliste,newElement(NULL));
	//printf("%d\n",eineliste->start->next->next->data);
	return 0;
}
