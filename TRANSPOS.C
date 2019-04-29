#include<stdio.h>
#include<conio.h>
#include<string.h>
const int r = 10;
const int c = 10;
int k,row,col,clen,rlen,plen,i,ckey[10],rkey[10],j;
char pt[100],mat[10][10],mat2[10][10],mat3[10][10],ct[100],temp[10][10];
void getpt()
{
	printf("Enter the plain Text\n");
	gets(pt);
	plen = strlen(pt);
}
void columnKey()
{
	printf("Enter the column key length\n");
	scanf("%d",&clen);
	printf("Enter column key\n");
	for(i=0;i<clen;i++)
		scanf("%d",&ckey[i]);
}
void rowKey()
{
	printf("Enter the row key length\n");
	scanf("%d",&rlen);
	printf("Enter row key\n");
	for(i=0;i<rlen;i++)
		scanf("%d",&rkey[i]);
}
void display()
{
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%c\t",temp[i][j]);
		}
		printf("\n");
	}
}
void main()
{
	clrscr();
	//Encryption
	getpt();
	columnKey();
	rowKey();
	col = clen;
	row = rlen;
	k=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			mat[i][j] = pt[k];
			temp[i][j] = mat[i][j];
			k++;
		}
	}
	//display();
	//column transposition
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			mat2[i][ckey[j]] = mat[i][j];
			temp[i][ckey[j]] = mat2[i][ckey[j]];
		}
	}
	//display();
	//row transposition
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			mat3[rkey[i]][j] = mat2[i][j];
			temp[rkey[i]][j] = mat3[rkey[i]][j];
		}
	}
	printf("After Colmn And Row Transposition\n");
	display();
	//cipher text
	printf("Cipher Text\n");
	k=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			ct[k] = mat3[i][j];
			printf("%c",ct[k]);
			k++;
		}
	}
	printf("\n");
	//Decryption
	columnKey();
	rowKey();
	col = clen;
	row = rlen;
	k=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			mat[i][j] = ct[k];
			temp[i][j] = mat[i][j];
			k++;
		}
	}
	//display();
	//column transposition
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			mat2[i][j] = mat[i][ckey[j]];
			temp[i][j] = mat2[i][j];
		}
	}
	//display();
	//row transposition
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			mat3[i][j] = mat2[rkey[i]][j];
			temp[i][j] = mat3[i][j];
			}
	}
	printf("After Colmn And Row Transposition\n");
	display();
	//Decrypted text
	printf("After Decryption\n");
	k=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			pt[k] = mat3[i][j];
			printf("%c",pt[k]);
			k++;
		}
	}
	printf("\n");
	getch();
}