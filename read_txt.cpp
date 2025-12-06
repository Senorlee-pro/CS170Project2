#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

// Z-score normalization
void normalization(vector<vector<double>>& X) {
    int n = X.size();
    int m = X[0].size();
    vector<double> mean(m, 0.0);
    vector<double> stddev(m, 0.0);

    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            mean[j] += X[i][j];
        }
        mean[j] /= n;
        for(int i = 0; i < n; i++){
            double diff = X[i][j] - mean[j];
            stddev[j] += diff * diff;
        }
        stddev[j] = sqrt(stddev[j] / n);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            X[i][j] = (X[i][j] - mean[j]) / stddev[j];
        }
    }
}

// Need to include ".txt" as the suffix in "filename"
// Create empty labels and features beforehand and pass them as the arguments
void read(string filename, vector<int>& labels, vector<vector<double>>& features){
    ifstream fin(filename);
    if(!fin.is_open()) {
        cerr << "Unable to open file\n";
        return;
    }

    string line;
    while (getline(fin, line)) {
        if (line.size() == 0) continue;

        stringstream ss(line);

        double cls_val;
        ss >> cls_val;
        labels.push_back((int)cls_val);

        vector<double> x;
        double val;

        while (ss >> val) {
            x.push_back(val);
        }

        features.push_back(x);
    }

    fin.close();

    normalization(features);
}