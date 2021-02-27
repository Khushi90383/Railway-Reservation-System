#include<stdio.h>
#include<stdlib.h>
#include "conio2.h"
#include "rlyes.h"
int main()
{
    int choice,tn,result,res;
    struct passenger* ptr;
    int ticket_no;
    char*pmob_no;
    int*pticket_no;
    char*ptrain_no;
    char*train_no;
    add_trains();
    while(1)
    {
        choice=enterchoice();
        if(choice==9)
            exit(0);
        switch(choice)
        {
                        case 1:
                                    clrscr();
                                    textcolor(LIGHTCYAN);
                                    view_trains();
                                    getch();
                                    clrscr();
                                    break;
                        case 2:
                                    ptr=get_passenger_details();
                                    clrscr();
                                    if(ptr!=NULL)
                                    {
                                       ticket_no=book_ticket(*ptr);
                                       if(ticket_no==-1)
                                       {
                                           textcolor(LIGHTRED);
                                           printf("Booking Failed!");
                                       }
                                       else
                                       {
                                           textcolor(LIGHTGREEN);
                                           printf("Your ticket successfully booked\nYour Ticket no. is %d",ticket_no);

                                       }
                                       textcolor(WHITE);
                                       printf("\nPress any key to go back to the main screen.....!");
                                       getch();
                                       clrscr();
                                    }
                                    break;
                       case 3:
                                    clrscr();
                                    ticket_no=accept_ticket_no();
                                    clrscr();
                                    if(ticket_no!=0)
                                    {
                                        view_ticket(ticket_no);
                                        textcolor(WHITE);
                                        printf("\n\n\nPress any key to go back to the main screen!");
                                    }
                                    getch();
                                    clrscr();

                                    break;
                       case 4:
                                    clrscr();
                                      pmob_no=accept_mob_no();
                                      if(pmob_no!=NULL)
                                      {
                                         pticket_no=get_ticket_no(pmob_no);
                                         view_all_tickets(pmob_no,pticket_no);
                                      }
                                      clrscr();
                                    break;
                       case 5:

                                     clrscr();
                                     view_all_bookings();
                                     getch();
                                     clrscr();
                                     break;
                       case 6:
                                     clrscr();
                                     ptrain_no=accept_train_no();
                                     gotoxy(1,1);
                                     if(ptrain_no!=NULL)
                                     {
                                         view_booking(ptrain_no);
                                     }
                                      clrscr();
                                     getch();
                                     break;
                       case 7:
                                    clrscr();
                                    tn=accept_ticket_no();
                                    if(tn!=0)
                                    {
                                        result=cancel_ticket(tn);
                                    }
                                    if(result==0)
                                    {
                                        textcolor(LIGHTRED);
                                        printf("SORRY!No tickets booked against the ticket no %d",tn);
                                    }
                                    else if(result==1)
                                    {
                                        textcolor(LIGHTGREEN);
                                        printf("Ticket no. %d successfully cancelled!",tn);
                                    }
                                    getch();
                                    clrscr();
                                    break;
                       case 8:
                                     clrscr();
                                     train_no =accept_train_no();
                                     if(train_no!=NULL)
                                     {
                                         res=cancel_train(train_no);
                                     }
                                     if(res==0)
                                     {
                                         textcolor(LIGHTRED);
                                         printf("\nNo such Train exists..!");
                                     }

                                     else if(res==1)
                                     {
                                         textcolor(LIGHTGREEN);
                                         gotoxy(1,4);
                                         printf("\nTrain no %s cancelled....!",train_no);
                                         textcolor(WHITE);
                                         printf("\n\nPress any key to go back to the main screen..!");
                                     }
                                     getch();
                                     clrscr();
                                    break;
                       default:
                                      textcolor(LIGHTRED);
                                      printf("Wrong Choice! Try Again\n");
                                      getch();
                                      clrscr();

    }
    }
    return 0;
}

