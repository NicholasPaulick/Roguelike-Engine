#include "DungeonGenerator.h"

int main() {
    DungeonGenerator dungeon(40, 20);
    dungeon.generateDungeon();
    dungeon.printDungeon();
    return 0;
}
