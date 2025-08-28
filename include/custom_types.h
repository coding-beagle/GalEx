#ifndef CUSTOM_TYPES_H
#define CUSTOM_TYPES_H

enum FLOW_TYPES {
    PRODUCTION, CONSUMPTION, TRADE_IN, TRADE_OUT
};

enum RESOURCES {
    AGRICULTURE, ORES, REFINED_GOODS, LUXURY_GOODS, CREDITS
};

struct ResourceFlow {
    int ResourceID;
    float FlowRate;        // Positive = production/income, Negative = consumption/expense
    float UnitCost;        // Cost per unit (positive for expenses, negative for income)
    int CounterpartyID;    // Who you're trading with (0 for internal production/consumption)
    int FlowType;          // PRODUCTION, CONSUMPTION, TRADE_IN, TRADE_OUT
};

struct ResourceFlowVector {
    ResourceFlow ** flows;  
    int FlowCount;
};

struct ResourceCapacity {
    int ResourceID;
    int StoredQuantity;
};

struct ResourceCapacityVector {
    ResourceCapacity ** capacity;  
    int ResourceTypeCount;
};

struct System {
    int SystemID;
    int SystemX; // System Grid Coordinates
    int SystemY;
};

void init_resource_flow_vector(ResourceFlowVector* vector);

void free_resource_flow_vector(ResourceFlowVector* vector);

void add_resource_flow(ResourceFlowVector* vector, ResourceFlow flow);

void remove_resource_flow(ResourceFlowVector* vector, int index);

void resize_flow_vector(ResourceFlowVector* vector, int new_capacity);

void init_resource_capacity_vector(ResourceCapacityVector* vector);

void free_resource_capacity_vector(ResourceCapacityVector* vector);

void add_resource_capacity(ResourceCapacityVector* vector, ResourceCapacity flow);

void remove_resource_capacity(ResourceCapacityVector* vector, int index);

void resize_resource_capacity(ResourceCapacityVector* vector, int new_capacity);

#endif