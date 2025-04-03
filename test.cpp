#include "test.h"
#include "services.h"
#include <cassert>

void Tester::test_add_repo() {
    Repository repo;
    Car a{"abc", "abc", 2007, "red"};
    Car b{"abc", "abc", 2007, "blue"};
    assert(repo.add_car(a));
    assert(!repo.add_car(b));
    std::vector<Car> cars = repo.get_cars();
    assert(cars[0] == a && cars[0].get_color() == a.get_color());
}

void Tester::test_add_service() {
    Repository repo;
    Service service(repo);
    Car a{"abc", "abc", 2007, "red"};
    Car b{"abc", "abc", 2007, "blue"};
    assert(service.add_car(a));
    assert(!service.add_car(b));
    std::vector<Car> cars = repo.get_cars();
    assert(cars[0] == a && cars[0].get_color() == a.get_color());
}

void Tester::test_get_vintage() {
    Repository repo;
    Service service(repo);
    Car a{"abc", "abc", 2007, "red"};
    Car b{"abc", "abc", 1900, "blue"};
    service.add_car(a);
    service.add_car(b);
    std::vector<Car> cars = service.get_vintage_cars();
    assert(cars.size() == 1);
    assert(cars[0] == b && cars[0].get_color() == b.get_color());
}

void Tester::test_all() {
    test_add_repo();
    test_add_service();
    test_get_vintage();
}
