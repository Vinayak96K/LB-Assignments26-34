#include"MyHeader.h"

int main(int argc, char const *argv[])
{
    int iChoice,iNo;
    BOOL Running=TRUE;
    char ch;
    char str[30];

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
                printf("Enter a character to display in reccursive order:");
                scanf("\n%c",&ch);
                DisplayCharR(ch);
                printf("\n");
                break;

            case 2:
                printf("Enter an integer to display in reccursive order:");
                scanf("%d",&iNo);
                fflush(stdin);
                DisplayIntR(iNo);
                printf("\n");
                break;

            case 3:
                printf("Enter an integer to display in reccursive order:");
                scanf("%d",&iNo);
                printf("Factorial of %d is %d\n",iNo,FactR(iNo));
                break;

            case 4:
                printf("Enter a string:");
                scanf("%s",str);
                StrDisplayR(str);
                printf("\n");
                break;

            case 5:
                printf("Enter a string:");
                scanf("%s",str);
                printf("Lenght of string is:%d\n",StrLenR(str));
                break;

            default:
                printf("Invalid Choice!\n");
                break;
        }

    }

    return 0;
}