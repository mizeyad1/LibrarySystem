#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#include "myhead.h"



char c,c1,c2;
FILE* pBook;
FILE* pMembers;
FILE* pBorrowing;
Book books[100];
int nbooks=0;
Member members[100];
int nmembers=0;
Borrowing borrowings[100];
int nborrowings=0;
int ww=1;






int main()
{


    read_book_from_file();
    read_member_from_file();
    read_borrows_from_file();


    while(1)
    {
        int result_search;
        print_menu();
        c=getchar();
        switch (c)
        {
        case '1':
            print_book_managment();
            getchar();
            scanf("%c",&c1);
            switch(c1)
            {
            case '1':
                insert_book();
                break;
            case '2':
                system("cls");
                printf("Enter Type of Search You Want:\n");
                printf("1.Search By Name\n");
                printf("2.Search by ISBN\n");
                printf("3.Search by Category\n");
                printf("4.Search by Author");
                getchar();
                scanf("%c",&c2);
                switch(c2)
                {
                case '1':
                    result_search=search_function();

                    if (result_search>-1)
                        printf("Found at location %d",result_search);

                        getchar();
                        getchar();

                    break;
                case '2':
                    result_search=search_by_isbn();
                    if (result_search>-1){
                        printf("Found at location %d",result_search);
                        getchar();
                        getchar();
                    }
                    else{
                        printf("Not Found");
                        getchar();
                        getchar();
                    }
                    break;
                case '3':
                    search_books_category();
                    break;
                case '4':

                    search_books_by_author();
                    break;
                }


                break;
            case '3':
                add_new_copies();
                break;
            case '4':
                delete_book();
                break;

            }

            break;


        case '2':
            print_member_managment();
            getchar();
            scanf("%c",&c1);
            switch(c1)
            {
            case '1':
                Register_member();
                break;
            case '2':
                remove_member();
                break;
            }
            break;

        case '3':

            print_borrow_managment();
            getchar();
            scanf("%c",&c1);
            switch(c1)
            {
            case '1':
                borrow_book();
                break;
            case '2':
                ReturnBookDate();
                update_file_borrow();
                break;
            }
            break;

        case '4':

            print_admin_actions();
            getchar();
            scanf("%c",&c1);
            switch(c1)
            {
            case '1':
                overdue_books();
                break;
            case '2':
                popular_books();
                break;
            }
            break;

        case '5':

            system("cls");
            update_books();
            update_member_file();
            update_file_borrow();

            break;
        case '6':
            system("cls");
            printf("1.Show All Members\n");
            printf("2.Show All Books\n");
            printf("3.Show All Borrows\n");
            printf("4.Back\n");
            getchar();
            scanf("%c",&c1);
            switch(c1)
            {
            case '1':
                print_all_members();
                break;
            case '2':
                print_all_books();
                break;
            case '3':
                print_all_borrows();

            }
            break;

        case '7':

            print_exit();
            getchar();
            scanf("%c",&c1);
            switch(c1)
            {
            case '1':
                Exit_with_saving();
                exit(0);
                break;
            case '2':
                exit(0);
                break;
            }
            break;

        default:
            printf("Please choose an action from the main menu\n");


        }
    }





    return 0;

}
void insert_book()
{

    system("cls");
    Book b;
    int i;
    pBook=fopen("Books.txt","a");
    getchar();
    printf("Enter Book Title:\n");
    scanf("%[^\n]s",b.Title);
    getchar();
    printf("Enter Book Author:");
    scanf("%[^\n]s",b.Author);
    getchar();
    printf("Enter Book Publisher:");
    scanf("%[^\n]s",b.Publisher);
    getchar();
    printf("Enter Book ISBN:");
    scanf("%s",b.ISBN);
    for(i=0; i<nbooks; i++)
    {
        if(strcmp(b.ISBN,books[i].ISBN)==0)
        {
            printf("This ISBN is already taken\n");
            printf("Enter another one\n");
            scanf("%s",b.ISBN);
        }
    }
    printf("Enter day of Publication:\n");
    scanf("%d",&b.date.day);
    printf("Enter month of Publication:\n");
    scanf("%d",&b.date.month);
    printf("Enter Year of Publication:\n");
    scanf("%d",&b.date.year);
    printf("Enter the available number of Copies:\n");
    scanf("%d",&b.Copies);
    printf("Please Enter Category of new book:\n");
    scanf("%s",b.Category);
    getchar();
    books[nbooks]=b;
    nbooks++;
}
void Register_member()
{
    system("cls");
    int i;
    Member member;
    pMembers=fopen("Members.txt","a");
    printf("Enter your first name:\n");
    scanf("%s",member.name.FirstName);
    printf("Enter Your last name:\n");
    scanf("%s",member.name.LastName);
    printf("Enter Member ID:\n");
    scanf("%d",&member.ID);
    for(i=0; i<nmembers; i++)
    {
        if(member.ID==members[i].ID)
        {
            printf("This ID is already taken\n");
            printf("Enter another one\n");
            scanf("%d",&member.ID);
        }
    }
    printf("For your address information:\n");
    printf("Enter Your Building Number:\n");
    scanf("%d",&member.address.Building);
    printf("Enter your street name:\n");
    scanf("%s",member.address.Street);
    printf("Enter your city:\n");
    scanf("%s",member.address.City);
    printf("Enter your Phone Number:\n");
    scanf("%s",member.PhoneNumber);
    printf("Enter Your age:\n");
    scanf("%d",&member.Age);
    printf("Enter your e-mail account:\n");
    scanf("%s",member.Email);
    printf("Thanks for joining our Library!\n");

    members[nmembers]=member;


    nmembers++;

}
int search_function()
{

    system("cls");
int i;
int flag=1;

    char book_name[100];
    getchar();
    printf("Enter the Book Name\n");
    scanf("%[^\n]",book_name);
        for (i=0; i<100; i++)
    {
        if (strcmpi(book_name,books[i].Title)==0)
            return i;
    }
for (i=0;i<nbooks;i++)
{
    if (strstr(books[i].Title,book_name))
    {
        printf("%s\n",books[i].Title);
        flag=0;
    }
}
if (flag)
{
    printf("Not Found ");
}
getchar();

    return -1;
}
int search_by_isbn()
{
    system("cls");
    char isbn_number[100];
    printf("Enter the Book ISBN: ");
    scanf("%s",isbn_number);
    strlwr(isbn_number);
    int i;
    for (i=0; i<100; i++)
    {
        if (strcmp(isbn_number,strlwr(books[i].ISBN))==0)
            return i;
    }

    return -1;
}
void add_new_copies()
{
    system("cls");
    int copies,result;
    result=search_by_isbn();
    do
    {
        printf("Enter the correct number of copies\n");
        scanf("%d",&copies);
    }
    while(copies<0);

    books[result].Copies+=copies;

}
void delete_book()
{
    int i,result;
    result=search_by_isbn();
    if (result>=0)
    {


    for (i=result; i<nbooks-1; i++)
    {
        books[i]=books[i+1];
    }
    nbooks--;
    }
    else
    {

        delete_book();
    }

}
void read_book_from_file()
{

    pBook=fopen("Books.txt","r");
    while (fscanf(pBook,"%[^,],%[^,],",books[nbooks].Title,books[nbooks].Author)>0)
    {



        fscanf(pBook,"%[^,],",books[nbooks].Publisher);

        fscanf(pBook,"%[^,],",books[nbooks].ISBN);

        fscanf(pBook,"%d",&books[nbooks].date.day);
        getc(pBook);
        fscanf(pBook,"%d",&books[nbooks].date.month);
        getc(pBook);
        fscanf(pBook,"%d",&books[nbooks].date.year);
        fgetc(pBook);
        fscanf(pBook,"%d",&books[nbooks].Copies);
        fgetc(pBook);
        fscanf(pBook,"%s",books[nbooks].Category);
        fscanf(pBook,"\n");
        nbooks++;
    }
    fclose(pBook);


}
void read_member_from_file()
{

    pMembers=fopen("Members.txt","r");
    while (fscanf(pMembers,"%[^,],%[^,],",members[nmembers].name.FirstName,members[nmembers].name.LastName)>0)
    {


        fscanf(pMembers,"%d",&members[nmembers].ID);
        fgetc(pMembers);
        fscanf(pMembers,"%d",&members[nmembers].address.Building);
        fgetc(pMembers);
        fscanf(pMembers,"%[^,],",members[nmembers].address.Street);

        fscanf(pMembers,"%[^,],",members[nmembers].address.City);
        fscanf(pMembers,"%[^,],",members[nmembers].PhoneNumber);


        fscanf(pMembers,"%d",&members[nmembers].Age);
        fgetc(pMembers);
        fscanf(pMembers,"%s",members[nmembers].Email);
        fscanf(pMembers,"\n");
        nmembers++;
    }
    fclose(pMembers);
}
int search_member_id()
{
    system("cls");
    int id_number,i;
    printf("Please Enter User ID:");
    scanf("%d",&id_number);
    for (i=0; i<100; i++)
    {
        if (members[i].ID==id_number)
            return i;
    }

    return -1;


}
void remove_member()
{
    int i,result;
    int flag=1;
    char l;
    result=search_member_id();
    if (result<0)
    {
        printf("Member does not exist");
        return;
    }
    for (i=0; i<nborrowings; i++)
    {

        if(members[result].ID==borrowings[i].memberb.ID)
        {

            if (borrowings[i].datereturned.day==0)
            {
                printf("This Member has not returned a book so cannot be removed\n");
                scanf("%c",&l);
                scanf("%c",&l);
                flag=0;
            }
        }

    }
    if (flag)
    {
        for (i=result; i<nmembers-1; i++)
        {
            members[i]=members[i+1];
        }
        nmembers--;
    }




}
void print_all_members()
{
    system("cls");
    int i,c;
    for (i=0; i<nmembers; i++)
    {
        printf("%s,%s,%d,%d,",members[i].name.FirstName,members[i].name.LastName,members[i].ID,members[i].address.Building);
        printf("%s,%s,%s,",members[i].address.Street,members[i].address.City,members[i].PhoneNumber);
        printf("%d,%s\n",members[i].Age,members[i].Email);
    }
    scanf("\n%d",&c);

}
void print_all_books()
{
    system("cls");
    int i,c;
    for (i=0; i<nbooks; i++)
        printf("%s,%s,%s,%s,%d/%d/%d,%d,%s\n",books[i].Title,books[i].Author,books[i].Publisher,books[i].ISBN,books[i].date.day,books[i].date.month,books[i].date.year,books[i].Copies,books[i].Category);
    scanf("\n%d",&c);
}
void borrow_book()
{
    system("cls");
    int i;
    char k;
    int countmemberborrows=0;
    int res_isbn=search_by_isbn();
    if (res_isbn==-1){

        printf("This Book Does not Exist\n");
    getchar();
    getchar();
        return;
    }
    int res_id=search_member_id();
    if (res_id==-1){
        printf("This is not a member in Library\n");
        getchar();
        getchar();
    return;
    }

    for (i=0; i<nborrowings; i++)
    {
        if (members[res_id].ID==borrowings[i].memberb.ID)
            countmemberborrows++;
    }

    if (countmemberborrows>=3)
    {
        printf("Member cannot borrow more than 3 books");
        scanf("%c",&k);
        scanf("%c",&k);
    }
    else
    {
        pBorrowing=fopen("Borrowings.txt","a");
        SYSTEMTIME st;
        GetLocalTime(&st);


        borrowings[nborrowings].dateborrowed.year=st.wYear;
        borrowings[nborrowings].dateborrowed.month=st.wMonth;
        borrowings[nborrowings].dateborrowed.day=st.wDay;

        borrowings[nborrowings].datereturned.day=0;
        borrowings[nborrowings].datereturned.month=0;
        borrowings[nborrowings].datereturned.year=0;


        books[res_isbn].Copies--;

        printf("Enter Date Due to Return:");
        scanf("%d%d%d",&borrowings[nborrowings].dateduetoreturn.day,&borrowings[nborrowings].dateduetoreturn.month,&borrowings[nborrowings].dateduetoreturn.year);
        strcpy(borrowings[nborrowings].bookb.ISBN,books[res_isbn].ISBN);
        borrowings[nborrowings].memberb.ID=members[res_id].ID;

        nborrowings++;



    }

}
void read_borrows_from_file()
{
    pBorrowing=fopen("Borrowings.txt","r");
    while(fscanf(pBorrowing,"%[^,],",borrowings[nborrowings].bookb.ISBN)>0)
    {


        fscanf(pBorrowing,"%d",&borrowings[nborrowings].memberb.ID);
        fgetc(pBorrowing);
        fscanf(pBorrowing,"%d",&borrowings[nborrowings].dateborrowed.day);
        fgetc(pBorrowing);
        fscanf(pBorrowing,"%d",&borrowings[nborrowings].dateborrowed.month);
        getc(pBorrowing);
        fscanf(pBorrowing,"%d",&borrowings[nborrowings].dateborrowed.year);
        fgetc(pBook);
        fscanf(pBorrowing,"%d",&borrowings[nborrowings].dateduetoreturn.day);
        getc(pBorrowing);
        fscanf(pBorrowing,"%d",&borrowings[nborrowings].dateduetoreturn.month);
        getc(pBorrowing);
        fscanf(pBorrowing,"%d",&borrowings[nborrowings].dateduetoreturn.year);
        getc(pBorrowing);
        fscanf(pBorrowing,"%d",&borrowings[nborrowings].datereturned.day);
        getc(pBorrowing);
        fscanf(pBorrowing,"%d",&borrowings[nborrowings].datereturned.month);
        getc(pBorrowing);
        fscanf(pBorrowing,"%d",&borrowings[nborrowings].datereturned.year);

        fscanf(pBorrowing,"\n");
        nborrowings++;

    }
    fclose(pBorrowing);
}
void print_all_borrows()
{
    system("cls");
    int i,c;
    for (i=0; i<nborrowings; i++)
    {
        printf("%s,",borrowings[i].bookb.ISBN);
        printf("%d,",borrowings[i].memberb.ID);
        printf("%d/%d/%d,",borrowings[i].dateborrowed.day,borrowings[i].dateborrowed.month,borrowings[i].dateborrowed.year);
        printf("%d/%d/%d,",borrowings[i].dateduetoreturn.day,borrowings[i].dateduetoreturn.month,borrowings[i].dateduetoreturn.year);
        printf("%d/%d/%d",borrowings[i].datereturned.day,borrowings[i].datereturned.month,borrowings[i].datereturned.year);
        printf("\n");

    }
    scanf("\n%d",&c);
}
void update_books()
{
    int i;
    pBook=fopen("Books.txt","w");
    for (i=0; i<nbooks; i++)
    {
        fprintf(pBook,"%s,%s,%s,%s,%d/%d/%d,%d,%s",books[i].Title,books[i].Author,books[i].Publisher,books[i].ISBN,books[i].date.day,books[i].date.month,books[i].date.year,books[i].Copies,books[i].Category);
        fprintf(pBook,"\n");
    }
    fclose(pBook);
}
int searchID_ISBN_Borrowing()
{
    system("cls");
    int i,ID;
    char isbn[14];

    printf("Enter the member ID\n");
    scanf("%d",&ID);
    printf("Enter the book ISBN\n");
    scanf("%s",isbn);
    strlwr(isbn);
    for(i=0; i<100; i++)
    {
        if(strcmp(isbn,strlwr(books[i].ISBN))==0)
            books[i].Copies++;

    }

    for(i=0; i<nborrowings; i++)
    {
        if(ID==borrowings[i].memberb.ID)
        {

            if(strcmp(strlwr(isbn),strlwr(borrowings[i].bookb.ISBN))==0)

            {

                return i;
            }
        }

    }

    return -1;
}
void ReturnBookDate()
{
    system("cls");
    int result;
    char c;
    result=searchID_ISBN_Borrowing();
    if(result==-1)
    {
        printf("This member does not borrow this book\n");
        scanf("%c",&c);
    }
    else
    {

        printf("Enter Date of Return Book");
        scanf("%d%d%d",&borrowings[result].datereturned.day,&borrowings[result].datereturned.month,&borrowings[result].datereturned.year);

    }


}

