#include "signaling.h"




void signal_handle_calculation(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data)
{
    /* TASK 2
    xSemaphoreTake(request);
    data += 5;
    xSemaphoreGive(response);
    
    */
}

BaseType_t signal_request_calculate(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data)
{
    /*  TASK 1
    xSemaphoreGive(request);
    xSemaphoreTake(response);
    return data;
    
    */
}