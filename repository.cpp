#include "repository.h"
#include <iostream>

int Repository::get_size() const {
    return this->cars.size();
}

std::vector<Car> Repository::get_cars() {
    return this->cars;
}

bool Repository::add_car(const Car& car) {
    /*
     * Adds a car to the repository
     *
     * @param car - the car to be added
     * @returns true if the car was added, false otherwise
     */
    for(int i=0; i<this->cars.size(); i++)
        if(this->cars[i] == car) return false;
    this->cars.push_back(car);
    return true;
}

void Repository::remove_car(const int& index) {
    this->cars.erase(this->cars.begin() + index);
}