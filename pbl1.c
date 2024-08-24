#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define MAX_STUDENTS 40
#define MAX_ID_LENGTH 20
#define MAX_NAME_LENGTH 50

typedef struct {
    char id[MAX_ID_LENGTH];
    char name[MAX_NAME_LENGTH];
    float lab1, lab2, progress_test1, progress_test2, presentation, final_test;
    float average;
    char grade;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

int isAlpha(const char *str);
int isNumber(char *str);
void calculating();
void enterScores();
void updateScores(char id[]);
void displayColumn();
void displayInformation(Student sv);
void displayList(Student *ds, int slsv);
int linearSearch(char id[]);
void viewScores(char id[]);
void merge(Student arr[], int left, int mid, int right);
void mergeSort(Student arr[], int left, int right);
void arrangement();
void inputFile();
void readFromFile(char *fileName);
void saveToFile(char *fileName);
void logo();
void displayMenu();

int main() {
    logo();
    inputFile();
    displayMenu();
    return 0;
}

//  ham kiem tra chu cai
int isAlpha(const char *str) {
    while (*str) {
        if (!isalpha(*str) && *str != ' ') {
            return 0;
        }
        str++;
    }
    return 1;
}

//  ham kiem tra so
int isNumber(char *str) {
    for (size_t i = 0; i < strlen(str); i++) {
        if (!isdigit((unsigned char)str[i])) {
            return 0;
        }
    }
    return 1;
}

//  ham tinh diem trung binh va xep loai
void calculating() {
    for (int i = 0; i < studentCount; i++) {
        students[i].average = (students[i].lab1 + students[i].lab2 + students[i].progress_test1 + students[i].progress_test2 + students[i].presentation + students[i].final_test) / 6.0;

        if (students[i].average >= 8.5)
            students[i].grade = 'A';
        else if (students[i].average >= 7.0)
            students[i].grade = 'B';
        else if (students[i].average >= 5.5)
            students[i].grade = 'C';
        else if (students[i].average >= 4.0)
            students[i].grade = 'D';
        else
            students[i].grade = 'F';
    }
}

void enterScores() {
    system("cls");
    char ch;
    do {
        //  kiem tra so luong sinh vien nhap vao co lon hon so luong sinh vien toi da khong
        if (studentCount >= MAX_STUDENTS) {
            printf("EXCEEDED THE MAXIMUM NUMBER OF STUDENTS!\n");
            break;
        }

        printf("ENTER INFORMATION OF STUDENT %d:\n", studentCount + 1);

        do {
            printf("\tENTER STUDENT'S ID: ");
            scanf("%s", students[studentCount].id);
            getchar();

            // kiem tra ma sinh vien co hop le khong
            if (!isNumber(students[studentCount].id)) {
                printf("\tINVALID STUDENT'S ID! PLEASE ENTER AGAIN!\n");
            }
            else {
                int found = 0;
                for (int i = 0; i < studentCount; i++) {
                    //  strcmp(char *s, char *t) so sanh 2 xau
                    //  kiem tra ma sinh vien da ton tai hay chua
                    if (strcmp(students[i].id, students[studentCount].id) == 0) {
                        found = 1;
                        printf("\tSTUDENT'S ID ALREADY EXISTS! PLEASE ENTER AGAIN!\n");
                        break;
                    }
                }
                if (!found) {
                    break;
                }
            }
        } while (1);

        do {
            printf("\tENTER STUDENT'S NAME: ");
            fgets(students[studentCount].name, MAX_NAME_LENGTH, stdin);
            students[studentCount].name[strcspn(students[studentCount].name, "\n")] = 0;
            //  kiem tra ten sinh vien co hop le khong
            if (!isAlpha(students[studentCount].name)) {
                printf("\tINVALID STUDENT'S NAME! PLEASE ENTER AGAIN!\n");
            }
            else {
                break;
            }
        } while (1);

        float diem;
        do {
            printf("\tENTER LAB 1 SCORE: ");
            //  kiem tra diem co hop le khong
            if (scanf("%f", &diem) != 1 || diem < 0 || diem > 10) {
                printf("\tINVALID SCORE! PLEASE ENTER AGAIN!\n");
                while (getchar() != '\n');
            }
            else {
                break;
            }
        } while (1);
        students[studentCount].lab1 = diem;

        do {
            printf("\tENTER LAB 2 SCORE: ");
            //  kiem tra diem co hop le khong
            if (scanf("%f", &diem) != 1 || diem < 0 || diem > 10) {
                printf("\tINVALID SCORE! PLEASE ENTER AGAIN!\n");
                while (getchar() != '\n');
            }
            else {
                break;
            }
        } while (1);
        students[studentCount].lab2 = diem;

        do {
            printf("\tENTER PROGRESS TEST 1 SCORE: ");
            //  kiem tra diem co hop le khong
            if (scanf("%f", &diem) != 1 || diem < 0 || diem > 10) {
                printf("\tINVALID SCORE! PLEASE ENTER AGAIN!\n");
                while (getchar() != '\n');
            }
            else {
                break;
            }
        } while (1);
        students[studentCount].progress_test1 = diem;

        do {
            printf("\tENTER PROGRESS TEST 2 SCORE: ");
            //  kiem tra diem co hop le khong
            if (scanf("%f", &diem) != 1 || diem < 0 || diem > 10) {
                printf("\tINVALID SCORE! PLEASE ENTER AGAIN!\n");
                while (getchar() != '\n');
            }
            else {
                break;
            }
        } while (1);
        students[studentCount].progress_test2 = diem;

        do {
            printf("\tENTER PRESENTATION SCORE: ");
            //  kiem tra diem co hop le khong
            if (scanf("%f", &diem) != 1 || diem < 0 || diem > 10) {
                printf("\tINVALID SCORE! PLEASE ENTER AGAIN!\n");
                while (getchar() != '\n');
            }
            else {
                break;
            }
        } while (1);
        students[studentCount].presentation = diem;

        do {
            printf("\tENTER FINAL TEST SCORE: ");
            //  kiem tra diem co hop le khong
            if (scanf("%f", &diem) != 1 || diem < 0 || diem > 10) {
                printf("\tINVALID SCORE! PLEASE ENTER AGAIN!\n");
                while (getchar() != '\n');
            }
            else {
                break;
            }
        } while (1);
        students[studentCount].final_test = diem;

        getchar(); // xoa bo nho dem

        calculating();

        studentCount++;

        printf("\n        PRESS ESC TO EXIT.\n        PRESS ENTER TO CONTINUE...\n\n");
        while (1) {
            ch = getch();
            if (ch == 27 || ch == 13) { // ESC or Enter key
                break;
            }
        }

        if (ch == 27) { // ESC key
            break;
        }
        system("cls");
    } while (1);
    system("cls");
}

void updateScores(char id[]) {
    system("cls");
    int found = 0;
    int choice;
    char input[10];
    char ch;

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].id, id) == 0) {
            found = 1;
            do {
                printf("\n =========================== CHOOSE THE GRADE COLUMN TO UPDATE FOR STUDENT WITH ID %s: =========================\n", id);
                printf(" |                                                 1. LAB 1                                                           |\n");
                printf(" |                                                 2. LAB 2                                                           |\n");
                printf(" |                                                 3. PROGRESS TEST 1                                                 |\n");
                printf(" |                                                 4. PROGRESS TEST 2                                                 |\n");
                printf(" |                                                 5. PRESENTATION                                                    |\n");
                printf(" |                                                 6. FINAL TEST                                                      |\n");
                printf(" |                                                 7. RETURN TO MENU                                                  |\n");
                printf(" ======================================================================================================================\n");
                printf("\n PLEASE CHOOSE A NUMBER: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;

                if (isNumber(input)) {
                    //  atoi(char *num); ham tra ve so
                    choice = atoi(input);
                }
                else {
                    choice = -1;
                }

                printf("\n");

                if (choice < 1 || choice > 7) {
                    printf(" INVALID CHOICE! PLEASE CHOOSE AGAIN!\n");
                    continue;
                }

                switch (choice) {
                case 1:
                    do {
                        printf(" LAB 1: %.2f", students[i].lab1);
                        printf("\n ENTER THE NEW SCORE FOR LAB 1: ");
                        if (scanf("%f", &students[i].lab1) != 1 || students[i].lab1 < 0 || students[i].lab1 > 10) {
                            printf(" INVALID SCORE! PLEASE ENTER AGAIN!\n");
                            while (getchar() != '\n');
                        }
                        else{
                            break;
                        }
                    } while (1);
                    break;
                case 2:
                    do {
                        printf(" LAB 2: %.2f", students[i].lab2);
                        printf("\n ENTER THE NEW SCORE FOR LAB 2: ");
                        if (scanf("%f", &students[i].lab2) != 1 || students[i].lab2 < 0 || students[i].lab2 > 10) {
                            printf(" INVALID SCORE! PLEASE ENTER AGAIN!\n");
                            while (getchar() != '\n');
                        }
                        else {
                            break;
                        }
                    } while (1);
                    break;
                case 3:
                    do {
                        printf(" PROGRESS TEST 1: %.2f", students[i].progress_test1);
                        printf("\n ENTER THE NEW SCORE FOR PROGRESS TEST 1: ");
                        if (scanf("%f", &students[i].progress_test1) != 1 || students[i].progress_test1 < 0 || students[i].progress_test1 > 10) {
                            printf(" INVALID SCORE! PLEASE ENTER AGAIN!\n");
                            while (getchar() != '\n');
                        }
                        else {
                            break;
                        }
                    } while (1);
                    break;
                case 4:
                    do {
                        printf(" PROGRESS TEST 2: %.2f", students[i].progress_test2);
                        printf("\n ENTER THE NEW SCORE FOR PROGRESS TEST 2: ");
                        if (scanf("%f", &students[i].progress_test2) != 1 || students[i].progress_test2 < 0 || students[i].progress_test2 > 10) {
                            printf(" INVALID SCORE! PLEASE ENTER AGAIN!\n");
                            while (getchar() != '\n');
                        }
                        else {
                            break;
                        }
                    } while (1);
                    break;
                case 5:
                    do {
                        printf(" PRESENTATION: %.2f", students[i].presentation);
                        printf("\n ENTER THE NEW SCORE FOR PRESENTATION: ");
                        if (scanf("%f", &students[i].presentation) != 1 || students[i].presentation < 0 || students[i].presentation > 10) {
                            printf(" INVALID SCORE! PLEASE ENTER AGAIN!\n");
                            while (getchar() != '\n');
                        }
                        else {
                            break;
                        }
                    } while (1);
                    break;
                case 6:
                    do {
                        printf(" FINAL TEST: %.2f", students[i].final_test);
                        printf("\n ENTER THE NEW SCORE FOR FINAL TEST: ");
                        if (scanf("%f", &students[i].final_test) != 1 || students[i].final_test < 0 || students[i].final_test > 10) {
                            printf(" INVALID SCORE! PLEASE ENTER AGAIN!\n");
                            while (getchar() != '\n');
                        }
                        else {
                            break;
                        }
                    } while (1);
                    break;
                case 7:
                    printf(" RETURN TO MENU...\n");
                    printf("\n PRESS ENTER TO CONTINUE...\n");
                    while (getchar() != '\n'); // doi nguoi dung nhan Enter
                    system("cls");
                    break;
                }

                if (choice >= 1 && choice <= 6) {
                    calculating();
                    printf("\n THE GRADE FOR STUDENT WITH ID %s HAS BEEN UPDATED.\n", id);
                    printf("\n PRESS ENTER TO CONTINUE...\n\n");
                    do {
                        ch = getch();
                    } while (ch != 13);
                    system("cls");
                }

                if (choice >= 1 && choice <= 6) {
                    getchar();
                }

            } while (choice != 7);
            break;
        }
    }

    if (!found) {
        printf("\n STUDENT WITH ID %s NOT FOUND.\n", id);
        printf("\n PRESS ENTER TO CONTINUE...\n\n");


        do {
            ch = getch();
        } while (ch != 13);
        system("cls");
    }
}

