#include<iostream>
using namespace std;
#include<malloc.h>


#define TRUE 1;
#define FALSE 0;

struct Node;
typedef struct Node * PNODE;

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
            void DisplayAll();    

    };

    class Number
    {
        public:
            //inline int Addition(int,int);
            inline int Maximum(int,int);
            inline int Minimum(int,int);

    };

    class Operation : public SinglyLinkedList,public Number
    {
        public:
            int SearchFirst(int);
            int SearchLast(int);
            int Addition(PNODE);
            int Maximum();
            int Minimum();
            int Search(PNODE,int);
    };
}