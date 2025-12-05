#include <vector>
#include <stdexcept>
#include <cmath>

using namespace std;

double euclidean(const vector<double>& a, const vector<double>& b){
    if(a.size() != b.size())
        throw runtime_error("Invalid: Dimension mismatch");

    else{
        double sum = 0.0;
        for (size_t i = 0; i < a.size(); i++){
            double diff = a[i] - b[i];
            sum += diff * diff;
        }
        return sqrt(sum);
    }
}

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