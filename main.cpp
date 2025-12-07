#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void read(string filename, vector<int>& labels, vector<vector<double>>& features);
void forward_selection(int feature_num, double initial_score);
void backward_elimination(int feature_num, double initial_score);
double evaluate(const vector<int>& cur_features, int new_feature);

vector<vector<double>> global_features;
vector<int> global_labels;

int main() {
    string filename;
    int choice = 0;
    

    cout << "Welcome to BJY Final Feature Selection Algorithm." << endl;
    cout << "Type in the name of the file to test (include suffix .txt): ";
    cin >> filename;

    read(filename, global_labels, global_features);

    if (global_features.empty()) {
        cerr << "Error." << endl;
        return 1;
    }

    int feature_num = global_features[0].size();
    int instance_num = global_features.size();
    
    int label_1 = count(global_labels.begin(), global_labels.end(), 0) + count(global_labels.begin(), global_labels.end(), 2);
    int label_2 = count(global_labels.begin(), global_labels.end(), 1);

    vector<int> all_features;
    for (int i = 1; i <= feature_num; ++i) {
        all_features.push_back(i);
    }

    cout << "This dataset has " << feature_num << " features (not including the class attribute), with " << instance_num << " instances." << endl;

    cout << "\nType the number of the algorithm you want to run." << endl;
    cout << "1) Forward Selection" << endl;
    cout << "2) Backward Elimination" << endl;
    cin >> choice;

    if (choice == 1) {
        double initial_accuracy = max(label_1, label_2) / global_labels.size() * 100.0;
        cout << "Running nearest neighbor with no features (default rate), using leaving-one-out evaluation, I get an accuracy of " << initial_accuracy << "%" << endl;
        forward_selection(feature_num, initial_accuracy);
    } else if (choice == 2) {
        double initial_accuracy = evaluate(all_features, 0);
        cout << "Running nearest neighbor with all features, using leaving-one-out evaluation, I get an accuracy of " << initial_accuracy << "%" << endl;
        backward_elimination(feature_num, initial_accuracy);
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}