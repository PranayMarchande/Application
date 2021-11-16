/*
4. Write a program which return largest element from singly linear linked 
list. 
Function Prototype :
int Maximum( PNODE Head); 
Input linked list : |110|->|230|->|320|->|240| 
 
Output : 320 
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

int Maximum(PNODE Head)
{
	int iLarge = Head->Data;
	
		while(Head != NULL)
		{	
			if((Head->Data)>iLarge)
			{
				iLarge = Head->Data;
			}
			Head = Head->Next;
		}
		return iLarge;
	}
	

int main()
{

	int iRet = 0, iMax = 0;
	PNODE First = NULL;
	InsertFirst(&First, 101);
	InsertFirst(&First, 51);
	InsertFirst(&First, 201);
	InsertFirst(&First, 11);
	InsertFirst(&First, 51);
	iRet = Count(First);
	printf("Count of Linkedlist is :%d\n",iRet);
	
	iMax = Maximum( First);
	printf("Largest number is: %d\n",iMax);
	
	return 0;
}


