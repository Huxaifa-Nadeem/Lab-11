#include <stdio.h>

struct Marks {
    int maths;
    int science;
    int english;
};

struct Student {
    int roll_no;
    char name[50];
    struct Marks marks;
};

float calculateAverage(struct Marks marks) {
    return (marks.maths + marks.science + marks.english) / 3.0;
}

int main() {
    struct Student students[5];

    for (int i = 0; i < 5; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].roll_no);
        printf("Name: ");
        getchar();
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';
        printf("Marks (Maths, Science, English): ");
        scanf("%d %d %d", &students[i].marks.maths, &students[i].marks.science, &students[i].marks.english);
    }

    for (int i = 0; i < 5; i++) {
        float avg = calculateAverage(students[i].marks);
        printf("Roll No: %d\n", students[i].roll_no);
        printf("Name: %s\n", students[i].name);
        printf("Average Marks: %.2f\n\n", avg);
    }

    return 0;
}
