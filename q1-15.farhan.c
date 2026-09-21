/*Q1. Student Record Management
Write a C program to dynamically allocate memory for N student records using structures and pointers.
Accept the roll number, name, and CGPA of each student. Display the details of the topper.   */
#include<stdio.h>
#include<stdlib.h>
/*typedef struct stu{
    int rollno;
    char name[20];
    float cgpa;
}stu;

int main(){
    int n;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    stu *s= (stu*)malloc(sizeof(stu)*n);
    if(s==NULL){
        printf("Memory not allocated");
        return 1;
    }
    for(int i=0; i<n; i++){
        printf("Enter roll number: ");
        scanf("%d",&s[i].rollno);
        printf("Enter name: ");
        scanf("%19s",&s[i].name);
        printf("Enter cgpa: ");
        scanf("%f",&s[i].cgpa);
    }
    int topper=0;
    for(int i=0; i<n; i++){
        if(s[i].cgpa>s[topper].cgpa){
            topper=i;;
        }
    }
    printf("-----Topper_Details-----\n");
    printf("Name: %19s, Roll no.: %d, CGPA %.2f",s[topper].name,s[topper].rollno,s[topper].cgpa);
}  */

/*Q2. Employee Salary Analysis

Create a structure for employee information. Dynamically allocate memory for N employees using malloc(). Calculate and display:

Highest salary
Lowest salary
Average salary */

/*typedef struct emp{
    int id;
    char name[20];
    float salary;
}emp;

int main(){
    int n;
    printf("Enter number of employees: ");
    scanf("%d",&n);
    emp *s= (emp*)malloc(n*sizeof(emp));
    if(s==NULL){
        printf("Memory not allocated");
        return 1;
    }
    for(int i=0; i<n; i++){
        printf("Enter employee id: ");
        scanf("%d",&s[i].id);
        printf("Enter employee name: ");
        scanf("%19s",s[i].name);
        printf("Enter employee's salary: ");
        scanf("%f",&s[i].salary);
    }
    //Highest salary
    int highest=0;
    for(int i=0; i<n; i++){
        if(s[i].salary>s[highest].salary)
            highest=i;
    }
    printf("Highest salary: %f --> Name: %s, id: %d\n",s[highest].salary,s[highest].name,s[highest].id);

    //Lowest salary
    int lowest=0;
    for(int i=0; i<n; i++){
        if(s[i].salary<s[lowest].salary)
            lowest=i;
    }
    printf("Lowest salary: %f --> Name: %s, id: %d\n",s[lowest].salary,s[lowest].name,s[lowest].id);
    //Average salary
    float sum=0;
    for(int i=0; i<n; i++){
        sum+=s[i].salary;
    }
    printf("Average salary: %f", sum/n);
    free(s);
    return 0;
}*/

/*Q3. Book Inventory
Write a program to dynamically allocate memory for an array of book structures. 
Search for a book using its ID and display its details using pointer notation only.
*/
typedef struct book{
    int id;
    char title[50];
    char author[20];
    float price;
}book;

int main(){
    
    return 0;
}