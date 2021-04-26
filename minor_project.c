#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

static int choice = 0;

struct Hospital
{
    char name[1000];
    char username[1000];
    char password[1000];
    char address[1000];
    char city[1000];
    char state[1000];
    char pincode[1000];
    char category[1000];
};

struct Patient
{
    char p_name[1000];
    char p_username[1000];
    char p_password[1000];
    char p_address[1000];
    char p_city[1000];
    char p_state[1000];
    char p_pincode[1000];
    char p_phone_no[1000];
};

struct HealthServices
{
    char name[1000];
    char type[1000];
    char beds[10];
    char icu_wards[10];
    char vent[10];
    char nur_staff[10];
    char doctors[10];
    char other_services[1000];
};

struct Ratings
{
    char Hospital_Name[1000];
    char rate[10];
    char count_reviews[10];
};
struct Ratings1
{
    char Hospital_Name[1000];
    float rate;
    int count_reviews;
};

void Menu();
void About_us();
void Hospital();
void Hospital_Registration(struct Hospital*, int);
void Hospital_login(struct Hospital*, int);
void Patient();
void Patient_Registration(struct Patient*, int);
void Patient_login(struct Patient*, int);
void city_name();
void question();
int getRecords(char[]);
int readHospital(struct Hospital*);
int readPatient(struct Patient*);
int readHealthServices(struct HealthServices*);
int readRatings(struct Ratings*);
void Hospital_Dashboard(struct Hospital*, int, int);
void Patient_Dashboard(struct Patient*, int, int);
void HealthServices(struct Hospital*, int, int);
void giveReview(char*, char*);
void updateFile(char*, int, char*);
void Search_Hospitals();
void List_by_Ratings();
void List_by_Services();
void QuickSort(struct Ratings1[], int, int);
int partition(struct Ratings1[], int, int);
void showReviews(char*);


void Menu()
{
    printf("\n\n\n\n\t\t\t\t\t\t 1) About Us \n");
    printf("\t\t\t\t\t\t 2) Hospital Admin Portal \n");
    printf("\t\t\t\t\t\t 3) Patient Portal \n");
    printf("\t\t\t\t\t\t 4) Search Hospitals\n");
    printf("\t\t\t\t\t\t 5) Exit \n\n");
    printf("\t\t\t\t\t\t Enter your choice:");
    scanf("%d", &choice);

    switch (choice) {
    case 1: {
        About_us();
        break;
    }
    case 2: {
        Hospital();
        break;
    }
    case 3: {
        Patient();
        break;
    }
    case 4: {
        Search_Hospitals();
        break;
    }
    case 5: {

        question();
        break;

    }
    default:
        printf("Wrong Input\n");
    }
}

int getRecords(char fname[])
{
    int count = 0;
    FILE *p = fopen(fname,"r");
    char ch = "";
    while(ch != EOF)
    {
        ch = fgetc(p);
        if(ch == '\n')
            count++;
    }
    fclose(p);
    return count;
}

int readHospital(struct Hospital *l)
{
    //struct Hospital l[10];
    int i=0,j=0,count=0;
    FILE *p1;
    p1 = fopen("Hospital_Details.txt","r");
    char ch = "";
    while(ch != EOF)
    {
        ch = fgetc(p1);

        //printf("%c",ch);
        if(ch == '\n')
        {
            j++;
            i=0;
            count = 0;
            continue;
        }
        if(ch == ',' && count == 0)
            {i = 0;  count++; continue;}
        if(ch == ',' && count == 1)
            {i = 0;  count++; continue;}
        if(ch == ',' && count == 2)
            {i = 0;  count++; continue;}
        if(ch == ',' && count == 3)
            {i = 0;  count++; continue;}
        if(ch == ',' && count == 4)
            {i = 0;  count++; continue;}
        if(ch == ',' && count == 5)
            {i = 0;  count++; continue;}
        if(ch == ',' && count == 6)
            {i = 0;  count++; continue;}
        if(count == 0)
            l[j].name[i] = ch;
        if(count == 1)
            l[j].username[i] = ch;
        if(count == 2)
            l[j].password[i] = ch;
        if(count == 3)
            l[j].address[i] = ch;
        if(count == 4)
            l[j].city[i] = ch;
        if(count == 5)
            l[j].state[i] = ch;
        if(count == 6)
            l[j].pincode[i] = ch;
        if(count == 7)
            l[j].category[i] = ch;
        i++;
    }

    fclose(p1);
    return j;
}

int readPatient(struct Patient *p)
{
    int i=0,j=0,count=0;
    FILE *p2;
    p2 = fopen("Patient_Details.txt","r");
    char ch = "";
    while(ch != EOF)
    {
        ch = fgetc(p2);

        if(ch == '\n')
        {
            j++;
            i=0;
            count = 0;
            continue;
        }
        if(ch == ',' && count == 0)
            {i = 0;  count++; continue;}
        if(ch == ',' && count == 1)
            {i = 0;  count++; continue;}
        if(ch == ',' && count == 2)
            {i = 0;  count++; continue;}
        if(ch == ',' && count == 3)
            {i = 0;  count++; continue;}
        if(ch == ',' && count == 4)
            {i = 0;  count++; continue;}
        if(ch == ',' && count == 5)
            {i = 0;  count++; continue;}
        if(ch == ',' && count == 6)
            {i = 0;  count++; continue;}
        if(count == 0)
            p[j].p_name[i] = ch;
        if(count == 1)
            p[j].p_username[i] = ch;
        if(count == 2)
            p[j].p_password[i] = ch;
        if(count == 3)
            p[j].p_address[i] = ch;
        if(count == 4)
            p[j].p_city[i] = ch;
        if(count == 5)
            p[j].p_state[i] = ch;
        if(count == 6)
            p[j].p_pincode[i] = ch;
        if(count == 7)
            p[j].p_phone_no[i] = ch;
        i++;
    }

    fclose(p2);
    return j;
}

