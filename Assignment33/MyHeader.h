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
            void LLCopyEX(Operation &);
            int SubList(Operation &);
            void CopyAsen(Operation &);
            void ListReverse();
            void TraversalSwap(PNODE);
            BOOL chkLoop();
            void createLoop();
    };
}