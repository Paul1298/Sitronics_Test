#include <fstream>
#include <vector>
#include <iostream>
#include "Utils.h"
#include "RailwayReader.h"
#include "RouteManager.h"


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int station_num, path_num;
    std::cin >> station_num >> path_num;

    std::vector<Station> railway(station_num);
    read_railway(railway, path_num);
    initiate_routes(railway);
    printf("No collisions.");
    return 0;
}
