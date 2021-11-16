/*
1. Write a program which search first occurrence of particular
element from singly linear linked list. 
Function should return position at which element is found. 
Function Prototype :
int SearchFirstOcc( PNODE Head , int no ); 

Input linked list : |10|->|20|->|30|->|40|->|50|->|30|->|70| 
Input element : 30
 
Output : 3 
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

int SearchFirstOcc( PNODE Head ,int no,int size )
{
	static int i = 1;
	int index = 0;
	
		while(Head != NULL)
		{
			
			if(Head->Data == no)
			{
				index = i;
				break;
			}
			else
			{
				Head = Head->Next;
				i++;
			}
			
		}
		return index;
		
	}
	

int main()
{

	int iRet = 0, iIndex = 0;
	PNODE First = NULL;
	InsertFirst(&First, 101);
	InsertFirst(&First, 51);
	InsertFirst(&First, 21);
	InsertFirst(&First, 11);
	InsertFirst(&First, 51);
	iRet = Count(First);
	printf("Count of Linked list is: %d\n",iRet);
	
	iIndex = SearchFirstOcc( First,51,iRet );
	printf("First occurence of index is : %d\n",iIndex);
	
	return 0;
}


