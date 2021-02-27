#include<stdio.h>
#include "conio2.h"
#include<string.h>
#include "rlyes.h"
#include<ctype.h>
#include<stdlib.h>
#include<errno.h>
int enterchoice()
{
    int choice,i;
    textcolor(YELLOW);
    gotoxy(25,1);
    textcolor(YELLOW);
    printf("RAILWAY RESERVATION SYSTEM\n");
    textcolor(MAGENTA);
    for(i=1;i<=70;i++)
    {
        printf("*");
    }
    textcolor(LIGHTGREEN);
    printf("\nSelect an option");
    printf("\n1-View Trains");
    printf("\n2-Book Ticket");
    printf("\n3-View Ticket");
    printf("\n4-Search Ticket No");
    printf("\n5-View All Bookings");
    printf("\n6-View Train Bookings");
    printf("\n7-Cancel Ticket");
    printf("\n8-Cancel Train");
    printf("\n9-Quit");
    textcolor(YELLOW);
    printf("\n\nEnter choice:");
    scanf("%d",&choice);
    return choice;

}
void add_trains()
{
    train alltrains[4]={
              {"123","BPL","GWA",2100,1500},


              {"546","BPL","DEL",3500,2240},

              {"345","HBJ","AGR",1560,1135},

              {"896","HBJ","MUM",4500,3360},
                     };
       FILE*fp=fopen("e:\\My new C project learning\\alltrains.dat","rb");
       if(fp==NULL)
       {
           fp=fopen("e:\\My new C project learning\\alltrains.dat","wb");
           fwrite(alltrains,4*sizeof(train),1,fp);
           printf("File saved successfully!\n");
       }
       else
       {
           printf("\nFile already present!!");
       }
     fclose(fp);

}
void view_trains()
{
    int i;
    printf("Train no\tFrom\tTo\tFirst AC fare\tSecond AC fare\n");
    textcolor(MAGENTA);
    for(i=1;i<=70;i++)
    {
        printf("*");
    }
    FILE *fp=fopen("e:\\My new C project learning\\alltrains.dat","rb");
    train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        printf("\n%s\t\t%s\t%s\t%d\t\t%d",tr.train_no,tr.from,tr.to,tr.fac_fare,tr.sac_fare);
    }
    printf("\n\n\n\n");
    fclose(fp);

}
int check_train_no(char*train_no)
{
    FILE *fp=fopen("e:\\My New C project learning\\alltrains.dat","rb");
    train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        if(strcmp(tr.train_no,train_no)==0)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int check_mob_no(char*mob_no)
{
    if(strlen(mob_no)!=10)
    {
        return 0;
    }
    while((*mob_no)!='\0')
    {
        if(isdigit(*mob_no)==0)
           return 0;
           (mob_no)++;
    }
    return 1;
}
passenger*get_passenger_details()
{
    static passenger psn;
    clrscr();
    gotoxy(55,1);
    textcolor(GREEN);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("Enter passenger name:-");
    fflush(stdin);
    fgets(psn.p_name,20,stdin);
    char *pos;
    pos=strchr(psn.p_name,'\n');
    *pos='\0';
    if(strcmp(psn.p_name,"0")==0)
            {
                textcolor(LIGHTRED);
                gotoxy(1,21);
                printf("Reservation Cancelled!");
                getch();
                textcolor(YELLOW);
                return NULL;
            }
  int valid=0;
  printf("Enter gender(M/F):-");
  do
  {
      valid=1;
      fflush(stdin);
      scanf("%c",&psn.gender);
      if(psn.gender=='0')
      {
          textcolor(LIGHTRED);
          gotoxy(1,21);
          printf("\t\t\t\t\t\t");
          printf("Reservation cancelled");
          getch();
          textcolor(YELLOW);
          return NULL;
      }
      if(psn.gender!='M'&&psn.gender!='F')
      {
        gotoxy(1,21);
        valid=0;
      textcolor(LIGHTRED);
      printf("Gender should be (M/F) in upper case");
      gotoxy(19,2);
      printf("\t\t\t");
      gotoxy(19,2);
      textcolor(YELLOW);}
      }while(valid==0);
      gotoxy(1,21);
      printf("\t\t\t\t\t\t");
      gotoxy(1,3);
      printf("Enter train no:");
      do
      {
          valid=1;
        fflush(stdin);
        scanf("%s",psn.train_no);
      if(strcmp(psn.train_no,"0")==0)
      {
          textcolor(LIGHTRED);
                gotoxy(1,21);
                printf("Reservation Cancelled!");
                getch();
                textcolor(YELLOW);
                return NULL;
      }
      valid=check_train_no(psn.train_no);
            if(valid==0)
            {
            textcolor(LIGHTRED);
            gotoxy(1,21);
            printf("Error! Invalid Train No");
            getch();
            gotoxy(16,3);
            printf("\t\t\t\t\t\t");
            gotoxy(16,3);
            textcolor(YELLOW);
            }
            }while(valid==0);
            gotoxy(1,21);
            printf("\t\t\t\t\t\t");
            gotoxy(1,4);
printf("Enter travelling class(First AC-F/Second AC-S):");
do
{
    valid=1;
    fflush(stdin);
    scanf("%c",&psn.p_class);
    if(psn.p_class=='0')
    {
        textcolor(LIGHTRED);
          gotoxy(1,21);
          printf("\t\t\t\t\t\t");
          printf("Reservation cancelled");
          getch();
          textcolor(YELLOW);
          return NULL;
    }
    if(psn.p_class!='F'&&psn.p_class!='S')
    {
        gotoxy(1,21);
        textcolor(LIGHTRED);
        printf("Invalid Travelling class!Try Again");
        valid=0;
        getch();
        gotoxy(48,4);
        textcolor(YELLOW);
        printf(" \b");
    }
}while(valid==0);
        gotoxy(1,21);
        printf("\t\t\t\t\t\t\t\t");
        gotoxy(1,5);
        printf("Enter your address:");
        fflush(stdin);
        fgets(psn.address,30,stdin);
        pos=strchr(psn.address,'\n');
        *pos='\0';
         if(strcmp(psn.address,"0")==0)
            {
                textcolor(LIGHTRED);
                gotoxy(1,21);
                printf("Reservation Cancelled!");
                getch();
                textcolor(YELLOW);
                return NULL;
            }
          gotoxy(1,6);
     printf("Enter age:");
     do
     {
         valid=1;
     fflush(stdin);
     scanf("%d",&psn.age);
     if(psn.age==0)
     {
        textcolor(LIGHTRED);
                gotoxy(1,21);
                printf("Reservation Cancelled!");
                getch();
                textcolor(YELLOW);
                return NULL;
     }
     if(psn.age<0||psn.age>125)
     {
         valid=0;
         textcolor(LIGHTRED);
         gotoxy(1,21);
         printf("Invalid Age!Try again");
         getch();
         gotoxy(11,6);
         printf("\t\t\t\t\t\t");
         textcolor(YELLOW);
         gotoxy(11,6);
     }}while(valid==0);
     gotoxy(1,21);
     printf("\t\t\t\t\t\t");
      gotoxy(1,7);
      printf("Enter your mobile no:");
      do
      {
          valid=1;
          fflush(stdin);
          fgets(psn.mob_no,12,stdin);
          char*pos=strchr(psn.mob_no,'\n');
          if(pos!=NULL)
          *pos='\0';
          if(strcmp(psn.mob_no,"0")==0)
          {
               valid=0;
             textcolor(LIGHTRED);
             gotoxy(1,21);
             printf("Reservation Cancelled!");
             getch();
             textcolor(YELLOW);
             return NULL;
          }
          valid=check_mob_no(psn.mob_no);
          if(valid==0)
          {
              textcolor(LIGHTRED);
              gotoxy(1,21);
              printf("Invalid Mobile no.!");
              getch();
         gotoxy(22,7);
         printf("\t\t\t\t\t\t");
         textcolor(YELLOW);
         gotoxy(22,7);
          }
     }while(valid==0);
     return &psn;
}
int get_booked_ticket_count(char*train_no,char tc)
{
    FILE *fp;
    fp=fopen("e:\\My new C project learning\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }
    passenger pr;
    int count=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if((strcmp(pr.train_no,train_no)==0)&&pr.p_class==tc)
            count++;
    }
    fclose(fp);
    return count;
}
int last_ticket_no()
{
    FILE*fp;
    fp=fopen("e:\\My new C project learning\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }
    passenger pr;
    fseek(fp,-1L*sizeof(pr),SEEK_END);
    fread(&pr,sizeof(pr),1,fp);
    fclose (fp);
    return pr.ticketno;
}
int book_ticket(passenger p)
{
    int ticket_count=get_booked_ticket_count(p.train_no,p.p_class);
    if(ticket_count==30)
    {
        textcolor(LIGHTRED);
        printf("All seats full in train %s and class %c\n!",p.train_no,p.p_class);
        return -1;
    }
    int ticket_no=last_ticket_no()+1;
    p.ticketno=ticket_no;
    FILE*fp=fopen("e:\\My new C project learning\\allbookings.dat","ab");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry!File cannot be opened");
        return -1;
    }
    fwrite(&p,sizeof(p),1,fp);
    fclose(fp);
    return ticket_no;
}
int accept_ticket_no()
{
    int tn,valid;
    textcolor(YELLOW);
    printf("Enter ticket no:");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%d",&tn);
        if(tn==0)
        {
            gotoxy(1,21);
            printf("\t\t\t\t");
            textcolor(LIGHTRED);
            printf("Process of viewing ticket cancelled!");
            getch();
            textcolor(YELLOW);
            clrscr();
            return NULL;
        }
        if(tn<0)
        {
            gotoxy(1,21);
            textcolor(LIGHTRED);
            printf("Error!Ticket no. should be positive..Try again..! ");
            gotoxy(16,1);
            printf("\t\t\t");
            gotoxy(16,1);
        }
        }while(valid==0);
        return tn;
    }
