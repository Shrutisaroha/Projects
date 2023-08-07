#include<stdio.h>
#include<stdlib.h>

//declaring structure for ticket booking
struct book
{
	char code[20];
	char name[50];
	char date[20];
	int cost;
	
}b;

//Login system
void login()
{
	int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
    	system("cls");
	printf("\n***********************************************************************************");
    printf("\n---------------------------------  LOGIN FIRST ------------------------------------ ");
   	printf("\n***********************************************************************************");
	printf(" \n\n                  ENTER USERNAME:- \t");
	scanf("%s", &uname); 
	printf(" \n\n                  ENTER PASSWORD:- \t");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword); 
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
		system("cls");
	printf("\n\n\n");
	printf("\n*****************************************************************************************");
	printf("\n\n              WELCOME TO OUR BOOKING SYSTEM !!!! LOGIN IS SUCCESSFUL");
	printf("\n\n*****************************************************************************************");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		system("cls");
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		
		getch();//holds the screen
		
	}
}
	while(a<=2);
	if (a>2)
	{
			system("cls");
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		exit(0);
		getch();
		
		}
		system("cls");
	
		
}



void insert_details()
{
	
	FILE *fp;
	struct book b;
	printf("Enter Movie code :\t ");	
	scanf("%s",b.code);
	printf("Enter  Movie name :\t ");	
	scanf("%s",b.name);
	printf("Enter Release Date:\t ");	
	scanf("%s",b.date);
	printf("Enter Ticket Price:\t ");	
	scanf("%d",&b.cost);
	
	fp=fopen("Movie_data.txt","a");

	if(fp == NULL)
	{
		printf("\n\n\n\n\n\n\nFile not Found!!!!");
	}
	else
	{
		
		fprintf(fp,"\t\t%s\t\t %s \t %s\t\t %d \n",b.code,b.name,b.date,b.cost);
		printf("\n\nRecords Inserted Successfully in the Movie_data file!");
		getch();
	}
		printf("\n");
	fclose(fp);
	system("cls");
}

void viewAll()
{
	
	char ch;
	FILE *fp;

	fp = fopen("Movie_data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		system("cls");
		printf("\n\t\tHere is the List of all the Movies!!!!!\n");
		printf("\n\t\tMovie Code \t Movie Name \t Release date  \t Ticket Price \n");
		printf("------------------------------------------------------------------------------------------------------\n");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
	}
	fclose(fp);
	getch();
	system("cls");

}
void book_ticket()
{
 struct book b;
	FILE *fp;

	FILE *ufp;

	int total_seat,mobile,total_amount;
	char name[20];

	
	char ch; 
	char movie_code[20]; 
	fp = fopen("Movie_data.txt","r");
	if(fp == NULL)
	{
		printf("File does not found!");
		exit(1);

	}
	else
	{	
		system("cls");
		printf("\t\t\tHere is the list of shows which are currently available!\n");
		printf("\n\t\tMovie Code \t Movie Name \t Release date  \t Ticket Price \n");
		printf("----------------------------------------------------------------------------------------\n");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
		
	}
	fclose(fp);
	printf("\n\n");
	printf("\n*************************************************************************************\n");
	printf("\t\t\t\t  * Fill Your Deatails  *");
	printf("\n*************************************************************************************\n");
	printf("\n Enter Your Name :\t");
	scanf("%s",name);
	printf("\n Enter Your Mobile Number :\t");
	scanf("%d",&mobile);
	printf("\n Enter the total number of tickets :\t");
	scanf("%d",&total_seat);
	
	//display ends
	printf("\n\n\n\n\t\t\t For Booking ticket\n \n First enter the code of the Movie you want see!!");
	printf("\n\n\t\t\t Enter movie code :\t");
	scanf("%s",movie_code);
	fp = fopen("Movie_data.txt","r");
	if(fp == NULL)
	{
		printf("File does not found !");
		exit(1);

	}
	else
	{	
		while(fgetc(fp) != EOF)
		{
			fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
			if(strcmp(b.code,movie_code) == 0)
			{	
				printf("\n===================================================================\n");	
				printf("\n \t\t\tRecord Found\n");
				printf("\n===================================================================\n");
				printf("\n\t\tMovie Code 		  ::%s",b.code);
				printf("\n\t\tMovie Name 		  ::%s",b.name);
				printf("\n\t\tRelease Date 		  ::%s",b.date);
				printf("\n\t\tPrice of ticket	  ::%d",b.cost);
				printf("\n===================================================================\n");
				
				printf("\n\n");
				printf("\t\t\t=======================================================================\n");
       			printf("\t\t\t----------------------THEATER BOOKING TICKET---------------------------\n");
        		printf("\t\t\t=======================================================================\n");
				printf("\n\t\t\t\t\tCustomer Name 	   ::   %s",name);
				printf("\n\t\t\t\t\tMobile Number 	   ::   %d",mobile);
				printf("\n\t\t\t\t\tMovie Name         ::   %s",b.name);
			 	printf("\n\t\t\t\t\tTime               ::   08:00pm");
                printf("\n\t\t\t\t\tHall               ::   02");
				printf("\n\t\t\t\t\tTotal Seats 	   ::   %d",total_seat);
				printf("\n\t\t\t\t\tCost per ticket    ::   %d",b.cost);
				total_amount = b.cost * total_seat;
				printf("\n\t\t\t\t\tTotal Amount 	   ::   %d",total_amount);
				printf("\n\t\t\t=====================================================================\n");
				
				ufp=fopen("Customer_Record.txt","a");
				if(ufp == NULL)
				{
					printf("File not Found");
				}
				else
				{
					fprintf(ufp,"\n %s \t \t%d \t %s \t \t %d \t\t    %d ",name,mobile,b.name,b.cost,total_amount);
					printf("\n\n\n\n\t\t\tENJOY YOUR MOVIE!!!");
					printf("\n\n\n\n\t\t\tRecord inserted Sucessfully to the Customer_Record file!");
				}
	
			}
			
		}
	}
	
	
		printf("\n");
	fclose(ufp);
	fclose(fp);

}

