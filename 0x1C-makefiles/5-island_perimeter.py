#!/usr/bin/python3

def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in grid.

    Args:
        grid (List[List[int]]): A list of lists representing the grid where:
            - 0 represents a water zone
            - 1 represents a land zone
            - One cell is a square with side length 1

    Returns:
        int: The perimeter of the island

    Constraints:
        - Grid cells are connected horizontally/vertically (not diagonally).
        - Grid is rectangular, width and height don’t exceed 100
        - Grid is completely surrounded by water, and there is one island (or nothing).
        - The island doesn’t have “lakes” (water inside that isn’t connected to the water around the island).
    """
width = len(grid[0])
height = len(grid)
edges = 0
size = 0

for row_index in range(height):
    for column_index in range(width):
        if grid[row_index][column_index] == 1:
            size += 1
            if (column_index > 0 and grid[row_index][column_index - 1] == 1):
                edges += 1
            if (row_index > 0 and grid[row_index - 1][column_index] == 1):
                edges += 1
return size * 4 - edges * 2
