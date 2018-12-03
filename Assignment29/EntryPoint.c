#include"MyHeader.h"

int main(int argc, char const *argv[])
{
    int iChoice,iNo;
    PNODE First=NULL,temp=NULL;
    BOOL Running=TRUE;
    char ch;
    char str[30];
    int iArr[5]={10,20,30,45,75};

    while(Running)
    {
        printf("1. Question 1\n2. Question 2\n3. Question 3\n4. Question 4\n5. Question 5\n0. Exit\nEnter your choice:");
        scanf("%d",&iChoice);

        
        switch (iChoice)
        {
            case 0:
                Running=FALSE;
                break;

            case 1:
                printf("Enter a positive integer number:");
                scanf("%d",&iNo);
                printf("Number of digits in %d is %d\n",iNo,Count(iNo));
                break;

            case 2:
                printf("Addition of array is:%d\n",AddR(iArr,5));
                break;

            case 3:
                InsertFirst(&First,15);
                InsertFirst(&First,20);
                InsertFirst(&First,12);
                InsertFirst(&First,25);
                InsertFirst(&First,10);   
                DisplayLL(First);                             
                printf("NULL\n");
                break;

            case 4:
                printf("Enter a string:");
                scanf("%s",str);
                StrRevDisplayR(str);
                printf("\n");
                break;

            case 5:
                printf("Enter a positive integer number:");
                scanf("%d",&iNo);
                printf("Factors of %d is:\t",iNo);
                FactorR(iNo);
                printf("\n");
                break;

            default:
                printf("Invalid Choice!\n");
                break;
        }

    }
    
    while(First!=NULL)
    {
        temp=First->next;
        free(First);
        First=temp;
    }
    printf("Linked list after deleting all nodes:\n");
    DisplayLL(First);
    printf("NULL\n");

    return 0;
}