#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define STUDENT_MAX     100
#define NAME_MAX_LENGTH 100
#define PATH_MAX     100

//structure declaration
typedef struct
{
    char name[NAME_MAX_LENGTH];
    int grades;
}studentNode;

typedef struct
{
    studentNode studentList[STUDENT_MAX];
    int studentNum;
    double avg;
}gradeNode;

//function declaration
void add_student(gradeNode* myGrades);
void rm_student(gradeNode* myGrades);
void show_student(gradeNode myGrades);
void update_student(gradeNode* myGrades);
void search_student(gradeNode myGrades);

int find_by_grade(studentNode studentList[], int target, int size);
int find_by_name(studentNode studentList[], char target[], int size);
void append_list(int pos, studentNode studentList[], int size);
void remove_list(int pos, studentNode studentList[], int size);
void show_list(gradeNode myGrades);

void save_data(gradeNode* myGrades);
void load_data(gradeNode* myGrades);

int main(void)
{
    char ch;
    gradeNode myGrades;
    myGrades.studentNum = 0;

    while(1)
    {
        printf(" -------------------------------------------------\n");
        printf("| 1. Add a student and his/her score to list.    |\n");
        printf("| 2. Remove a student from list.                 |\n");
        printf("| 3. Show the information of the list.           |\n");
        printf("| 4. Update a student's score.                   |\n");
        printf("| 5. Search a student's score.                   |\n");
        printf("| S. Save student's data.                        |\n");
        printf("| L. Load student's data.                        |\n");
        printf("| 6. Exit.                                       |\n");
        printf(" -------------------------------------------------\n");
        printf("What are you going to do? - ");
        scanf(" %c",&ch);
        switch(ch)
        {
            case '1':
                add_student(&myGrades);
                break;
            case '2':
                rm_student(&myGrades);
                break;
            case '3':
                show_student(myGrades);
                break;
            case '4':
                update_student(&myGrades);
                break;
			case '5':
                search_student(myGrades);
				break;
			case '6':
                return 0;
            case 'S':
                save_data(&myGrades);
                break;
            case 'L':
                load_data(&myGrades);
                break;

            default:
                printf("Wrong input. Please enter an input 1-4.\n");
                break;
        }
        printf("\n");

    }
    return 0;
}

void save_data(gradeNode* myGrades)
{
    FILE *fp;
    char file_name[100];
    printf("save file name:");
    scanf("%s", file_name);
    fp = fopen(file_name, "w");
    if(fp == NULL)
    {
        printf("Can't open %s\n", file_name);
        return;
    }
    else
    {
        fprintf(fp, "%d" , &(*myGrades));
        printf("Save Complete!!");
    }
    fclose(fp);
}

void load_data(gradeNode* myGrades)
{
    FILE *fp;
    char file_name[100];
    char ch;
    int temp;
    printf("Load file name:");
    scanf("%s", file_name);
    fp = fopen(file_name, "r");

    printf("\n");
    if(fp == NULL)
    {
        printf("Can't open %s\n", file_name);
        return;
    }
    else
    {
        fscanf(fp, "%d", &temp);
        printf("Load Complete!!");
    }
    printf("%d", temp);
    myGrades = temp;
    fclose(fp);
}

void add_student(gradeNode* myGrades)
{
    char studentName[NAME_MAX_LENGTH];
    int studentGrade;

    printf("Adding Name: ");
    scanf("%s", studentName);
    printf("Adding grade: ");
    scanf("%d", &studentGrade);

    if(find_by_name(myGrades->studentList, studentName, myGrades->studentNum) != -1)
    {
        printf("Student %s has already been added.\n", studentName);
    }
    else
    {
        int pos = find_by_grade(myGrades->studentList, studentGrade, myGrades->studentNum);
        append_list(pos, myGrades->studentList, myGrades->studentNum);
        myGrades->studentList[pos].grades = studentGrade;
        strcpy(myGrades->studentList[pos].name, studentName);
        myGrades->studentNum++;
    }

}

