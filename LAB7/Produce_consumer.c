#include <stdio.h>
int mutex = 1;
int full = 0;
int empty = 5;
int x = 0;
void wait() {
    mutex--;
}
void signal() {
    mutex++;
}
void producer() {
    wait();
    full++;
    empty--;
    x++;
    printf("Producer has produced: Item %d\n", x);
    signal();
}
void consumer() {
    wait();
    full--;
    empty++;
    printf("Consumer has consumed: Item %d\n", x);
    x--;
    signal();
}
int main() {
    int choice;
    do {
        printf("\n1. Produce\n2. Consume\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if ((mutex == 1) && (empty != 0)) {
                    producer();
                } else {
                    printf("Buffer is full!\n");
                }
                break;
            case 2:
                if ((mutex == 1) && (full != 0)) {
                    consumer();
                } else {
                    printf("Buffer is empty!\n");
                }
                break;
            case 3:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);
    return 0;
}


