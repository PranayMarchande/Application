/*
3. Write a program which returns addition of all element from singly linear 
linked list. 
Function Prototype :
int Addition( PNODE Head); 
Input linked list : |10|->|20|->|30|->|40| 
Output : 100
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

int Addition(PNODE Head)
{
	int add = 0;
	while(Head != NULL)
	{
		add = add + Head->Data;
		Head = Head->Next;
	}
	return add;
}

int main()
{

	int iRet = 0, iadd = 0;
	PNODE First = NULL;
	InsertFirst(&First, 10);
	InsertFirst(&First, 20);
	InsertFirst(&First, 30);
	InsertFirst(&First, 40);
	iRet = Count(First);
	printf("Count of Linked list is: %d\n",iRet);
	
	iadd = Addition(First);
	printf("Addition of Linkedlist is:%d\n",iadd);
	
	return 0;
}


