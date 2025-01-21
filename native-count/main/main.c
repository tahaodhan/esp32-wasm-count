#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h" // For high-resolution timing

void count_to_million(void *param) {
    printf("Beginning counting...\n");

    int64_t start_time = esp_timer_get_time(); // Record the start time
    for (int i = 1; i <= 1000000; i++) {
        if (i % 100000 == 0) {
            printf("Counted to: %d\n", i);
        }
    }
    int64_t end_time = esp_timer_get_time(); // Record the end time

    // Calculate and print elapsed time in milliseconds
    printf("Reached: 1000000\n");
    printf("Time taken: %lld ms\n", (end_time - start_time) / 1000);

    vTaskDelete(NULL); // End the task when done
}

void app_main(void) {
    printf("Starting counting task...\n");
    xTaskCreate(count_to_million, "CountTask", 2048, NULL, 5, NULL);
}
