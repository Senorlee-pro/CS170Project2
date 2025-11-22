#ifndef CLASS_H
#define CLASS_H

class Problem{
public:
    int feature_num;
    int get() const {
        return feature_num;
    }

    Problem(int a): feature_num(a) {}
};

#endif
