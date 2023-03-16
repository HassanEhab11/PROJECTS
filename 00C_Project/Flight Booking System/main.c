#include "header.h"


int main()
{

   List l;

    CreateList(&l);
    NewClient c;
    NewClient *pc;
    pc = &c;

     char *B[42]={"A1","A2","A3","A7","A8","A9","A10","C1","C2","C3","C7","C8","C9","C10",
                  "D1","D2","D3","D7","D8","D9","D10","G1","G2","G3","G7","G8","G9","G10",
                  "H1","H2","H3","H7","H8","H9","H10","K1","K2","K3","K7","K8","K9","K10"};

    char *E[60]={"A22","A23","A24","A25","A26","A27","A28","A29","C22","C23","C24","C25","C26","C27","C28","C29",
                 "D23","D24","D25","D26","D27","D28","D29","E23","E24","E25","E26","E27","E28","E29",
                 "F23","F24","F25","F26","F27","F28","F29","G23","G24","G25","G26","G27","G28","G29",
                 "H22","H23","H24","H25","H26","H27","H28","H29","K22","K23","K24","K25","K26","K27","K28","K29"};

    char *S[44]={"A45","A46","A47","A48","A49","A50","C45","C46","C47","C48","C49","C50",
                 "D46","D47","D48","D49","D50","E46","E47","E48","E49","E50",
                 "F46","F47","F48","F49","F50","G46","G47","G48","G49","G50",
                 "H45","H46","H47","H48","H49","H50","K45","K46","K47","K48","K49","K50",};




   int choice;
   int pos=0;//scanf("%d", &pos); fflush(stdin);
   int id;
	do
	{

		printf("\n\n\t*******************************************************************\n");
		printf("\n\t          <-------     Flight Booking System     ------->                  ");
		printf("\n\n\t*******************************************************************");
		printf("\n\t                      By: Hassan Ehab                  ");
		printf("\n\n\t*******************************************************************");
		printf("\n\n\n\t\t           Please enter your choice from below (0-6):");
		printf("\n\n\t\t 1. NEW_CLIENT");
		printf("\n\n\t\t 2. DELETE_CLIENT");
		printf("\n\n\t\t 3. CLIENT_LIST");
		printf("\n\n\t\t 4. CLIENT_EDIT");
		printf("\n\n\t\t 5. FREE_SEATS");
		printf("\n\n\t\t 6. CLASS_LIST");
		printf("\n\n\t\t 0. Exit");

		printf("\n\n\t\t Enter your choice : ");


		scanf("%d", &choice); fflush(stdin);


		switch (choice)
		{
		case 1:
			                                                          //1.NEW_CLIENT
            details(pc,pos);
            fflush(stdin);
            clas_seat(pc,B,E,S);
            //seats (B,&c);
		    InsertList( pos, pc, &l);
			printf("\n\n\t\t\tRegistration Successful");
            //printf("\n%d",pos);
			pos ++;
			//printf("\n%d",pos);
			printf("\n\n");

			break;
		case 2:

			printf("\n\t\t please inter your ID: ");
			scanf("%d",&id);                                                     //2.DELETE_CLIENT
			DeleteList( id-1  , pc , &l,B,E,S);
			printf("\t\tThis Account is deleted Successfully ...");
			pos --;

			break;
		case 3:
            printf("\n\n  ****--------------*****-------------****");
            printf("\n\t  CLIENT_LIST");                                            //3.CLIENT_LIST
            display( &l);
			//printf("NEW_CLIENT04");
			break;
		case 4:
					printf("\n\n  ****--------------*****-------------****");
                    printf("\n\t  CLIENT_EDIT\n");
					printf("\tplease inter id: ");
			        scanf("%d",&id);                                                //4.CLIENT_EDIT
			        fflush(stdin);
			        details(pc,id-1);
			        clas_seat(pc,B,E,S);
					ReplaceList(id-1, pc,&l);
					printf("Editing Successful");

				  break;
		case 5:
                    printf("\n\n  ****--------------*****-------------****");
                    printf("\n\t  FREE_SEATS");
					free_seats(B,E,S);                                           //5.FREE_SEATS

				  break;
        case 6:
                    printf("\n\n  ****--------------*****-------------****");        //6.CLASS_LIST
                    printf("\n\t  CLASS_LIST");
					class_list(&l);

				  break;
         case 0:
					printf("\n\n\t\t With Best Wishes");
                                                              //0.Exit
				  break;
		default:

			printf("\n\n\t PLEASE CHOOSE FROM 0-6");

		}


	} while (choice != 0);

    printf("\nHello world!\n");
    return 0;
}
