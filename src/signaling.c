#include "signaling.h"
#include <stdio.h>




void signal_handle_calculation(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data)
{
    // TASK 2
    xSemaphoreTake(request, portMAX_DELAY);
    
    printf("Task2: From task2, data-> input is %d\n", data->input);
    data->output = data->input + 5;
    xSemaphoreTake(response, portMAX_DELAY);

    xSemaphoreGive(request);
    xSemaphoreGive(response);
}

BaseType_t signal_request_calculate(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data)
{
    //  TASK 1
    printf("Task1: From task1, data input is: %d\n", data->input);
    xSemaphoreGive(request);
    xSemaphoreGive(response);
    vTaskDelay(100);
    // Can maybe take bfore updating
    xSemaphoreTake(response, portMAX_DELAY);
    return data->output;
    
}