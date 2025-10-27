#include <stddef.h>
#include <stdio.h>

#define SIZE 10

//Multipurpose bubble sort; parameter compare is a pointer to
//the comparison function that determines sorting order
void bubblesort(int work[], size_t size, int(*compare)(int a, int b));
void bubblesort2(char work[], size_t size, char(*compare)(char a, char b));

//determine whether numbers or letters are out of order for an ascending order sort
int ascending(int a, int b);
char ascending2(char a, char b);

//determine whether numbers or letters are out of order for an ascending order sort
int descending(int a, int b);
char descending2(char a, char b);

int main() {

    int a[SIZE] = {0};
    char b[SIZE] = "";

    printf("***Welcome to the sorting program!***\n\n");

    // Userinput for the numbers in the array
    for(int i = 0; i < SIZE; i++){
        printf("Enter 10 numbers to sort ascending or descending: ");
        scanf("%d", &a[i]);
        printf("\033[2J\033[H"); 
    }

    // prints the chosen numbers
    puts("Numbers written in original order");
    for (size_t counter = 0; counter < SIZE; counter++) {
        printf("%d ", a[counter]);
    }

    puts("");

    //user input for letters
    for (int counter2; counter2 < SIZE; counter2++) {
        printf("Enter 10 letters for me to sort in ascending or descending order: ");
        scanf(" %c", &b[counter2]);
        printf("\033[2J\033[H"); 
    }

    //prints user input
    puts("Numbers and letters written in original order are:");
    for (size_t counter = 0; counter < SIZE; counter++) {
        printf("%d ", a[counter]);
    }

    puts("");

    for (size_t counter2 = 0; counter2 < SIZE; counter2++) {
        printf("%c ", b[counter2]);
    }


    // gives the user a choice between sorting the numbers ascending or descending
    printf("%s", "\n\nEnter 1 to sort in ascending order, \n" 
        "Enter 2 to sort in descending order: ");
    int order = 0;
    scanf("%d", &order);

    if (order == 1) {
        bubblesort(a, SIZE, ascending);
        bubblesort2(b, SIZE, ascending2);
        puts("\nData items in ascending order");
    }
    else {
        bubblesort(a, SIZE, descending);
        bubblesort2(b, SIZE, descending2);
        puts("\nData items in descending order");
    }

    // prints the numbers in the order chosen
    for (size_t counter = 0; counter < SIZE; counter++) {
        printf("%d ", a[counter]);
    }

    puts("");

    for (size_t counter2 = 0; counter2 < SIZE; counter2++) {
        printf("%c ", b[counter2]);
    }

    puts("\n");

    return 0;
}

void bubblesort(int work[], size_t size, int(*compare)(int a, int b)) {
    void swap(int *numberPtr, int *number2Ptr);

    //loop to control passes
    for (int pass = 1; pass < size; pass++) {
        // loop to control number of comparisons per pass
        for (size_t count = 0; count < size - 1; count++) {
            //if adjacent elements are ut of order, swap them
            if ((*compare)(work[count], work[count + 1])) {
                swap(&work[count], &work[count + 1]);
            }
        }
    }
}

void bubblesort2(char work[], size_t size, char(*compare)(char a, char b)) {
    void swap2(char *letterPtr, char *letter2Ptr);

    //loop to control passes
    for (int pass = 1; pass < size; pass++) {
        // loop to control number of comparisons per pass
        for (size_t count = 0; count < size - 1; count++) {
            //if adjacent elements are ut of order, swap them
            if ((*compare)(work[count], work[count + 1])) {
                swap2(&work[count], &work[count + 1]);
            }
        }
    }
}

//swap values at memory locations to which the numberPtr and
//number2Ptr point
void swap(int *numberPtr, int *number2Ptr) {
    int hold = *numberPtr;
    *numberPtr = *number2Ptr;
    *number2Ptr = hold;
}
void swap2(char *letterPtr, char *letter2Ptr) {
    char hold = *letterPtr;
    *letterPtr = *letter2Ptr;
    *letter2Ptr = hold;
}

int ascending(int a, int b) {
    return b < a;
}
char ascending2(char a, char b) {
    return b < a;
}

int descending(int a, int b) {
    return b > a;
}
char descending2(char a, char b) {
    return b > a;
}

