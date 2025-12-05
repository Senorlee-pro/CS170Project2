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


class Validator{
    public:
        double val_accuracy (const vector<int>& subset, Classifier& classifier, const vector<vector<double>>& features, const vector<int>& labels) {
            vector<vector<double>> subfeatures(features.size(), vector<double>(subset.size()));

            int col;
            for (int i = 0; i < features.size(); i++) {
                for (int j = 0; j < subset.size(); j++) {
                    subfeatures[i][j] = features[i][subset[j]-1];
                }
            }

            vector<vector<double>> test_features;
            vector<int> test_labels;
            int correct = 0;
            for (int i = 0; i < subfeatures.size(); i++) {
                test_features = subfeatures;
                test_features.erase(test_features.begin() + i);
                test_labels = labels;
                test_labels.erase(test_labels.begin() + i);

                classifier.train(test_features, test_labels);
                if (labels[i]==classifier.test(subfeatures[i])) {
                    correct++;
                }
            }
            return (double)correct / features.size();
        }
};