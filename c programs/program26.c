//Accept number from user and Display Addition of factors of that number
//Input :10
//Output:1,2,5

//Input:12
//output:1,2,3,4,6

//Input:33
//output:1,3,11,33

int DisplayFactors(int);

#include<stdio.h>
int main()
{
	int iNo=0;
	int iRet=0;
	
	printf("Enter number\n");
	scanf("%d",&iNo);				
	
	iRet = DisplayFactors(iNo);
	
	printf("%d",iRet);
	
	return 0;
}
int DisplayFactors(int iValue)
{
	int iCnt = 0;			//Loop counter
	int iSum = 0;
	if(iValue<0)
	{
		iValue = -iValue;
	}
	
	
	for(iCnt = 1;iCnt<(iValue);iCnt++)		//O(N/2)
	{
		
		if((iValue%iCnt)==0)		//iCnt is a Factor
		{
			iSum=iSum+iCnt;
			
		}
		
	}
	return iSum;
}
	