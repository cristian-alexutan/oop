#include "ui.h"
#include "test.h"

int main() {
    Tester t;
    t.test_all();
    Repository repository;
    repository.add_car({"Fiat", "Bravo", 2007, "red"});
    repository.add_car({"Fiat", "Idea", 2003, "black"});
    repository.add_car({"Audi", "A5", 2007, "blue"});
    repository.add_car({"BMW", "Coupe", 2013, "pink"});
    repository.add_car({"Ford", "Fiesta", 1960, "yellow"});
    Service service(repository);
    Ui ui(service);
    ui.run_ui();
    return 0;
}
