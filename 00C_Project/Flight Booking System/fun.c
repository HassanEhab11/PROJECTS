#include "header.h"

/*************************************************************/

void CreateList(List *pl){
	pl->head=NULL;                      // create list
	pl->size=0;
}

/*************************************************************/

int ListEmpty(List *pl){
	return (pl->size==0);         // Check if list is empty
	//or return !pl->head
}

/*************************************************************/

int ListFull(List *pl){
	return 0;                     // Check if list is full
}

/*************************************************************/

int ListSize(List *pl){
	return pl->size;               // List size
}

/*************************************************************/

void DestroyList(List *pl){
	ListNode *q;
	while(pl->head){
		q=pl->head->next;       // Destroy list
		free(pl->head);
		pl->head=q;
	}
	pl->size=0;
}

/*************************************************************/

void InsertList(int pos, NewClient* pc, List *pl){                      // this function is used to insert a new node
   ListNode *p, *q;
   int i;

	p=(ListNode *)malloc(sizeof(ListNode));
    strcpy(p->client.name,pc->name);
    strcpy(p->client.address,pc->address);
    strcpy(p->client.phone,pc->phone);

        strcpy(p->client.clas_1,pc->clas_1); /**********************************/
        strcpy(p->client.seat,pc->seat); /**********************************/


    p->client.birthday.day=pc->birthday.day;
    p->client.birthday.month=pc->birthday.month;
    p->client.birthday.year=pc->birthday.year;

    p->client.id=pc->id;
	p->next=NULL;

	if (pos==0){
	   p->next=pl->head;
	   pl->head=p;
	   return;
	}                                                   // Insert function.
	else{
	   for(q=pl->head, i=0; i<pos-1; i++)
		q=q->next;
	   p->next=q->next;
         q->next=p;
      }
      pl->size++;


      return;
}

/*************************************************************/

void DeleteList(int id, NewClient *pc, List *pl,char *(*B),char *(*E),char *(*S)){
                                                                                       // this function is used to delete list and return seat free to used by another customer
   int i;
   ListNode *q, *tmp;
   char *b="Business class";
   char *e="Economic class";
   char *s="Smoking class";
   char *x = "0";
   int j;


   if (id==0){
	//*pc=pl->head->client.seat;

	       if (!strcmp((pl->head->client.clas_1),b))
             {
                  for(j=0;j<42;j++)
                      {
                           if (!strcmp(B[j],x))
                               {

                                    B[j]=pl->head->client.seat;
                                            break;}

                  }}

        else if (!strcmp((pl->head->client.clas_1),e))
               {
                       for(j=0;j<60;j++)
                           {
                            if (!strcmp(E[j],x))
                             {

                            E[j]=pl->head->client.seat;
                                 break;}

                                }}
        else if (!strcmp((pl->head->client.clas_1),s))
                   {
                           for(j=0;j<44;j++)
                               {
                                if (!strcmp(S[j],x))
                                          {

                                         S[j]=pl->head->client.seat;
                                          break;}

    }}

	tmp=pl->head->next;
	free(pl->head);
	pl->head=tmp;
   }// it works also for one node
   else{                                                  // Delete List
	for(q=pl->head, i=0; i<id-1; i++)
		q=q->next;

	//*pc=q->next->client;
	if (!strcmp((q->next->client.clas_1),b))
             {
                  for(j=0;j<42;j++)
                      {
                           if (!strcmp(B[j],x))
                               {

                                    B[j]=q->next->client.seat;
                                            break;}

                  }}

        else if (!strcmp((q->next->client.clas_1),e))
               {
                       for(j=0;j<60;j++)
                           {
                            if (!strcmp(E[j],x))
                             {

                            E[j]=q->next->client.seat;
                                 break;}

                                }}
        else if (!strcmp((q->next->client.clas_1),s))
                   {
                           for(j=0;j<44;j++)
                               {
                                if (!strcmp(S[j],x))
                                          {

                                         S[j]=q->next->client.seat;
                                          break;}

    }}
	tmp=q->next->next;
	free(q->next);
	q->next=tmp;
   }
   pl->size--;
}

/*************************************************************/