//  hien thi tieu de ung voi moi cot diem khi hien thi tren console
void displayColumn() {
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("%-10s %-20s %-10s %-10s %-10s %-10s %-15s %-10s %-10s %-10s\n",
           "Ma SV", "Ten", "Lab 1", "Lab 2", "PT 1", "PT 2", "Presentation", "Final", "Average", "Grade");
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
}

void displayInformation(Student sv) {
    printf("%-10s %-20s %-10.2f %-10.2f %-10.2f %-10.2f %-15.2f %-10.2f %-10.2f %-10c\n",
           sv.id, sv.name, sv.lab1, sv.lab2, sv.progress_test1, sv.progress_test2, sv.presentation, sv.final_test, sv.average, sv.grade);
}

void displayList(Student *ds, int slsv) {
    system("cls");
    calculating();
    printf("\n STUDENT LIST:\n");
    displayColumn();
    for (int i = 0; i < slsv; i++) {
        displayInformation(ds[i]);
    }
    printf("-----------------------------------------------------------------------------------------------------------------------\n");

    printf("\n PRESS ENTER TO CONTINUE...\n\n");
    while (getchar() != '\n');
    system("cls");
}

int linearSearch(char id[]) {
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].id, id) == 0) {
            return i;
        }
    }
    return -1; // Khong tim thay sinh vien
}

