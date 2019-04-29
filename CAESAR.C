#include<stdio.h>
#include<conio.h>
#include<string.h>
int i,key,len;
char temp,pt[100],ct[100],seq[27]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
void main()
{
	clrscr();
	printf("Enter the plain Text\n");
	gets(pt);
	len = strlen(pt);
	for(i=0;i<len;i++)
	{
		if(pt[i] >='a' && pt[i] <= 'z')
		{
			pt[i] -= 97; 
		}
		else
		{
			pt[i] -= 65;
		}
	}
	printf("Enter The Key\n");
	scanf("%d",&key);
	for(i=0;i<len;i++)
		//printf("After Conversion: %d\n",pt[i]);
	for(i=0;i<len;i++)
	{
		pt[i] = (pt[i] + key) % 26;
		temp = pt[i];
		pt[i] = seq[temp];
	}
	printf("After Encryption: %s\n",pt);

	printf("Enter the Cipher Text\n");
	scanf("%s",ct);
	len = strlen(ct);
	for(i=0;i<len;i++)
	{
		if(ct[i] >='a' && ct[i] <= 'z')
		{
			ct[i] -= 97;
		}
		else
		{
			ct[i] -= 65;
		}
	}
	printf("Enter The Key\n");
	scanf("%d",&key);
	for(i=0;i<len;i++)
		//printf("After Conversion: %d\n",ct[i]);
	for(i=0;i<len;i++)
	{
		ct[i] = (ct[i] - key) % 26;
		if(ct[i] < 0)
			ct[i] += 26;
		temp = ct[i];
		ct[i] = seq[temp];
	}
	printf("After Encryption: %s\n",ct);
	getch();
}