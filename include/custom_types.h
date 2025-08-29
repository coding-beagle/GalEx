#ifndef CUSTOM_TYPES_H
#define CUSTOM_TYPES_H

typedef enum {
    PRODUCTION, CONSUMPTION, TRADE_IN, TRADE_OUT
} FLOW_TYPES;

typedef enum {
    AGRICULTURE, ORES, REFINED_GOODS, LUXURY_GOODS, CREDITS, POPULATION
} RESOURCES;

typedef struct ResourceFlow {
    RESOURCES ResourceID;
    float FlowRate;        // Positive = production/income, Negative = consumption/expense
    float UnitCost;        // Cost per unit (positive for expenses, negative for income)
    int CounterpartyID;    // Who you're trading with (0 for internal production/consumption)
    FLOW_TYPES FlowType;          // PRODUCTION, CONSUMPTION, TRADE_IN, TRADE_OUT
} ResourceFlow;

typedef struct ResourceFlowVector {
    ResourceFlow ** flows;  
    int FlowCount;
} ResourceFlowVector;

typedef struct ResourceCapacity {
    RESOURCES ResourceID;
    double StoredQuantity;
} ResourceCapacity;

typedef struct ResourceCapacityVector {
    ResourceCapacity ** capacity;  
    int ResourceTypeCount;
} ResourceCapacityVector;

typedef struct System {
    int SystemID;
    int SystemX; // System Grid Coordinates
    int SystemY;
} System;

void init_resource_flow_vector(ResourceFlowVector* vector);

void free_resource_flow_vector(ResourceFlowVector* vector);

void add_resource_flow(ResourceFlowVector* vector, ResourceFlow flow);

void remove_resource_flow(ResourceFlowVector* vector, RESOURCES resourceID);

void DEBUG_print_resource_flow(ResourceFlowVector* vector, char* name);

void init_resource_capacity_vector(ResourceCapacityVector* vector);

void free_resource_capacity_vector(ResourceCapacityVector* vector);

void add_resource_capacity(ResourceCapacityVector* vector, ResourceCapacity res_capacity);

// returns index if in, -1 if not in
int check_resource_in_capacity(ResourceCapacityVector* vector, RESOURCES resourceID);

void remove_resource_capacity(ResourceCapacityVector* vector, RESOURCES resourceID);

void flow_type_to_text_buffer(char* buff, FLOW_TYPES flow_type);

void resourceID_to_text_buffer(char* buff, RESOURCES resourceID);

#endif