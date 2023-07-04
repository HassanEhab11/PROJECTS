#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*************************************************************************/
typedef struct date{

     int day;
     int month;
     int year;

}Date;

/***-----------------------------------------------------------------***/

typedef struct NEW_CLIENT{

     char name[50];
     Date birthday;
     int id;
     char address [50];
     char phone[15];
     char clas;
     char clas_1[50];
     char seat[5];   /* class and seat need to edit ?????????????????????????????????????????*/

}NewClient;

/***********************************************************************/

typedef struct listnode{
	NewClient client;
	struct listnode *next;
}ListNode;
/***-------------------------------------------------------------------***/
typedef struct list{
	ListNode	*head;
	int		size;
}List;
/**********************************************************************/



                                                                             // Global Variables



/**********************************************************************/
void CreateList(List *pl);
int ListEmpty(List *pl);
int ListFull(List *pl);
int ListSize(List *pl);
void DestroyList(List *pl);
void sorting (List ** pl);
                                                         // Data Structure function
void InsertList(int pos, NewClient* pc, List *pl);
void DeleteList(int id, NewClient *pc, List *pl,char **B,char **E,char **S);
void ReplaceList(int id, NewClient *pc, List *pl);
void display(  List *pl);

/**********************************************************************/

void details(NewClient *pc,int pos);

void seats (char **B,NewClient *pc);

void clas_seat(NewClient *pc,char **B,char **E,char **S);

void free_seats(char **B,char **E,char **S);

void class_list(List *pl);


