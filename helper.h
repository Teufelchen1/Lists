
typedef struct element element;

struct element{
	element *last;
	element *next;
	void *data;
};

typedef struct{
	int length;
	element *start;
}list;

element *newElement(void *data);
element *findLastElm(list *in);
element *findlastElm(element *el);
element *nextElement(element *el);
list *newList(int len);
void addElement(list *in,element *el);
void removeElement(element *el);
void *knalloc(size_t size); 
