#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void normalization(vector<vector<double>>& X);

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