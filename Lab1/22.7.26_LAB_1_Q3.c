#include <stdio.h>

struct Employee {
    int emp_id;
    char name[50];
    char designation[50];
    float basic_salary;
    float hra;
    float da;
};

int main() {
    int n;
    printf("Enter no.of employees: ");
    scanf("%d", &n);

    struct Employee emp[n];

    for (int i = 0; i < n; i++) {
        printf("Enter employee %d information:\n", i + 1);
        printf("Emp ID: ");
        scanf("%d", &emp[i].emp_id);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Designation: ");
        scanf("%s", emp[i].designation);
        printf("Basic Salary: ");
        scanf("%f", &emp[i].basic_salary);
        printf("HRA %%: ");
        scanf("%f", &emp[i].hra);
        printf("DA %%: ");
        scanf("%f", &emp[i].da);
    }

    printf("\nEmployee Information:\n");
    for (int i = 0; i < n; i++) {
        float gross_salary = emp[i].basic_salary + (emp[i].basic_salary * emp[i].hra / 100) + (emp[i].basic_salary * emp[i].da / 100);

        printf("\nEmp ID: %d\n", emp[i].emp_id);
        printf("Name: %s\n", emp[i].name);
        printf("Designation: %s\n", emp[i].designation);
        printf("Basic Salary: %.2f\n", emp[i].basic_salary);
        printf("HRA %%: %.0f%%\n", emp[i].hra);
        printf("DA %%: %.0f%%\n", emp[i].da);
        printf("Gross Salary: %.2f\n", gross_salary);
    }

    return 0;
}