void viewScores(char id[]) {
    system("cls");
    int ch;
    calculating();
    int index = linearSearch(id);
    if (index != -1) {
        printf("\n STUDENT'S INFORMATION:\n");
        displayColumn();
        displayInformation(students[index]);
        printf("-----------------------------------------------------------------------------------------------------------------------\n");
    }
    else {
        printf("\n STUDENT WITH ID %s NOT FOUND.\n", id);
    }
    printf("\n PRESS ENTER TO CONTINUE...\n\n");
    do {
        ch = getch();
    } while (ch != 13);
    system("cls");
}

void merge(Student arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    //  tao mang tam thoi de luu 2 nua mang goc
    Student Left[n1], Right[n2];
    //  sao chep du lieu vao cac mang tam thoi left right
    for (i = 0; i < n1; i++)
        Left[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        Right[j] = arr[mid + 1 + j];
    i = 0;    //  chi so ban dau cua mang left
    j = 0;    //  chi so ban dau cua mang right
    k = left; // chi so ban dau cua mang sau khi gop
    //  gop cac mang tam thoi lai thanh mang arr
    while (i < n1 && j < n2) {
        if (Left[i].average >= Right[j].average) {
            arr[k] = Left[i];
            i++;
        }
        else {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }
    //  sao chep cac phan tu con lai cua left
    while (i < n1) {
        arr[k] = Left[i];
        i++;
        k++;
    }
    //  sao chep cac phan tu con lai cua right
    while (j < n2) {
        arr[k] = Right[j];
        j++;
        k++;
    }
}

//  ham sap xep sinh vien theo diem trung binh
void mergeSort(Student arr[], int left, int right) {
    if (left < right) {
        //  tim chi so o giua de chia doi mang
        int mid = left + (right - left) / 2;
        //  de quy sap xep mang 1
        mergeSort(arr, left, mid);
        //  de quy sap xep mang 2
        mergeSort(arr, mid + 1, right);
        //  gop 2 mang da sap xep
        merge(arr, left, mid, right);
    }
}

void arrangement() {
    //  tinh diem trung binh
    calculating();

    //  sap xep sinh vien theo diem trung binh
    mergeSort(students, 0, studentCount - 1);

    printf(" THE STUDENT LIST HAS BEEN SORTED BY AVERAGE SCORE.\n");
    printf("\n PRESS ENTER TO SHOW THE LIST...\n\n");
    while (getchar() != '\n');

    displayList(students, studentCount);
}

void inputFile() {
    int choice;
    char fileName[100];
    char input[10];
    do {
        printf("\n ======================================================================================================================\n");
        printf(" |                                                                                                                    |\n");
        printf(" |                                1. OPEN AN EXISTING FILE                                                            |\n");
        printf(" |                                2. IF FILE DOES NOT EXIST, PRESS ENTER TO ENTER DATA                                |\n");
        printf(" ======================================================================================================================\n");
        printf("\n PLEASE CHOOSE A NUMBER: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (isNumber(input)) {
            choice = atoi(input);
        }
        else {
            choice = -1;
        }

        printf("\n");

        switch (choice) {
        case 1:
            printf(" ENTER THE FILE'S NAME TO OPEN: ");
            fgets(fileName, sizeof(fileName), stdin);
            fileName[strcspn(fileName, "\n")] = 0; //  tim ki tu xuong dong (\n) va loai bo
            readFromFile(fileName);
            displayMenu();
            break;
        case 2:
            continue;
        default:
            printf(" INVALID CHOICE! PLEASE CHOOSE AGAIN!\n");
        }
    } while (choice != 2);
}

//  doc sinh vien tu file va luu vao mang students
void readFromFile(char *fileName)
{
    FILE *file = fopen(fileName, "r"); //  mo file de doc
    if (file == NULL) {
        printf(" CANNOT OPEN FILE %s.\n", fileName);
        exit(1);
    }
    else {
        printf(" SUCCESSFULLY OPEN FILE %s\n", fileName);
        printf("\n PRESS ENTER TO CONTINUE...");
        getch();
    }
    char line[256];                         // bien de luu tung dong doc duoc tu file
    while (fgets(line, sizeof(line), file)) { //  doc tu dong tu file
        Student newStudent;
        sscanf(line, "%49[^;];;%49[^;];;%f;;%f;;%f;;%f;;%f;;%f \n",
               newStudent.id, newStudent.name, &newStudent.lab1, &newStudent.lab2,
               &newStudent.progress_test1, &newStudent.progress_test2,
               &newStudent.presentation, &newStudent.final_test);

        if (studentCount < MAX_STUDENTS) {
            students[studentCount++] = newStudent;
        }
        else {
            printf(" EXCEEDED THE MAXIMUM NUMBER OF STUDENTS!\n");
            break;
        }

        if (studentCount == 1) {
            displayColumn();
        }

        displayInformation(newStudent);
    }
    calculating();
    fclose(file);
}

//  luu danh sach sinh vien vao file
void saveToFile(char *fileName) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf(" CANNOT SAVE TO FILE %s.\n", fileName);
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        //  ghi thong tin sinh vien vao file
        fprintf(file, "%s;;%s;;%.2f;;%.2f;;%.2f;;%.2f;;%.2f;;%.2f \n",
                students[i].id, students[i].name, students[i].lab1, students[i].lab2,
                students[i].progress_test1, students[i].progress_test2,
                students[i].presentation, students[i].final_test);
    }

    fclose(file);
    printf(" THE DATA HAS BEEN SAVED INTO THE FILE %s.\n", fileName);
}

