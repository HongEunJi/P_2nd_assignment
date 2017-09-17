#include <stdio.h>
#include <math.h>

int between_prime(int n);
int checkprime(int n);
int armstrong(int n);

int main()
{
	int x;

	puts("Choose one among the menu.");
	puts("1. Find prime numbers between intervals you put");
	puts("2. Check prime or armstrong number");
	puts("3. Check whether a number can be expressed as sum of two prime numbers.");
	scanf("%d",&x);

	if(x==1)
	{
		int i,n1,n2;

		printf("Enter two number:");
		scanf("%d %d",&n1, &n2);

		for(i=n1+1; i<n2; i++)
			between_prime(i);
	}
 
	else if(x==2)
	{
		int n,flag;

		printf("Enter a number:");
		scanf("%d",&n);

		flag = checkprime(n);

		if(flag==1)
			printf("%d is a prime number.\n",n);
		else
			printf("%d is not a prime number.\n",n);
		flag = armstrong(n);
		if(flag==1)
			printf("%d is an armstrong number.\n",n);
		else
			printf("%d is not a armstrong number.\n",n);
		return 0;
	}
	else if(x==3)
	{
		int n,i,flag=0;
		printf("Enter a number:");
		scanf("%d",&n);
		for(i=2; i<=n/2; ++i){
			if(checkprime(i)==1&&checkprime(n-i)==1)
					printf("%d = %d + %d\n",n,i,n-i);
					flag=1;
			}
	}
	return 0;
}
int between_prime(int n)
{
	int i;
	for(i=2; i<=n; i++)
		if(n%i==0)
			break;
	if(n==i)
		printf("%d\n",n);

	return 0;
}
int checkprime(int n){
	int i,flag=0;
	for(i=1; i<=n; i++){
		if(n%i==0)
			flag++;
	}
	return (flag==2);
}
int armstrong(int n){
	int original_number, remainder, result=0, number=0, flag;
	original_number=n;
	while(original_number != 0)
	{
		original_number/=10;
		++number;
	}
	original_number=n;
	while(original_number!=0)
	{
		remainder = original_number % 10;
		result += pow(remainder,number);
		original_number/=10;
	}
	if(result==n)
		flag=1;
	else
		flag=0;
	return flag;
}