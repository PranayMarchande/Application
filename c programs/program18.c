//write a program to display the numbers on screen number given by user.
//Input:3
//output:6
//Input:5
//output:15

#include<stdio.h>

int Addition(int);			//Declaration

int main()
{
	int iNo=0, iRet=0;
	
	printf("Enter number\n");
	scanf("%d",&iNo);				//Accept the number
	
	iRet=Addition(iNo);		
	
	printf("Addition is:%d\n",iRet);
	
	return 0;
}

int Addition(int iValue)
{
	
	int iSum=0;
	int iCnt=0;
	
	if(iValue<0) 			//Updater
	{
		iValue = -iValue;
	}
	//		1		2		  3
	for(iCnt=1;iCnt<=iValue;iCnt++)
	{
		iSum = iSum+iCnt;	//4			//assignment statement
	}
	return iSum;
}
		
	