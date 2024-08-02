#include "DungeonGenerator.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

DungeonGenerator::DungeonGenerator(int width, int height)
    : width(width), height(height) {
    dungeon.resize(height, std::vector<Tile>(width, {'#', false}));
}

void DungeonGenerator::generateDungeon() {
    srand(time(nullptr));
    int numRooms = 10;

    for (int i = 0; i < numRooms; ++i) {
        int roomWidth = 5 + rand() % 5;
        int roomHeight = 5 + rand() % 5;
        int x = rand() % (width - roomWidth);
        int y = rand() % (height - roomHeight);

        addRoom(x, y, roomWidth, roomHeight);

        if (i > 0) {
            int prevX = rand() % (width - roomWidth);
            int prevY = rand() % (height - roomHeight);
            addCorridor(prevX + roomWidth / 2, prevY + roomHeight / 2, x + roomWidth / 2, y + roomHeight / 2);
        }
    }
}

void DungeonGenerator::printDungeon() const {
    for (const auto& row : dungeon) {
        for (const auto& tile : row) {
            std::cout << tile.symbol;
        }
        std::cout << std::endl;
    }
}

void DungeonGenerator::addRoom(int x, int y, int w, int h) {
    for (int i = y; i < y + h; ++i) {
        for (int j = x; j < x + w; ++j) {
            dungeon[i][j] = {'.', true};
        }
    }
}

void DungeonGenerator::addCorridor(int x1, int y1, int x2, int y2) {
    while (x1 != x2) {
        dungeon[y1][x1] = {'.', true};
        x1 += (x2 > x1) ? 1 : -1;
    }
    while (y1 != y2) {
        dungeon[y1][x1] = {'.', true};
        y1 += (y2 > y1) ? 1 : -1;
    }
    dungeon[y1][x1] = {'.', true};
}
