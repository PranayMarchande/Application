
using namespace std;

#include<iostream>

typedef struct node
{
	int data;
	struct node *next;
}NODE,*PNODE;

class SinglyCL
{
private:
	PNODE first;
	PNODE last;
	int size;
	
public:
	SinglyCL()
	{
		first = NULL;
		last = NULL;
		size = 0;
	}
	
	void Display()
	{
		PNODE temp = first;
		
		if((first == NULL)&&(last == NULL))
		{
			return;
		}
		else
		{
			do
			{
				cout<<"|"<<temp->data<<"|-> ";
				temp = temp->next;
			}while(temp != last->next);
			cout<<"\n";
		}
	}
	int Count()
	{
		return size;
	}
	
	void InsertFirst(int no)
	{
		PNODE newn = new NODE;
		
		newn->data = no;
		newn->next = NULL;
		
		if((first == NULL)&&(last == NULL))
		{
			first = newn;
			last = newn;
		}
		else
		{
			newn->next = first;
			first = newn;
		}
		last->next = first;
		size++;
	}
	
	void InsertLast(int no)
	{
		PNODE newn = new NODE;
		
		newn->data = no;
		newn->next = NULL;
		
		if((first == NULL)&&(last == NULL))
		{
			first = newn;
			last = newn;
		}
		else
		{
			last->next = newn;
			last = newn;
		}
		last->next = first;
		size++;
	}
	void InsertAtPos(int no, int ipos)
	{
		if((ipos<1)||(ipos>(size+1)))
		{
			return;
		}
		if(ipos == 1)
		{
			InsertFirst(no);
		}
		else if(ipos == size+1)
		{
			InsertLast(no);
		}
		else
		{
			int i = 0;
			PNODE temp = first;
			PNODE newn = new NODE;
			newn->data = no;
			newn->next = NULL;
			
			for(i=1; i<ipos-1; i++)
			{
				temp = temp->next;
			}
			newn->next = temp->next;
			temp->next = newn;
			size++;
		}
	}
	void DeleteFirst()
	{
		if((first == NULL)&&(last == NULL))
		{
			return;
		}
		else if(first == last)
		{
			delete first;
			first = NULL;
			last = NULL;
		}
		else
		{
			first = first->next;
			delete last->next;
			last->next = first;
		}
		size--;
	}
	void DeleteLast()
	{
		PNODE temp = first;
		if((first == NULL)&&(last == NULL))
		{
			return;
		}
		else if(first == last)
		{
			delete first;
			first = NULL;
			last = NULL;
		}
		else
		{
			while(temp->next != last)
			{
				temp = temp->next;
			}
			delete last;
			last = temp;
			last->next = first;
		}
		size--;
	}
	void DeleteAtPos(int ipos)
	{
		if((ipos<1)||(ipos>(size+1)))
		{
			return;
		}
		if(ipos == 1)
		{
			DeleteFirst();
		}
		else if(ipos == size)
		{
			DeleteLast();
		}
		else
		{
			int i = 0;
			PNODE temp = first;
			PNODE targeted = NULL;
			
			for(i=1; i<ipos-1; i++)
			{
				temp = temp->next;
			}
			targeted = temp->next;
			temp->next = targeted->next;
			delete targeted;
			size--;
		}
	}
	
};
int main()
{
	PNODE first = NULL;
	int iChoice = 1, value = 0, iRet = 0, pos = 0;
	SinglyCL obj;
	
	while(iChoice != 0)
	{
		cout<<"\n_________________________________________________\n";
		cout<<"Enter the desired operation that you want to perform on Doubly Linear Linkedlist\n";
		cout<<"1 : Insert the node at first position\n";
		cout<<"2 : Insert the node at Last position\n";
		cout<<"3 : Insert the node at desired position\n";
		cout<<"4 : Delete the first node\n";
        cout<<"5 : Delete the last node\n";
        cout<<"6 : Delete the node at desired position\n";
        cout<<"7 : Display the contents of linked list\n";
        cout<<"8 : Count the number of nodes from linked list\n";
        cout<<"0 : Terminate the application\n";
		
		cin>>iChoice;
		printf("\n_________________________________________________\n");
		
		switch(iChoice)
		{
			case 1:
				cout<<"Enter the data to insert\n";
				cin>>value;
				obj.InsertFirst(value);
				break;
				
			case 2:
				cout<<"Enter the data to insert\n";
				cin>>value;
				obj.InsertLast(value);
				break;	
				
			case 3:
                cout<<"Enter the data to insert\n";
                cin>>value;
                cout<<"Enter the position\n";
                cin>>pos;
                obj.InsertAtPos(value,pos);
                break;
                
            case 4:
                obj.DeleteFirst();
                break;
                
            case 5:
                obj.DeleteLast();
                break;
                
            case 6 :
                cout<<"Enter the position\n";
                cin>>pos;
                obj.DeleteAtPos(pos);
                break;
                
            case 7:
                cout<<"Elemenet of Linked list are\n";
                obj.Display();
                break;
                
            case 8:
                iRet = obj.Count();
                cout<<"Number of elements are :"<<iRet<<"\n";
                break;
                
            case 0:
                cout<<"Thank for using Doubly Linear Linked List\n";
                break;
                
            default:
                cout<<"Please enter proper choice\n";
                break;
				
			
		}
	}
	
	return 0;
}


