#include<stdio.h>
#include<stdlib.h>
#include"STD_TYPES.h"
#include"Head.h"

Patient *head=NULL;
Patient *current=NULL;
Patient *prev=NULL;
u32 List_Length=0,Size=0,ID,Time,i;
u8 Patient_name[100];
u8 Patient_gender[10];
u32 Patient_age,Patient_id,_id;
int main(void)
{
	u32 MODE_Choice,Input,New_Value,Patient_NodeValue,Position,User_Password;
	u8 flag=0,Exit_flag=1;
	
	while(Exit_flag)
	{
		printf("\t\t\t/***************************************************************/\n");
		printf("\t\t\t/*****************     Author:hassan diab    *******************/\n");
		printf("\t\t\t/*****************     Version:29/12/2021    *******************/\n");       
		printf("\t\t\t/***************************************************************/\n");
		printf("Enter 1 for admin mode (or) enter 2 for user mode (or) Enter 3 to exit\n");
		printf("your MODE_Choice :");
		scanf("%d",&MODE_Choice);
		if(MODE_Choice==1)
		{
			printf("\t\t\t************* ADMIN MODE *************\n\n");
			printf("\t");
			printf("please Enter the Password :");
			for(i=0;i<3;i++)
			{
				scanf("%d",&User_Password);
				if(User_Password==1234)
				{
					printf("\t\t\t****** WELCOME ******\n\n");
					flag=1;
					break;
				}
				else if(i<2)
				{
					printf("Try again: ");
				}
			}
			if(flag==1)
			{
				printf("if you want to add new patient record press 1 \n");
				printf("if your want to edit patient record press 2\n");
				printf("if you want to reserve a slot with the doctor press 3\n");
				printf("if you want to cancel reservation press 4\n");
				printf("Your Choice: ");
				scanf("%d",&Input);
				switch(Input)
				{
					case 1: printf("please Enter the patient's name :");
					scanf(" %[^\n]%*c",Patient_name);
					printf("Please Enter The Patient's Age : ");
					scanf("%d",&Patient_age);
					printf("Please Enter The Patient's gender (Male or Female): ");
					scanf(" %[^\n]%*c",Patient_gender);
					printf("Please Enter The Patient's ID : ");
					scanf("%d",&Patient_id);
					Add_Patient(Patient_name,Patient_age,Patient_gender,Patient_id);
					break;
					case 2 :printf("enter Your ID:");
					scanf("%d",&_id);
					Edit_List(_id);
					break;
					case 3 : 
					Time_Reservation();
					break;
					case 4:
					printf("Enter Your ID : ");
					scanf("%d",&_id);
					Cancel_Reservation(_id);
					break;
					default: printf("Invalid Choice please try again\n");
					break;
				}
			}
			else if (flag==0)
			{
				printf("Incorrect Password for 3 contiguous times \n");
				Exit_flag=0;
			}
			
		}
		else if(MODE_Choice==2)
		{
			printf("\t\t\t********* User Mode *********\n\n");
			printf("For Patient record press 1\n");
			printf("For today's reservation press 2 \n");
			printf("Your choice : ");
			scanf("%d",&MODE_Choice);
			switch(MODE_Choice)
			{
				case 1 : 
				printf("Enter Your ID: ");
				scanf("%d",&_id);
				printf("\t\t\t********** Patient Record **********\n\n");
				Print_Patient_List(_id);
				break;
				case 2 :
				printf("\t\t\t********** Today's Reservation **********\n\n");
				print_Patient_Reservation();
				break;
				default :
				printf("Invalid Choice Please try again\n");
				break;
			}
		}
		else if(MODE_Choice==3)
		{
			Exit_flag=0;
			printf("Enjoy Your Time ,Bye");
			
		}
		else
		{
			printf("Wrong entry\n");
		}
	}
}
