#include <stdio.h>
#include <conio.h>

int Length(char a[])
{
	int i, b;
	for(i=0;a[i]!='\0';i++)
	{
		b = i;
	}
	return b+1;
}

void FindPattern(char MainStr[], char Pattern[])
{
	int i=0,breaker=0,j=0,INDEX=0,flag=0,Comparisons = 0;
	int MAX = Length(MainStr)-Length(Pattern);
	
	for(i=0;i<=MAX;i++)
	{
		flag = 0;
		if (breaker !=0) //Using this condition returns the first match. Not using it returns the last match.
			break;
		breaker = 0;
		
		for(j=0;j<Length(Pattern);j++)
		{
			
			Comparisons++; //Counts the number of comparisons made
			if((MainStr[i+j]) == Pattern[j]) //Compares the Big strings xth char with Patterns 0th char then with xth+1 char and Patterns 1st char and so on.
			{		

				{
					flag++; //To identify if pattern has been found. Flag signal matching characters. Once flag is equal to the length of Pattern we know that one match has been found
					if(flag == Length(Pattern))
					{
						INDEX = i;	
						breaker++;
						break;
					}
				}				
			}	
			else
				break;
		}
	}
	if(INDEX !=0)
		printf("The index of the pattern is %d\n", INDEX + 1 );
	else 
		printf("The index of the pattern is %d\n", INDEX );
	printf("Total Comparisons = %d",Comparisons );
}

//Main program for testing
//
//int main()
//{	
//	char a[50], b[50];
//	printf("Enter the main string:");
//	scanf("%s",&a);
//	printf("Enter the pattern string:");
//	scanf("%s",&b);
//	FindPattern(a,b);
//	getch();
//	return 0;
//}