void ReplaceList(int id, NewClient *pc, List *pl){
	int i;
	ListNode *q;
	for(q=pl->head, i=0; i<id; i++)                 // Replace List
		q=q->next;
	strcpy(q->client.name,pc->name);
    strcpy(q->client.address,pc->address);
    strcpy(q->client.phone,pc->phone);
        strcpy(q->client.clas_1,pc->clas_1);
        strcpy(q->client.seat,pc->seat);
    q->client.birthday.day=pc->birthday.day;
    q->client.birthday.month=pc->birthday.month;
    q->client.birthday.year=pc->birthday.year;
    //q->client.phone=pc->phone;
    q->client.id=pc->id;
}

/*************************************************************/


void details(NewClient *pc,int pos)                 // this function ask the user to inter some details and gets this information from user
{
    pc->id = pos+1;
	printf("\n\t Your ID is: %d\n",pc->id);
	printf(" \n\t *** THIS ID IS IMPORTANT IF YOU WANT TO EDIT OR DELETE YOUR REGESTRIATION *** \n");

	//pc->id ++;
    //NewClient *pc = &c;
	printf("\n\t Enter your Name: ");
	gets(pc->name); fflush(stdin);
	printf("\n\t Enter your Date of birth (day/month/year): ");
	scanf("%d%d%d",&(pc->birthday).day,&(pc->birthday).month,&(pc->birthday).year);

	fflush(stdin);
	printf("\n\t Enter your Phone Number: ");
	gets(pc->phone); fflush(stdin);

	/*printf("\n\t Enter your ID:");
	scanf("%d",&(pc->id)); fflush(stdin);*/

    printf("\n\t Enter Your Address : ");
    gets(pc->address); fflush(stdin);

	//scanf("%s",&(pc->phone)); //fflush(stdin);

	//printf("\n\t Your ID is: %d",pc->id);
	printf("\n\t Enter your prefferd class :\n\t\t\t\t\t 1.Business \n\t\t\t\t\t 2.Economic \n\t\t\t\t\t 3.Smoking \n\t Your choose is :");
	scanf("%c",&(pc->clas));fflush(stdin);

}

