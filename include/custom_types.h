#ifndef CUSTOM_TYPES_H
#define CUSTOM_TYPES_H

typedef enum {
    PRODUCTION, CONSUMPTION, TRADE_IN, TRADE_OUT
} FLOW_TYPES;

typedef enum {
    AGRICULTURE, ORES, REFINED_GOODS, LUXURY_GOODS, CREDITS
} RESOURCES;

typedef struct ResourceFlow {
    int ResourceID;
    float FlowRate;        // Positive = production/income, Negative = consumption/expense
    float UnitCost;        // Cost per unit (positive for expenses, negative for income)
    int CounterpartyID;    // Who you're trading with (0 for internal production/consumption)
    int FlowType;          // PRODUCTION, CONSUMPTION, TRADE_IN, TRADE_OUT
} ResourceFlow;

typedef struct ResourceFlowVector {
    ResourceFlow ** flows;  
    int FlowCount;
} ResourceFlowVector;

typedef struct ResourceCapacity {
    int ResourceID;
    int StoredQuantity;
} ResourceCapacity;

typedef struct ResourceCapacityVector {
    ResourceCapacity ** capacity;  
    int ResourceTypeCount;
} ResourceCapacityVector;

struct System {
    int SystemID;
    int SystemX; // System Grid Coordinates
    int SystemY;
};

void init_resource_flow_vector(ResourceFlowVector* vector);

void free_resource_flow_vector(ResourceFlowVector* vector);

void add_resource_flow(ResourceFlowVector* vector, ResourceFlow flow);

void remove_resource_flow(ResourceFlowVector* vector, int resourceID);

void DEBUG_print_resource_flow(ResourceFlowVector* vector, char* name);

void init_resource_capacity_vector(ResourceCapacityVector* vector);

void free_resource_capacity_vector(ResourceCapacityVector* vector);

void add_resource_capacity(ResourceCapacityVector* vector, ResourceCapacity flow);

void remove_resource_capacity(ResourceCapacityVector* vector, int resourceID);

#endif