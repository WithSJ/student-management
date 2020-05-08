#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "conio.h"


#define ReadFile fscanf(file,"%d\t%s\t%d\t%s\t%s\t%ld\t%s\t%d\n",&student.srno,student.name,&student.age,student.cls,student.email,&student.phone,student.city,&student.fee_deposited)
typedef struct{
    int srno;
    char name[30];
    int age;
    char cls[10];
    char email[50];
    long int phone;
    char city[15];
    int fee_deposited;

}Data;

int TotalFee=45000;

void CollegeLogo();
void Admission();
void View_Students();
void Fee();
void DataModify();
int Admission_Number();
void Change_BackColor(int x,int y,int x2,int y2);
void Table_Info();
void Class_Students(char *class_);
void All_Students();
void FeeDeposite();
void FeeDueList();
int main()
{   char ch;
    int x=55,y=10;
    clrscr();
    
    Change_BackColor(x,y,40,13);
    CollegeLogo();
    gotoxy(x+10,y+2);
    printf("|1| Admission ");
    gotoxy(x+10,y+4);
    printf("|2| View Students ");
    gotoxy(x+10,y+6);
    printf("|3| Fee  ");
    gotoxy(x+10,y+8);
    printf("|4| Data Modify  ");
    gotoxy(x+10,y+10);
    printf("|5| Exit  ");
    ch=getch();
    switch (ch)
    {
        case '1':   Admission();
                    break;
        case '2':   View_Students();
                    break;
        case '3':   Fee();
                    break;
        
        case '4':   DataModify();
                    break;
        
        case '5':   clrscr();
                    exit(0);
                    break;

        default:    clrscr();
                    main();
                    break;
    }

 
    return 0;
}

void Admission()
{
    clrscr();
    Data student;
    FILE *file;
    
    file=fopen("studentR.txt","a+");

    student.srno=Admission_Number();
    int x=55,y=10;
    CollegeLogo();
    Change_BackColor(x,y,40,20);
    gotoxy(x+10,y+2);
    printf("Admission number : %d ",student.srno);
    gotoxy(x+10,y+3);
    printf("Full Name : ");
    scanf(" %s",student.name);
    gotoxy(x+10,y+4);
    printf("Age : ");
    scanf("%d",&student.age);
    gotoxy(x+10,y+5);
    printf("Class : ");
    scanf("%s",student.cls);
    gotoxy(x+10,y+6);
    printf("E-mail : " );
    scanf("%s",student.email);
    gotoxy(x+10,y+7);
    printf("Phone no : ");
    scanf("%ld",&student.phone);
    gotoxy(x+10,y+8);
    printf("City : ");
    scanf("%s",student.city);
    
    gotoxy(x+10,y+10);
    printf("Data Saved... Press any key... ");
    student.fee_deposited=0;
    getch();
    
    fprintf(file,"%d\t%s\t%d\t%s\t%s\t%ld\t%s\t%d\n",student.srno,student.name,student.age,student.cls,student.email,student.phone,student.city,student.fee_deposited);
    fclose(file); 
    main();   
    
}

int Admission_Number()
{
    int index=1; 
    Data student;
    FILE *file;
    file=fopen("studentR.txt","r");
    while (ReadFile !=EOF)
    {index++;}
    fclose(file);        
    return index;
}

void View_Students()
{   clrscr();
    char ch,ca;
    
    int x=55,y=10;
    CollegeLogo();
    Change_BackColor(x,y,40,17);
    
    textbackground(0);
    textcolor(4);
 
    gotoxy(x+10,y+=2);
    printf("|1| BCA ");   
    gotoxy(x+10,y+=2);
    printf("|2| BBA ");
    gotoxy(x+10,y+=2);
    printf("|3| Graphics ");
    gotoxy(x+10,y+=2);
    printf("|4| Fashion ");
    gotoxy(x+10,y+=2);
    printf("|5| Interior ");
    gotoxy(x+10,y+=2);
    printf("|6| All Students ");
    
    gotoxy(x+10,y+=2);
    printf("|7| Menu ");
    
    ch=getch();
    clrscr();
    
    switch (ch)
    {
        case '1':   Class_Students("BCA");
                    printf("\n\n\tPress any key...");
                    getchar();
                    View_Students();
                    break;

        case '2':   Class_Students("BBA");
                    printf("\n\n\tPress any key...");
                    getch();
                    View_Students();
                    break;

        case '3':   Class_Students("Graphics");
                    printf("\n\n\tPress any key...");
                    getch();     
                    View_Students();
                    break;

        case '4':   Class_Students("Fashion");
                    printf("\n\n\tPress any key...");
                    getch();     
                    View_Students();
                    break;
        case '5':   Class_Students("Interior");
                    printf("\n\n\tPress any key...");
                    getch();     
                    View_Students();
                    break;
        
        case '6':   All_Students();
                    printf("\n\n\tPress any key...");
                    getch();
                    View_Students();
                    break;
        
        case '7':   clrscr();
                    main();
                    break;
        
        default:    clrscr();
                    View_Students();
                    break;
    }
}


