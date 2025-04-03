#pragma once
#include "repository.h"
#include "domain.h"

class Service{
private:
    Repository &repository;
public:
    Service(Repository &repository);
    bool add_car(const Car& car) const;
    void remove_car(const int& index) const;
    std::vector<Car> get_all_cars() const;
    std::vector<Car> get_vintage_cars() const;
};