int readHealthServices(struct HealthServices *h)
{
    int i=0,j=0,count=0;
    FILE *p1;
    p1 = fopen("HealthServices.txt","r+");
    char ch = "";
    while(ch != EOF)
    {
        ch = fgetc(p1);

        //printf("%c",ch);
        if(ch == '\n')
        {
            j++;
            i=0;
            count = 0;
            continue;
        }
        if(ch == ',' && count == 0)
            {i = 0;  count++; continue;}
        if(ch == ',' && count == 1)
            {i = 0;  count++; continue;}
        if(ch == ',' && count == 2)
            {i = 0;  count++; continue;}
        if(ch == ',' && count == 3)
            {i = 0;  count++; continue;}
        if(ch == ',' && count == 4)
            {i = 0;  count++; continue;}
        if(ch == ',' && count == 5)
            {i = 0;  count++; continue;}
        if(ch == ',' && count == 6)
            {i = 0;  count++; continue;}
        if(count == 0)
            h[j].name[i] = ch;
        if(count == 1)
            h[j].type[i] = ch;
        if(count == 2)
            h[j].beds[i] = ch; //printf("%c",h[j].beds);}
        if(count == 3)
            h[j].icu_wards[i] = ch;
        if(count == 4)
            h[j].vent[i] = ch;
        if(count == 5)
            h[j].nur_staff[i] = ch;
        if(count == 6)
            h[j].doctors[i] = ch;
        if(count == 7)
            h[j].other_services[i] = ch;
        i++;
    }
    //*t = j;
    //printf("Hello");
    //printf("%s",l[3].password);
    fclose(p1);
    //printf("--> %d <--",h[1].beds);
    return j;
}

int readRatings(struct Ratings *r)
{
    int i=0,j=0,count=0;
    FILE *p1;
    p1 = fopen("Ratings.txt","r+");
    char ch = "";
    while(ch != EOF)
    {
        ch = fgetc(p1);

        //printf("%c",ch);
        if(ch == '\n')
        {
            j++;
            i=0;
            count = 0;
            continue;
        }
        if(ch == ',' && count == 0)
            {i = 0;  count++; continue;}
        if(ch == ',' && count == 1)
            {i = 0;  count++; continue;}
        if(count == 0)
            r[j].Hospital_Name[i] = ch;
        if(count == 1)
            r[j].rate[i] = ch;
        if(count ==2)
            r[j].count_reviews[i] = ch;
        i++;
    }
    fclose(p1);
    return j;
}

void Hospital_Registration(struct Hospital *l, int t)
{
    int i;
    struct Hospital b;
    t = readHospital(l);

    int check1,check2;
    char temp[1000];
    //getting details from user
    int c = 0;
    do
    {
        if(c == 0)
        {
            printf("Enter Hospital name:");
            getchar();
            gets(b.name);
            //printf("\n%s",b.name);
        }
        else
        {
            printf("\n\nAgain Enter Hospital name:");
            gets(b.name);
            //printf("\n%s",b.name);
        }
        c++;


    //Verify Name and User name
        for(i=0;i<t;i++)
        {
            check1 = strcmp(b.name,l[i].name);
            if(check1 == 0)
            {
                printf("Hospital name already exists.");
                break;
            }
        }
    }while(check1 == 0);

    if(check1 != 0)
    {
        do
        {
            printf("\nEnter user name:");
            gets(b.username);
            strcpy(temp,b.username);
            for(i=0;i<t;i++)
            {
                check2 = strcmp(strupr(temp),strupr(l[i].username));
                if(check2 == 0)
                    break;
            }
            if(check2 == 0)
                printf("\nUsername already taken.");
        }while(check2 == 0);
        if(check2 != 0)
        {
            printf("\nEnter password:");
            gets(b.password);
            printf("\nEnter address of Hospital:");
            gets(b.address);
            printf("\nEnter city:");
            gets(b.city);
            printf("\nEnter state:");
            gets(b.state);
            printf("\nEnter PIN Code:");
            gets(b.pincode);
            printf("\nEnter Hospital category:");
            gets(b.category);

            FILE *fp;
            fp = fopen("Hospital_Details.txt","a");
            if(fp == NULL)
            {
                printf("Cannot open file.");
                exit(1);
            }
            fputs(b.name,fp);
            fputs(",",fp);
            fputs(b.username,fp);
            fputs(",",fp);
            fputs(b.password,fp);
            fputs(",",fp);
            fputs(b.address,fp);
            fputs(",",fp);
            fputs(b.city,fp);
            fputs(",",fp);
            fputs(b.state,fp);
            fputs(",",fp);
            fputs(b.pincode,fp);
            fputs(",",fp);
            fputs(b.category,fp);
            fputs("\n",fp);
            fclose(fp);
            printf("\n\t\tREGISTRATION SUCCESSFUL");
            delay(3000);

            int choice;
            do
            {
                system("CLS");
                printf("\n1. Login\t2. Back to Main Menu\n");
                scanf("%d",&choice);
                if(choice <1 || choice > 2)
                    printf("\nWrong Choice");

            }while(choice <1 || choice > 2);
            switch(choice)
            {
                case 1:
                    {
                        int s = readHospital(l);
                        Hospital_login(l,s);
                        break;
                    }
                case 2:
                    {
                        system("CLS");
                        int s = readHospital(l);
                        Menu();
                        break;
                    }
                default:
                    {
                        printf("\nWrong Choice");
                        break;
                    }
            }
        }
    }
    //else
       //printf("\nHospital name already exists.");
}

