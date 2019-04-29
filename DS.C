#include<stdio.h>
#include<conio.h>
#include<math.h>
double p,q,e,d,n,fn,gcd,m,temp,cipher,z,cp;
int i = 0,flag = 1,k = 0;
void getin()
{
	printf("Enter the prime numbers\n");
	scanf("%lf%lf",&p,&q);
}
int getGCD(int a,int b)
{
	int small;
	if(a < b)
		small = a;
	else
		small = b;
	for(i=small;i>0;i--)
	{
		if(a % i == 0 && b % i == 0)
			return i;
	}
	return 0;
}
int power(int a,int b)
{
	z = 1;
	for(i=0;i<b;i++)
		z = z * a;
	return z;
}
void main()
{
	clrscr();
	getin();
	n = p * q;
	fn = (p - 1)*(q - 1);
	e = 2;
	while(flag)
	{
		gcd = getGCD(e,fn);
		if(gcd == 1)
			break;
		else
			e++;
	}
	printf("n = %lf\n",n);
	printf("fn = %lf\n",fn);
	printf("e = %lf\n",e);
	temp = 1;
	flag = 1;
	k=0;
	printf("Possible values of d are:\n");
	while(flag)
	{
		temp = temp + fn;
		if((int)temp % (int)e == 0)
		{
			cp = temp / e;
			k++;
			if(k == 1)
				d = temp / e;
			if(k==5)
				flag = 0;
			printf("%lf",cp);
		}
	}
	printf("d = %lf\n",d);
	if(e == d)
	{
		printf("Value of e and d is same\nEnter the new value of d\n");
		scanf("%lf",&d);
	}
	//encryption
	printf("Enter the message\n");
	scanf("%lf",&m);
	z = 1;
	for(i=0;i<d;i++)
		z = z * m;
	printf("Cipher Text : %lf\n",fmod(z,n));

	//decryption
	printf("Enter cipher text\n");
	scanf("%lf",&cipher);
	z = 1;
	for(i=0;i<e;i++)
		z = z * cipher;
	printf("Message : %lf\n",fmod(z,n));
	getch();
	}