#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "part2_class.h"
using namespace std;

void read(std::string filename, std::vector<int>& labels, std::vector<std::vector<double>>& features);

int main(){
    std::vector<int> labels;
    std::vector<std::vector<double>> features;
    read("small-test-dataset-2-2.txt", labels, features);
    // for(int j=0; j<features.size(); ++j){
    //     for(int i=0; i<features[0].size(); ++i)
    //         std::cout << setprecision(10) << features[j][i] << " ";
    //     std::cout << std::endl;
    // }
    // cout << labels[0];

    
    //testing
    Classifier cf;
    Validator val;
    cout << "Accuracy of small-test-dataset with features 3, 5, 7: " << val.val_accuracy({3, 5, 7}, cf, features, labels) << endl;
    read("large-test-dataset-2.txt", labels, features);
    cout << "Accuracy of large-test-dataset with features 1, 15, 27: " << val.val_accuracy({1, 15, 27}, cf, features, labels) << endl;

}