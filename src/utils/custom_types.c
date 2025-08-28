#include "custom_types.h"
#include "stdlib.h"
#include "stdio.h"

void init_resource_flow_vector(ResourceFlowVector* vector) {\
    vector->flows = NULL;
    vector->FlowCount = 0;
}

void free_resource_flow_vector(ResourceFlowVector* vector) {
    free(vector->flows);
    vector -> FlowCount = 0;
}

void add_resource_flow(ResourceFlowVector* vector, ResourceFlow flow) {
    if(vector->flows == NULL){
        printf("Flow is nullptr, allocating %d\n", sizeof(ResourceFlow*));
        vector->flows = malloc(sizeof(ResourceFlow*));
    } else {
        ResourceFlow** temp = realloc(vector->flows, sizeof(ResourceFlow*) * (vector->FlowCount + 1));
        if (temp == NULL) {
            printf("Realloc failed!");
            return;
        }
        vector->flows = temp;
    }
    
    if (vector->flows != NULL) {
        printf("Adding flow to %d\n", vector->FlowCount);
        // Allocate memory for the new flow and copy it
        vector->flows[vector->FlowCount] = malloc(sizeof(ResourceFlow));
        if (vector->flows[vector->FlowCount] != NULL) {
            *(vector->flows[vector->FlowCount]) = flow;
            printf("Flow has been added!\n");
            vector->FlowCount++;
        }
    } else {
        printf("PTR Allocation Failed!");
    }
}

void remove_resource_flow(ResourceFlowVector* vector, int resourceID){
    for(int i = 0; i < vector->FlowCount; i++){
        if((*vector->flows)[i].ResourceID == resourceID){
            // Shift remaining elements
            for(int j = i; j < vector->FlowCount - 1; j++){
                vector->flows[j] = vector->flows[j + 1];
            }
            vector->FlowCount--;
            
            // Reallocate to smaller size
            if(vector->FlowCount > 0){
                vector->flows = realloc(vector->flows, sizeof(ResourceFlow) * vector->FlowCount);
            } else {
                free(vector->flows);
                vector->flows = NULL;
            }
            return;  // Found and removed, exit
        }
    }
}

void DEBUG_print_resource_flow(ResourceFlowVector* vector, char* name){
    char debug_string[30];
    sprintf(debug_string, "DEBUGGING %s", name);
    printf(debug_string);
    for(int i = 0; i < vector->FlowCount; i++){
        printf("\tFlow %d\n", i);
        printf("\tResourceID = %d\n", (vector->flows)[i]->ResourceID);
        printf("\tFlowRate = %f\n", (vector->flows)[i]->FlowRate);
        printf("\tUnitCost = %f\n", (vector->flows)[i]->UnitCost);
        printf("\tCounterpartyID = %d\n", (vector->flows)[i]->CounterpartyID);
        printf("\tFlowType = %d\n", (vector->flows)[i]->FlowType);
    }
}


void init_resource_capacity_vector(ResourceCapacityVector* vector){
    vector->capacity = NULL;
    vector->ResourceTypeCount = 0;
}

void free_resource_capacity_vector(ResourceCapacityVector* vector){
    free(vector->capacity);
    vector -> ResourceTypeCount = 0;
}

void add_resource_capacity(ResourceCapacityVector* vector, ResourceCapacity flow){
    if(vector->capacity == NULL){
        printf("Flow is nullptr, allocating %d\n", sizeof(ResourceCapacity*));
        vector->capacity = malloc(sizeof(ResourceFlow*));
    } else {
        ResourceCapacity** temp = realloc(vector->capacity, sizeof(ResourceCapacity*) * (vector->ResourceTypeCount + 1));
        if (temp == NULL) {
            printf("Realloc failed!");
            return;
        }
        vector->capacity = temp;
    }
    
    if (vector->capacity != NULL) {
        // Allocate memory for the new capacity and copy it
        vector->capacity[vector->ResourceTypeCount] = malloc(sizeof(ResourceCapacity));
        if (vector->capacity[vector->ResourceTypeCount] != NULL) {
            *(vector->capacity[vector->ResourceTypeCount]) = flow;
            vector->ResourceTypeCount++;
        }
    } else {
        printf("PTR Allocation Failed!");
    }
}

void remove_resource_capacity(ResourceCapacityVector* vector, int resourceID){
    for(int i = 0; i < vector->ResourceTypeCount; i++){
        if((*vector->capacity)[i].ResourceID == resourceID){
            // Shift remaining elements
            for(int j = i; j < vector->ResourceTypeCount - 1; j++){
                vector->capacity[j] = vector->capacity[j + 1];
            }
            vector->ResourceTypeCount--;
            
            // Reallocate to smaller size
            if(vector->ResourceTypeCount > 0){
                vector->capacity = realloc(vector->capacity, sizeof(ResourceCapacity) * vector->ResourceTypeCount);
            } else {
                free(vector->capacity);
                vector->capacity = NULL;
            }
            return;  // Found and removed, exit
        }
    }
}
