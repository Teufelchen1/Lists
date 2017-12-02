
typedef struct element element;

struct element{
	element *last;
	element *next;
	void *data;
	char ch;
	//int data;
};

typedef struct{
	int length;
	element *start;
}list;

element *newElement(void *data);
element *findlastElm(element *in);
list *newList(int len);
void addElement(list *in,element *el);
void *knalloc(size_t size); 
int fillList(list *in, char *txt);