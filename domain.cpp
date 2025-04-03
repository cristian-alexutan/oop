#include "domain.h"

Car::Car(const std::string &brand, const std::string &model, int year, const std::string &color) :
    brand(brand), model(model), year(year), color(color) {}

std::string Car::get_brand() const {
    return this->brand;
}

std::string Car::get_model() const {
    return this->model;
}

int Car::get_year() const {
    return this->year;
}

std::string Car::get_color() const {
    return this->color;
}

std::string Car::to_string() const {
    return this->brand + " | " + this->model + " | " + std::to_string(this->year) + " | " + this->color;
}

bool Car::operator==(const Car &other) const {
    return this->brand == other.brand && this->model == other.model && this->year == other.year;
}