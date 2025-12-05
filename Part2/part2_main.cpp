#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;

void read(std::string filename, std::vector<int>& labels, std::vector<std::vector<double>>& features);

int main(){
    std::vector<int> labels;
    std::vector<std::vector<double>> features;
    read("small-test-dataset-2-2.txt", labels, features);
    for(int j=0; j<features.size(); ++j){
        for(int i=0; i<features[0].size(); ++i)
            std::cout << setprecision(10) << features[j][i] << " ";
        std::cout << std::endl;
    }
    cout << labels[0];
}