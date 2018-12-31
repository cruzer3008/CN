#include<stdio.h>

char h[10];
char l[10];

int h_f=0;
int h_r=0;

int l_f=0;
int l_r=0;

int output_rate=2;

int h_empty()
{
	return h_r==h_f;
}

int h_full()
{
	return h_r==9;
}

void h_in(char ele)
{
	h[h_r++]=ele;
}

char h_out()
{
	char out=h[h_f++];
	if(h_empty())
		h_f=h_r=0;
	return out;
}

int l_full()
{
	return l_r==9;
}

int l_empty()
{
	return l_r==l_f;
}

void l_in(char ele)
{
	l[l_r++]=ele;
}

char l_out()
{
	char out=l[l_f++];
	if(l_empty())
		l_f=l_r=0;
	return out;
}

int get_priority()
{
	int priority;
	printf("Enter 1 for High priority 0 for low priority \n");
	scanf("%d",&priority);
	return priority;
}

int insert_data(int priority)
{
	int times;
	char ele;
	printf("Enter NO. of elemets to be inputed \n");
	scanf("%d",&times);
	for(int i=0;i<times;i++)
	{
		
		printf("Enter a Charecter \n");
		scanf(" %c",&ele);
		if(priority==1 && !h_full())
			h_in(ele);
		else if(priority==0 && !l_full())
			l_in(ele);
		else
			printf("Full ,dropped\n");
					
	}
}

int process()
{
	printf("\n processing data_____________________ \n");
	for(int i=0;i<output_rate;i++)
	{
		if(!h_empty())
			printf("%c \n",h_out());
		else if(!l_empty())
			printf("%c \n",l_out());
		else
			printf("NOthing to process \n");
	}
	printf("\n");

}

void main()
{
int priority;
while(1)
{

priority=get_priority();
insert_data(priority);
process();



}

}
