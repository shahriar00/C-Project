#include<stdio.h>
#include<conio.h>
#include<string.h>
void reg();
void login();
int ATM_Transaction();
int ATM_cheak(double balance);
//int ATM_back();
int anotherTransaction,amountToWithdraw,amountToDeposit,pin;
double balance = 1000;
int n,pin;
struct lo
{
    char name[100];
    char pass[50];
};
int main()
{
    //reg();
    // login();
menu:
    system("cls");
    printf("\n\n\n\n\n\t\t\t\tWELCOME TO MY PROJECT!");
    printf("\n\n\n\n\t\t\t\t\t\tPlease Press [ENTER]");
    if(getch()==13)
    {
        system("cls");
    }
    else
    {
        goto menu;
    }
menu_main:
    printf("\n\n\n\t\t\t[1] LOGIN\t\t[2] REGISTRATION\t\t[3] EXIT");
    printf("\n\n\n\t\t\t\t  INPUT YOUR SELECTION THEN PRESS [ENTER]: ");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        system("cls");
        login();
        break;
    case 2:
        system("cls");
        reg();
        break;
    case 3:
        system("cls");
        printf("\n\n\t\t\t\tTHANK YOU FOR USING THIS PROCESS\n");
    //break;
    default:
        system("cls");
        printf("\n\n\t\t\t\tNOT AVAILABLE");
        printf("\n\n\t\t\tPRESS ANY KEY TO GO BACK");
        getch();
        goto menu_main;
    }
    printf("\n\n\t\t***********Welcome to IBL bank ************\n\n");
    printf("\nEnter your pin number please: \n");
    scanf("%d",&pin);
    if(pin!=1234)
    {
        printf("Sorry your pin is wrong ,please try again with the card");
    }
    else
    {
        ATM_Transaction();
    }

    ATM_cheak(balance);
    //ATM_back( balance);
    struct lo l;
    FILE *fp;
    fp=fopen("file.txt","r");
    fscanf(fp,"%s%s",&l.name,&l.pass);
    FILE *file;
    file = fopen("cheak.txt","w");
    fprintf(file,"%s %s %f",l.name,l.pass,balance);

}
void reg()
{
    //FILE *fp;
    int num,i=1;
    //char name[30],pass[30];
    struct lo l;
    //struct registration reg;
    FILE *fp;
    fp = fopen("file.txt","w");
    printf("\n\nHow many registration you want to done!\n\n");
    scanf("%d",&num);
    while(i<=num)
    {
        printf("\nUSERNAME : ");
        scanf("%s",&l.name);

        printf("\nPASSWORD: ");
        scanf("%s",&l.pass);
        printf("\n");
        fprintf(fp,"%s %s\n",l.name,l.pass);
        i++;
    }
    system("cls");
    printf("\n\t\tRegistration successfully...");
    printf("\n\nThanks For Registration and stay with us happily!\n\n");
    printf("\nWhen your registration completed please pin input and exit this process!\n\n");
    // login();
}

void login()
{
    struct lo l;
    int i;
    char nam[100],pas[50];
    int cekun,cekpw;
    FILE *fp;
    fp=fopen("file.txt","r");
    printf("\n\n\tPlease enter your user name and password correctly.\n\n");
    printf("\n\n\t\tUSERNAME:");
    scanf("%s",&nam);
    printf("\n\t\tPASSWORD:");
    scanf("%s",&pas);
    fscanf(fp,"%s%s",&l.name,&l.pass);
    cekun = strcmp(nam,l.name);
    cekpw = strcmp(pas,l.pass);
    if(cekun==0 && cekpw==0)
    {
        printf("\n\n\tLOGIN SUCESSFULLY\n\n");
        //ATM_Transaction();
        //break;

    }
    else
    {
        printf("\n\n\tYOU ARE NOT REGISTRATION");
        reg();
    }
//system("cls");
}
int ATM_Transaction( )
{

    int choice;
    printf("Enter any option to be served!\n");
    printf("1.Balance Enquiry\n");
    printf("2.Cash withdraw\n");
    printf("3.Deposit cash\n");
    printf("4.Exit\n");
    scanf("%d",&choice);
    FILE *file;
    //double balance;
    file = fopen("cheak.txt","r");
    fscanf(file,"%lf",&balance);
    switch(choice)
    {
    case 1:
        printf("Your bank balance is : %lf",balance);
        printf("\n\nDo you want to perform another transaction?\nPress 1 to proceed and 2 exit.\n\n");
        scanf("%d",&anotherTransaction);
        if(anotherTransaction==1)
        {
            ATM_Transaction();
        }
        break;
    case 2:
        printf("Please enter amountToWithdraw: ");
        scanf("%d",&amountToWithdraw);
        if(amountToWithdraw<=balance)
        {
            printf("Please collect your cash\n");
            balance=balance-amountToWithdraw;
            printf("Your available balance is: %f\n",balance);
            printf("\n\nDo you want to perform another transaction?\nPress 1 to proceed and 2 exit.\n\n");
            scanf("%d",&anotherTransaction);
            if(anotherTransaction==1)
            {
                ATM_Transaction();
            }
        }
        else
        {
            printf("Sorry insufficient in your account\n");
            printf("\n\nDo you want to perform another transaction?\nPress 1 to proceed and 2 exit.\n\n");
            scanf("%d",&anotherTransaction);
            if(anotherTransaction==1)
            {
                ATM_Transaction();
            }
        }
        break;
    case 3:
        printf("Please enter amount to deposit \n");
        scanf("%d",&amountToDeposit);
        balance=amountToDeposit+balance;
        printf("Thank you for depositing,Your new balance is = %f",balance);
        printf("\n\nDo you want to perform another transaction?\nPress 1 to proceed and 2 exit.\n\n");
        scanf("%d",&anotherTransaction);
        if(anotherTransaction==1)
        {
            ATM_Transaction();
        }
        break;
    default:
        printf("Thanks for using ATM service ,see you soon!\n");
    }
    return balance;
}
//return balance;

int ATM_cheak(double balance)
{
    FILE *file;
    //double balance;
    file = fopen("cheak.txt","w");
    if(file == NULL)
    {
        printf("File does not open!");
    }
    else
    {
        fprintf(file,"%f",balance);
        //printf("Total Balance:%f\n",balance);
    }
}

