#pragma once

class neighbor {
public:
    int target;
    double weight;
    neighbor(int arg_target, double arg_weight)
            : target(arg_target), weight(arg_weight) { }

    friend class DijkstraGraph;
};
