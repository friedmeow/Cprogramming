#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define STUDENT_MAX     100
#define NAME_MAX_LENGTH 100

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
void arrange_student(gradeNode* myGrades, int grade);
int check_name(char *temp_name, gradeNode myGrades);

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
            default:
                printf("Wrong input. Please enter an input 1-4.\n");
                break;
        }
        printf("\n");
        
    }
    return 0;
}

int check_name(char *temp_name, gradeNode myGrades)
{
    int i;
    
    for( i = 0; i < myGrades.studentNum; i++)
    {
        if(strcmp(temp_name, myGrades.studentList[i].name) == 0)
            return i;
    }
    return -1;
}

void add_student(gradeNode* myGrades)
{
    //**************************
    char temp_name[100];
    int temp_grade = 0, i = 0, j = 0;
    printf("Adding Name:");
    scanf("%s", temp_name);
    if(check_name(temp_name, *myGrades) >= 0)
    {
        printf("Student %s has already been added.", temp_name);
        return;
    }    
    printf("Adding grade:");
    scanf("%d", &temp_grade);
    myGrades->avg += temp_grade;
    for (i = 0; i < myGrades->studentNum; i++)
    {
        if(temp_grade > myGrades->studentList[i].grades)
            break;
    }
    for (j = myGrades->studentNum; j > i; j--)
    {
        strcpy(myGrades->studentList[j].name,myGrades->studentList[j-1].name);
        myGrades->studentList[j].grades = myGrades->studentList[j-1].grades;
    }
    strcpy(myGrades->studentList[j].name, temp_name);
    myGrades->studentList[j].grades = temp_grade;
    myGrades->studentNum++;
    
    //**************************
}

void rm_student(gradeNode* myGrades)
{
    //**************************
    char temp_name[100];
    int i = 0, j = 0;
    printf("Student Name:");
    scanf("%s", temp_name);
    i = check_name(temp_name, *myGrades);
    if(i < 0)
    {
        printf("No such a student called %s.", temp_name);
        return;
    }
    myGrades->avg -= myGrades->studentList[i].grades;
    myGrades->studentNum--;
    for (j = i ; j < myGrades->studentNum ; j++)
    {
        strcpy(myGrades->studentList[j].name,myGrades->studentList[j+1].name);
        myGrades->studentList[j].grades = myGrades->studentList[j+1].grades;
    }

    //**************************
}

void show_student(gradeNode myGrades)
{
    //**************************
    if(myGrades.studentNum == 0)
    {
        printf("The list is empty.");
        return;
    }
    int i = 0;
    for(i = 0; i < myGrades.studentNum; i++)
        printf("%-7s           %-5d\n", myGrades.studentList[i].name, myGrades.studentList[i].grades);
    printf("AVG               %-5.3f\n", myGrades.avg / myGrades.studentNum);

    //**************************
}
void update_student(gradeNode* myGrades)
{
    //**************************
    char temp_name[100];
    int i = 0, temp_grade = 0, j = 0;
    printf("Student Name:");
    scanf("%s", temp_name);
    i = check_name(temp_name, *myGrades);
    if(i < 0)
    {
        printf("No such a student called %s.", temp_name);
        return;
    }
    printf("Original Grade: %d\n", myGrades->studentList[i].grades);
    myGrades->avg -= myGrades->studentList[i].grades;
    printf("Update:");
    scanf("%d", &temp_grade);
    myGrades->avg += temp_grade;
    
    
    for (i = 0; i < myGrades->studentNum; i++)
    {
        if(temp_grade > myGrades->studentList[i].grades)
            break;
    }
    for (j = myGrades->studentNum; j > i; j--)
    {
        strcpy(myGrades->studentList[j].name,myGrades->studentList[j-1].name);
        myGrades->studentList[j].grades = myGrades->studentList[j-1].grades;
    }
    strcpy(myGrades->studentList[i].name, temp_name);
    myGrades->studentList[i].grades = temp_grade;

    //**************************
}

void search_student(gradeNode myGrades)
{
    //**************************
     char temp_name[100];
     int i = 0;
     printf("Student Name:");
     scanf("%s", temp_name);
     i = check_name(temp_name, myGrades);
     if(i < 0)
     {
         printf("No such a student called %s.", temp_name);
         return;
     }
     printf("%-7s           %-5d\n", myGrades.studentList[i].name, myGrades.studentList[i].grades);

     //**************************
}

void arrange_student(gradeNode* myGrades, int grade)
{
    int i = 0, j = 0;
    for (i = 0; i < myGrades->studentNum; i++)
    {
        if(grade > myGrades->studentList[i].grades)
            break;
    }
    for (j = myGrades->studentNum; j > i; j--)
    {
        strcpy(myGrades->studentList[j].name,myGrades->studentList[j-1].name);
        myGrades->studentList[j].grades = myGrades->studentList[j-1].grades;
    }
}