void updateFile(char *filename, int delete_line, char *edited_line)
{
    FILE *fp1, *fp2;
    char ch;
    int temp = 0;

    //open file in read mode
    fp1 = fopen(filename, "r");

    //open new file in write mode
    fp2 = fopen("temp.txt", "a");
    ch = getc(fp1);
    int cnt = 0;
    while (ch != EOF)
    {
        if (ch == '\n')
            temp++;
            if(cnt==0 && temp == delete_line)
            {
                if(temp == 0)
                {
                    fputs(edited_line,fp2);
                    cnt++;
                }
                else
                {
                    putc('\n',fp2);
                    fputs(edited_line,fp2);
                    cnt++;
                }
            }
            if (temp != delete_line)
                putc(ch, fp2);
        ch = getc(fp1);
    }
    fclose(fp1);
    fclose(fp2);
    remove(filename);
    rename("temp.txt", filename);
}

void Hospital_Dashboard(struct Hospital *l, int t, int index)
{
    system("CLS");
    int c;
    printf("\n\t\t\t\t\t\t\t Hospital Dashboard");
    printf("\n\t\t\t\t\t\t\t********************");
    printf("\n\t1. Profile\t\t2. Health Services\t\t3. Status and Reviews\t\t4. Logout\n");
    scanf("%d",&c);
    //printf("Hello");
    switch(c)
    {
        case 1:
            {
                char ch;
                do
                {
                    system("CLS");
                    int choice;
                    printf("\n\t1. View Profile\t\t2. Edit Profile\t\t3. Back\n");
                    scanf("%d",&choice);
                    getchar();
                    if(choice == 1)
                    {
                        printf("Hospital Name: %s\nUsername: %s\nPassword: %s\nAddress: %s\nCity: %s\nState: %s\nPincode: %s\nCategory: %s\n\n",
                                l[index].name,l[index].username,l[index].password,l[index].address,l[index].city,l[index].state,l[index].pincode,l[index].category);
                    }
                    //EDIT PROFILE
                    if(choice == 2)
                    {
                        char rec[8][100] = {"Hospital Name","Username","Password","Address","City","State","Pincode","Category"};
                        char det[8][1000];
                        strcpy(det[0],l[index].name); strcpy(det[1],l[index].username); strcpy(det[2],l[index].password);
                        strcpy(det[3],l[index].address); strcpy(det[4],l[index].city); strcpy(det[5],l[index].state);
                        strcpy(det[6],l[index].pincode); strcpy(det[7],l[index].category);
                        for(int i=2;i<8;i++)
                        {
                            char e;
                            printf("\n%s: %s\n",rec[i],det[i]);
                            printf("Edit? y or n");

                            //printf("\r            ");
                            scanf("%c",&e);
                            getchar();
                            //printf("%c",e);
                            if(e == 'y')
                            {
                                printf("\n\t\t\t\tNew %s: ",rec[i]);
                                gets(det[i]);
                            }
                        }
                        strcpy(l[index].name,det[0]); strcpy(l[index].username,det[1]); strcpy(l[index].password,det[2]);
                        strcpy(l[index].address,det[3]); strcpy(l[index].city,det[4]); strcpy(l[index].state,det[5]);
                        strcpy(l[index].pincode,det[6]); strcpy(l[index].category,det[7]);
                        printf("\n\t\tUpdated Successfully");
                        //printf("\n\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",l[index].name,l[index].username,l[index].password,l[index].address,
                          //      l[index].city,l[index].state,l[index].pincode,l[index].category);
                        char edit[1000];
                        for(int i=0;i<8;i++)
                        {
                            edit[1000] = strcat(edit,det[i]);
                            if(i != 7)
                                edit[1000] = strcat(edit,",");
                        }
                        updateFile("Hospital_Details.txt",index,edit);
                    }
                    if(choice == 3)
                    {
                        Hospital_Dashboard(l,t,index);
                        break;
                    }
                    scanf("%c",&ch);
                }while(ch == '\n');
                break;
            }
        case 2:
            {
                HealthServices(l,t,index);
                break;
            }
        case 3:
            {
                char ch;
                do{
                    int n;
                    do{
                        system("CLS");
                        printf("\n1. Show Status\t\t2. Show Reviews\t\t3. Back\n");
                        scanf("%d",&n);
                        if(n < 1 || n > 3)
                            printf("\nWrong Choice");

                        getchar();
                    }while(n < 1 || n > 3);
                    switch(n)
                    {
                    case 1:
                        {
                            struct Ratings r[getRecords("Ratings.txt")+10];
                            int rat_size = readRatings(r);
                            struct Ratings1 R[getRecords("Ratings.txt")+10];
                            for(int i=0;i<rat_size;i++)
                            {
                                strcpy(R[i].Hospital_Name,r[i].Hospital_Name);
                                R[i].rate = atof(r[i].rate);
                                R[i].count_reviews = atoi(r[i].count_reviews);
                            }
                            QuickSort(R,0,rat_size-1);
                            int check;
                            for(int i=0;i<rat_size;i++)
                            {
                                if(strcmp(l[index].name,R[i].Hospital_Name) == 0)
                                { check = i; break; }
                                else
                                { check = -1; }
                            }
                            if(check != -1)
                                printf("\nRatings = %.2f\nReviews = %d\n",R[check].rate,R[check].count_reviews);
                            else
                                printf("\nThis Hospital is not rated");
                            break;
                        }
                    case 2:
                        {
                            showReviews(l[index].name);
                            break;
                        }
                    case 3:
                        break;
                    }
                    if(n == 3)
                       break;
                    else
                        scanf("%c",&ch);
                }while(ch == '\n');
                Hospital_Dashboard(l,t,index);
                break;
            }
        case 4:
                break;
        default:
            printf("Wrong Choice");
    }
    system("CLS");
    Menu();
}

