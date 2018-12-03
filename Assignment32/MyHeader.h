#include<iostream>
using namespace std;
#include<malloc.h>


#define TRUE 1;
#define FALSE 0;

struct Node;
typedef struct Node * PNODE;
typedef unsigned int BOOL;

/*class SinglyLinkedList;
class Number;
class Operation;*/
/*namespace MyNamespace
{

}*/
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

    };


    class Operation : public SinglyLinkedList
    {
        public:
            
            Operation();
            ~Operation();
            Operation & operator+(Operation &);
            void ConcatFirstN(Operation &,int);
            void ConcatListRange(Operation &,int,int);
            void LLCopy(Operation &);
            void LLNCopy(Operation &,int);
            void TraveseInsertFirst(PNODE,PNODE);
            void InsertFirstN(PNODE,int);

    };
}