void Table_Info()
{
    int tab=5,line=1;

    gotoxy(tab,line);tab+=4;
    printf("| Sr ");
    gotoxy(tab,line);tab+=20;
    printf("| Name ");
    gotoxy(tab,line);tab+=5;
    printf("| Age ");
    gotoxy(tab,line);tab+=8;
    printf("| Class ");
    gotoxy(tab,line);tab+=25;
    printf("| E-mail ");
    gotoxy(tab,line);tab+=13;
    printf("| Phone ");
    gotoxy(tab,line);tab+=15;
    printf("| City ");
    gotoxy(tab,line);tab+=10;
    printf("| Fee ");
    gotoxy(tab,line);
    printf("|");
}

void Class_Students(char *class_)
{
    int line=2;
    int tab=5;
    Data student;
    FILE *file;
    file=fopen("studentR.txt","r");
    Table_Info();
    while (ReadFile !=EOF)
    {   if(!strcmp(student.cls,class_))
            { 
                gotoxy(tab,line);tab+=4;
                printf("| %d ",student.srno);
                gotoxy(tab,line);tab+=20;
                printf("| %s ",student.name);
                gotoxy(tab,line);tab+=5;
                printf("| %d ",student.age);
                gotoxy(tab,line);tab+=8;
                printf("| %s ",student.cls);
                gotoxy(tab,line);tab+=25;
                printf("| %s ",student.email);
                gotoxy(tab,line);tab+=13;
                printf("| %ld ",student.phone);
                gotoxy(tab,line);tab+=15;
                printf("| %s ",student.city);
                gotoxy(tab,line);tab+=10;
                printf("| %d ",student.fee_deposited);
                gotoxy(tab,line);
                printf("|");
                tab=5;
                line+=1;

            }
    }

    tab=5;
    line=2;
    fclose(file); 
}

void All_Students()
{
    int line=2;
    int tab=5;
    Data student;
    FILE *file;
    file=fopen("studentR.txt","r");
    Table_Info();
    while (ReadFile !=EOF)
    {           
        
        gotoxy(tab,line);tab+=4;
        printf("| %d ",student.srno);
        gotoxy(tab,line);tab+=20;
        printf("| %s ",student.name);
        gotoxy(tab,line);tab+=5;
        printf("| %d ",student.age);
        gotoxy(tab,line);tab+=8;
        printf("| %s ",student.cls);
        gotoxy(tab,line);tab+=25;
        printf("| %s ",student.email);
        gotoxy(tab,line);tab+=13;
        printf("| %ld ",student.phone);
        gotoxy(tab,line);tab+=15;
        printf("| %s ",student.city);
        gotoxy(tab,line);tab+=10;
        printf("| %d ",student.fee_deposited);
        gotoxy(tab,line);
        printf("|");
        tab=5;
        line+=1;
    }
            
    tab=5;
    line=2;
    fclose(file);
}

void Fee()
{
    clrscr();
    char ch,ca;
    
    int x=55,y=10;
    CollegeLogo();
    Change_BackColor(x,y,40,9);

    textbackground(0);
    textcolor(4);

    gotoxy(x+10,y+=2);
    printf("|1| Fee Deposite ");   
    gotoxy(x+10,y+=2);
    printf("|2| Due Fee List");
    gotoxy(x+10,y+=2);
    printf("|3| Menu ");
    
    ch=getch();
    clrscr();
    
    switch (ch)
    {
        case '1':   FeeDeposite();
                    break;

        case '2':   FeeDueList();
                    printf("\n\n\tPress any key...");
                    getch();
                    Fee();
                    break;

        case '3':   clrscr();
                    main();
                    break;
        default:    clrscr();
                    Fee();
                    break;
    }

}

void FeeDeposite()
{   int sr,amount;
    clrscr();
    char ch,ca;
    Data student;
    FILE *file;
    FILE *temp;
    file=fopen("studentR.txt","r");
    temp=fopen("temp.txt","a+");
    
    int x=55,y=10;
    CollegeLogo();
    Change_BackColor(x,y,40,9);
    
    textbackground(0);
    textcolor(4);

    gotoxy(x+5,y+=2);
    printf("Enter Student Sr no :");
    scanf("%d",&sr);   
    
    while (ReadFile !=EOF)
    {   
        if(sr==student.srno)
        {   gotoxy(x+5,y+=2);
            printf("Enter Amount :");
            scanf("%d",&amount);
            student.fee_deposited += amount;
            fprintf(temp,"%d\t%s\t%d\t%s\t%s\t%ld\t%s\t%d\n",student.srno,student.name,student.age,student.cls,student.email,student.phone,student.city,student.fee_deposited);
        }
        else
        {fprintf(temp,"%d\t%s\t%d\t%s\t%s\t%ld\t%s\t%d\n",student.srno,student.name,student.age,student.cls,student.email,student.phone,student.city,student.fee_deposited);}
    }  

    fclose(file);
    fclose(temp);
    remove("studentR.txt");
    rename("temp.txt","studentR.txt");         
    main();
}