void display(  List *pl)
{
	ListNode *p;
	p = pl->head;
         printf("\n  ------------------------------------------------------------------------------------------------------------------------------------------ ");
        printf("\n\tID\t\tName\t\t\tAddress\t\tDate of birth\t\tPhone number\t\tclass _ seat");
         printf("\n  ------------------------------------------------------------------------------------------------------------------------------------------ ");

	while (p)
	{
       /* printf("\n\n  ****--------------*****-------------****");
        printf("\n         ID            : %d ", (p->client).id);
        printf("\n         Name          : %s ", (p->client).name);
		printf("\n         Address       : %s ", (p->client).address);

        printf("\n         Date of birth : %d / %d / %d ", (p->client).birthday.day,(p->client).birthday.month,(p->client).birthday.year);
        printf("\n         Phone number  : %s ", p->client.phone);

        printf("\n         class         : %s ", p->client.clas_1);
        printf("\n         seat          : %s ", p->client.seat);    */


        printf("\n\t%d\t\t%s\t\t%s\t\t%d/%d/%d\t\t%s\t\t%s _ %s"
               , (p->client).id, (p->client).name, (p->client).address, (p->client).birthday.day,(p->client).birthday.month,(p->client).birthday.year, p->client.phone, p->client.clas_1, p->client.seat);



		p = p->next;
	}

}
/*********************************************************************************************************/
void clas_seat(NewClient *pc,char *(*B),char *(*E),char *(*S))   // Class seat and seat number: check if the same seat repeated. need some edit
{                                                                // if seat is repeated i need to print for user to choose another seat and return
                                                                  // the user to choose another available seat.
                                                                  // this function is done.
   char clas = pc->clas;
   char *name;
    int i;
    int x=1;
    switch (clas)
    {
    case '1':


        printf("\n\t\t\t *** Now you are in Business class ***");
        while (x){
        name="Business class";
        strcpy(pc->clas_1,name);

        printf("\n\n\tplease inter seat you preferred:  ");
        gets(pc->seat); fflush(stdin);
        //printf("%s",B[1]);

        for (i=0;i<42;i++){
        if (!strcmp(pc->seat,B[i]))
         {
         printf("\n\t\t\tSeat booking successful");
         B[i]="0";
         x=0;
              break;
                                                                  // under edit
              }
          }

          if(x)
          {
              printf("\n\t\t Sorry ... This seat is not available ... please choose another seat");

          }}

        break;

    case '2':

        printf("\n\t\t\t *** Now you are in Economic class ***\n");
        while (x){
        name="Economic class";
        strcpy(pc->clas_1,name);

        printf("\n\n\t\tplease inter seat you preferred:");
        gets(pc->seat); fflush(stdin);
        //printf("%s",B[1]);

        for (i=0;i<60;i++){
        if (!strcmp(pc->seat,E[i]))
         {
         printf("\n\t\t\tSeat booking successful");
         E[i]="0";
          x=0;

              break;
                                                  // under edit
              }
            }

         if(x)
          {
              printf("\n\t\t Sorry ... This seat is not available ... please choose another seat");

          }}

        break;

    case '3':

        printf("\n\t\t\t *** Now you are in Smoking class ***");
        while (x){
        name="Smoking class";
        strcpy(pc->clas_1,name);

        printf("\n\n\t\tplease inter seat you preferred:");
        gets(pc->seat); fflush(stdin);
        //printf("%s",B[1]);

        for (i=0;i<44;i++){
        if (!strcmp(pc->seat,S[i]))
         {
         printf("\n\t\t\tSeat booking successful");
         S[i]="0";
         x=0;
              break;
                                                  // under edit
              }

             }

       if(x)
          {
              printf("\n\t\t Sorry ... This seat is not available ... please choose another seat");

          }}

        break;
    }
//return;

}
/*****************************************************************************************************/
/*
void seats (char *(*B),NewClient *pc){

       // int x;
        printf("\n\n\t\tplease inter seat you preferred:");
        gets(pc->seat); fflush(stdin);
        //printf("%s",B[1]);
int i;
for (i=0;i<44;i++){
if (!strcmp(pc->seat,B[i]))
    {
         printf("\n\t\t\tSeat booking successful");
         B[i]="0";

      break;
           // under edit
    }

}
if (strcmp(pc->seat,B[i])==1)
       printf("seat %s is not available ",pc->seat);
      //   printf("this seat is not available ... please choose another seat");

}
*/


/*******************************************************************************************************/
void free_seats(char *(*B),char *(*E),char *(*S))                        // this function help the user to know free seat in each class.

