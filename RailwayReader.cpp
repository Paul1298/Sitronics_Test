#include <vector>
#include <iostream>
#include "Utils.h"

/*
 * Check railway input data for collisions
 */
void read_railway(std::vector<Station> &railway, int path_num) {
    for (int i = 0; i != path_num; ++i) {
        int in, out, length;
        std::cin >> in >> out >> length;
        auto find_iter = railway[in].edges.find(out);
        if (find_iter != railway[in].edges.end() and find_iter->second.length != length) {
            fprintf(stderr, "Error when reading path %i. Same edge with different lengths.", i);
            exit(0);
        } else railway[in].edges.insert({out, Edge(length)});

        find_iter = railway[out].edges.find(in);
        if (find_iter != railway[out].edges.end() and find_iter->second.length != length) {
            fprintf(stderr, "Error when reading path %i. Same edge with different lengths.", i);
            exit(0);
        } else railway[out].edges.insert({in, Edge(length)});
    }
}