void Hospital_login(struct Hospital *l, int t)
{
    struct Hospital b;
    int check1, check2, i, index;
    int c = 0;
    do
    {
        if(c == 0)
        {
            printf("Enter username:");
            getchar();
            gets(b.username);
        }
        else
        {
            printf("\nAgain enter username:");
            gets(b.username);
        }
        c++;

        for(i=0;i<t;i++)
        {
            check1 = strcmp(b.username,l[i].username);
            if(check1 == 0)
            {
                index = i;
                break;
            }
        }
        if(check1 != 0)
            printf("\nWrong Username\n\n");
    }while(check1 != 0);
    //printf("\n%s",l[index].password);
    if(check1 == 0)
    {
        for(i=0;i<3;i++)
        {
            printf("\nEnter password:");
            gets(b.password);
            if(strcmp(b.password,l[index].password) == 0)
            {
                Hospital_Dashboard(l,t,index);
                break;
            }
            else
            {
                printf("Wrong Password\n");
                if(i == 2)
                    printf("\nMore than 3 attempts");
            }
        }
    }
}


void Hospital()
{
    struct Hospital l[20];
    int t = readHospital(l);
    system("CLS");
    printf("\n\t\t\t\t\t\tHospital Admin Portal");
    printf("\n\t\t\t\t\t\t*********************");
    printf("\n\n\n\t\t\t\t\t\t  1. REGISTER \n\n\t\t\t\t\t\t  2. LOGIN");
    printf("\n\n\n\t\t\t\t\tENTER YOUR CHOICE: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1: {
        Hospital_Registration(l,t);
        break;
    }
    case 2: {
        Hospital_login(l,t);
        break;
    }
    default: {
        if (getchar() == '\n')
        {
            printf("\n\n\t\t\tPress Enter to re-Enter the choice");
            if (getchar() == '\n')
            {
                Hospital(l,t);
            }
            else
                printf("\nThank you for using Our System");
        }
        }
    }
}

void HealthServices(struct Hospital *l, int t, int index)
{
    struct HealthServices hs[20];
    int choice;
    char name[1000];
    char type[1000]; char beds[10]; char icu_wards[10]; char vent[10]; char nur_staff[10]; char doctors[10]; char other_services[1000];
    strcpy(name,l[index].name);
    strcpy(type,l[index].category);
    int line;
    char ch;
    do{
        system("CLS");
        int hs_size = readHealthServices(hs);
        printf("\n1. View health Services\t\t\t\t2. Edit Health Services\t\t\t\t3. Back\n");
        scanf("%d",&choice);
        getchar();
        //printf("%d",hs_size);
        for(int i=0;i<=hs_size;i++)
        {
            if(strcmp(hs[i].name,name) == 0)
            {
                line = i;
                break;
            }
            else
                line = -1;
        }
        if(choice == 1)
            {
                if(line == -1)
                    printf("\nNo Health Services");
                else
                {
                    //printf("%s %s",hs[line].type,hs[line].beds);
                    printf("\nType: %s\nNo. of beds: %s\nNo. of ICU wards: %s\nNo. of ventilators:%s\nNo. of nursing staff: %s\nNo. of doctors: %s\nOther services: %s",
                           hs[line].type,hs[line].beds,hs[line].icu_wards,hs[line].vent,hs[line].nur_staff,hs[line].doctors,hs[line].other_services);
                }
            }

        if(choice == 2)
            {
                printf("\nEnter Services");
                printf("\nNumber of beds: ");                            gets(beds);
                printf("\nNumber of ICU Wards: ");                       gets(icu_wards);
                printf("\nNumber of Ventilators: ");                     gets(vent);
                printf("\nNumber of Nursing Staff: ");                   gets(nur_staff);
                printf("\nNumber of Doctors:");                          gets(doctors);
                printf("\nOther Services: ");                            gets(other_services);
                char det[8][100];
                strcpy(det[0],name); strcpy(det[1],type); strcpy(det[2],beds);
                strcpy(det[3],icu_wards); strcpy(det[4],vent); strcpy(det[5],nur_staff);
                strcpy(det[6],doctors); strcpy(det[7],other_services);
                char edit[1000]="";
                for(int i=0;i<8;i++)
                {
                    edit[1000] = strcat(edit,det[i]);
                    if(i != 7)
                        edit[1000] = strcat(edit,",");
                }
                printf("Details: %s",edit);
                if(line == -1)
                {
                    FILE *fp = fopen("HealthServices.txt","a");
                    fputs(edit,fp);
                    fputs("\n",fp);
                    fclose(fp);
                }
                else
                    updateFile("HealthServices.txt",line,edit);
            }

        if(choice == 3)
            Hospital_Dashboard(l,t,index);
        scanf("%c",&ch);
    }while(ch == '\n');
}

