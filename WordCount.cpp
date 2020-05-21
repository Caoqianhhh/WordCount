#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *Fpoint;
void Charnumber(char *Filename)
{	
	
	int Charnumber=0;
	char ch;
	if((Fpoint=fopen(Filename,"rb"))==NULL)
	{
	    printf("File open error!\n");
		exit(0);
	}
	 while(!feof(Fpoint))
    {
	   ch=fgetc(Fpoint);
	   if(ch!='\n'&&ch!='\t'&&ch!=' ')
		{
			Charnumber++;
		}

	}
		fclose(Fpoint);
		printf("字符数：%d\n",Charnumber);
}
void Wordnumber(char *Filename)
{		
	int Wordnumber=0;
	int flag=0;//记录单词的状态
	char c;
	if((Fpoint=fopen(Filename,"rb"))==NULL)
	{
	    printf("File open error!\n");
		exit(0);
	}
    while(!feof(Fpoint))
    {
	   c=fgetc(Fpoint);
	   if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
	   {
			  	   flag=1;
	   }
	  else if(flag)
	  {
				 	Wordnumber++;
					flag=0;
	  }
	}

		fclose(Fpoint);
		printf("单词数：%d\n",Wordnumber);
}
		
			
int  main(int argc,char *argv[])
{
    if(!strcmp(argv[1],"-w"))
		Wordnumber(argv[2]);
	else if(!strcmp(argv[1],"-c"))
		Charnumber(argv[2]);
	return 0;
}
