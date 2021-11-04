//Accept number from user and Display factor of that number
//Input :10
//Output:1,2,5

//Input:12
//output:1,2,3,4,6

//Input:33
//output:1,3,11,33

void DisplayFactors(int);

#include<stdio.h>
int main()
{
	int iNo=0;
	
	printf("Enter number\n");
	scanf("%d",&iNo);				
	
	DisplayFactors(iNo);
	
}
void DisplayFactors(int iValue)
{
	int iCnt = 0;			//Loop counter
	if(iValue<0)
	{
		iValue = -iValue;
	}
	
	
	for(iCnt = 1;iCnt<iValue;iCnt++)		//O(N)
	{
		if(((iValue)%iCnt)==0)		//iCnt is a Factor
		{
			printf("%d\n",iCnt);
		}
	}
}
	