#pragma once
typedef struct element element;

struct element{
	element *last;
	element *next;
	void *data;
	size_t size;
};

typedef struct{
	int length;
	element *start;
}list;

element *newElement(void *data, size_t size);
element *findLastElm(list *in);
element *findlastElm(element *el);
element *nextElement(element *el);
list *newList(int len);
void addElement(list *in,element *el);
void removeElement(list *in, element *el);
void *knalloc(size_t size); 
