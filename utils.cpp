#include "class.h"
#include <random>
#include <vector>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <iomanip>

// Initialize the random seed engine
std::mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
std::uniform_real_distribution<double> dist(30.0, 80.0);

// Helper function to print features in format {1,2,3,4}
void print_features(const std::vector<int>& features) {
    std::cout << "{";
    for (size_t i = 0; i < features.size(); ++i) {
        std::cout << features[i];
        if (i != features.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "}";
}

// Return the evaluation score of adding a new feature to current features
// In this case the function only returns a random number
double evaluate(std::vector<int> cur_features, int new_feature){
    double num = dist(rng);
    num = std::round(num * 10.0) / 10.0;
    return num;
}

void forward_selection(const Problem& p, double initial_score){
    std::vector<int> remain, selected;
    double best_score = initial_score;
    for(int i=1; i<p.get()+1; ++i){
        remain.push_back(i);
    }
    while(!remain.empty()){
        auto best_it = remain.end();
        double score = 0;
        for(auto it = remain.begin(); it != remain.end(); ++it){
            double s = evaluate(selected, *it);
            std::cout << "Using feature(s) {";
            for(size_t k=0; k<selected.size(); ++k) std::cout << selected[k] << ",";
            std::cout << *it << "} accuracy is " << s << "%" << std::endl;

            if(s > score){
                score = s;
                best_it = it;
            }
        }

        if (score <= best_score){
            std::cout << "(Warning, Accuracy has decreased!)" << std::endl;
            break;
        }
            
        best_score = score;
        selected.push_back(*best_it);
        remain.erase(best_it);

        std::cout << "Feature set ";
        print_features(selected);
        std::cout << " was best, accuracy is " << best_score << "%" << std::endl;
    }
    std::cout << "Finished search!! The best feature subset is ";
    print_features(selected);
    std::cout << ", which has an accuracy of " << best_score << "%" << std::endl;
}

void backward_elimination(const Problem& p, double initial_score){
    std::vector<int> selected, remain;
    std::vector<int>::iterator best_it;
    double score = 0;
    double best_score = initial_score;
    for(int i=1; i<p.get()+1; ++i){
        selected.push_back(i);
    }
    remain = selected;
    while(selected.size() > 0) {
        best_it = remain.begin();
        score = 0;
        for(auto it = remain.begin(); it != remain.end(); ++it) {
            remain = selected;
            remain.erase(it);
            double s = evaluate(remain, 0);
            std::cout << "Using feature(s) {";
            for(size_t k=0; k<remain.size(); ++k) {
                if (k+1 >= remain.size())
                    std::cout << remain[k];
                else
                    std::cout << remain[k] << ",";
            }
            std::cout << "} accuracy is " << s << "%" << std::endl;
            if (s > score) {
                score = s;
                best_it = it;
            }
        }
        if (score < best_score) {
            std::cout << "(Warning, Accuracy has decreased!)" << std::endl;
            break;
        }
        best_score = score;
        remain = selected;
        remain.erase(best_it);
        selected = remain;


        std::cout << "Feature set ";
        print_features(selected);
        std::cout << " was best, accuracy is " << best_score << "%" << std::endl;
        
    }
    std::cout << "Finished search!! The best feature subset is ";
    print_features(selected);
    std::cout << ", which has an accuracy of " << best_score << "%" << std::endl;
}

