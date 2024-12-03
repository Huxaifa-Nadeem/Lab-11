#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Event {
    char event_name[100];
    struct Date date;
    char location[100];
};

void displayEventDetails(struct Event event) {
    printf("Event: %s\n", event.event_name);
    printf("Date: %02d/%02d/%d\n", event.date.day, event.date.month, event.date.year);
    printf("Location: %s\n", event.location);
}

int main() {
    struct Event event1 = {"Music Concert", {25, 12, 2024}, "Madison Square Garden"};
    struct Event event2 = {"Tech Conference", {15, 9, 2024}, "Silicon Valley"};

    displayEventDetails(event1);
    printf("\n");
    displayEventDetails(event2);

    return 0;
}