void Patient_login(struct Patient *p, int s)
{
    struct Patient r;
    int check1, check2, i, index;
    int c = 0;
    do
    {
        if(c == 0)
        {
            printf("Enter username:");
            getchar();
            gets(r.p_username);
        }
        else
        {
            printf("\nAgain enter username:");
            gets(r.p_username);
        }
        c++;

        for(i=0;i<s;i++)
        {
            check1 = strcmp(r.p_username,p[i].p_username);
            if(check1 == 0)
            {
                index = i;
                break;
            }
        }
        if(check1 != 0)
            printf("\nWrong Username\n\n");
    }while(check1 != 0);
    //printf("\n%s",l[index].password);
    if(check1 == 0)
    {
        for(i=0;i<3;i++)
        {
            printf("\nEnter password:");
            gets(r.p_password);
            if(strcmp(r.p_password,p[index].p_password) == 0)
            {
                Patient_Dashboard(p,s,index);
                break;
            }
            else
            {
                printf("Wrong Password\n");
                if(i == 2)
                    printf("\nMore than 3 attempts");
            }
        }
    }
}

void Patient()
{
    struct Patient p[20];
    int s = readPatient(p);
    system("CLS");
    printf("\n\t\t\t\t\t\tPatient Portal");
    printf("\n\t\t\t\t\t\t**************");
    printf("\n\n\n\t\t\t\t\t\t  1. REGISTER \n\n\t\t\t\t\t\t  2. LOGIN");
    printf("\n\n\n\t\t\t\t\tENTER YOUR CHOICE: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1: {
        Patient_Registration(p,s);
        break;
    }
    case 2: {
        Patient_login(p,s);
        break;
    }
    default: {
        if (getchar() == '\n')
        {
            printf("\n\n\t\t\tPress Enter to re-Enter the choice");
            if (getchar() == '\n')
            {
                Patient(p,s);
            }
            else
                printf("\nThank you for using Our System");
        }
        }
    }
}

void Patient_Registration(struct Patient *p, int s)
{

int i;
    struct Patient r;
    s = readPatient(p);

    int check1,check2;
    char temp[1000];
    //getting details from user
    int c = 0;
    do
    {
        if(c == 0)
        {
            printf("Enter Patient name:");
            getchar();
            gets(r.p_name);
        }
        else
        {
            printf("\n\nAgain Enter Patient name:");
            gets(r.p_name);
        }

        c++;


    //Verify Name and User name
    //int size = sizeof(l)/sizeof(l[0]);

    //printf("%d\n%d\n%d\n",size,sizeof(l),sizeof(l[0]));
        for(i=0;i<s;i++)
        {
            check1 = strcmp(r.p_name,p[i].p_name);
            if(check1 == 0)
            {
                printf("Patient name already exists.");
                break;
            }
        }
    }while(check1 == 0);
    //printf("%d",check);

    //File for all details
    if(check1 != 0)
    {
        do
        {
            printf("\nEnter user name:");
            gets(r.p_username);
            strcpy(temp,r.p_username);
            for(i=0;i<s;i++)
            {
                check2 = strcmp(strupr(temp),strupr(p[i].p_username));
                if(check2 == 0)
                    break;
            }
            if(check2 == 0)
                printf("\nUsername already taken.");
        }while(check2 == 0);
        if(check2 != 0)
        {
            printf("\nEnter password:");
            gets(r.p_password);
            printf("\nEnter your address:");
            gets(r.p_address);
            printf("\nEnter your city:");
            gets(r.p_city);
            printf("\nEnter your state:");
            gets(r.p_state);
            printf("\nEnter PIN Code:");
            gets(r.p_pincode);
            printf("\nEnter Mobile No.:");
            gets(r.p_phone_no);

            FILE *fp;
            fp = fopen("Patient_Details.txt","a");
            if(fp == NULL)
            {
                printf("Cannot open file.");
                exit(1);
            }
            fputs(r.p_name,fp);
            fputs(",",fp);
            fputs(r.p_username,fp);
            fputs(",",fp);
            fputs(r.p_password,fp);
            fputs(",",fp);
            fputs(r.p_address,fp);
            fputs(",",fp);
            fputs(r.p_city,fp);
            fputs(",",fp);
            fputs(r.p_state,fp);
            fputs(",",fp);
            fputs(r.p_pincode,fp);
            fputs(",",fp);
            fputs(r.p_phone_no,fp);
            fputs("\n",fp);
            fclose(fp);
            printf("\n\t\tREGISTRATION SUCCESSFUL");
            delay(3000);
            system("CLS");
            int choice;
            printf("\n1. Login\t2. Back to Main Menu\n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                    {
                        int size = readPatient(p);
                        Patient_login(p,size);
                        break;
                    }
                case 2:
                    {
                        system("CLS");
                        int size = readPatient(p);
                        Menu(p,size);
                        break;
                    }
                default:
                    printf("\nWrong Choice");
            }
        }
    }

}

