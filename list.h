#ifndef List_h
#define List_h

/* El programa presentó problemas para leer las estructuras de los nodos a pesar de haber incluido los archivos "list.h", por lo que se movio la estructura a este archivo para que tuviese un acceso más directo de momento.
*/
typedef struct Node{
    void * data;
    struct Node * next;
    struct Node * prev;
} Node;

typedef struct List{
    Node * head;
    Node * tail;
    Node * current;
} List;

List * createList(void);

void * firstList(List * list);

void * nextList(List * list);

void * lastList(List * list);

void * prevList(List * list);

void pushFront(List * list, void * data);

void pushBack(List * list, void * data);

void pushCurrent(List * list, void * data);

void * popFront(List * list);

void * popBack(List * list);

void * popCurrent(List * list);

void cleanList(List * list);

#endif /* List_h */


