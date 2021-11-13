//doubly LL
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}NODE, *PNODE, **PPNODE;

void InsertFirst(PPNODE Head,int no)
{
	PNODE newn = NULL;
	
	newn =(PNODE)malloc(sizeof(NODE));
	
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		newn->next = *Head;
		(*Head)->prev = newn;
		
		*Head = newn;
	}
}

void InsertLast(PPNODE Head,int no)
{
	PNODE newn = NULL;
	PNODE temp = *Head;
	newn =(PNODE)malloc(sizeof(NODE));
	
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
		newn->prev = temp;
	}
}

void Display(PNODE Head)
{
	while(Head != NULL)
	{
		printf("|%d|->",Head->data);
		Head = Head->next;
	}
	printf("NULL\n");
}

int Count(PNODE Head)
{
	int iCnt = 0;
	while(Head != NULL)
	{
		iCnt++;
		Head = Head->next;
	}
	return iCnt;
}
/*
void DeleteFirst(PPNODE Head)
{
	PNODE temp = *Head;
	if(*Head !=NULL)//LL contains atleast one node
	{
		*Head = (*Head)->next;
		free(temp);
		if(*Head != NULL)
		{
			(*Head)->prev = NULL;
		}	
	}
}*/

void DeleteFirst(PPNODE Head)
{
	if(*Head == NULL)
	{
		return;
	}
	else if((*Head)->next == NULL)
	{
		free(*Head);
		*Head = NULL;
	}
	else
	{
		*Head = (*Head)->next;
		free((*Head)->prev);
		(*Head)-> prev = NULL;
	}
}

void DeleteLast(PPNODE Head)
{
	PNODE temp = *Head;
	if(*Head == NULL)
	{
		return;
	}
	else if((*Head)->next == NULL)
	{
		free(*Head);
		*Head = NULL;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->prev->next = NULL;
		free(temp);
	}
}

void InsertAtPos(PPNODE Head,int no,int iPos)
{
	int size = Count(*Head);
	int i = 0;
	PNODE temp = *Head;
	PNODE newn = NULL;
	if((iPos<1)||(iPos>size+1))
	{
		printf("Invalide Position\n");
		return;
	}
	
	if(iPos == 1)
	{
		InsertFirst(Head,no);
	}
	else if(iPos == size+1)
	{
		InsertLast(Head,no);
	}		
	else
	{
		newn = (PNODE)malloc(sizeof(NODE));
		
		newn->next = NULL;
		newn->prev = NULL;
		newn->data = no;
		
		for(i=1; i<iPos-1; i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		newn->next->prev = newn;
		temp->next = newn;
		newn->prev = temp;
		
	}
	
	
}

void DeleteAtPos(PPNODE Head,int iPos)
{
	int size = Count(*Head);
	int i = 0;
	PNODE temp = *Head;
	
	if((iPos<1)||(iPos>size))
	{
		printf("Invalide Position\n");
		return;
	}
	
	if(iPos == 1)
	{
		DeleteFirst(Head);
	}
	else if(iPos == size)
	{
		DeleteLast(Head);
	}		
	else
	{
		
		for(i=1; i<iPos-1; i++)
		{
			temp = temp->next;
		}
		temp->next = temp->next->next;
		free(temp->next->prev);
		temp->next->prev = temp;
	}
	
	
}

int main()
{
	PNODE first = NULL;
	int iChoice = 1, value = 0, iRet = 0, pos = 0;
	
	while(iChoice != 0)
	{
		printf("\n_________________________________________________\n");
		printf("Enter the desired operation that you want to perform on Doubly Linear Linkedlist\n");
		printf("1 : Insert the node at first position\n");
		printf("2 : Insert the node at Last position\n");
		printf("3 : Insert the node at desired position\n");
		printf("4 : Delete the first node\n");
        printf("5 : Delete the last node\n");
        printf("6 : Delete the node at desired position\n");
        printf("7 : Display the contents of linked list\n");
        printf("8 : Count the number of nodes from linked list\n");
        printf("0 : Terminate the application\n");
		
		scanf("%d",&iChoice);
		printf("\n_________________________________________________\n");
		
		switch(iChoice)
		{
			case 1:
				printf("Enter the data to insert\n");
				scanf("%d",&value);
				InsertFirst(&first,value);
				break;
				
			case 2:
				printf("Enter the data to insert\n");
				scanf("%d",&value);
				InsertLast(&first,value);
				break;	
				
			case 3:
                printf("Enter the data to insert\n");
                scanf("%d",&value);
                printf("Enter the position\n");
                scanf("%d",&pos);
                InsertAtPos(&first,value,pos);
                break;
                
            case 4:
                DeleteFirst(&first);
                break;
                
            case 5:
                DeleteLast(&first);
                break;
                
            case 6 :
                printf("Enter the position\n");
                scanf("%d",&pos);
                DeleteAtPos(&first,pos);
                break;
                
            case 7:
                printf("Elemenet of Linked list are\n");
                Display(first);
                break;
                
            case 8:
                iRet = Count(first);
                printf("Number of elements are : %d\n",iRet);
                break;
                
            case 0:
                printf("Thank for using Doubly Linear Linked List\n");
                break;
                
            default:
                printf("Please enter proper choice\n");
                break;
				
			
		}
	}
	
	return 0;
}