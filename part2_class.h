#include <vector>
#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

double euclidean(const vector<double>& a, const vector<double>& b);

class Classifier{
private:
    vector<vector<double>> saved_features;
    vector<int> saved_labels;
public:
    void train(const vector<vector<double>>& features, const vector<int>& labels){
        saved_features = features;
        saved_labels = labels;
    }

    int test(const vector<double>& test_instance){
        if (saved_features.empty())
            throw runtime_error("Call train() first to save training instances.");

        int nearest_idx = 0;
        double nearest_dist = euclidean(saved_features[0], test_instance);
        for(size_t i=1 ; i<saved_features.size(); ++i){
            double new_dist = euclidean(saved_features[i], test_instance);
            if(new_dist < nearest_dist){
                nearest_dist = new_dist;
                nearest_idx = i;
            }
        }
        return saved_labels[nearest_idx];
    }
};