//for viewing all user transactions
void customer_record()
{
	char ch;
	FILE *fp;

	//system("clear");
	
	fp = fopen("Customer_Record.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		system("cls");
		printf("\t\n Records of all the customers who have booked ticket!\n\n\n");
		printf("Customer_Name \t Mobile_number \t Movie_name \t   Cost_of_one_ticket \t  Total_amount\n");
		printf("--------------------------------------------------------------------------------------------------------------------\n\n");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
		
	}
	fclose(fp);
	getch();
	system("cls");


}


int seat = 60 ;
void login();
void insert_details();//for inserting movie details
void book_ticket(); //for booking tickets
void customer_record(); //for view old recorrds of users,booked tickets
void viewAll();
void main()
{
    //login();
	 int ch;
 	do{
	printf("\n=====================================================================\n");
	printf("\n");	
	printf("\t                    Movie Ticket booking ");
	printf("\n");
	printf("\n=====================================================================");
	printf("\n====================================================================\n");
	printf("||             1- To Insert Movie (only admin):                   ||\n");
	printf("||             2- To view reserved tickets (only admin):          ||\n");
	printf("||             3- To puchase ticket:                              ||\n");
	printf("||             4- To View list of all Movies:                     ||\n");
	printf("||             5- Exit system:                                    ||\n");
	printf("||================================================================||\n");

   	printf("\n\n\n\tEnter your Choice ::  ");
   	scanf("%d",&ch); 
	   system("cls");	

   	switch (ch)
   	{
    	case 1 :
    		login();
    		insert_details();
   		break;
		case 2:
			login();
    		customer_record();
   		break;
    		
		case 3:
    		book_ticket();
   		break;

		case 4:
		 	viewAll();
		break;
		
		case 5:
			system("cls");
			printf("\n\n\n\n\n\t\t*** Thank You! Visit Again!!! ***\n\n");
			exit(0);
		break;

    	default:
    		printf("\n\n\t \t Wrong choice !!!!\n\t\t  Try Again!!!");
    		getch();
    		system("cls");
    	break;
   	}
 }while(ch!=0);

}


