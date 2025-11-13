#include "class.h"
#include <random>
#include <vector>

// Return the evaluation score of adding a new feature to current features
// In this case the function only returns a random number
double evaluate(std::vector<int> cur_features, int new_feature){
    std::mt19937 rng(std::random_device{}());
    std::uniform_real_distribution<double> dist(30.0, 80.0);
    double num = dist(rng);
    num = std::round(num * 10.0) / 10.0;
    return num;
}

void forward_selection(const Problem& p){
    std::vector<int> remain, selected;
    for(int i=1; i<p.get()+1; ++i){
        remain.push_back(i);
    }
}