#ifndef DUNGEONGENERATOR_H
#define DUNGEONGENERATOR_H

#include <vector>

class DungeonGenerator {
public:
    struct Tile {
        char symbol;
        bool walkable;
    };

    DungeonGenerator(int width, int height);
    void generateDungeon();
    void printDungeon() const;

private:
    int width, height;
    std::vector<std::vector<Tile>> dungeon;

    void addRoom(int x, int y, int w, int h);
    void addCorridor(int x1, int y1, int x2, int y2);
};

#endif // DUNGEONGENERATOR_H
