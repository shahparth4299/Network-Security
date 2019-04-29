#include<stdio.h>
#include<conio.h>
void main()
{
	char buffer[10];
	int i;
	clrscr();
	sprintf(buffer,"%s","fsf fsfsdfd gfdfg fdgfdhfg fgdg dfasd");
	printf("Buffer Data\n");
	printf("%s\n",buffer);
	for(i=0;i<10;i++)
	{
		printf("%c",buffer[i]);
	}
	getch();
}
