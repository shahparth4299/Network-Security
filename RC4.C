#include<stdio.h>
#include<conio.h>
#include<string.h>
static int max = 255;
int n,temp,z,i,j,s[255],t[255],len,keylen,kn[100];
char pt[100],ct[100],k[100],final[100];
void getpt()
{
	printf("Enter the Plain Text\n");
	gets(pt);
	len = strlen(pt);
	printf("Enter key\n");
	scanf("%s",k);
	keylen = strlen(k);
}
void getkey()
{
	printf("\nEnter key\n");
	scanf("%s",k);
	keylen = strlen(k);
}
void setST()
{
	for(i=0;i<max;i++)
	{
		s[i] = i;
		t[i] = k[(i % keylen)];
	}
}
void initial()
{
	j=0;
	for(i=0;i<max;i++)
	{
		j = (j + s[i] + t[i]) % (max+1);
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}
void stream()
{
	i=j=n=0;
	for(n=0;n<len;n++)
	{
		i = (i + 1) % (max + 1);
		j = (j + s[i]) % (max + 1);
		//swap
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		z = (s[i] + s[j]) % (max + 1);
		kn[n] = s[z];
		//printf("%d\t",kn[n]);
	}
	printf("\n");
}
void main()
{
	clrscr();
	//Encryption
	getpt();
	setST();
	initial();
	stream();
	printf("Encryption:\n");
	for(i=0;i<len;i++)
	{
		ct[i] = pt[i] ^ kn[i];
		printf("%c\t",ct[i]);
	}
	//Decryption
	getkey();
	setST();
	initial();
	stream();
	printf("\nDecryption:\n");
	for(i=0;i<len;i++)
	{
		pt[i] = ct[i] ^ kn[i];
		printf("%c\t",pt[i]);
	}
	getch();
}