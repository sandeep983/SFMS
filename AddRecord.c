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