void update_file_borrow()

{

    pBorrowing=fopen("Borrowings.txt","w");
    int i;
    for (i=0; i<nborrowings; i++)
    {
        fprintf(pBorrowing,"%s,",borrowings[i].bookb.ISBN);
        fprintf(pBorrowing,"%d,",borrowings[i].memberb.ID);
        fprintf(pBorrowing,"%d/%d/%d,",borrowings[i].dateborrowed.day,borrowings[i].dateborrowed.month,borrowings[i].dateborrowed.year);
        fprintf(pBorrowing,"%d/%d/%d,",borrowings[i].dateduetoreturn.day,borrowings[i].dateduetoreturn.month,borrowings[i].dateduetoreturn.year);
        fprintf(pBorrowing,"%d/%d/%d",borrowings[i].datereturned.day,borrowings[i].datereturned.month,borrowings[i].datereturned.year);
        fprintf(pBorrowing,"\n");

    }
    fclose(pBorrowing);
}
void overdue_books()
{
    char k;
    int i,j,x;
    system("cls");
    SYSTEMTIME st;
    GetLocalTime(&st);
    Date datesystem;
    datesystem.day=st.wDay;
    datesystem.month=st.wMonth;
    datesystem.year=st.wYear;

    for (i=0; i<nborrowings; i++)
    {
        x=compare_dates(datesystem,borrowings[i].dateduetoreturn);
        if (x==1)
        {
            for (j=0; j<nbooks; j++)
            {
                if(strcmp(strlwr(borrowings[i].bookb.ISBN),strlwr(books[j].ISBN))==0)



                    printf("Book Name:%s\tBook ISBN:%s\n",books[j].Title,borrowings[i].bookb.ISBN);

            }
        }

    }
    scanf("%c",&k);
    scanf("%c",&k);
}
void popular_books()
{
    system("cls");
    int i,j,k=0;
    char q;
    int l;
    char temp1[50];
    int temp;

    char name[100][50];
    int occurence[100]= {0};
    for (i=0; i<nbooks; i++)
    {
        for(j=0; j<nborrowings; j++)
        {
            if(strcmp(strlwr(books[i].ISBN),strlwr(borrowings[j].bookb.ISBN))==0)
            {
                k++;
                strcpy(name[i],borrowings[j].bookb.ISBN);
                occurence[i]++;

            }

        }


    }


    for(i=0; i<k; i++)
    {
        for (j=i+1; j<k; j++)
        {
            if (occurence[i]<occurence[j])
            {
                temp=occurence[i];
                occurence[i]=occurence[j];
                occurence[j]=temp;
                strcpy(temp1,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],temp1);

            }
        }


    }

    for(l=0; l<5; l++)

    {
        if (occurence[l]!=0)
            for(i=0; i<nbooks; i++)
            {
                if(strcmp(strlwr(name[l]),strlwr(books[i].ISBN))==0)
                {
                    strcpy(name[l],books[i].Title);
                }
            }

        printf("Title=%s\nOcc=%d\n",name[l],occurence[l]);
    }
    scanf("%c",&q);
    scanf("%c",&q);


}