void FeeDueList()
{   clrscr();
    int line=2;
    int tab=5;
    Data student;
    FILE *file;
    file=fopen("studentR.txt","r");
    Table_Info();
    gotoxy(105,1);
    printf("| Due ");
    gotoxy(115,1);
    printf("|");
    while (ReadFile !=EOF)
    {   if(student.fee_deposited<TotalFee)
        {      
            
            gotoxy(tab,line);tab+=4;
            printf("| %d ",student.srno);
            gotoxy(tab,line);tab+=20;
            printf("| %s ",student.name);
            gotoxy(tab,line);tab+=5;
            printf("| %d ",student.age);
            gotoxy(tab,line);tab+=8;
            printf("| %s ",student.cls);
            gotoxy(tab,line);tab+=25;
            printf("| %s ",student.email);
            gotoxy(tab,line);tab+=13;
            printf("| %ld ",student.phone);
            gotoxy(tab,line);tab+=15;
            printf("| %s ",student.city);
            gotoxy(tab,line);tab+=10;
            printf("| %d ",student.fee_deposited);
            gotoxy(tab,line);tab+=10;
            printf("| %d ",TotalFee - student.fee_deposited);
            gotoxy(tab,line);
            printf("|");
            tab=5;
            line+=1;
        }
    }
            
    tab=5;
    line=2;
    fclose(file);
    
}

void DataModify()
{   int found=0;
    int sr;
    clrscr();
    int ch;
    Data student;
    FILE *file;
    FILE *temp;
    file=fopen("studentR.txt","r");
    temp=fopen("temp.txt","a+");
    
    int x=55,y=10;
    CollegeLogo();
    Change_BackColor(x,y,40,9);
    
    textbackground(0);
    textcolor(4);

    gotoxy(x+5,y+=4);
    printf("Enter Student Sr no : ");
    scanf("%d",&sr);   
    x=55,y=10;
    CollegeLogo();
    Change_BackColor(x,y,55,21);

    textbackground(0);
    textcolor(4);
    while (ReadFile !=EOF)
    {   
        if(sr==student.srno)
        { sr=-1;
            gotoxy(x+5,y+=2);
            printf("|1| Change Name [%s]",student.name);
            gotoxy(x+5,y+=2);
            printf("|2| Change Age [%d]",student.age);
            gotoxy(x+5,y+=2);
            printf("|3| Change Class [%s]",student.cls);
            gotoxy(x+5,y+=2);
            printf("|4| Change E-mail [%s]",student.email);
            gotoxy(x+5,y+=2);
            printf("|5| Change Phone [%ld]",student.phone);
            gotoxy(x+5,y+=2);
            printf("|6| Change City [%s]",student.city);
            gotoxy(x+5,y+=2);
            printf("|7| Menu");
            gotoxy(x+5,y+=2);
            printf("Enter : ");
            scanf("%d",&ch);
            gotoxy(x+5,y+=2);
            switch (ch)
            {
                case 1:     printf("Change Name : ");
                            scanf("%s",student.name);
                            break;
                            
                case 2:     printf("Change Age : ");
                            scanf("%d",&student.age);
                            break;

                case 3:     printf("Change Class : ");
                            scanf("%s",student.cls);
                            break;

                case 4:     printf("Change E-mail : ");
                            scanf("%s",student.email);
                            break;
                case 5:     printf("Change Phone : ");
                            scanf("%ld",&student.phone);
                            break;
                case 6:     printf("Change City : ");
                            scanf("%s",student.city);
                            break;        
                
                case 7:   main();
                          break;

                default:    DataModify();
                            break; 
       
                

            }
            fprintf(temp,"%d\t%s\t%d\t%s\t%s\t%ld\t%s\t%d\n",student.srno,student.name,student.age,student.cls,student.email,student.phone,student.city,student.fee_deposited);
        }
        else
        {fprintf(temp,"%d\t%s\t%d\t%s\t%s\t%ld\t%s\t%d\n",student.srno,student.name,student.age,student.cls,student.email,student.phone,student.city,student.fee_deposited);}
    }  
    

    fclose(file);
    fclose(temp);
    remove("studentR.txt");
    rename("temp.txt","studentR.txt"); 
    main();
}

void CollegeLogo()
{
    FILE *file;
    char ch;

    int x=30,y=1;
    file=fopen("DezyneLogo.txt","r");
    while(fscanf(file,"%c",&ch) !=EOF)
    {   gotoxy(x,y);
        if(ch=='\n')
        {y+=1;x=30;}

        printf("%c",ch);
        x+=1;
        
    }
}
void Change_BackColor(int x,int y,int x2,int y2)
{
    for (int i = 0; i < y2; i++)
    {   for (int  j = 0; j < x2; j++)
        {
            
            gotoxy(x+j,y+i);
            textbackground(4);
            printf(" ");
           
        }
   
    }
     textbackground(0);
     textcolor(4);
    
}
