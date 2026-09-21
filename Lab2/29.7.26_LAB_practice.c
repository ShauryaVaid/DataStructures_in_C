#include<stdio.h>
#include <string.h>
struct students{
    int total_marks;
    int marks_sub1;
    int marks_sub2;
    int marks_sub3;
    int roll_number;
    int section;
    char name[35];
    int age;
};

void operations(int a,int b,int c,int d,int e,int g,int h,int l){
    int total_percentage=(b+c+d)/(a*3);
    printf("Name entered: %s\n", l);
    printf("student's roll number: %d\n",e);
    printf("student's section: %d\n",g);
    printf("student's age: %d\n",h);
    printf("Total Percentage Scored: %d\n",total_percentage);
    
}


int main(){
    struct students s;
    printf("Enter Name: ");
    scanf("%34s",s.name);
    printf("Enter marks for sub 1, 2 & 3: ");
    scanf("%d%d%d",&s.marks_sub1,&s.marks_sub2,&s.marks_sub3);
    printf("Enter total marks(assuming all the subjects hold equal weightage ): ");
    scanf("%d",&s.total_marks);
    printf("Enter roll number, section, age: ");
    scanf("%d%d%d",&s.roll_number,&s.section,&s.age);
    operations(s.total_marks,
    s.marks_sub1,
    s.marks_sub2,
    s.marks_sub3,
    s.roll_number,
    s.section,
    s.age,s.name);

}    