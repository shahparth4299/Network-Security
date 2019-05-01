#include<stdio.h>
#include<conio.h>
int findInverse(int a,int m)
{
	int i;
	a = a % m;
	for(i=0;i<m;i++)
	{
		if((a*i) % m == 1)
			return i;
	}
	return 0;
}
void main()
{
	int inverse,j,sum,i,private[10],public[10],message[100],m,n,keylen,mlen,divider,encryption[10],decryption[10],k;
	clrscr();
	printf("Enter m and n\n");
	scanf("%d%d",&m,&n);
	printf("Enter private key length\n");
	scanf("%d",&keylen);
	printf("Enter private key:\n");
	for(i=0;i<keylen;i++)
		scanf("%d",&private[i]);

	//public key
	printf("Public Key: {");
	for(i=0;i<keylen;i++)
	{
		public[i] = (m * private[i]) % n;
		printf("%d,",public[i]);
	}
	printf("}\n");

	//message
	printf("Enter message length\n");
	scanf("%d",&mlen);
	printf("Enter message\n");
	for(i=0;i<mlen;i++)
	{
		scanf("%d",&message[i]);
	}
	if(mlen % keylen == 0)
		divider = mlen / keylen;
	else
		divider = (mlen / keylen) + 1;
	//encryption
	k=0;
	for(i=0;i<divider;i++)
	{
		sum = 0;
		for(j=0;j<keylen;j++)
		{
			if(message[k] == 1)
			{
				sum = sum + public[j];
				//printf("%d",private[j]);
			}
			k++;
		}
		encryption[i] = sum;
		printf("%d\n",encryption[i]);
	}

	//decryption
	printf("Decryption\n");
	inverse = findInverse(m,n);
	printf("Inverse : %d",inverse);

	for(i=0;i<divider;i++)
	{
		decryption[i] = (encryption[i] * inverse) % n;
		printf("%d\n",decryption[i]);
	}
	getch();
}