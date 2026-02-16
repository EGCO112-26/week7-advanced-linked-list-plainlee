// #ifndef LL_H
// #define LL_H

// #include <string.h>
// // self-referential structure
// struct Node {
//    int id; // each listNode contains a character
//    char name[50];
//    struct Node *nextPtr; 
//    struct Node *previousPtr;// pointer to next node
// }; // end structure listNode

// typedef struct Node LLnode; // synonym for struct listNode
// typedef LLnode *LLPtr; // synonym for Listnode*

// // prototypes

// int deletes( LLPtr *sPtr, int id );
// int isEmpty( LLPtr sPtr );
// void insert( LLPtr *sPtr, int id, char *name );
// void printList( LLPtr currentPtr );
// void instructions( void );
// void clearList( LLPtr *sPtr );
// #endif

#ifndef LL_H
#define LL_H

#include <string.h>

struct Node {
   int id;
   char name[50];
   struct Node *nextPtr;
   struct Node *previousPtr;
};

typedef struct Node LLnode;
typedef LLnode *LLPtr;

// prototypes
int deletes( LLPtr *sPtr, int id );
int isEmpty( LLPtr sPtr );
void insert( LLPtr *sPtr, int id, char *name );
void printList( LLPtr currentPtr );
void instructions( void );
void clearList( LLPtr *sPtr );

#endif