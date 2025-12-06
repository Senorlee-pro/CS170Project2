#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "part1_class.h"

using namespace std;

vector<vector<double>> global_features;
vector<int> global_labels;

void read(string filename, vector<int>& labels, vector<vector<double>>& features);
void forward_selection(const Problem& p, double initial_score);
void backward_elimination(const Problem& p, double initial_score);
double evaluate(vector<int> cur_features, int new_feature);

int main() {
    string filename;
    int choice = 0;

    cout << "Welcome to BJY Final Feature Selection Algorithm." << endl;
    cout << "Type in the name of the file to test: ";
    cin >> filename;

    read(filename, global_labels, global_features);

    if (global_features.empty()) {
        cout << "Error." << endl;
        return 1;
    }

    int feature_num = global_features[0].size();
    int instance_num = global_features.size();
    
    long label_1 = std::count(global_labels.begin(), global_labels.end(), 0.0) + std::count(global_labels.begin(), global_labels.end(), 2.0);
    long label_2 = std::count(global_labels.begin(), global_labels.end(), 1.0);

    double initial_accuracy_1 = static_cast<double>(max(label_1, label_2)) / global_labels.size() * 100.0;

    std::vector<int> all_features;
    for (int i = 1; i <= feature_num; ++i) {
        all_features.push_back(i);
    }
    double initial_accuracy_2 = evaluate(all_features, 0);
    cout << "This dataset has " << feature_num << " features (not including the class attribute), with " << instance_num << " instances." << endl;

    Problem p(feature_num);

    cout << "\nType the number of the algorithm you want to run." << endl;
    cout << "1) Forward Selection" << endl;
    cout << "2) Backward Elimination" << endl;
    cin >> choice;

    if (choice == 1) {
        cout << "Running nearest neighbor with no features (default rate), using leaving-one-out evaluation, I get an accuracy of " << initial_accuracy_1 << "%" << endl;
        forward_selection(p, initial_accuracy_1);
    } else if (choice == 2) {
        cout << "Running nearest neighbor with all features, using leaving-one-out evaluation, I get an accuracy of " << initial_accuracy_2 << "%" << endl;
        backward_elimination(p, initial_accuracy_2);
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}