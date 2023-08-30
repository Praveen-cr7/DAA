#include <stdio.h>
#include <stdbool.h>

#define MAX_CONTAINERS 100
#define MAX_ITEMS 100

void load_containers(int items[], int num_items, int container_limit) {
    int containers[MAX_CONTAINERS][MAX_ITEMS] = {0};
    int container_sizes[MAX_CONTAINERS] = {0};
    
    for (int i = 0; i < num_items; i++) {
        int placed = 0;
        for (int j = 0; j < MAX_CONTAINERS; j++) {
            if (container_sizes[j] + items[i] <= container_limit) {
                containers[j][container_sizes[j]++] = items[i];
                placed = 1;
                break;
            }
        }
        if (!placed) {
            containers[MAX_CONTAINERS - 1][container_sizes[MAX_CONTAINERS - 1]++] = items[i];
        }
    }
    
    // Print the containers and their contents
    for (int i = 0; i < MAX_CONTAINERS; i++) {
        if (container_sizes[i] == 0) {
            break;
        }
        printf("Container %d:", i + 1);
        for (int j = 0; j < container_sizes[i]; j++) {
            printf(" %d", containers[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int num_items, container_limit, items[MAX_ITEMS];
    
    printf("Enter the number of items: ");
    scanf("%d", &num_items);
    
    printf("Enter the weights of the items: ");
    for (int i = 0; i < num_items; i++) {
        scanf("%d", &items[i]);
    }
    
    printf("Enter the container weight limit: ");
    scanf("%d", &container_limit);
    
    load_containers(items, num_items, container_limit);
    
    return 0;
}

