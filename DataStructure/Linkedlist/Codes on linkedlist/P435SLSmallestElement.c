/*
5. Write a program which return smallest element from singly linear linked 
list. 
Function Prototype :
int Minimum( PNODE Head); 
Input linked list : |110|->|230|->|20|->|240|->|640| 
Output : 20
*/

//Consider below code snippet to solve given problem statements.
#include<stdio.h>
#include<stdlib.h>


struct node
{
	int Data;
	struct node *Next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE Head , int no )
{
	 PNODE newn = NULL;
	 
	 newn = (PNODE)malloc(sizeof(NODE));
	 
	 newn->Next = NULL;
	 newn->Data = no;
	 if (*Head == NULL)
	 {
		*Head = newn;
	 }
	 else
	 {
		 newn->Next = *Head;
		 *Head = newn;
	 }
}
int Count(PNODE Head)
{
	int iCnt = 0;
	while(Head != NULL)
	{
		iCnt++;
		Head = Head->Next;
	}
	return iCnt;
}

int Minimum(PNODE Head)
{
	int iSmall = Head->Data;
	
		while(Head != NULL)
		{	
			if((Head->Data)<iSmall)
			{
				iSmall = Head->Data;
			}
			Head = Head->Next;
		}
		return iSmall;
	}
	

int main()
{

	int iRet = 0, iMin = 0;
	PNODE First = NULL;
	InsertFirst(&First, 101);
	InsertFirst(&First, 51);
	InsertFirst(&First, 10);
	InsertFirst(&First, 11);
	InsertFirst(&First, 51);
	iRet = Count(First);
	printf("Count of Linkedlist are :%d\n",iRet);
	
	iMin = Minimum( First);
	printf("Largest number is: %d\n",iMin);
	
	return 0;
}


