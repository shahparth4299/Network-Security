#include<stdio.h>
#include<conio.h>
long int a,b,ak,bk,x,y,p,q;
int isPrime(long int a)
{
	int i;
	for(i=2;i<a/2;i++)
	{
		if(a % i == 0)
			return 0;
	}
	return 1;
}
long int power(long int a,long int b)
{
	long int i;
	long int mul = 1;
	for(i=0;i<b;i++)
	{
		mul *= a;
	}
	return mul;
}
void sender()
{
	x = power(bk,a);
	printf("POWER : %ld\n",x);
	x = x % p;
}
void receiver()
{
	y = power(ak,b);
	printf("POWER : %ld\n",y);
	y = y % p;
}
void main()
{
	clrscr();
	do{
		printf("Enter First prime number\n");
		scanf("%ld",&p);
	}while(!isPrime(p));
	printf("Enter Second prime number\n");
	scanf("%ld",&q);
	printf("Enter value of a and b\n");
	scanf("%ld%ld",&a,&b);
	ak = power(q,a);
	printf("POWER : %ld\n",ak);
	ak = ak % p;
	bk = power(q,b);
	printf("POWER : %ld\n",bk);
	bk = bk % p;
	printf("Public Key: %ld AND %ld\n",ak,bk);


	sender();
	receiver();
	printf("Secret Key: %ld AND %ld\n",x,y);
	getch();
}

