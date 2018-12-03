#include<iostream>
using namespace std;
#include<malloc.h>


#define TRUE 1;
#define FALSE 0;

struct Node;
typedef struct Node * PNODE;
typedef unsigned int BOOL;

namespace MyNamespace
{
    class SinglyLinkedList
    {
        protected:
            PNODE Head;
            int Length;

        public:
            SinglyLinkedList();
            void InsertFirst(int);
            void InsertLast(int);
            void DisplayAll();
            void InsertAt(PNODE,int);
            void InsertBefore(PNODE,PNODE,int); 

    };

    class Operation : public SinglyLinkedList
    {
        public:            
            Operation();
            ~Operation();
            Operation & operator+(Operation &);
            void Swap();
            void InsertLinkedListAt(Operation &,int);
            BOOL ListIntersect(Operation &);
            BOOL ListPallindrome();
            BOOL TraversalCheck(PNODE);
            BOOL CmpList(Operation &);

    };
}