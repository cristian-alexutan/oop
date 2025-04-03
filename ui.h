#pragma once
#include "services.h"

class Ui {
private:
    Service &service;
    void print_menu();
    void add_car();
    void remove_car();
    void get_all_cars();
    void get_vintage_cars();
public:
    Ui(Service& service);
    void run_ui();
};