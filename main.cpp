#include "class.h"

void forward_selection(const Problem& p);

int main(){
    Problem p = Problem(5);
    forward_selection(p);
    return 0;
}