void view_ticket(int ticket_no)
{
    FILE*fp;
    int i;
    fp=fopen("e:\\My new C project learning\\allbookings.dat","rb");
    if(fp==NULL)
    {
        printf("No bookings done yet!");
        return;
    }
    passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(pr.ticketno==ticket_no)
        {
         clrscr();
         for(i=0;i<=69;i++)
         {
             textcolor(LIGHTRED);
             printf("-");
         }
         textcolor(LIGHTBLUE);
         printf("\nName");
         gotoxy(11,3);
         printf("Gender");
         gotoxy(20,3);
         printf("Train no");
         gotoxy(29,3);
         printf("class");
         gotoxy(37,3);
         printf("Address");
         gotoxy(55,3);
         printf("Age");
         gotoxy(60,3);
         printf("mobile no\n");
         for(i=0;i<=69;i++)
         {
             textcolor(LIGHTRED);
            printf("-");
         }
         textcolor(LIGHTMAGENTA);
         printf("%s",pr.p_name);
         gotoxy(11,5);
         printf("%c",pr.gender);
         gotoxy(20,5);
         printf("%s",pr.train_no);
         gotoxy(29,5);
         printf("%c",pr.p_class);
         gotoxy(37,5);
         printf("%s",pr.address);
         gotoxy(55,5);
         printf("%d",pr.age);
         gotoxy(60,5);
         printf("%s",pr.mob_no);
         found=1;
         break;
        }
    }
        if(!found)
        {
            textcolor(LIGHTRED);
         printf("\n\n\nNo details of the ticket no. %d found!",ticket_no);
        }

    fclose(fp);
}
char*accept_mob_no()
{
    static char mob_no[12];
    int valid;
    char*pos;
    printf("Enter mobile no:");
    do
    {
        valid=1;
        fflush(stdin);
        fgets(mob_no,12,stdin);
        pos=strchr(mob_no,'\n');
        *pos='\0';
        if(strcmp(mob_no,"0")==0)
        {
            gotoxy(1,21);
            textcolor(LIGHTRED);
            printf("Reservation cancelled!");
            textcolor(YELLOW);
            return NULL;
            getch();
        }
        passenger psn;
        valid=check_mob_no(mob_no);
        if(valid==0)
          {
              textcolor(LIGHTRED);
              gotoxy(1,21);
              printf("Invalid Mobile no.!");
              getch();
         gotoxy(17,1);
         printf("\t\t\t\t\t\t");
         textcolor(YELLOW);
         gotoxy(17,1);
          }
     }while(valid==0);
      clrscr();
      return mob_no;
}
int *get_ticket_no(char*p_mob_no)
{
    int count =0,i=0;
    FILE *fp;
    fp=fopen("e:\\My new C project learning\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("File cannot be opened");
        return NULL;
    }
    passenger pr;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.mob_no,p_mob_no)==0)
        {
            count++;
        }
    }
    if(!count)
    {
        fclose(fp);
        return NULL;
    }
    int*p=(int*)malloc((count+1)*sizeof(int));
    rewind(fp);
    while(fread(&pr,sizeof(pr),1,fp))
    {
        if(strcmp(pr.mob_no,p_mob_no)==0)
        {
            *(p+i)=pr.ticketno;
            i++;
        }
    }
    *(p+i)=-1;
    fclose(fp);
    return p;
}
void view_all_tickets(char*pmob_no,int*pticket_no)
{
    if(pticket_no==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry!no tickets booked against mob no.%s",pmob_no);
        textcolor(WHITE);
        printf("\nPress any key to go back to the main menu");
        textcolor(YELLOW);
        getch();
        return;
    }
    int i;
    printf("Following are the tickets for mob no. %s",pmob_no);
    printf("\n\nTicket numbers\n");
    textcolor(LIGHTGREEN);
    for(i=0;i<=69;i++)
    {
       printf("-");
    }
    textcolor(LIGHTMAGENTA);
    for(i=0;*(pticket_no+i)!=-1;i++)
    printf("\n%d",*(pticket_no+i));
    textcolor(WHITE);
    //int result;
    /*extern int errno;
    printf("Result is %d",result);
    printf("\nError code is %d",errno);
    printf("Reason:%s\n",strerror(errno));
    perror("caused by");*/
    printf("\nPress any key to go back to the main screen");
    textcolor(YELLOW);
    getch();
    free(pticket_no);
}
void view_all_bookings()
{
    FILE *fp;
    int i;
    fp=fopen("e:\\My new C project learning\\allbookings.dat","rb");
    if(fp==NULL)
    {
       printf("SORRY!File cannot be opened!");
       return;
    }
    gotoxy(14,1);
    printf("Following is the allover details of the file:\n");
    textcolor(LIGHTGREEN);
    for(i=1;i<=69;i++)
    {
        printf("~");
    }
    passenger pr;
    textcolor(LIGHTMAGENTA);
    int row=3;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
       printf("\n%d\t%s\t%c\t%s",pr.ticketno,pr.train_no,pr.p_class,pr.p_name);
            gotoxy(41,row);
            printf("%c\t%d\t%s",pr.gender,pr.age,pr.mob_no);
            row++;
    }
    fclose(fp);
    return;
}
char*accept_train_no()
{
    static char train_no[10];
    int valid;
    gotoxy(55,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to quit");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("Enter a valid train no:");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%s",&train_no);
        gotoxy(1,21);
        printf("\t\t\t\t\t");
        if(strcmp(train_no,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,21);
            printf("Cancelling Input..!");
            getch();
            return NULL;
        }
    valid=check_train_no(train_no);
    if(valid==0)
    {
        gotoxy(1,21);
        textcolor(LIGHTRED);
        printf("Invalid Train no.Try Again..!");
        textcolor(YELLOW);
        gotoxy(24,1);
        printf("\t\t\t\t");
        gotoxy(24,1);
        getch();
        gotoxy(1,21);
        printf("\t\t\t\t");
        gotoxy(24,1);
    }
    }while(valid==0);
