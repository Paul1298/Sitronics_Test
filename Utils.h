#pragma once
#ifndef UNTITLED_UTILS_H
#define UNTITLED_UTILS_H

#include <map>
#include <unordered_map>

struct Edge {
    std::map<int, int> in_times;
    int length;

    explicit Edge(int length) {
        this->length = length;
    }

    bool operator==(const Edge &p) const {
        return in_times == p.in_times && length == p.length;
    }
};

struct Station {
    std::unordered_map<int, Edge> edges;
    std::unordered_map<int, int> stop_times;
};

#endif //UNTITLED_UTILS_H