void giveReview(char *Hospital_Name, char *Patient_Name)
{
    system("CLS");
    printf("\t\t\t\t\t\tRATE HOSPITAL\n\t\t\t\t\t\t*************");
    ///Get Ratings
    printf("\nRate the Hospital on the scale of 0-5: \n");
    int rate1,rate2,rate3,rate4,rate5,rate6;
    printf("1. Hospital Environment: ");
    scanf("%d",&rate1);
    printf("2. Doctor's behavior towards patient: ");
    scanf("%d",&rate2);
    printf("3. Staff's behavior towards patient: ");
    scanf("%d",&rate3);
    printf("4. Quality of treatment/diagnosis: ");
    scanf("%d",&rate4);
    printf("5. Availability of health services: ");
    scanf("%d",&rate5);
    printf("6. Waiting Time: ");
    scanf("%d",&rate6);
    float rate = (rate1+rate2+rate3+rate4+rate5+rate6)/6;
    char edit[1000],srate[10];
    char count_reviews[10] = "1";

    ///Update Ratings File
    struct Ratings r[20];
    int r_size = readRatings(r);
    int line;
    for(int i=0;i<=r_size;i++)
        {
            if(strcmp(r[i].Hospital_Name,Hospital_Name) == 0)
            {
                line = i;
                break;
            }
            else
                line = -1;
        }
    if(line == -1)
    {
        sprintf(srate,"%f",rate);     ///To convert from float to string.
        strcat(edit,Hospital_Name);
        strcat(edit,",");
        strcat(edit,srate);
        strcat(edit,",");
        strcat(edit,count_reviews);
        FILE *p = fopen("Ratings.txt","a");
        fputs(edit,p);
        fputs("\n",p);
        fclose(p);
    }
    else
    {
        sprintf(srate,"%f",((atof(r[line].rate)+rate)/2)); ///atof converts string to float, here used to convert rate already stored in file to float
        sprintf(count_reviews,"%d",((atoi(r[line].count_reviews)+1)));///atoi converts string to int, here used to convert count_reviews already stored in file to int
        strcat(edit,r[line].Hospital_Name);
        strcat(edit,",");
        strcat(edit,srate);
        strcat(edit,",");
        strcat(edit,count_reviews);
        updateFile("Ratings.txt",line,edit);
    }

    char ch;
    printf("\nRATINGS RECORDED");
    scanf("%c",&ch);
    getchar();


    ///Get Reviews
    char filename[1000],review_line[1000];
    strcat(filename,Hospital_Name);
    strcat(filename,".txt");

    system("CLS");
    printf("\t\t\t\t\t\tREVIEW\n\t\t\t\t\t\t******");
    char review[10000];
    printf("\nGive your own review about the Hospital.\n");
    gets(review);

    ///Updating Reviews
    FILE *fp;
    //printf("%s",Hospital_Name);
    fp = fopen(filename,"a");
    if(fp == NULL)
    {
        printf("Cannot open file.");
        exit(1);
    }
    fputs(Patient_Name,fp);
    fputs("\n",fp);
    fputs(review,fp);
    fputs("\n\n",fp);
    fclose(fp);
    printf("\nREVIEWS RECORDED");
    scanf("%c",&ch);
    getchar();
}