void rm_student(gradeNode* myGrades)
{
    char studentName[NAME_MAX_LENGTH];
    if(myGrades->studentNum == 0)
    {
        printf("The list has already been empty.\n");
    }
    else
    {
        printf("Removing Name: ");
        scanf("%s", studentName);
        int pos2 = find_by_name(myGrades->studentList, studentName, myGrades->studentNum);
        if(pos2 == -1)
        {
            printf("No such a student called %s.\n", studentName);
        }
        else
        {
            remove_list(pos2, myGrades->studentList, myGrades->studentNum);
            myGrades->studentNum--;
        }
    }
}

void show_student(gradeNode myGrades)
{
    if(myGrades.studentNum == 0)
        printf("The list is empty.\n");
    else
        show_list(myGrades);
}

int find_by_grade(studentNode studentList[], int target, int size)
{
    int i, pos = size;
    for(i = 0 ; i < size ; i++)
    {
        if(studentList[i].grades < target)
        {
            pos = i;
            break;
        }
    }
    return pos;
}

int find_by_name(studentNode studentList[], char target[], int size)
{
    int i, pos = -1;
    for(i = 0 ; i < size ; i++)
    {
        if(!strcmp(target, studentList[i].name))
        {
            pos = i;
        }
    }
    return pos;
}

void append_list(int pos, studentNode studentList[], int size)
{
    int i;
    for(i = size - 1 ; i >= pos ; i--)
    {
        studentList[i+1].grades = studentList[i].grades;
        strcpy(studentList[i+1].name, studentList[i].name);
    }
}

void remove_list(int pos, studentNode studentList[], int size)
{
    int i;
    for(i = pos ; i < size-1 ; i++)
    {
        studentList[i].grades = studentList[i+1].grades;
        strcpy(studentList[i].name, studentList[i+1].name);
    }
}

void show_list(gradeNode myGrades)
{
    int i;
    myGrades.avg = 0.0;
    for(i = 0 ; i< myGrades.studentNum;i++)
    {
        printf("%s\t\t%d\n", myGrades.studentList[i].name, myGrades.studentList[i].grades);
        myGrades.avg += (double)myGrades.studentList[i].grades;
    }

    myGrades.avg /= (double)myGrades.studentNum;
    printf("AVG\t\t%.3lf\n", myGrades.avg);
}
void update_student(gradeNode* myGrades)
{
    char Name[NAME_MAX_LENGTH];
    int i,NewGrade;
    printf("Student Name:");
    scanf("%s",Name);
    for(i=0;i<myGrades->studentNum;i++)
    {
        if(strcmp(myGrades->studentList[i].name,Name)==0)
        {
            printf("Original Grade: %d\nUpdate:",myGrades->studentList[i].grades);
            scanf("%d",&NewGrade);
            //remove
            //myGrades->studentList[i].grades=NewGrade;
            remove_list(i, myGrades->studentList, myGrades->studentNum);
            myGrades->studentNum--;

            //add
            int pos = find_by_grade(myGrades->studentList, NewGrade, myGrades->studentNum);
            append_list(pos, myGrades->studentList, myGrades->studentNum);
            myGrades->studentList[pos].grades = NewGrade;
            strcpy(myGrades->studentList[pos].name, Name);
            myGrades->studentNum++;


            //printf("\n%d",myGrades.studentList[i].grades);
            return;
        }
    }
    printf("No such a student called %s.\n", Name);
}

void search_student(gradeNode myGrades)
{
    char Name[NAME_MAX_LENGTH];
    int i;
    printf("Student Name:");
    scanf("%s",Name);
    for(i=0;i<myGrades.studentNum;i++)
    {
        if(strcmp(myGrades.studentList[i].name,Name)==0)
        {
            printf("%s\t\t%d\n", myGrades.studentList[i].name, myGrades.studentList[i].grades);
            return;
        }
    }
    printf("No such a student called %s.\n", Name);
}
