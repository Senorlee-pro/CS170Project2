#include "class.h"
#include <iostream>
#include <vector>
#include <iomanip>

void forward_selection(const Problem& p, double initial_score);
void backward_elimination(const Problem& p, double initial_score);
double evaluate(std::vector<int> cur_features, int new_feature);

int main(){
    int feature_num;
    int choice = 0;

    std::cout << "Welcome to BJY Feature Selection Algorithm." << std::endl;
    std::cout << "Please enter total number of features: ";
    std::cin >> feature_num;
    
    Problem p = Problem(feature_num);

    std::cout << "\nType the number of the algorithm you want to run." << std::endl;
    std::cout << "1) Forward Selection" << std::endl;
    std::cout << "2) Backward Elimination" << std::endl;
    std::cout << "3) BJY's Special Algorithm" << std::endl; 
    std::cout << "Enter choice (1, 2, 3): ";
    std::cin >> choice;

    std::vector<int> empty_set;
    double initial_score = evaluate(empty_set, 0); 

    switch (choice) {
        case 1:
            std::cout << "\nUsing no features and \"random\" evaluation, I get an accuracy of " << initial_score << "%" << std::endl;
            std::cout << "\n--- Running Forward Selection ---" << std::endl;
            std::cout << "Beginning search." << std::endl;
            forward_selection(p, initial_score);
            break;
        case 2:
            std::cout << "\nUsing all " << feature_num << " features and \"random\" evaluation, I get an accuracy of " << initial_score << "%" << std::endl;
            std::cout << "\n--- Running Backward Elimination ---" << std::endl;
            std::cout << "Beginning search." << std::endl;
            backward_elimination(p, initial_score);
            break;
        case 3:
            std::cout << "Not yet implemented." << std::endl;
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            break;
    }

    return 0;
}