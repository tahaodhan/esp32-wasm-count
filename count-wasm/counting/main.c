#include <stdio.h>
#include <stdint.h>
#include <time.h>

void count_to_million() {
    printf("Starting counting to 1 million...\n");

    // Start timing
    clock_t start_time = clock();

    // Count to 1 million
    for (int i = 1; i <= 1000000; i++) {
        if (i % 100000 == 0) {
            printf("Reached: %d\n", i);
        }
    }

    // End timing
    clock_t end_time = clock();

    // Calculate elapsed time in milliseconds
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;
    printf("Finished counting to 1 million.\n");
    printf("Time taken: %.2f ms\n", elapsed_time);
}

int main() {
    count_to_million();
    return 0;
}
