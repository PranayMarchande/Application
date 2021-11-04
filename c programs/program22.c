//Check number whether it is even or not 

#include<stdio.h>			//for printf() & scanf()
#include<stdbool.h>			//for bool datatype



bool CheckEven(int);		//Declaration

int main()
{
	int iNo=0;
	bool bRet=false;
	
	printf("Enter number\n");
	scanf("%d",&iNo);
	
	bRet=CheckEven(iNo);
	
	if(bRet==true)
	{
		printf("%d is even number\n",iNo);
	}
	else
	{
		printf("%d is not even number\n",iNo);
	}
	
	return 0;
}
bool CheckEven(int iValue)
{
	if((iValue%2)==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
