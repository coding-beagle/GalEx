#ifndef ENTITY_H
#define ENTITY_H

#include "raylib.h"
#include "custom_types.h"

struct EntityData_T
{
    char name[30];
    int ID;

    System HomeSystem;

    // Resource Data
    ResourceCapacityVector CurrentResources;
    ResourceFlowVector CurrentResourceFlows;

    // Entity Characteristics
    float DevelopmentIndex; // 0.0 - 1.0, dictates the demand for luxury + advanced resources
    int Population;         // Logarithmic scalar for resource flows
    int Wealth;             // How much money this entity has
};

void entity_add_trade_flow(EntityData_T* entity, int resourceID, float rate, float price, int partner);
int entity_get_resource_quantity(EntityData_T* entity, int resourceID);

void entity_process_flows(EntityData_T* entity);  // Apply flows to storage


#endif