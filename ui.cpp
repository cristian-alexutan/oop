#include "ui.h"
#include "domain.h"
#include <iostream>

Ui::Ui(Service &service) : service(service) {}

void Ui::print_menu() {
    system("cls");
    std::cout << "1 - add car\n";
    std::cout << "2 - remove car\n";
    std::cout << "3 - get all cars\n";
    std::cout << "4 - get vintage cars\n";
    std::cout << "0 - exit\n";
    std::cout << "=====================\n";
}

void Ui::get_all_cars() {
    std::vector<Car> cars = this->service.get_all_cars();
    for(int i=0; i<cars.size(); i++)
        std::cout << i << ": " << cars[i].to_string() << "\n";
    std::cout << "\n";
}

void Ui::add_car() {
    std::cout << "current list of cars:\n";
    std::vector<Car> cars = this->service.get_all_cars();
    for(int i=0; i<cars.size(); i++)
        std::cout << i << ": " << cars[i].to_string() << "\n";
    if(cars.empty())
        std::cout << "there are no cars\n";
    std::cout << "\n";
    std::cout << "enter the details of the new car:\n";
    std::string brand;
    std::cout << "brand: "; std::cin >> brand;
    std::string model;
    std::cout << "model: "; std::cin >> model;
    int year;
    std::cout << "year: "; std::cin >> year;
    std::string color;
    std::cout << "color: "; std::cin >> color;
    Car temp{brand, model, year, color};
    bool ans = this->service.add_car(temp);
    if(!ans)
        std::cout << "car was not added, identical model exists\n";
    std::cout << "car was added successfully\n";
}

void Ui::remove_car() {
    std::vector<Car> cars = this->service.get_all_cars();
    if(cars.empty()) {
        std::cout << "there are no cars to delete\n";
        return;
    }
    std::cout << "current list of cars:\n";
    for(int i=0; i<cars.size(); i++)
        std::cout << i << ": " << cars[i].to_string() << "\n";
    std::cout << "\n";
    int index;
    std::cout << "index of car to be deleted: "; std::cin >> index;
    if(index < 0 || index >= cars.size()) {
        std::cout << "invalid index\n";
        return;
    }
    this->service.remove_car(index);
}

void Ui::get_vintage_cars() {
    std::vector<Car> cars = this->service.get_vintage_cars();
    for(int i=0; i<cars.size(); i++)
        std::cout << i << ": " << cars[i].to_string() << "\n";
    std::cout << "\n";
}

void Ui::run_ui() {
    while(true) {
        print_menu();
        int opt = 0;
        std::cout << " >>> "; std::cin >> opt;
        switch(opt) {
            case 0: {
                system("pause");
                return;
            }
            case 1: {
                add_car();
                break;
            }
            case 2: {
                remove_car();
                break;
            }
            case 3: {
                get_all_cars();
                break;
            }
            case 4: {
                get_vintage_cars();
                break;
            }
            default: {
                std::cout << "please enter a valid option\n";
                break;
            }
        }
        system("pause");
    }
}