void logo() {
    char ch;
    printf("\n   ___________________________________________________________________________________________________________________ \n");
    printf("  |                                                                                                                   |\n");
    printf("  |                                          MINISTRY OF EDUCATION AND TRAINING                                       |\n");
    printf("  |                             UNIVERSITY OF SCIENCE AND TECHNOLOGY-UNIVERSITY OF DA NANG                            |\n");
    printf("  |                                                  _______________                                                  |\n");
    printf("  |                                                                                                                   |\n");
    printf("  |                                          Lecturer       : Tran Ho Thuy Tien                                       |\n");
    printf("  |                                                                                                                   |\n");
    printf("  |                                          Project        : PBL1-Quan Ly Diem Sinh Vien                             |\n");
    printf("  |                                                                                                                   |\n");
    printf("  |                                          Students       : Nguyen Trung Kien                                       |\n");
    printf("  |                                                           Mai Phuc Thinh                                          |\n");
    printf("  |                                                                                                                   |\n");
    printf("  |                                          Section Class  : 23.99A                                                  |\n");
    printf("  |                                                                                                                   |\n");
    printf("  |                                          Activity Class : 23T_Nhat1                                               |\n");
    printf("  |                                                                                                                   |\n");
    printf("  |                                          Da Nang, Ngay 26 thang 06 nam 2024                                       |\n");
    printf("  |                                                                                                                   |\n");
    printf("  |___________________________________________________________________________________________________________________|\n");
    printf("\n");

    printf(" PRESS ENTER TO START\n");
    do {
        ch = getch();
    } while (ch != 13);
    system("cls");
}

