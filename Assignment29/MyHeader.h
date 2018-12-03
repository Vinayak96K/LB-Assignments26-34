#include<stdio.h>
#include<malloc.h>
#define TRUE 1
#define FALSE 0

typedef struct Node
{
    int data;
    struct Node *next;
}** PPNODE,* PNODE,NODE;

typedef unsigned int BOOL;

int Count(int);

int AddR(int *,int);

void DisplayLL(PNODE);

void StrRevDisplayR(char *);

void FactorR(int);

void InsertFirst(PPNODE,int);

void DisplayI(PNODE);