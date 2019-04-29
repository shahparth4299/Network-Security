#include<stdio.h>
#include<conio.h>
#include<string.h>
char pt[100],ct[100],dc[100];
int key[10],i,len,c,j;
void main()
{
	clrscr();
	printf("Enter the plain text\n");
	gets(pt);
	len = strlen(pt);
	printf("Enter the key\n");
	for(i=0;i<len;i++)
		scanf("%d",&key[i]);
	for(i=0;i<len;i++)
		ct[key[i]] = pt[i];

	printf("Cipher Text Is\n");
	for(i=0;i<len;i++)
		printf("%c",ct[i]);

	printf("\nEnter the Key\n");
	for(i=0;i<len;i++)
		scanf("%d",&key[i]);
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			if(i == key[j])
			{
				c = j;
				break;
			}
		}
		dc[c] = ct[i];
	}
	printf("Decryption: %s",dc);
	getch();
}