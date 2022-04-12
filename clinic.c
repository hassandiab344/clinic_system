#include "STD_TYPES.h"
#include "Head.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern Patient *head;
extern Patient *current;
extern Patient *prev;
extern u32 List_Length,Size,ID,Time,i;
u32 Arr[5]={-1,-1,-1,-1,-1};

Patient* New_Patient()
{
	Patient* Temp=(Patient*)malloc(sizeof(Patient));
	return Temp;
}
void Add_Patient(u8 copy_u8Patient_Name[],u32 copy_u32Patient_Age,u8 copy_u8Patient_Gender[],u32 copy_u32Patient_ID)
{
	Patient *Link=(Patient*)malloc(sizeof(Patient));
	u32 pos=0;
	current=head;
	while(current!=NULL)
	{
		if(current->Patient_ID==copy_u32Patient_ID)
		{
			printf("The Patient ID is already exist, please try again\n\n");
			return;
		}
		current=current->next;
		pos++;
	}
	strcpy(Link->Patient_Name,copy_u8Patient_Name);
	Link->Patient_Age=copy_u32Patient_Age;
	strcpy(Link->Patient_Gender,copy_u8Patient_Gender);
	Link->Patient_ID=copy_u32Patient_ID;
	Link->next=NULL;
	printf("Patient is added to the clinic successfully\n\n\n\n");
	current=head;
	if(head==NULL)
	{
		head=Link;
		return;
	}
	while(current->next!=NULL)
	{
		current=current->next;
	}
	current->next=Link;
	Size++;
}
void Edit_List(u32 copy_u32Patient_ID)
{
	u8 x=0;
	current=head;
	while(current!=NULL&&x==0)
	{
		if(current->Patient_ID==copy_u32Patient_ID)
		{
			printf("Please Enter Your Name :");
			scanf(" %[^\n]%*c",current->Patient_Name);
			printf("Please Enter Your Age :");
			scanf("%d",&current->Patient_Age);
			printf("Please Enter Your Gender :");
			scanf(" %[^\n]%*c",current->Patient_Gender);
			printf("Please Enter Your ID :");
			scanf("%d",&current->Patient_ID);
			x=1;
			return;
		}
		current=current->next;
	}
	if(x==0)
	{
		printf("The ID is not exist\n");
	}
	return;
}
void Time_Reservation()
{
	u8 x=0;
	for(i=0;i<5;i++)
	{
		switch(i)
		{
			case 0 :
			if(Arr[0]!=-1)
			{
				break;
			}
			else
			{
				printf("From 2pm to 2:30pm available,to reserve this slot please press 1\n ");
				break;
			}
			case 1 :
			if(Arr[1]!=-1)
			{
				break;
			}
			else 
			{
				printf("From 2:30pm to 3pm available, to reserve this slot please press 2\n");
				break;
			}
			case 2 :
			if(Arr[2]!=-1)
			{
				break;
			}
			else
			{
				printf("From 3:30pm to 4pm available, to reserve this slot please press 3\n");
				break;
			}
			case 3 :
			if (Arr[3]!=-1)
			{
				break;
			}
			else
			{
				printf("From 4pm to 4:30pm available, to reserve this slot please press 4\n");
				break;
			}
			case 4 :
			if(Arr[4]!=-1)
			{
				break;
			}
			else
			{
				printf("From 4:30 to 5pm available, to reserve this slot please press 5\n");
				break;
			}
			
		}
	}
	printf("Your choice is :");
	scanf("%d",&Time);
	printf("Please Enter Your ID : ");
	scanf("%d",&ID);
	current=head;
	while(current!=NULL)
	{
		if(current->Patient_ID==ID)
		{
			Arr[Time-1]=ID;
			x=1;
			return;
		}
		current=current->next;
	}
	if(x==0)
	{
		printf("This ID is not exist,please sign in First\n");
		return;
	}
}
void Cancel_Reservation(u32 copy_u32ID)
{
	u8 y=0;
	for(i=0;i<5;i++)
	{
		if(Arr[i]==copy_u32ID)
		{
			Arr[i]=-1;
			y=1;
		}
	}
	if(y==0)
	{
		printf("Wrong ID\n");
	}
	return;
}
void Print_Patient_List(u32 copy_u32Patient_ID)
{
	u8 x=0;
	current=head;
	while(current!=NULL)
	{
		if(current->Patient_ID==copy_u32Patient_ID)
		{
			printf("Name: ");
			printf(current->Patient_Name);
			printf("\n");
			printf("Age : %d\n",current->Patient_Age);
			printf("Gender : ");
			printf(current->Patient_Gender);
			printf("\n");
			printf("ID: %d\n",current->Patient_ID);
			x=1;
		}
		current=current->next;
	}
	if(x==0)
	{
		printf("This ID is not Exist");
	}
	return;
}
void print_Patient_Reservation()
{
	for(i=0;i<5;i++)
	{
		switch(i)
		{
			case 0:
			if(Arr[0]==-1)
			{
				break;
			}
			else
			{
				printf("From 2pm to 2:30pm is reserved by the ID NUM:%d\n",Arr[0]);
				break;
			}
			case 1:
			if(Arr[1]==-1)
			{
				break;
			}
			else
			{
				printf("From 2:30pm to 3pm is reserved by the ID NUM:%d\n",Arr[1]);
				break;
			}
			case 2:
			if(Arr[2]==-1)
			{
				break;
			}
			else
			{
				printf("From 3:30pm to 4pm is reserved by the ID NUM:%d\n",Arr[2]);
				break;
			}
			case 3:
			if(Arr[3]==-1)
			{
				break;
			}
			else
			{
				printf("From 4pm to 4:30pm is reserved by the ID NUM:%d\n",Arr[3]);
				break;
			}
			case 4:
			if(Arr[4]==-1)
			{
				break;
			}
			else
			{
				printf("From 4:30pm to 5pm is reserved by the ID NUM:%d\n",Arr[4]);
				break;
			}
		}
	}
}