return train_no;
}
void view_booking(char*train_no)
{
    int found=0,i;
    FILE*fp;
    fp=fopen("e:\\My new C project learning\\allbookings.dat","rb");
    if(fp==NULL)
    {
        printf("File not opened..!");
    }
    textcolor(BLUE);
    printf("Ticket no\tClass\tName\t\tGender\tAge\tMobile no.\n");
    for(i=1;i<=69;i++)
    {
        textcolor(LIGHTMAGENTA);
        printf("-");
    }
    textcolor(CYAN);
    int row=3;
    passenger pr;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0)
        {
            printf("\n%d\t\t%c\t%s",pr.ticketno,pr.p_class,pr.p_name);
            gotoxy(41,row);
            printf("%c\t%d\t%s",pr.gender,pr.age,pr.mob_no);
            row++;
            found=1;
        }
    }
 if(!found)
 {
     printf("\nNo details of the ticket no. %s found",train_no);
 }
 textcolor(WHITE);
 printf("\n\n\n\nPress any key to continue....");
 textcolor(YELLOW);
 getch();
 fclose(fp);
}
int cancel_ticket(int ticket_no)
{
  int found=0;
  FILE*fp,*fq;
  fp=fopen("e:\\My new C project learning\\allbookings.dat","rb");
  if(fp==NULL)
  {
      textcolor(LIGHTRED);
      printf("\nNo bookings done yet..!");
      return -1;
  }
  fq=fopen("e:\\My new C project learning\\temp.dat","wb");
  if(fq==NULL)
  {
      printf("\nSORRY!File cannot be created..");
      return -1;
  }
    passenger pr;
  while(fread(&pr,sizeof(pr),1,fp)==1)
  {
      if(pr.ticketno==ticket_no)
      {
          found=1;
      }
      else
      {
          fwrite(&pr,sizeof(pr),1,fq);
      }

  }
fclose(fp);
fclose(fq);
if(found==0)
{
    remove("e:\\My new C project learning\\temp");
}
else
{
    remove("e:\\My new C project learning\\allbookings.dat");
    rename("e:\\My new C project learning\\temp.dat","e:\\My new C project learning\\allbookings.dat");
}
return found;
}
int cancel_train(char*train_no)
{
    int found=0;
    FILE *fp3,*fp4;
    fp3=fopen("e:\\My new C project learning\\allbookings.dat","rb");
    if(fp3==NULL)
    {
        printf("SORRY!File cannot be opened..!");
        return -1;
    }
    fp4=fopen("e:\\My new C project learning\\Freshbookings.dat","wb");
    if(fp4==NULL)
    {
        printf("SORRY!File cannot be created....!");
        return -1;
    }
    passenger pr;
    while(fread(&pr,sizeof(pr),1,fp3)==1)
    {
        if(strcmp(pr.train_no,train_no)==0)
        {
            found=1;
        }
        else
        {
            fwrite(&pr,sizeof(pr),1,fp4);
        }
    }
    fclose(fp3);
    fclose(fp4);
if(found==0)
{
    remove("e:\\My new C project learning\\Freshbookings.dat");
}
else
{
    remove("e:\\My new C project learning\\allbookings.dat");
    rename("e:\\My new C project learning\\Freshbookings.dat","e:\\My new C project learning\\allbookings.dat");
}
  return found;
  }































