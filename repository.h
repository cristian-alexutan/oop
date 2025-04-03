#pragma once
#include "domain.h"
#include <vector>

class Repository {
private:
    std::vector<Car> cars;
public:
    int get_size() const;
    std::vector<Car> get_cars();
    bool add_car(const Car& car);
    void remove_car(const int& index);
};