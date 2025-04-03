#pragma once
#include <string>

class Car {
private:
    std::string brand;
    std::string model;
    int year;
    std::string color;
public:
    Car(const std::string& brand, const std::string& model, int year, const std::string& color);
    std::string get_brand() const;
    std::string get_model() const;
    int get_year() const;
    std::string get_color() const;
    std::string to_string() const;
    bool operator==(const Car& car) const;
};