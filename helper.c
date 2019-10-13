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

element *newElement(void *data, size_t size){
	element *ptr = knalloc(sizeof(element));
	ptr->data = data;
	ptr->size = size;
	return ptr;
}


element *findLastElm(list *in){
	if(in->start != NULL){
		return findlastElm(in->start);
	}
	return NULL;
}

element *findlastElm(element *el){
	if(el->next != NULL){
		return findlastElm(el->next);
	}
	return el;
}

list *newList(int len){
	list *ls = knalloc(sizeof(list));
	ls->start = NULL;
	ls->length = 0;
	if(len){
		ls->start = newElement(NULL, 0);
		ls->length = 1;
		for (int i = 1; i < len; ++i){
			addElement(ls, newElement(NULL, 0));
		}
	}
	return ls; 
}

void addElement(list *in, element *el){
	if(in->start != NULL){
		element *last = findlastElm(in->start);
		last->next = el;
		el->last = last;
	} else {
		in->start = el;
		el->last = NULL;
	}
	in->length++;
}

void removeElement(list *in, element *el){
	if(el->last && el->next){
		el->last->next = el->next;
		el->next->last = el->last;
	} else if(el->last) {
		el->last->next = NULL;
	} else {
		in->start = NULL;
	}
	in->length--;
}

element *nextElement(element *el){
	if(el != NULL && el->next != NULL){
		return el->next;
	} else {
		return NULL;
	}

}

/*
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
*/