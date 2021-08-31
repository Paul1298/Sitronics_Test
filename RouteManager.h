#ifndef UNTITLED_ROUTEMANAGER_H
#define UNTITLED_ROUTEMANAGER_H

bool check_movement(Edge &edge, int cur_time);
void start_route(std::vector<Station> &railway, std::vector<int> &route, int train_number);
void initiate_routes(std::vector<Station> &railway);

#endif //UNTITLED_ROUTEMANAGER_H
