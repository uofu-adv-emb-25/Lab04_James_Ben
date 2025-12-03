#include "signaling.h"
#include "fifo.h"

#include <stdio.h>

void signal_handle_calculation(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data)
{
    // TASK 2
    xSemaphoreTake(request, portMAX_DELAY);
    
    printf("Task2: From task2, data-> input is %d\n", data->input);
    data->output = data->input + 5;
    xSemaphoreGive(response);
}

BaseType_t signal_request_calculate(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data)
{
    //  TASK 1
    printf("Task1: From task1, data input is: %d\n", data->input);
    xSemaphoreGive(request);
    BaseType_t result = xSemaphoreTake(response, 666);
    
    return result;
    
}

void fifo_worker_handler(QueueHandle_t requests, QueueHandle_t results, int id)
{
    while(1)
    {
        struct request_msg input_data = {};

        // take input struct from the requests queue
        xQueueReceive(requests, &input_data, portMAX_DELAY);

        input_data.output = input_data.input + 5;
        input_data.handled_by = id;

        // send altered struct to the results queue
        xQueueSend(results, &input_data, portMAX_DELAY);
    }
}