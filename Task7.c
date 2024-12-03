#include <stdio.h>

struct Company {
    char name[100];
    int year_established;
    char departments[5][50];
};

void displayCompanyDetails(struct Company company) {
    printf("Company Name: %s\n", company.name);
    printf("Year Established: %d\n", company.year_established);
    printf("Departments:\n");
    for (int i = 0; i < 5; i++) {
        if (company.departments[i][0] != '\0') {
            printf("- %s\n", company.departments[i]);
        }
    }
}

int main() {
    struct Company company;

    printf("Enter company name: ");
    fgets(company.name, sizeof(company.name), stdin);
    company.name[strcspn(company.name, "\n")] = '\0';

    printf("Enter year established: ");
    scanf("%d", &company.year_established);
    getchar();

    printf("Enter up to 5 departments:\n");
    for (int i = 0; i < 5; i++) {
        printf("Department %d: ", i + 1);
        fgets(company.departments[i], sizeof(company.departments[i]), stdin);
        company.departments[i][strcspn(company.departments[i], "\n")] = '\0';
        if (company.departments[i][0] == '\0') break;
    }

    displayCompanyDetails(company);

    return 0;
}
