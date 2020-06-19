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