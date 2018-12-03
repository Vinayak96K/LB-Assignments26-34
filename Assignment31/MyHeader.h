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
            void DisplayAll();    

    };

    class Number
    {
        public:
            inline int Addition(int,int);
            inline int Maximum(int,int);
            inline int Minimum(int,int);
            bool IsPerfect(int);
            bool IsPrime(int);
            int SumDigit(int);
                      

    };

    class Operation : public SinglyLinkedList,public Number
    {
        public:
        ~Operation();
        void DisplayPerfect();
        void DisplayPrime();
        void DisplaySumDigit();
        int SecMaximum();
        int AdditionEven();
    };
}