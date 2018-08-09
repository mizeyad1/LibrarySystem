
#ifndef MYHEAD_H_INCLUDED
#define MYHEAD_H_INCLUDED
typedef struct
{
    int day,month,year;
}Date;
typedef struct
{
    char Title[150];
    char Author[150];
    char Publisher[150];
    char ISBN[14];
    Date date;
    int Copies;
    char Category[150];


} Book;
typedef struct
{
    char FirstName[50];
    char LastName[50];
} Name;
typedef struct
{
    int Building;
    char Street[50];
    char City [50];
}
Address;

typedef struct
{
    Name name;
    int ID;
    Address address;
    char PhoneNumber[11];
    int Age;
    char Email[150];



} Member;
typedef struct
{

    Book bookb;
    Member memberb;
    Date dateborrowed;
    Date dateduetoreturn;
    Date datereturned;


} Borrowing;
void read_book_from_file();
void read_member_from_file();
void print_menu();
void print_book_managment();
void insert_book();
void add_new_copies();
int search_function();
int search_by_isbn();
void delete_book();
void print_member_managment();
int search_member_id();
void remove_member();
void Register_member();
void print_borrow_managment();
void borrow_book();
void read_borrows_from_file();
void print_admin_actions();
void print_all_books();
void print_all_members();
void print_all_borrows();
void update_books();
void print_exit();
void ReturnBookDate();
int compare_dates (Date d1, Date d2);
void search_books_by_author();
void search_books_category();
void popular_books();
void overdue_books();
void update_file_borrow();
void update_member_file();
void Exit_with_saving();



void print_book_managment()
{
    system("cls");

    printf("Book Management:\n");
    printf("1.Insert Book\n");
    printf("2.Search for a Book \n");
    printf("3.Add new copy\n");
    printf("4.Delete Book\n");
    printf("5.Back\n");

}


void print_member_managment()
{
    system("cls");
    printf("Member Management:\n");
    printf("1.Register new member\n");
    printf("2.Remove member\n");
    printf("3.Back\n");
}
void print_borrow_managment()
{
    system("cls");
    printf("Borrow Management:\n");
    printf("1.Borrow a book\n");
    printf("2.Return a book\n");
    printf("3.Back\n");
}
void print_admin_actions()
{
    system("cls");
    printf("Administrative actions:\n");
    printf("1.Overdue books\n");
    printf("2.Popular\n");
    printf("3.Back\n");
}
void print_exit()
{
    system("cls");
    printf("Exit:\n");
    printf("1.Save and exit\n");
    printf("2.Exit without saving\n");
    printf("3.Back\n");
}

void print_menu()
{
    system("cls");
system("COLOR 0A");
    printf("1-Book Management\n");
    printf("2-Member Management\n");
    printf("3-Borrow Management\n");
    printf("4-Administrative actions\n");
    printf("5-Save changes\n");
    printf("6-Print Option\n");
    printf("7-Exit\n");
}

int compare_dates (Date d1, Date d2)
{
    if (d1.year < d2.year)
       return -1;

    else if (d1.year > d2.year)
       return 1;

    if (d1.year == d2.year)
    {
         if (d1.month<d2.month)
              return -1;
         else if (d1.month>d2.month)
              return 1;
         else if (d1.day<d2.day)
              return -1;
         else if(d1.day>d2.day)
              return 1;
         else
              return 0;
    }

}



#endif // MYHEAD_H_INCLUDED
