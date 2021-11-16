//SinglyCircularLL

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE, *PNODE, **PPNODE;

void Display(PNODE Head, PNODE Tail)
{
	if((Head == NULL)&&(Tail == NULL))
	{
		return;
	}
	do
	{
		printf("|%d|->",Head->data);
		Head = Head->next;
	}while(Head != Tail->next);
	printf("\n");
}
int Count(PNODE Head, PNODE Tail)
{
	int icnt = 0;
	if((Head == NULL)&&(Tail == NULL))
	{
		return 0;
	}
	do
	{
		icnt++;
		Head = Head->next;
	}while(Head != Tail->next);
	return icnt;
}

void InsertFirst(PPNODE Head, PPNODE Tail, int no)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	
	newn->data = no;
	newn->next = NULL;
	
	if((*Head == NULL)&&(*Tail == NULL))  //LL is empty
	{
		*Head = newn;
		*Tail = newn;
	}
	else
	{
		newn->next = *Head;
		*Head = newn;
	}
	(*Tail)->next = *Head; // To maintain circular nature

}
void InsertLast(PPNODE Head, PPNODE Tail, int no)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	
	newn->data = no;
	newn->next = NULL;
	
	if((*Head == NULL)&&(*Tail == NULL))  //LL is empty
	{
		*Head = newn;
		*Tail = newn;
	}
	else
	{
		(*Tail)->next = newn;
		*Tail = newn;
	}
	(*Tail)->next = *Head;
}

void InsertAtPos(PPNODE Head,PPNODE Tail,int no,int iPos)
{
	PNODE temp = *Head;
	int i = 0;
	int size = Count(*Head,*Tail);
	
	if((iPos<1)||(iPos>size+1))
	{
		return;
	}
	if(iPos == 1)
	{
		InsertFirst(Head, Tail, no);
	}
	else if(iPos == size+1)
	{
		InsertLast(Head, Tail, no);
	}
	else
	{
		PNODE newn = (PNODE)malloc(sizeof(NODE));
		
		newn->data = no;
		newn->next = NULL;
		
		for(i=1; i<iPos-1; i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;
		
	}
}
void DeleteFirst(PPNODE Head, PPNODE Tail)
{
	if((*Head == NULL)&&(*Tail == NULL))
	{
		return;
	}
	else if(*Head == *Tail)
	{
		free(*Head);
		*Head = NULL;
		*Tail = NULL;
	}
	else
	{
		*Head = (*Head)->next;
		free((*Tail)->next);
		(*Tail)->next = *Head;
	}
}

void DeleteLast(PPNODE Head, PPNODE Tail)
{
	PNODE temp = *Head;
	if((*Head == NULL)&&(*Tail == NULL))
	{
		return;
	}
	else if(*Head == *Tail)
	{
		free(*Head);
		*Head = NULL;
		*Tail = NULL;
	}
	else
	{
		while(temp->next != *Tail)
		{
			temp = temp->next;
		}
		free(*Tail);
		*Tail = temp;
		
		(*Tail)->next = *Head;
	}
}
void DeleteAtPos(PPNODE Head, PPNODE Tail, int iPos)
{
	PNODE temp = *Head;
	PNODE targeted = NULL;
	int size = Count(*Head,*Tail);
	int i = 0;
	if((iPos<1)||(iPos>size+1))
	{
		return;
	}
	if(iPos == 1)
	{
		DeleteFirst(Head,Tail);
	}
	else if(iPos == size+1)
	{
		DeleteLast(Head,Tail);
	}
	else
	{
		for(i=1; i<iPos-1; i++)
		{
			temp = temp->next;
		}
		targeted = temp->next;
		temp->next = targeted->next;
		free(targeted);
	}
}

int main()
{
	PNODE first = NULL;
	PNODE last = NULL;
	int iChoice = 1,iValue=0,iRet=0,iPos=0;
	
	while(iChoice != 0)
	{
		printf("\n___________________________________________\n");
		printf("Enter the desired operation that you want to perform on Linkedlist\n");
		printf("1: Insert the node at first position\n");
		printf("2: Insert the node at last position\n");
		printf("3: Insert the node at desired position\n");
		printf("4: Delete the first node\n");
		printf("5: Delete the last node\n");
		printf("6: Delete the node at desired position\n");
		printf("7: Display the content of linked list\n");
		printf("8: Count the number ofnodes from linked list\n");
		printf("0: Terminate the application\n");
		scanf("%d",&iChoice);
		printf("\n____________________________________ \n");
		
		switch(iChoice)
		{
		  case 1:
			printf("Enter the data to insert\n");
			scanf("%d",&iValue);
			InsertFirst(&first,&last,iValue);
			break;
		
		  case 2:
			printf("Enter the data to insert\n");
			scanf("%d",&iValue);
			InsertLast(&first,&last,iValue);
			break;
		
		  case 3:
			printf("Enter the data to insert\n");
			scanf("%d",&iValue);
			printf("Enter the position\n");
			scanf("%d",&iPos);
			InsertAtPos(&first,&last,iValue,iPos);
			break;
		
		  case 4:
			DeleteFirst(&first,&last);
			break;
		
		  case 5:
			DeleteLast(&first,&last);
			break;
		
		  case 6:
			printf("Enter the position\n");
			scanf("%d",&iPos);
			DeleteAtPos(&first,&last,iPos);
			break;
		
		  case 7:
			printf("Element of Linked list are\n");
			Display(first,last);
			break;
		
		  case 8:
			iRet = Count(first,last);
			printf("Number of elements are : %d\n",iRet);
			break;
		
		  case 0:
			printf("Thank you for using Marvellous Linked list\n");
			break;
		
		default:
			printf("Please enter proper choice\n");
			break;
		}
	}
		 
	return 0;
}

