#ifndef RLYES_H_INCLUDED
#define RLYES_H_INCLUDED
struct train
{
    char train_no[10];
    char from[10];
    char to[10];
    int fac_fare;
    int sac_fare;
};
struct passenger
{
    char p_name[20];
    char gender;
    char train_no[10];
    char p_class;
    char address[30];
    int age;
    int ticketno;
    char mob_no[11];
};
typedef struct train train;
typedef struct passenger passenger;

int enterchoice();
void add_trains();
void view_trains();
int bookticket(passenger);
void view_all_bookings();
int cancel_ticket(int);
int cancel_train(char*);
int check_train_no(char*);
passenger*get_passenger_details();
int get_booked_ticket_count(char*,char);
int last_ticket_no();
int check_mob_no(char*);
int book_ticket(passenger);
int accept_ticket_no();
void view_ticket(int ticket_no);
char*accept_mob_no();
void view_all_tickets();
int* get_ticket_no(char*);
char*accept_train_no();
void view_booking(char*);






#endif // RLYES_H_INCLUDED
