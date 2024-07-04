#include <iostream>
#include "OrderedMap.h"

int main() {
    OrderedMap map;

    // Testing put function
    map.put(5, 10);
    map.put(3, 6);
    map.put(7, 14);
    map.put(2, 4);
    map.put(4, 8);
    map.put(6, 12);
    map.put(8, 16);

    std::cout << "Map size after insertions: " << map.size() << std::endl;

    // Testing get function
    std::cout << "Value for key 4: " << map.get(4) << std::endl;
    std::cout << "Value for key 7: " << map.get(7) << std::endl;

    // Testing containsKey function
    int keyToCheck = 6;
    if (map.containsKey(keyToCheck)) {
        std::cout << "Map contains key " << keyToCheck << std::endl;
    } else {
        std::cout << "Map does not contain key " << keyToCheck << std::endl;
    }

    // Testing remove function
    int keyToRemove = 3;
    if (map.containsKey(keyToRemove)) {
        map.remove(keyToRemove);
        std::cout << "Key " << keyToRemove << " removed successfully." << std::endl;
    } else {
        std::cout << "Key " << keyToRemove << " not found in the map." << std::endl;
    }

    std::cout << "Map size after removal: " << map.size() << std::endl;

    // Testing hasNext and next functions
    std::cout << "Iterating through map:" << std::endl;
    map.resetIterator();
    while (map.hasNext()) {
        int key = map.next();
        std::cout << "Key: " << key << ", Value: " << map.get(key) << std::endl;
    }

    return 0;
}
