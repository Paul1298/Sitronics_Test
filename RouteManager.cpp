#include <vector>
#include <iostream>
#include <cstring>
#include "Utils.h"

/*
 * If trains collided in movement, returns train number, -1 otherwise.
 */
int check_movement(Edge &edge, int cur_time) {
    if (edge.in_times.empty()) return -1;
    auto res_time = edge.in_times.lower_bound(cur_time).operator--(); //iterator to time no greater than cur_time
    if (cur_time > res_time->first and cur_time < res_time->first + edge.length) return res_time->second;
    else return -1;
}

void start_route(std::vector<Station> &railway, std::vector<int> &route, int train_number) {
    int cur_time = 0;
    for (int i = 1; i < route.size(); ++i) {
        int in = route[i - 1];
        int out = route[i];
        if (railway[in].stop_times.find(cur_time) != railway[in].stop_times.end()) {
            if (in == route.front()) {// starting station
                printf("Error in initial routes configuration. Trains %i and %i start in the same station.",
                       train_number, railway[in].stop_times[cur_time]);
                exit(0);
            } else
                printf("Train %i collided with train %i at station %i.\n", train_number,
                       railway[in].stop_times[cur_time],
                       in);
        } else {
            railway[in].stop_times[cur_time] = train_number;
        }
        railway[in].edges.at(out).in_times.insert({cur_time, train_number});

        int move_result = check_movement(railway[out].edges.at(in), cur_time);
        if (move_result != -1) {
            printf("Train %i collided with train %i between station %i and %i.\n", train_number, move_result,
                   in, out);
        }
        cur_time += railway[in].edges.at(out).length;
    }
}

void initiate_routes(std::vector<Station> &railway) {
    int route_num;
    std::cin >> route_num;
    std::cin.get(); // read newline character
    for (int train_number = 0; train_number != route_num; ++train_number) {
        std::string str_tmp;
        std::getline(std::cin, str_tmp);
        char *route_str = const_cast<char *> (str_tmp.c_str());
        char *station_str = std::strtok(route_str, " ");

        std::vector<int> route;
        while (station_str) {
            route.push_back(atoi(station_str));
            station_str = strtok(nullptr, " ");
        }
        start_route(railway, route, train_number);
    }
}