void displayMenu() {
    system("cls");
    int choice;
    char id[20];
    char fileName[100];
    char input[10];

    do {
        printf(" _____________________________________________________________________________________________________________________\n");
        printf("|                                                                                                                     |\n");
        printf("|                                                       MENU                                                          |\n");
        printf("|_____________________________________________________________________________________________________________________|\n");
        printf("|                                                                                                                     |\n");
        printf("|                                          1. ENTER SCORES                                                            |\n");
        printf("|                                          2. VIEW SCORES                                                             |\n");
        printf("|                                          3. UPDATE SCORES                                                           |\n");
        printf("|                                          4. SORT STUDENTS BY AVERAGE SCORE                                          |\n");
        printf("|                                          5. PRINT STUDENT LIST                                                      |\n");
        printf("|                                          6. SAVE AND EXIT                                                           |\n");
        printf("|_____________________________________________________________________________________________________________________|\n");
        printf(" PLEASE CHOOSE A NUMBER: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (isNumber(input)) {
            choice = atoi(input);
        }
        else {
            choice = -1;
        }

        printf("\n");

        switch (choice) {
        case 1:
            enterScores();
            break;
        case 2:
            printf(" ENTER STUDENT ID: ");
            scanf("%s", id);
            getchar();
            viewScores(id);
            break;
        case 3:
            printf(" ENTER STUDENT ID: ");
            scanf("%s", id);
            getchar();
            updateScores(id);
            break;
        case 4:
            arrangement();
            break;
        case 5:
            displayList(students, studentCount);
            break;
        case 6:
            printf(" ENTER THE FILE'S NAME: ");
            fgets(fileName, sizeof(fileName), stdin);
            fileName[strcspn(fileName, "\n")] = 0;
            saveToFile(fileName);
            printf("\n EXIT!!!\n");
            exit(1);
        default:
            printf(" INVALID CHOICE! PLEASE CHOOSE AGAIN!\n");
        }
    } while (choice != 6);
}