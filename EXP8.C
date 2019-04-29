#include<stdio.h>
#include<conio.h>
void main()
{
	char str1[5],str[10]={'\0'};
	char str3[]="The folding smartphone concept by Xiaomi uses not just one but two creases";
	int i;
	clrscr();
	strcpy(str1,str3);
	printf("After using strcpy function\n");
	printf("str1 : %s \n",str1);
	printf("10th Character : %c\n",str1[10]);

	//Other Method
	printf("Expected Output\n");
	for(i=0;i<10;i++)
	{
		str[i] = str3[i];
		printf("%c",str[i]);
	}
	getch();
}