void Patient_Dashboard(struct Patient *p, int s, int ind)
{
    system("CLS");
    int c;
    printf("\t\t\t\t\t Patient Dashboard \n");
    printf("\n\t\t\t\t\t*****************");
    printf("\n\t1. Profile\t\t2. Feedback for Hospital\t\t3. Logout\n");
    scanf("%d",&c);
    getchar();
    switch(c)
    {
        case 1:
            {
                char ch;
                do
                {
                    system("CLS");
                    int choice;
                    printf("\n\t1. View Profile\t\t2. Edit Profile\t\t3. Back\n");
                    scanf("%d",&choice);
                    getchar();
                    if(choice == 1)
                    {
                        printf("Patient Name: %s\nUsername: %s\nPassword: %s\nAddress: %s\nCity: %s\nState: %s\nPincode: %s\nPhone No.: %s\n\n",
                                p[ind].p_name,p[ind].p_username,p[ind].p_password,p[ind].p_address,p[ind].p_city,p[ind].p_state,p[ind].p_pincode,p[ind].p_phone_no);
                    }
                    //EDIT PROFILE
                    if(choice == 2)
                    {
                        char rec[8][100] = {"Patient Name","Username","Password","Address","City","State","Pincode","Phone no"};
                        char det[8][1000];
                        strcpy(det[0],p[ind].p_name); strcpy(det[1],p[ind].p_username); strcpy(det[2],p[ind].p_password);
                        strcpy(det[3],p[ind].p_address); strcpy(det[4],p[ind].p_city); strcpy(det[5],p[ind].p_state);
                        strcpy(det[6],p[ind].p_pincode); strcpy(det[7],p[ind].p_phone_no);
                        for(int i=2;i<8;i++)
                        {
                            char e;
                            printf("\n%s: %s\n",rec[i],det[i]);
                            printf("Edit? y or n:\n");
                            //printf("\r            ");
                            scanf("%c",&e);
                            getchar();
                            //printf("%c",e);
                            if(e == 'y')
                            {
                                printf("\n\t\t\t\tNew %s: ",rec[i]);
                                gets(det[i]);
                            }
                        }
                        strcpy(p[ind].p_name,det[0]); strcpy(p[ind].p_username,det[1]); strcpy(p[ind].p_password,det[2]);
                        strcpy(p[ind].p_address,det[3]); strcpy(p[ind].p_city,det[4]); strcpy(p[ind].p_state,det[5]);
                        strcpy(p[ind].p_pincode,det[6]); strcpy(p[ind].p_phone_no,det[7]);
                        printf("\n\t\tUpdated Successfully");
                        //printf("\n\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",l[index].name,l[index].username,l[index].password,l[index].address,
                          //      l[index].city,l[index].state,l[index].pincode,l[index].category);
                        char edit[1000];
                        for(int i=0;i<8;i++)
                        {
                            edit[1000] = strcat(edit,det[i]);
                            if(i != 7)
                                edit[1000] = strcat(edit,",");
                        }
                        updateFile("Patient_Details.txt",ind,edit);
                    }
                    if(choice == 3)
                    {
                        Patient_Dashboard(p,s,ind);
                        break;
                    }
                    scanf("%c",&ch);
                }while(ch == '\n');
                break;
            }
        case 2:
            {
                int check,wt;
                struct Hospital rl[getRecords("Hospital_Details.txt")+10];
                int hos_size = readHospital(rl);
                char Hospital_Name[1000];
                do{
                    system("CLS");
                    printf("\nEnter Hospital Name:");
                    gets(Hospital_Name);
                    printf("\n%s",Hospital_Name);
                    for(int i=0;i<hos_size;i++)
                    {
                        if(strcmp(rl[i].name,Hospital_Name) == 0)
                        {
                            check = 0;
                            break;
                        }
                        else
                            check = -1;
                    }
                    if(check != 0)
                    {
                        printf("\nHospital not Registered.");
                        scanf("%c",&wt);
                        getchar();
                    }
                }while(check != 0);
                if(check == 0)
                        giveReview(Hospital_Name,p[ind].p_name);
                Patient_Dashboard(p,s,ind);
                break;
            }
        case 3:
            {
                system("CLS");
                Menu(p,s);
                break;
            }
        default:
            printf("Wrong Choice");
    }
}

