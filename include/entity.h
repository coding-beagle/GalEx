#ifndef ENTITY_H
#define ENTITY_H

#include "raylib.h"
#include "custom_types.h"
#include "stdio.h"

typedef struct EntityData_T
{
    char name[30];
    int ID;

    System HomeSystem;

    // Resource Data
    ResourceCapacityVector CurrentResources;
    ResourceFlowVector CurrentResourceFlows;

    // Entity Characteristics
    float DevelopmentIndex; // 0.0 - 1.0, dictates the demand for luxury + advanced resources
} EntityData_T;

void init_entity(EntityData_T* entity, char* name, int ID, System system, float development);

void cleanup_entity(EntityData_T* entity);

void entity_add_trade_flow(EntityData_T* entity, RESOURCES resourceID, float rate, float price, int partner, FLOW_TYPES flow_type);

// return -1 if not found
int entity_get_resource_quantity(EntityData_T* entity, RESOURCES resourceID);

void entity_process_flows(EntityData_T* entity);  // Apply flows to storage

void DEBUG_print_entity_stats(EntityData_T* entity);


#endif