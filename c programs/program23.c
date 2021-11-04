//write a program to display the Factorial on screen number given by user.
//Input :1
//Output:1

//Input:3
//output:6
//Input:5
//output:120

#include<stdio.h>

typedef unsigned long int UINT;    			//typedef 1000gm  kilo
UINT Factorial(int);			//Declaration

int main()
{
	int iNo=0;
	UINT iRet=0;
	
	printf("Enter number\n");
	scanf("%d",&iNo);				//Accept the number
	
	iRet=Factorial(iNo);		
	
	printf("Factorialis:%ld\n",iRet);
	
	return 0;
}

 UINT Factorial(int iValue)
{
	
	UINT iFact=1;
	int iCnt=0;
	
	if(iValue<0) 			//Updater
	{
		iValue = -iValue;
	}
	/*
			1		2		  3
	for(iCnt=1;iCnt<=iValue;iCnt++)
	{
		iFact = iFact*iCnt;	//4			//assignment statement
	}
	*/
	iCnt = 1;				//1
	while(iCnt<=iValue)		//2
	{
		iFact = iFact*iCnt;	//4	
		iCnt++;				//3
	}
	return iFact;
}
		
	