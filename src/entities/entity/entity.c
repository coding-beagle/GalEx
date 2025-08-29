#include "entity.h"

void init_entity(EntityData_T* entity, char* name, int ID, System system, float development){
    snprintf(entity->name, 30, name);

    entity->ID = ID;
    entity->HomeSystem = system;
    entity->DevelopmentIndex = development;

    init_resource_flow_vector(&entity->CurrentResourceFlows);
    init_resource_capacity_vector(&entity->CurrentResources);
}

void cleanup_entity(EntityData_T* entity){
    free_resource_flow_vector(&entity->CurrentResourceFlows);
    free_resource_capacity_vector(&entity->CurrentResources);
}

void entity_add_trade_flow(EntityData_T* entity, RESOURCES resourceID, float rate, float price, int partner, FLOW_TYPES flow_type){
    ResourceFlow new_flow;

    new_flow.CounterpartyID = partner;
    new_flow.FlowRate = rate;
    new_flow.ResourceID = resourceID;
    new_flow.UnitCost = price;
    new_flow.FlowType = flow_type;

    add_resource_flow(&entity->CurrentResourceFlows, new_flow);
}

int entity_get_resource_quantity(EntityData_T* entity, RESOURCES resourceID){
    for(int i = 0; i< entity->CurrentResources.ResourceTypeCount; i++){
        ResourceCapacity current_cap = *entity->CurrentResources.capacity[i];
        if(resourceID == current_cap.ResourceID){
            return current_cap.StoredQuantity;
        }
    }
    return -1;
}

// transfer everything from the entity's flows into capacity
void entity_process_flows(EntityData_T* entity){
    // iterate over all current resource flows and create capacity if they don't exist,
    // or add to existing capacity if they do
    for(int i = 0; i < entity->CurrentResourceFlows.FlowCount; i++) {
        int check_resource_id = entity->CurrentResourceFlows.flows[i]->ResourceID;
        double resource_amount = entity->CurrentResourceFlows.flows[i]->FlowRate;
        ResourceCapacityVector* capacity_vector = &entity->CurrentResources;
        int in_capacity = check_resource_in_capacity(capacity_vector, check_resource_id);
        if(in_capacity == -1){
            ResourceCapacity new_capacity;
            new_capacity.ResourceID = check_resource_id;
            new_capacity.StoredQuantity = resource_amount;
            add_resource_capacity(capacity_vector, new_capacity);
        } else {
            entity->CurrentResources.capacity[in_capacity]->StoredQuantity += resource_amount;
        }
    }
}

void DEBUG_print_entity_stats(EntityData_T* entity){
    printf("=== Entity Stats: %s (ID: %d) ===\n", entity->name, entity->ID);
    printf("Home System: %d at (%d, %d)\n", 
           entity->HomeSystem.SystemID, 
           entity->HomeSystem.SystemX, 
           entity->HomeSystem.SystemY);
    printf("Development Index: %.2f\n", entity->DevelopmentIndex);
    
    printf("\n--- Current Resources ---\n");
    for(int i = 0; i < entity->CurrentResources.ResourceTypeCount; i++){
        ResourceCapacity* cap = entity->CurrentResources.capacity[i];
        char resource_id_str[20];
        resourceID_to_text_buffer(resource_id_str, cap->ResourceID);
        printf("Resource ID %s: %.2f units\n", resource_id_str, cap->StoredQuantity);
    }
    
    printf("\n--- Current Flows ---\n");
    for(int i = 0; i < entity->CurrentResourceFlows.FlowCount; i++){
        ResourceFlow* flow = entity->CurrentResourceFlows.flows[i];
        char flow_type_str[20];
        char resource_id_str[20];
        flow_type_to_text_buffer(flow_type_str, flow->FlowType);
        resourceID_to_text_buffer(resource_id_str, flow->ResourceID);
        printf("Flow %d: Resource %s, Rate %.2f, Cost %.2f, Partner %d, Type %s\n",
               i, resource_id_str, flow->FlowRate, flow->UnitCost, 
               flow->CounterpartyID, flow_type_str);
    }
    printf("==============================\n\n");
}