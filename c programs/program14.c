//write a program to display the numbers on screen number given by user.
//Input:3
//output:1 2 3
//Input:7
//output:1 2 3 4 5 6 7

#include<stdio.h>



void Display(int);
int main()
{
	int iNo=0;
	
	printf("Enter number\n");
	scanf("%d",&iNo);
	
	Display(iNo);		//Function call
	
	return 0;
}

void Display(int iValue)
{
	int i=0;
	
	if(iValue==0)       //filter
	{
		printf("you Entered number is 0\n");
		return;
    }
	
	if(iValue<0)      //input updater
	{
		iValue=-iValue;
	}
	
	for(i=1;i<=iValue;i++)
	{
		printf("%d\n",i);
	}
}
	