#include "class.h"
#include <random>
#include <vector>
#include <iostream>
#include <chrono>

// Initialize the random seed engine
std::mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
std::uniform_real_distribution<double> dist(30.0, 80.0);

// Return the evaluation score of adding a new feature to current features
// In this case the function only returns a random number
double evaluate(std::vector<int> cur_features, int new_feature){
    double num = dist(rng);
    num = std::round(num * 10.0) / 10.0;
    return num;
}

void forward_selection(const Problem& p){
    std::vector<int> remain, selected;
    std::vector<int>::iterator best_it;
    double score;
    double best_score = 0;
    for(int i=1; i<p.get()+1; ++i){
        remain.push_back(i);
    }
    while(selected.size() < p.get()){
        best_it = remain.begin();
        score = 0;
        for(auto it = remain.begin(); it != remain.end(); ++it){
            double s = evaluate(selected, *it);
            if(s > score){
                score = s;
                best_it = it;
            }
        }
        if (score < best_score)
            break;
        best_score = score;
        selected.push_back(*best_it);
        remain.erase(best_it);
        for (const auto& x : selected)
            std::cout << x << " ";
        std::cout << std::endl;
    }
}