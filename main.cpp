#include "class.h"
#include <iostream>

void forward_selection(const Problem& p);
void backward_elimination(const Problem& p);

int main(){
    Problem p = Problem(5);
    std::cout << "Forward Selection:" << std::endl;
    forward_selection(p);

    std::cout << "Backward Elimination:" << std::endl;
    backward_elimination(p);
    return 0;
}