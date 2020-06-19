#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct student{
    char name[25];
    char f_name[25];
    char mobile[12];
    char roll_no[20];
    char course[10];
    char sem[5];
    char total_fee[8];
    char paid_fee[8];
};

struct student add_record()
{
    struct student data;

    FILE *fp;
    fp = fopen("StudentData.dat", "ab");

    printf("Enter The Following Details\n\n");
    while ((getchar()) != '\n');

    printf("Student's Name: ");
    scanf("%[^\n]", data.name);
    while ((getchar()) != '\n');

    printf("Father's Name: ");
    scanf("%[^\n]", data.f_name);
    while ((getchar()) != '\n');

    printf("Mobile: ");
    scanf("%s", data.mobile);
    while ((getchar()) != '\n');

    printf("Roll Number: ");
    scanf("%s", data.roll_no);
    while ((getchar()) != '\n');

    printf("Course: ");
    scanf("%s", data.course);
    while ((getchar()) != '\n');

    printf("Semester: ");
    scanf("%s", data.sem);
    while ((getchar()) != '\n');

    printf("Total Fee: ");
    scanf("%s", data.total_fee);
    while ((getchar()) != '\n');

    printf("Fee Paid: ");
    scanf("%s", data.paid_fee);
    while ((getchar()) != '\n');

    //fwrite(AdressOfData = &data, SizeOfData = sizeof(data), Records Writing at a time = 1, FilePointer = fp)
    fwrite(&data, sizeof(data), 1, fp);
    fclose(fp);
    printf("\nRecord Added Successfully\nPress any key");
    getch();
}

struct student search_record()
{

    struct student data;
    int rem_fee;

    FILE *fp;
    fp = fopen("StudentData.dat", "rb");

    if (fp == NULL)
    {
        printf("ERROR: File Not Found");
        exit(1);
    }

    while(fread(&data, sizeof(data), 1, fp) > 0)
    {
        printf("\n\nStudent Details: \n\n");
        printf("Name: %s",data.name);
        printf("\nFather's Name: %s",data.f_name);
        printf("\nMobile: %s",data.mobile);
        printf("\nCourse: %s",data.course);
        printf("\nSemester: %s",data.sem);
        printf("\nTotal Fee: %s",data.total_fee);
        printf("\nFee Paid: %s",data.paid_fee);
        rem_fee = atoi(data.total_fee) - atoi(data.paid_fee);
        printf("\nRemaining Fee: %d", rem_fee);
        printf("\n\nPress any key");
        getch();
        fclose(fp);
    }
}

int main()
{
    int choice;

    while(1)
    {
        system("cls");
        printf("Student Record System\n");
        printf("-----------------------\n");
        printf("\n1. Add Record");
        printf("\n2. Search Record");
        printf("\n3. Modify Record");
        printf("\n4. Delete Record");
        printf("\n5. Exit");
        printf("\n\nPlease enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                add_record();
                break;

            case 2:
                search_record();
                break;

            /*case 3:
                modify_record();

            case 4:
                delete_record();*/

            case 5:
                exit(0);
        }
    }
    return 0;
}

