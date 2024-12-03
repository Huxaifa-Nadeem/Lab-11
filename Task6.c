#include <stdio.h>
#include <stdlib.h>

struct Address {
    char city[50];
    int zip_code;
};

struct Employee {
    char name[50];
    int id;
    float salary;
    struct Address address;
};

void writeEmployeesToFile(struct Employee employees[], int count) {
    FILE *file = fopen("employees.dat", "wb");
    fwrite(&count, sizeof(int), 1, file);
    fwrite(employees, sizeof(struct Employee), count, file);
    fclose(file);
}

void readEmployeesFromFile() {
    FILE *file = fopen("employees.dat", "rb");
    int count;
    fread(&count, sizeof(int), 1, file);
    
    struct Employee employee;
    while (fread(&employee, sizeof(struct Employee), 1, file)) {
        printf("Name: %s\n", employee.name);
        printf("ID: %d\n", employee.id);
        printf("Salary: %.2f\n", employee.salary);
        printf("City: %s\n", employee.address.city);
        printf("Zip Code: %d\n\n", employee.address.zip_code);
    }
    fclose(file);
}

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee employees[n];
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        printf("Name: ");
        getchar();
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = '\0';

        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);

        printf("City: ");
        getchar();
        fgets(employees[i].address.city, sizeof(employees[i].address.city), stdin);
        employees[i].address.city[strcspn(employees[i].address.city, "\n")] = '\0';

        printf("Zip Code: ");
        scanf("%d", &employees[i].address.zip_code);
    }

    writeEmployeesToFile(employees, n);
    printf("\nEmployee data written to file.\n");

    printf("\nReading employee data from file:\n");
    readEmployeesFromFile();

    return 0;
}