{
    int choose;
    printf("\n\tEnter your prefferd class :\n\t\t\t\t\t 1.Business \n\t\t\t\t\t 2.Economic \n\t\t\t\t\t 3.Smoking \n\t Your choose is : ");
	scanf("%d",&choose);fflush(stdin);

	int i;

    switch (choose)
    {
case 1:
    printf("\n\tFree Seats in Business Class :\n\n\t");
    for (i=0;i<42;i++)
       {
           if (B[i])
        printf("%s\t",B[i]);

       }
    break;
case 2:
    printf("\n\tFree Seats in Economic Class :\n\n\t");
    for (i=0;i<60;i++)
       {
           if (E[i])
        printf("%s\t",E[i]);

       }
    break;
case 3:
    printf("\n\tFree Seats in Smoking Class :\n\n\t");
    for (i=0;i<44;i++)
       {
           if (S[i])
        printf("%s\t",S[i]);

       }
    break;


    }



}
/****************************************************************************************************/
void class_list(List *pl)                               //Class List function : this function display the client in each list . . . need to simplify
{
   char *name;
   int choose;
   ListNode *p;
   p = pl->head;
   int i;
   printf("\n\tEnter your prefferd class :\n\t\t\t\t\t 1.Business \n\t\t\t\t\t 2.Economic \n\t\t\t\t\t 3.Smoking \n\t Your choose is : ");
	scanf("%d",&choose);fflush(stdin);

    switch (choose)
    {
    case 1:

        printf("\t\t  Business class List");
        name="Business class";
          printf("\n  ------------------------------------------------------------------------------------------------------------------------------------------ ");
        printf("\n\tID\t\tName\t\t\tAddress\t\tDate of birth\t\tPhone number\t\tclass _ seat");
         printf("\n  ------------------------------------------------------------------------------------------------------------------------------------------ ");

       for (i=0;i<=pl->size;i++){
       if (!strcmp(p->client.clas_1,name))
         {
       /* printf("\n\n  ****--------------*****-------------****");
        printf("\n         ID            : %d ", (p->client).id);
        printf("\n         Name          : %s ", (p->client).name);
		printf("\n         Address       : %s ", (p->client).address);

        printf("\n         Date of birth : %d / %d / %d ", (p->client).birthday.day,(p->client).birthday.month,(p->client).birthday.year);
        printf("\n         Phone number  : %s ", p->client.phone);

        printf("\n         class         : %s ", p->client.clas_1);
        printf("\n         seat          : %s ", p->client.seat); */
        printf("\n\t%d\t\t%s\t\t%s\t\t%d/%d/%d\t\t%s\t\t%s _ %s"
               , (p->client).id, (p->client).name, (p->client).address, (p->client).birthday.day,(p->client).birthday.month,(p->client).birthday.year, p->client.phone, p->client.clas_1, p->client.seat);


	     }
	     p = p->next;
       }

        break;

    case 2:

        printf("\t\t  Economic class List\n");
        name="Economic class";
        printf("\n  ------------------------------------------------------------------------------------------------------------------------------------------ ");
        printf("\n\tID\t\tName\t\t\tAddress\t\tDate of birth\t\tPhone number\t\tclass _ seat");
         printf("\n  ------------------------------------------------------------------------------------------------------------------------------------------ ");

         for (i=0;i<=pl->size;i++){
       if (!strcmp(p->client.clas_1,name))
         {
        /*printf("\n\n  ****--------------*****-------------****");
        printf("\n         ID            : %d ", (p->client).id);
        printf("\n         Name          : %s ", (p->client).name);
		printf("\n         Address       : %s ", (p->client).address);

        printf("\n         Date of birth : %d / %d / %d ", (p->client).birthday.day,(p->client).birthday.month,(p->client).birthday.year);
        printf("\n         Phone number  : %s ", p->client.phone);

        printf("\n         class         : %s ", p->client.clas_1);
        printf("\n         seat          : %s ", p->client.seat); */

         printf("\n\t%d\t\t%s\t\t%s\t\t%d/%d/%d\t\t%s\t\t%s _ %s"
               , (p->client).id, (p->client).name, (p->client).address, (p->client).birthday.day,(p->client).birthday.month,(p->client).birthday.year, p->client.phone, p->client.clas_1, p->client.seat);


	     }
	     p = p->next;
       }

        break;

    case 3:
        printf("\t\t  Smoking class List");
        name="Smoking class";
        printf("\n  ------------------------------------------------------------------------------------------------------------------------------------------ ");
        printf("\n\tID\t\tName\t\t\tAddress\t\tDate of birth\t\tPhone number\t\tclass _ seat");
         printf("\n  ------------------------------------------------------------------------------------------------------------------------------------------ ");
         for (i=0;i<=pl->size;i++){
       if (!strcmp(p->client.clas_1,name))
         {
       /* printf("\n\n  ****--------------*****-------------****");
        printf("\n         ID            : %d ", (p->client).id);
        printf("\n         Name          : %s ", (p->client).name);
		printf("\n         Address       : %s ", (p->client).address);

        printf("\n         Date of birth : %d / %d / %d ", (p->client).birthday.day,(p->client).birthday.month,(p->client).birthday.year);
        printf("\n         Phone number  : %s ", p->client.phone);

        printf("\n         class         : %s ", p->client.clas_1);
        printf("\n         seat          : %s ", p->client.seat); */
        printf("\n\t%d\t\t%s\t\t%s\t\t%d/%d/%d\t\t%s\t\t%s _ %s"
               , (p->client).id, (p->client).name, (p->client).address, (p->client).birthday.day,(p->client).birthday.month,(p->client).birthday.year, p->client.phone, p->client.clas_1, p->client.seat);


	     }
	     p = p->next;
       }



 break;



}    }

/*void sorting (List * pl)
{



    for (i = *pl; i!=NULL;i=i->next)
    {
        for (j = i->next;j!=NULL;j=j->next)
        {
            if(compare_names(i,j) > 0)

        }
    }


}*/
