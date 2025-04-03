#include "services.h"
#include <algorithm>

bool comp1(Car a, Car b) {
    if(a.get_brand() > b.get_brand()) return false;
    if(a.get_brand() == b.get_brand() and a.get_model() > b.get_model()) return false;
    return true;
}

bool comp2(Car a, Car b) {
    return a.get_color() < b.get_color();
}

Service::Service(Repository &repository) : repository(repository) {}

bool Service::add_car(const Car& car) const {
    /*
     * Adds a car to the current list of cars
     *
     * @param car - the  car to be added
     * @returns true if the car was added, false otherwise
     */
    return this->repository.add_car(car);
}

void Service::remove_car(const int& index) const {
    this->repository.remove_car(index);
}

std::vector<Car> Service::get_all_cars() const {
    std::vector<Car> cars = this->repository.get_cars();
    sort(cars.begin(), cars.end(), comp1);
    return cars;
}

std::vector<Car> Service::get_vintage_cars() const {
    /*
     * Returns all vintage cars sorted by color
     *
     * @returns the list of vintage cars sorted by color
     */
    std::vector<Car> cars = this->repository.get_cars();
    std::vector<Car> vintage_cars;
    for(auto i : cars)
        if(i.get_year() <= 1980) vintage_cars.push_back(i);
    sort(vintage_cars.begin(), vintage_cars.end(), comp2);
    return vintage_cars;
}