void search_books_category()
{
    system("cls");
    int i;
    char c;
    char category[150];
    printf("Please Enter Category You want to Search For:\n");
    scanf("%s",category);

    for (i=0; i<nbooks; i++)
    {
        if (strcmp(strlwr(category),strlwr(books[i].Category))==0)
            printf("%s\n",books[i].Title);
    }
    scanf("%c",&c);
    scanf("%c",&c);

}
void search_books_by_author()
{
    system("cls");
    int i;
    char c;
    char author[50];
    printf("Please Enter Author Name:\n");
    scanf("%s",author);
    for (i=0; i<nbooks; i++)
    {
        if (strcmp(strlwr(author),strlwr(books[i].Author))==0)
            printf("%s\n",books[i].Title);
    }
    scanf("%c",&c);
    scanf("%c",&c);
}
void Exit_with_saving()
{

    update_books();
    update_member_file();
    update_file_borrow();

}
void update_member_file()
{
    int i;
    pMembers=fopen("Members.txt","w");
    for (i=0; i<nmembers; i++)
    {
        fprintf(pMembers,"%s,%s,%d,%d,",members[i].name.FirstName,members[i].name.LastName,members[i].ID,members[i].address.Building);
        fprintf(pMembers,"%s,%s,%s,",members[i].address.Street,members[i].address.City,members[i].PhoneNumber);
        fprintf(pMembers,"%d,%s\n",members[i].Age,members[i].Email);

    }
    fclose(pMembers);
}
