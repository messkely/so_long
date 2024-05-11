#include <stdio.h>
#include <stdlib.h>

// Define the t_map structure
typedef struct {
    char **map2d;       // 2D array representing the game map
    int size_x;         // Width (number of columns) of the map
    int size_y;         // Height (number of rows) of the map
} t_map;

// Function prototype for flood fill
void flood_fill(t_map *my_map, int y, int x, int coin);

// Flood fill function to mark visited cells and handle coin collection
void flood_fill(t_map *my_map, int y, int x, int coin) {
    // Boundary check to ensure coordinates are within the map boundaries
    if (y < 0 || y >= my_map->size_y || x < 0 || x >= my_map->size_x) {
        return;
    }

    // Check if the current cell is a wall ('1') or already visited ('x')
    if (my_map->map2d[y][x] == '1' || my_map->map2d[y][x] == 'x') {
        return;
    }

    // Check if the current cell has a coin ('C')
    if (my_map->map2d[y][x] == 'C') {
        // Decrement the coin counter since the player collects the coin
        coin--;
    }

    // Mark the current cell as visited by placing 'x'
    my_map->map2d[y][x] = 'x';

    // Recursive calls to explore neighboring cells (up, down, left, right)
    flood_fill(my_map, y - 1, x, coin); // Up
    flood_fill(my_map, y + 1, x, coin); // Down
    flood_fill(my_map, y, x + 1, coin); // Right
    flood_fill(my_map, y, x - 1, coin); // Left
}

int main() {
    // Initialize the game map and player information
    t_map my_map;
    my_map.size_x = 5;
    my_map.size_y = 5;

    // Allocate memory for the game map (2D array)
    my_map.map2d = (char **)malloc(my_map.size_y * sizeof(char *));
    for (int i = 0; i < my_map.size_y; i++) {
        my_map.map2d[i] = (char *)malloc(my_map.size_x * sizeof(char));
    }

    // Define the game map (replace with your map data)
    char map_data[5][5] = {
        {'1', '1', '1', '1', '1'},
        {'1', 'P', '1', '1', '1'},
        {'1', '1', '1', 'C', '1'},
        {'1', 'E', '0', '1', '1'},
        {'1', '1', '1', '1', '1'}
    };

    // Copy the map data into the game map structure
    for (int i = 0; i < my_map.size_y; i++) {
        for (int j = 0; j < my_map.size_x; j++) {
            my_map.map2d[i][j] = map_data[i][j];
        }
    }

    // Perform flood fill starting from the player's initial position
    flood_fill(&my_map, 1, 1, 0); // Start with coin counter = 0

    // Display the updated game map after flood fill
    printf("Game Map after flood fill:\n");
    for (int i = 0; i < my_map.size_y; i++) {
        for (int j = 0; j < my_map.size_x; j++) {
            printf("%c", my_map.map2d[i][j]);
        }
        printf("\n");
    }

    // Free memory allocated for the game map
    for (int i = 0; i < my_map.size_y; i++) {
        free(my_map.map2d[i]);
    }
    free(my_map.map2d);

    return 0;
}



