#include<stdio.h>
#include<string.h>

char input[100];
int error=0,i=0;
void S();
void A();

void main()
{
	printf("\nEnter the expression: ");
	gets(input);
	S();
	if(strlen(input)==i&&error==0)
	{
		printf("\nInput Accepted\n");
	}
	else
	{
		printf("\nInput Rejected\n");
	}
}
void S()
{
	if(input[i]=='p')
	{
		i++;
		A();
		if(input[i] == 'y')
		{
			i++;
		}
	}
	else
	{
		error = 1;
	}
}
void A()
{
	if(input[i]=='a')
	{
		i++;
	}
	else if(input[i]=='l')
	{
		i++;
		if(input[i]=='a')
		{
			i++;
		}
		else
		{
			error = 1;
		}
	}
	else
	{
		error = 1;
	}
}

