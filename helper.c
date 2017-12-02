#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helper.h"

//Dynamische Speicherzuweisung für die Anzahl an bytes die übergeben wird, Fehlerbehandlng ist integriert
void *knalloc(size_t size) {
	/* The german word "Knall" means bang/explosion.
	* This function's name is thus to be considered a pun. cc PyroPeter*/
	void *mem = calloc(size,1);
	if (mem == NULL) {
		fprintf(stderr, "malloc() failed. out of memory?\n");
		exit(EXIT_FAILURE);
	}
	return mem;
}

element *newElement(void *data){
	element *ptr = knalloc(sizeof(element));
	ptr->data = data;
	return ptr;
}

element *findlastElm(element *in){
	if(in->next != NULL){
		return findlastElm(in->next);
	}
	return in;
}

list *newList(int len){
	list *ls = knalloc(sizeof(list));
	ls->start = newElement(NULL);
	ls->length = 1;
	for (int i = 1; i < len; ++i){
		addElement(ls, newElement(NULL));
	}
	return ls; 
}

void addElement(list *in,element *el){
	if(in->start != NULL){
		findlastElm(in->start)->next = el;
	} else {
		printf("Your list is broken!\n");
		return;
	}
	in->length++;
}

int fillList(list *in, char *txt){
	element *tmp;

	if(strlen(txt) > in->length){
		for (int i = in->length; i < (strlen(txt)); ++i){
			addElement(in, newElement(NULL));
		}
	}

	tmp = in->start;
	for (int i = 0; i < strlen(txt); ++i){
		tmp->ch = txt[i];
		tmp = tmp->next;
	}
	return 0;
}