void swapRate(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}
void swapName(char *a, char *b)
{
    char t[1000];
    strcpy(t,a);
    strcpy(a,b);
    strcpy(b,t);
}
void swapCount(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (struct Ratings1 R[], int low, int high)
{
    float pivot;
    int pivot2;
    pivot = R[high].rate;
    pivot2 = R[high].count_reviews;
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {

        if (R[j].rate > pivot)
        {
            i++;
            swapName(R[i].Hospital_Name, R[j].Hospital_Name);
            swapRate(&R[i].rate, &R[j].rate);
            swapCount(&R[i].count_reviews, &R[j].count_reviews);
        }
        else
        {
            if(R[j].rate == pivot)
            {
                if(R[j].count_reviews > pivot2)
                {
                    i++;
                    swapName(R[i].Hospital_Name, R[j].Hospital_Name);
                    swapRate(&R[i].rate, &R[j].rate);
                    swapCount(&R[i].count_reviews, &R[j].count_reviews);
                }
            }
        }
    }
    swapName(R[i+1].Hospital_Name, R[high].Hospital_Name);
    swapRate(&R[i+1].rate, &R[high].rate);
    swapCount(&R[i+1].count_reviews, &R[high].count_reviews);
    return (i + 1);
}

void QuickSort(struct Ratings1 R[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(R, low, high);


        QuickSort(R, low, pi - 1);
        QuickSort(R, pi + 1, high);
    }
}

void List_by_Ratings()
{
    struct Ratings r[getRecords("Ratings.txt")+100];
    int rat_size = readRatings(r);
    struct Ratings1 R[getRecords("Ratings.txt")+100];
    for(int i=0;i<rat_size;i++)
    {
        strcpy(R[i].Hospital_Name,r[i].Hospital_Name);
        R[i].rate = atof(r[i].rate);
        R[i].count_reviews = atoi(r[i].count_reviews);
    }
    QuickSort(R,0,rat_size-1);
    printf("\n\n");
    printf("\t_______________________________________________________________________________________________");
    printf("\n\t| Rank    |%27sHospital Name    |%3sRatings    |%5sNumber of Reviews  |\n","","","");
    printf("\t|_________|____________________________________________|______________|________________________|\n");
  //printf("\t+---------+--------------------------------------------+--------------+------------------------+\n");
    for(int i=0;i<rat_size;i++)
    {
        printf("\t|%5d    |%40s    |%10.2f    |%15d         |\n",i+1,R[i].Hospital_Name,R[i].rate,R[i].count_reviews);
        printf("\t|_________|____________________________________________|______________|________________________|\n");
    }
    //printf("\t+---------+--------------------------------------------+--------------+------------------------+");
    printf("\n\n\n\n\n");
}

void List_by_Services()
{
    struct HealthServices hs[getRecords("HealthServices.txt")+100];
    int h_size = readHealthServices(hs);
    char l;
    do
    {
        int ls;
        do{
            system("CLS");
            printf("\n\t\t1. List all\t\t2. List Specific\t\t3. Back\n");
            scanf("%d",&ls);
            if(ls > 3 || ls < 1)
                printf("\Wrong choice");
            getchar();
        }while(ls > 3 || ls < 1);
        switch(ls)
        {
        case 1:
            {
                printf("________________________________________________________________________________________________________________________\n");
                printf("|%11sHospital Name |%5sType |%2sBeds |%1sICU Wards |%1sVentilators |%1sNursing Staff |%1sDoctors|%5sOther Services   |",
                       "","","","","","","","");
                printf("\n|_________________________|__________|_______|___________|_____________|_______________|________|______________________|");
                for(int i=0;i<h_size;i++)
                {
                    printf("\n|%24s |%10s| %5s | %9s | %11s | %13s | %6s | %20s |",
                           hs[i].name,hs[i].type,hs[i].beds,hs[i].icu_wards,hs[i].vent,hs[i].nur_staff,hs[i].doctors,hs[i].other_services);
                    printf("\n|_________________________|__________|_______|___________|_____________|_______________|________|______________________|");
                }
                break;
            }
        case 2:
            {
                char name[1000];
                printf("\nEnter the name of Hospital: ");
                gets(name);
                int i,check;
                for(i=0;i<h_size;i++)
                {
                    if(strcmp(name,hs[i].name) == 0)
                    { check =i; break; }
                    else
                        check =-1;
                }
                if(check != -1)
                {
                    printf("________________________________________________________________________________________________________________________\n");
                    printf("|%11sHospital Name |%5sType |%2sBeds |%1sICU Wards |%1sVentilators |%1sNursing Staff |%1sDoctors|%5sOther Services   |",
                            "","","","","","","","");
                    printf("\n|_________________________|__________|_______|___________|_____________|_______________|________|______________________|");
                    printf("\n|%24s |%10s| %5s | %9s | %11s | %13s | %6s | %20s |",
                            hs[i].name,hs[i].type,hs[i].beds,hs[i].icu_wards,hs[i].vent,hs[i].nur_staff,hs[i].doctors,hs[i].other_services);
                    printf("\n|_________________________|__________|_______|___________|_____________|_______________|________|______________________|");
                }
                else
                    printf("\nNo Health Services Available for this Hospital");
                break;
            }
        case 3:
            break;
        }
        if(ls == 3)
            break;
        else
            scanf("%c",&l);
    }while(l == '\n');
    Search_Hospitals();
}

void showReviews(char *Hospital_Name)
{
    char filename[] = "";
    strcat(filename,Hospital_Name);
    strcat(filename,".txt");
    FILE *p = fopen(filename,"r");
    if(p == NULL)
        printf("\nNo Reviews for this Hospital");
    else
    {
        char ch = "";
        while(ch != EOF)
        {
            ch = fgetc(p);
            printf("%c",ch);
        }
    }
    fclose(p);
    getchar();
    Search_Hospitals();
}


void Search_Hospitals()
{
    char sH;
    do
    {
        int choice;
        do
        {
            system("CLS");
            printf("\t\t1. List by Ratings\t\t2. List by Services\t\t3. Show Reviews\t\t4. Back\n");
            scanf("%d",&choice);
            if(choice > 4 || choice < 1)
                printf("\nWrong Choice");
            getchar();
        }while(choice > 4 || choice < 1);
        switch(choice)
        {
        case 1:
            {
                List_by_Ratings();
                break;
            }
        case 2:
            {
                List_by_Services();
                break;
            }
        case 3:
            {
                char Hospital_Name[1000];
                printf("\nEnter the Hospital Name: ");
                gets(Hospital_Name);
                showReviews(Hospital_Name);
                break;
            }
        case 4:
            break;
        }
        if(choice == 4)
            break;
        else
            scanf("%c",&sH);

    }while(sH == '\n');
    system("CLS");
    Menu();
}

void About_us()
{

    ShellExecute(NULL, "open", "AboutUs.html",NULL, NULL, SW_SHOWNORMAL);
    system("CLS");
    Menu();

}

void question(struct Hospital *l, int t, struct Patient *p, int s)
{
   char e;
        printf("\n\t\t\t\t Press 'y' to exit the system or Press 'n' to back to main menu: ");
        scanf("%s",&e);
        if(e == 'Y' || e == 'y')
        {
            exit(0);
        }
        else{
            if(e=='n')
            {
                Menu();
            }
        }
}


int main()
{
    printf("\n\n\n\n\n\n\t\t\t\t*******************************************************************************");
    printf("\n\t\t\t\t|                                                                             |");
    printf("\n\t\t\t\t| Welcome To Health Services Availability and Outcome Based Monitoring System |");
    printf("\n\t\t\t\t*******************************************************************************");
    printf("\n\n\n\n\t\t\t\t\t\t\tPress Enter to proceed...!!");
    struct Hospital l[100];
    int t = readHospital(l);
    struct Patient p[100];
    int s = readPatient(p);

    if (getchar() == '\n')//To check enter is pressed for not
        Menu();
    else
    {
      printf("Press only Enter key For Using the System");
    }


    return 0;
}
