#include "include/dynamicStringList.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



// Function to shuffle an array of integers
void shuffle(int *array, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
}

// also why int main? cant we just use void
int main() {
    StringList list;
    initStringList(&list);

    // Add parts to the list
    addString(&list, "Power Elevator");
    addString(&list, "Looping");
    addString(&list, "Trampoline");
    addString(&list, "Power Lift");
    addString(&list, "Jumper");
    addString(&list, "Catapult");
    addString(&list, "Transfer");
    addString(&list, "Lift");
    addString(&list, "Scoop");
    addString(&list, "Tunnel");
    addString(&list, "Bridges");
    addString(&list, "Magnetic Cannon");
    addString(&list, "Releaser");
    addString(&list, "Power Starter");
    addString(&list, "Power Finish");
    addString(&list, "Flextube");
    addString(&list, "Turnable");

    int amount_of_pieces;
    char amount_of_pieces_char[100]; //only for scanf

    printf("How many pieces? ");
    scanf("%s", amount_of_pieces_char); // Read input as string

    amount_of_pieces = atoi(amount_of_pieces_char);

    if (amount_of_pieces <= 0 || amount_of_pieces > list.size) {
        printf("Invalid input\n");
        return 1;
    }

    // Allocate memory for an array of indices
    int *indices = (int *)malloc(list.size * sizeof(int));
    if (indices == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize the array of indices
    for (int i = 0; i < list.size; i++) {
        indices[i] = i;
    }

    srand(time(NULL));
    shuffle(indices, list.size); // Shuffle the array of indices

    // Print the randomly selected elements
    printf("Randomly selected elements:\n");
    for (int i = 0; i < amount_of_pieces; i++) {
        printf("%s\n", list.data[indices[i]]);
    }

    // Free the memory allocated for the array of indices
    free(indices);

    // Free the memory allocated for the list
    freeStringList(&list);

    return 0;
}
