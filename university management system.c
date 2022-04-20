//Al-Mahamud
//1907082
//Computer Science Engineering
//Khulna University of Engineering & Technology,Khulna
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void admin_panel();
void a_register();
void log_in();
void a_h_page();
void teacher();
void add_teacher();
void teacher_info();
void t_modify();
void t_erase();
void student();
void add_student();
void student_info();
void s_modify();
void s_erase();
void teacher_panel();
void t_register();
void t_login();
void t_hpage();
void ct();
void p_ct();
void u_p_ct();
void s_s_roll();
void s_s_name();
void n_students();
void student_portal();
void s_register();
void s_login();
void s_hpage();
void c_marks();
//struct for admin information
struct info
{
    char full_name[25];
    char user_name[25];
    char password[10];
}d;
//struct for teacher information
struct teacher
{
    char name[25];
    char us_name[25];
    char id[15];
    char passcode[10];
    struct course
    {
        char course[10];
        int c_code;
    }c[10];
}t,*u;
//struct for student information
struct student
{
    char name_s[25];
    char u_name[25];
    char Class[25];
    char roll[15];
    char pass_code[10];
    int marks[100];
}s,*r;
//struct for loop
struct checker
{
    char checker[10];
    int d_code;
}dis[10];

char teacher_id[15],student_roll[15],semester[15],name[25];
//first page/main menu
int main()
{
    int choice;
    while(1)
    {
        system("cls");//clear system
        printf("\t\t\t\t***Welcome to University Management System***\n");
        printf("1. Admin Panel\n");
        printf("2. Teacher's Panel\n");
        printf("3. Student's Portal\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d",&choice);
        switch(choice)//each case calling function
        {
        case 1:
            admin_panel();
            break;
        case 2:
            teacher_panel();
            break;
        case 3:
            student_portal();
            break;
        case 4:
            exit(0);
        }
        printf("Press any key to continue.......");
        getch();
    }
}
//admin page
FILE *fp_r;//register_info file
void admin_panel()
{
    int choice;
    while(1)
    {
        system("cls");
        printf("\t\t\t\t***Welcome to University Management System***\n");
        printf("University Management System->>Admin Panel\n");
        printf("Welcome to Admin Panel\n");
        printf("What do you want?\n");
        printf("1. Register\n");
        printf("2. Log in\n");
        printf("3. Main Menu\n");
        printf("4. Exit\n");
        printf("Please enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            fp_r=fopen("register_info.txt","rb"); // read mode for checking previous registration
            if (fp_r == NULL){
                a_register();
            }
            else printf("\nyou already registered.Login first\n");
            break;
        case 2:
            log_in();
            break;
        case 3:
            main();
            break;
        case 4:
            exit(0);
        }
        printf("Press any key to continue........");
        getch();
        system("cls");
    }
}
//admin registration page
void a_register()
{

    system("cls");
    printf("\t\t\t\t***Welcome to University Management System***\n");
    printf("University Management System->>Admin Panel->>Register\n");
    printf("Please, give proper info to register.\n");
    fp_r=fopen("register_info.txt","a");//opens a text file in append mode
    printf("\nEnter name: ");
    fflush(stdin);
    gets(d.full_name);
    printf("\nEnter user name: ");
    fflush(stdin);
    gets(d.user_name);
    printf("\nEnter a new password within 8 characters: ");
    fflush(stdin);
    gets(d.password);
    while(1)
    {
        char password_2[10];
        printf("Enter password again: ");
        fflush(stdin);
        gets(password_2);
        if(strcmp(d.password,password_2)==0)//compare two string password
            break;
        else
            printf("Password didn't match:-(\nPlease try again.\n");
    }
    fwrite(&d,sizeof(struct info),1,fp_r);//write struct data in file
    printf("Congratulations! \nYou have registered successfully.\n");
    printf("Press any key to continue.......\n");
    getch();
    fclose(fp_r);//close file
    while(1){
        printf("1.login\n2.main menu\n3.exit\nPlease enter your choice:");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            log_in();
            break;
        case 2:
            main();
            break;
        case 3:
            exit(0);
        }
    }
}
//admin logging page
void log_in()
{
    system("cls");
    printf("\t\t\t\t***Welcome to University Management System***\n");
    printf("University Management System->>Admin Panel->>Log in\n");
    printf("Please, log in with user name and password\n");
    char u_name[25],u_pass[10];
    FILE *fp;//file pointer.
    fp=fopen("register_info.txt","rb");//opens a binary file in read mode
    printf("\nUser Name: ");
    fflush(stdin);
    gets(u_name);
    printf("\nPassword: ");
    fflush(stdin);
    gets(u_pass);
    while(fread(&d,sizeof(d),1,fp)==1)
    {
        if(strcmp(u_name,d.user_name)==0 && strcmp(u_pass,d.password)==0)
        {
            printf("Logged in successfully\n");
            printf("Press any key to continue........\n");
            getch();
            a_h_page();
        }
        else{
            printf("You have entered wrong user name or wrong password or both wrong.Please try again.\n");
            printf("Press any key to continue_ _ _ _ \n");
            char a;//any character
            scanf("%c",&a);
            log_in();
        }
    }
    fclose(fp);
}
//admin home page
void a_h_page()
{
    while(1)
    {
        system("cls");
        printf("\t\t\t\t***Welcome to University Management System***\n");
        printf("University Management System->>Admin Panel->>%s->>Main page\n",d.full_name);
        printf("Welcome, %s\n",d.full_name);
        printf("1. Teacher\n");
        printf("2. Student\n");
        printf("3. Main Menu\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            teacher();
            break;
        case 2:
            student();
            break;
        case 3:
            main();
            break;
        case 4:
            exit(0);
            }
        printf("Press any key to continue........");
        getch();
        system("cls");
    }
}
//admin to teacher page
void teacher()
{
    int choice;
    while(1)
    {
        system("cls");
        printf("\t\t\t\t***Welcome to University Management System***\n");
        printf("University Management System->>Admin Panel->>Teacher\n");
        printf("Welcome to teachers site   :-)\n");
        printf("1. Add Teacher\n");
        printf("2. Teacher Info\n");
        printf("3. Edit\n");
        printf("4. Delete\n");
        printf("5. Back\n");
        printf("6. Main Menu\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            add_teacher();
            break;
        case 2:
            teacher_info();
            break;
        case 3:
            t_modify();
            break;
        case 4:
            t_erase();
            break;
        case 5:
            a_h_page();
            break;
        case 6:
            main();
            break;
        case 7:
            exit(0);
        }
        system("cls");
    }
}
//admin to teacher add page
void add_teacher()
{
    system("cls");
    printf("\t\t\t\t***Welcome to University Management System***\n");
    printf("University Management System->>Admin Panel->>Add Teacher\n");
    FILE *fp;
    fp=fopen("teacher.txt","a");//opens a text file in append mode
    printf("\nEnter Name: ");
    fflush(stdin);
    gets(t.name);
    printf("\nEnter User Name: ");
    fflush(stdin);
    gets(t.us_name);
    printf("\nEnter ID: ");
    fflush(stdin);
    gets(t.id);
    printf("\nEnter password: ");
    fflush(stdin);
    gets(t.passcode);
    while(1)
    {
        char passcode_2[10];
        printf("\nEnter password again: ");
        fflush(stdin);
        gets(passcode_2);
        if(strcmp(t.passcode,passcode_2)==0)
            break;
        else
            printf("Password didn't match:-(\nPlease try again.\n");
    }
    for(int i=0;i<10;i++)//loop for course
    {
        printf("\nEnter course %d: ",i+1);
        fflush(stdin);
        gets(t.c[i].course);
        printf("Enter course %d code(if no course is assigned, please enter 0): ",i+1);
        scanf("%d",&t.c[i].c_code);
        if(t.c[i].c_code==0)
        {
            while(i<10)
            {
                strcpy(t.c[i].course,"N/A");
                t.c[i].c_code=0;
                i++;
            }
        }
    }
    fwrite(&t,sizeof(t),1,fp);//write struct data in file
    printf("Info have been recorded successfully.\n");
    printf("Press any key to continue.......");
    getch();
    system("cls");
    fclose(fp);
}
//admin to teacher information
void teacher_info()
{
    FILE *fp;
    system("cls");
    printf("\t\t\t\t***Welcome to University Management System***\n");
    printf("University Management System->>Admin Panel->>Teachers Info\n");
    fp=fopen("teacher.txt","r");//opens a text file in read mode
    printf("Teacher's Info:\n");
    while(fread(&t,sizeof(t),1,fp)==1)//while loop for print teacher information
    {
        printf("Name: %s\nUser Name: %s\nID: %s\npassword: %s\n",t.name,t.us_name,t.id,t.passcode);
        for(int i=0;i<10;i++)
        {
            if(t.c[i].c_code!=0)
                printf("Course %d: %s\tCourse_%d Code: %d\n",i+1,t.c[i].course,i+1,t.c[i].c_code);
        }
        printf("\n\n\n");
    }
    fclose(fp);
    printf("Press any key to continue.........");
    getch();
    system("cls");
}
//admin to teacher modify
void t_modify()
{
    u=&t;//assign struct t's memory address in u struct.
    FILE *fp;
    system("cls");
    printf("\t\t\t\t***Welcome to University Management System***\n");
    printf("University Management System->>Admin Panel->>Teacher Info Updating\n");
    fp=fopen("teacher.txt","rb+");//opens a binary file in read and write mode
    char t_id[15],t_pass[10];
    int check=0,l;
    l=sizeof(*u);//size of u struct pointer assign in l.
    printf("Modify Info \n");
    printf("Please give id to modify data.\n");
    printf("Enter ID: ");
    fflush(stdin);
    gets(t_id);
    while(fread(u,sizeof(*u),1,fp)==1)
    {
        if(strcmp(t_id,u->id)==0)
        {
            check=1;
            printf("\nEnter new name: ");
            fflush(stdin);
            gets(u->name);
            printf("\nEnter new user name: ");
            fflush(stdin);
            gets(u->us_name);
            printf("\nEnter new ID: ");
            fflush(stdin);
            gets(u->id);
            printf("\nEnter new password: ");
            fflush(stdin);
            gets(u->passcode);
            while(1)
            {
                char passcode_2[10];
                printf("\nEnter password again: ");
                fflush(stdin);
                gets(passcode_2);
                if(strcmp(u->passcode,passcode_2)==0)
                    break;
                else
                    printf("Password didn't match:-(\nPlease try again.\n");
            }
            for(int i=0;i<10;i++)//loop for adding new course.
            {
                printf("\nEnter new course %d: ",i+1);
                fflush(stdin);
                gets(u->c[i].course);
                printf("Enter new course %d code(if no course is assigned, please enter 0): ",i+1);
                scanf("%d",&u->c[i].c_code);
                if(t.c[i].c_code==0)
                {
                    while(i<10)
                    {
                        strcpy(t.c[i].course,"N/A");
                        t.c[i].c_code=0;
                        i++;
                    }
                }
            }
            fseek(fp,-l,SEEK_CUR);//fseek used to move file pointer associated with a given file to a specific position.
            fwrite(u,sizeof(*u),1,fp);
            check=1;
            fclose(fp);
            break;
        }
    }
     if(check==1)
            printf("Info have been updated successfully. :-)\n");
    else
        printf("Info have not been found:-(\n");
    printf("Press any key to continue........");
    getch();
    system("cls");
}
//admin to teacher erase page
void t_erase()
{
    u=&t;
    FILE *fp,*ft;
    char id_t[15],pass_t[10];
    system("cls");
    printf("\t\t\t\t***Welcome to University Management System***\n");
    printf("University Management System->>Admin Panel->>Teacher Info Erasing\n");
    int check=0;
    printf("Erase Info   :-)\n");
    printf("Please give id to erase data.\n");
    fp=fopen("teacher.txt","rb");
    ft=fopen("temp_t.txt","a");
    printf("Enter ID: ");
    fflush(stdin);
    gets(id_t);
    while(fread(u,sizeof(*u),1,fp)==1)
    {
        if(strcmp(id_t,u->id)==0)
        {
            printf("Name: %s\nID: %s\n",u->name,u->id);
            check=1;
        }
        else
            fwrite(u,sizeof(*u),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("teacher.txt");//remove previous teacher data
    rename("temp_t.txt","teacher.txt");//rename temporary file name .
    if(check==1)
        printf("Info have been deleted successfully.\n");
    else
        printf("Info have not been found\n");
    printf("Press any key to continue........");
    getch();
    system("cls");
}
//admin to student
void student()
{
    int choice;
    while(1)
    {
        system("cls");
        printf("\t\t\t\t***Welcome to University Management System***\n");
        printf("University Management System->>Admin Panel->>Student\n");
        printf("Welcome to students site   :-)\n");
        printf("1. Add Student\n");
        printf("2. Student Info\n");
        printf("3. Modify\n");
        printf("4. Erase\n");
        printf("5. Back\n");
        printf("6. Main Menu\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            add_student();
            break;
        case 2:
            student_info();
            break;
        case 3:
            s_modify();
            break;
        case 4:
            s_erase();
            break;
        case 5:
            a_h_page();
            break;
        case 6:
            main();
            break;
        case 7:
            exit(0);
        }
        system("cls");
    }
}
//admin to student add page
void add_student()
{
    system("cls");
    printf("\t\t\t\t***Welcome to University Management System***\n");
    printf("University Management System->>Admin Panel->>Add Student\n");
    FILE *fp;
    fp=fopen("student.txt","a");
    printf("\nEnter Name: ");
    fflush(stdin);
    gets(s.name_s);
    printf("\nEnter user name: ");
    fflush(stdin);
    gets(s.u_name);
    printf("\nEnter Class: ");
    fflush(stdin);
    gets(s.Class);
    printf("\nEnter Roll: ");
    fflush(stdin);
    gets(s.roll);
    printf("\nEnter password: ");
    fflush(stdin);
    gets(s.pass_code);
    while(1)
    {
        char passcode_2[10];
        printf("Enter password again: ");
        fflush(stdin);
        gets(passcode_2);
        if(strcmp(s.pass_code,passcode_2)==0)
            break;
        else
            printf("Password didn't match:-(\nPlease try again.\n");
    }
    fwrite(&s,sizeof(s),1,fp);//write struct data in file.
    fclose(fp);
    printf("Press any key to continue_ _ _ _ :-)");
    getch();
    system("cls");
}
//admin to student information page
void student_info()
{
    system("cls");
    printf("\t\t\t\t***Welcome to University Management System***\n");
    printf("University Management System->>Admin Panel->>Student Info\n");
    FILE *fp;
    fp=fopen("student.txt","r");
    printf("Student's Info:\n");
    while(fread(&s,sizeof(s),1,fp)==1)
          printf("Name: %s\nUser Name: %s\nClass: %s\nRoll: %s\nPassword: %s\n\n\n",s.name_s,s.u_name,s.Class,s.roll,s.pass_code);
    fclose(fp);
    printf("Press any key to continue_ _ _ _ :-)");
    getch();
    system("cls");
}
//admin to student modify page
void s_modify()
{
    system("cls");
    printf("\t\t\t\t***Welcome to University Management System***\n");
    printf("University Management System->>Admin Panel->>Student Info Updating\n");
    FILE *fp;
    fp=fopen("student.txt","rb+");//opens a binary file in read and write mode
    char s_roll[15],s_pass[10];
    r=&s;
    int check=0,l;
    l=sizeof(*r);
    printf("Modify Info   :-)\n");
    printf("Please give roll to modify data.\n");
    printf("Enter Roll: ");
    fflush(stdin);
    gets(s_roll);
    while(fread(r,sizeof(*r),1,fp)==1)
    {
        if(strcmp(s_roll,r->roll)==0)
        {
            check=1;
            printf("\nEnter new name: ");
            fflush(stdin);
            gets(r->name_s);
            printf("\nEnter new user name: ");
            fflush(stdin);
            gets(r->u_name);
            printf("\nEnter new class: ");
            fflush(stdin);
            gets(r->Class);
            printf("\nEnter new Roll: ");
            fflush(stdin);
            gets(r->roll);
            printf("\nEnter new password: ");
            fflush(stdin);
            gets(r->pass_code);
            while(1)
            {
                char passcode_2[10];
                printf("Enter password again: ");
                fflush(stdin);
                gets(passcode_2);
                if(strcmp(r->pass_code,passcode_2)==0)
                    break;
                else
                    printf("Password didn't match:-(\nPlease try again.\n");
            }
            fseek(fp,-l,SEEK_CUR);
            fwrite(r,sizeof(*r),1,fp);
            check=1;
            fclose(fp);
            break;
        }
    }
    if(check==1)
        printf("Info have been updated successfully. :-)\n");
    else
        printf("Info have not been found:-(\n");

    printf("Press any key to continue.......");
    getch();
    system("cls");
}
//admin to student erase page
void s_erase()
{
    FILE *fp,*ft;
    char roll_s[15],pass_s[10];
    system("cls");
    printf("\t\t\t\t***Welcome to University Management System***\n");
    printf("University Management System->>Admin Panel->>Student Info Erasing\n");
    r=&s;
    int check=0;
    printf("Erase Info .\n");
    printf("Please give roll to erase data.\n");
    fp=fopen("student.txt","rb");
    ft=fopen("temp_s.txt","a");
    printf("Enter Roll: ");
    fflush(stdin);
    gets(roll_s);
    while(fread(r,sizeof(*r),1,fp)==1)
    {
        if(strcmp(roll_s,r->roll)==0)
        {
            printf("Name: %s\nClass: %s,Roll: %s\n",r->name_s,r->Class,r->roll);
            check=1;
        }
        else
            fwrite(r,sizeof(*r),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("student.txt");
    rename("temp_s.txt","student.txt");
    if(check==1)
        printf("Info have been deleted successfully.\n");
    else
        printf("Info have not been found:-(\n");
    printf("Press any key to continue........");
    getch();
    system("cls");
}
//main menu to teacher panel
void teacher_panel()
{
    system("cls");
    printf("\t\t\t\t***Welcome to University Management System***\n");
    while(1)
    {
        printf("University Management System->>Teachers Panel\n");
        printf("Welcome to teachers panel\n");
        printf("0. Exit\n");
        printf("1. Register\n");
        printf("2. Log in\n");
        printf("3. Main Menu/Back\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
        case 0:
            exit(0);
        case 1:
            t_register();
            break;
        case 2:
            t_login();
            break;
        case 3:
            main();
            break;
        }
    }
    printf("Press any key to continue_ _ _ _ :-)");
    getch();
    system("cls");
}
//teacher panel to registration
void t_register()
{
    system("cls");
    printf("\t\t\t\t***Welcome to University Management System***\n");
    printf("University Management System->>Teachers Panel->>Registration\n");
    printf("Welcome to teachers registration page.\n");
    char choice;
    printf("Are you admin?(y/n): ");
    fflush(stdin);
    scanf("%c",&choice);
    if(choice=='y')
    {
        printf("You can register.\n");
        admin_panel();
    }
    else
    {
        printf("(\nOnly admin can register\n");
        printf("Press any key to continue_ _ _ _ :-)");
        getch();
        teacher_panel();
    }
    printf("Press any key to continue_ _ _ _ :-)");
    getch();
    system("cls");
}
//teachers logging page
void t_login()
{
    system("cls");
    printf("\t\t\t\t***Welcome to University Management System***\n");
    printf("University Management System->>Teachers Panel->>log in\n");
    printf("Please enter your correct id and password........ \n");
    int check=0;
    char m_id[15],m_pass[10];
    FILE *fp;
    fp=fopen("teacher.txt","rb");
    printf("\nEnter User Id: ");
    fflush(stdin);
    gets(m_id);
    printf("\nEnter password: ");
    fflush(stdin);
    gets(m_pass);
    while(fread(&t,sizeof(t),1,fp)==1)
    {
        if(strcmp(m_id,t.id)==0 && strcmp(m_pass,t.passcode)==0)
        {
            check=1;
            strcpy(teacher_id,t.id);
            strcpy(name,t.name);
            for(int i=0;i<10;i++)
            {
                strcpy(dis[i].checker,t.c[i].course);
                dis[i].d_code=t.c[i].c_code;
            }
            printf("\nSuccessful login\n");
            printf("Press any key to continue........");
            getch();
            system("cls");
            t_hpage();
        }
    }
    if(check==0)
        printf("Sorry:-(\nWrong password or wrong id or both wrong\nPlease try again;\n");
    fclose(fp);
    printf("Press any key to continue........:-)");
    getch();
    system("cls");
}
//teacher home page
void t_hpage()
{
    system("cls");
    int choice;
    while(1)
    {
        printf("\t\t\t\t***Welcome to University Management System***\n");
        printf("University Management System->>Teachers Panel->>%s->>Main page\n",name);
        printf("Welcome, %s\n",name);
        printf("1. students CT marks and information\n");
        printf("2. Update CT marks\n");
        printf("3. Search student by roll\n");
        printf("4. Search student by name\n");
        printf("5. Number of students\n");
        printf("6. Back\n");
        printf("7. Main Menu\n");
        printf("8. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            ct();
            break;
        case 2:
            u_p_ct();
            break;
        case 3:
            s_s_roll();
            break;
        case 4:
            s_s_name();
            break;
        case 5:
            n_students();
            break;
        case 6:
            teacher_panel();
            break;
        case 7:
            main();
            break;
        case 8:
            exit(0);
        }
    }
    printf("Press any key to continue_ _ _ _ :-)");
    getch();
    system("cls");
}
//students ct marks and information
void ct()
{
    system("cls");
    printf("\t\t\t\t***Welcome to University Management System***\n");
    printf("University Management System->>Teachers Panel->>%s->>CT marks\n",name);
    FILE *fp,*ft;
    int n_s=0;
    u=&t;
    r=&s;
    fp=fopen("student.txt","rb+");
    ft=fopen("teacher.txt","rb+");
    printf("Teachers name: %s\n",name);
    while(fread(r,sizeof(*r),1,fp)==1)
    {
        n_s++;
        printf("%d\nStudent Name: %s\nRoll: %s\nClass: %s\nUser name: %s\n",n_s,r->name_s,r->roll,r->Class,r->u_name);
        for(int i=0;i<10;i++)
        {
            if(dis[i].d_code!=0)
                printf("Course Name: %s\tCourse code: %d\tObtained Marks: %d\n",dis[i].checker,dis[i].d_code,r->marks[dis[i].d_code]);
        }
    }
    fclose(fp);
    fclose(ft);
    printf("Press any key to continue_ _ _ _ :-)");
    getch();
    system("cls");
}
//teacher update students ct marks
void u_p_ct()
{

    system("cls");
    FILE *fp;
    printf("\t\t\t\t***Welcome to University Management System***\n");
    printf("University Management System->>Teachers Panel->>%s->>CT marks\n",name);
    fp=fopen("student.txt","rb+");
    int check=0;
    r=&s;
    char stud_roll[15];
    printf("Enter student roll: ");
    fflush(stdin);
    gets(stud_roll);
    while(fread(r,sizeof(*r),1,fp)==1)
    {
        if(strcmp(stud_roll,r->roll)==0)
        {
            check=1;
            printf("Student Name: %s\nRoll: %s\nClass: %s\n",r->name_s,r->roll,r->Class);
            printf("Previous Marks:\n");
            for(int i=0;i<10;i++)
            {
                if(dis[i].d_code!=0)
                    printf("Course Name: %s\tCourse code: %d\tObtained Marks: %d\n",dis[i].checker,dis[i].d_code,r->marks[dis[i].d_code]);
            }
            printf("Provide/Update marks:\n");
            for(int i=0;i<10;i++)
            {
                if(dis[i].d_code!=0)
                {
                    printf("Course Name: %s\tCourse code: %d\tEnter Obtained Marks: ",dis[i].checker,dis[i].d_code);
                    scanf("%d",&r->marks[dis[i].d_code]);
                }
            }
            fseek(fp,-sizeof(*r),SEEK_CUR);//used to move file pointer associated with a given file to a specific position.
            fwrite(r,sizeof(*r),1,fp);//write struct data in file
            break;
        }
    }
    if(check==0)
    {
        printf("Oops!!!!\n You may provide wrong roll or student not found.\n");
        char choice;
        printf("Do you want to try again?(y/n): ");
        scanf("%c",&choice);
        if(choice=='y')
        {
            fclose(fp);
            u_p_ct();
        }
    }
    else
        printf("\nMarks have been updated successfully:-)\n");
    fclose(fp);
    printf("Press any key to continue_ _ _ _ :-)");
    getch();
    system("cls");
    t_hpage();
}
//students search box in teacher home page
void s_s_roll()
{
    system("cls");
    printf("\t\t\t\t***Welcome to University Management System***\n");
    printf("University Management System->>Teachers Panel->>%s->>Search Student By Roll\n",name);
    FILE *fp;
    r=&s;
    char st_roll[15];
    fp=fopen("student.txt","rb");
    int check=0;
    printf("Enter Student's Roll: ");
    fflush(stdin);
    gets(st_roll);
    while(fread(r,sizeof(*r),1,fp)==1)
    {
        if(strcmp(st_roll,r->roll)==0)
        {
            check=1;
            break;
        }
    }
    if(check==0)
    {
        printf("student not found.\n");
        char choice;
        printf("Do you want to try again?(y/n): ");
        fflush(stdin);
        scanf("%c",&choice);
        if(choice=='y')
        {
            fclose(fp);
            s_s_roll();
        }
    }
    else
        printf("Name: %s\nRoll: %s\nClass: %s\nUser Name: %s\n\n\n",r->name_s,r->roll,r->Class,r->u_name);
    fclose(fp);
    printf("Press any key to continue_ _ _ _ :-)");
    getch();
    system("cls");
}
//search students by name from teachers home page
void s_s_name()
{
    system("cls");
    printf("\t\t\t\t**Welcome to University Management System**\n");
    printf("University Management System->>Teachers Panel->>%s->>Search Student By Name\n",name);
    char stud_name[25];
    FILE *fp;
    int check=0;
    r=&s;
    fp=fopen("student.txt","rb");
    printf("Enter Student's Name: ");
    fflush(stdin);
    gets(stud_name);
    while(fread(r,sizeof(*r),1,fp)==1)
    {
        if(strcmp(stud_name,r->name_s)==0)
        {
            printf("Name: %s\nRoll: %s\nClass: %s\nUser Name: %s\n\n\n",r->name_s,r->roll,r->Class,r->u_name);
            check=1;
            break;
        }
    }
    if(check==0)
    {
        printf("Oops!!!!\n You may provide wrong Name or student not found.\n");
        char choice;
        printf("Do you want to try again?(y/n): ");
        fflush(stdin);
        scanf("%c",&choice);
        if(choice=='y')
        {
            fclose(fp);
            s_s_name();
        }
    }
    else
        printf("Info have been found:-)\n");
    fclose(fp);
    printf("Press any key to continue_ _ _ _ :-)");
    getch();
    system("cls");
}
//total students
void n_students()
{
    system("cls");
    printf("\t\t\t\t***Welcome to University Management System***\n");
    printf("University Management System->>Teachers Panel->>%s->>Counting Students\n",name);
    FILE *fp;
    fp=fopen("student.txt","rb+");
    int n_s=0;
    while(fread(&s,sizeof(s),1,fp)==1)
        n_s++;
    printf("Number of Students: %d\n",n_s);
    fclose(fp);
    printf("Press any key to continue_ _ _ _ :-)");
    getch();
    system("cls");
}
//students home page
void student_portal()
{
    system("cls");
    printf("\t\t\t\t***Welcome to University Management System***\n");
    while(1)
    {
        printf("University Management System->>Students Panel\n");
        printf("Welcome to students panel\n");
        printf("0. Exit\n");
        printf("1. Register\n");
        printf("2. Log in\n");
        printf("3. Main Menu/Back\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
        case 0:
            exit(0);
        case 1:
            s_register();
            break;
        case 2:
            s_login();
            break;
        case 3:
            main();
            break;
        }
    }
    printf("Press any key to continue_ _ _ _ :-)");
    getch();
    system("cls");
}
//students registration page .but only admin can register .
void s_register()
{
    system("cls");
    printf("\t\t\t\t***Welcome to University Management System***\n");
    printf("University Management System->>Students panel>>Register\n");
    printf("Welcome to students registration page.\n");
    char choice;
    printf("Are you admin?(y/n): ");
    fflush(stdin);
    scanf("%c",&choice);
    if(choice=='y')
    {
        printf("You can register.\n");
        admin_panel();
    }
    else
    {
        printf("\nOnly admin can register\n");
        printf("Press any key to continue........");
        getch();
        student_portal();
    }
    printf("Press any key to continue.........");
    getch();
    system("cls");
}
//students logging page.
void s_login()
{
    system("cls");
    printf("\t\t\t\t***Welcome to University Management System***\n");
    printf("University Management System->>Students panel>>Log in\n");
    printf("Please enter your correct roll and password........\n");
    int check=0;
    char s_roll[15],s_pass[10];
    FILE *fp;
    fp=fopen("student.txt","rb+");
    printf("\nEnter Roll: ");
    fflush(stdin);
    gets(s_roll);
    printf("\nEnter password: ");
    fflush(stdin);
    gets(s_pass);
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        if(strcmp(s_roll,s.roll)==0 && strcmp(s_pass,s.pass_code)==0)
        {
            check=1;
            strcpy(name,s.name_s);
            strcpy(semester,s.Class);
            strcpy(student_roll,s.roll);
            printf("\nSuccessful login\n");
            printf("Press any key to continue..........");
            getch();
            system("cls");
            s_hpage();
        }
    }
    if(check==0)
        printf("Sorry:-(\nYou have entered wrong password or wrong id or both wrong\nPlease try again;\n");
    fclose(fp);
    printf("Press any key to continue........");
    getch();
    system("cls");
}
//students home page after logging .
void s_hpage()
{
    system("cls");
    int choice;
    while(1)
    {
        printf("\t\t\t\t***Welcome to University Management System***\n");
        printf("University Management System->>Students panel>>%s->>Main Page\n",name);
        printf("Welcome to students page........\n");
        printf("0. Exit\n");
        printf("1. Check marks\n");
        printf("2. Back\n");
        printf("3. Main Menu\n");
        printf("Please enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 0:
            exit(0);
        case 1:
            c_marks();
            break;
        case 2:
            student_portal();
            break;
        case 3:
            main();
            break;
        }
    }
    printf("Press any key to continue........");
    getch();
    system("cls");
}
//student home page to ct marks page.
void c_marks()
{
    system("cls");
    printf("\t\t\t\t***Welcome to University Management System***\n");
    printf("University Management System->>Students panel>>%s->>CT marks\n",name);
    int n_s=0;
    FILE *fp,*ft;
    fp=fopen("student.txt","rb");
    ft=fopen("teacher.txt","rb");
    printf("Name: %s\nRoll: %s\nClass: %s\n\n\n",name,student_roll,semester);
    while(fread(&t,sizeof(t),1,ft)==1)
    {
        while(fread(&s,sizeof(s),1,fp)==1)
        {
            //printf("%d\n",1);
            if(strcmp(student_roll,s.roll)==0)
            {
                for(int i=0;i<10;i++)
                {
                    dis[i].d_code=t.c[i].c_code;
                    if(dis[i].d_code!=0)
                    {
                        printf("%d. Course: %s\n Marks: %d\n\n",++n_s,t.c[i].course,s.marks[dis[i].d_code]);
                    }
                }
                fseek(fp,-sizeof(s),SEEK_CUR);//used to move file pointer associated with a given file to a specific position.
                break;
            }
        }
    }
    fclose(ft);
    fclose(fp);
    printf("Press any key to continue.........");
    getch();
    system("cls");
}
