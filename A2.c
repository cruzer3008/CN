#include<stdio.h>
#include<stdlib.h>

int min(int x,int y)
{
	if(x>=y)
		return y;
	else
		return x;
}

int main()
{
	int cap,orate,nsec,choice,x,i=0,drop=0,count=0,inp[10]={0};
	printf("Enter the size of the bucket: ");
	scanf("%d",&cap);
	printf("Enter the output rate: ");
	scanf("%d",&orate);

	do{
		printf("Enter the size of the incoming packet at second %d: ",i+1);
		scanf("%d",&inp[i]);
		i++;
	
		printf("Enter 1 to continue or Enter 0 to quit: ");
		scanf("%d",&choice);
	}while(choice);

	nsec = i;
	printf("\nTime\tReceived\tSend\tDropped\tRemaining\n");
	for(i=0;count||i<nsec;i++)
	{
		printf("%d\t",i+1);
		printf("%d\t\t",inp[i]);
		printf("%d\t",min((inp[i]+count),orate));

		if((x=inp[i]+count-orate)>0)
		{	
			if(x>cap)
			{
				count=cap;
				drop = x-cap;
			}

			else
			{
				count=x;
				drop=0;
			}
		}

		else
		{
			drop=0;
			count=0;
		}

		printf("%d\t",drop);
		printf("%d\n",count);
	}
	return 0;
}
