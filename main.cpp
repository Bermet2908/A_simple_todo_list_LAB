#include "src/Todolist.hpp"
#include <iostream>

int main() {
    TodoList list;

    // test add
    list.add("Buy milk");
    list.add("Buy eggs");
    list.add("Do homework");
    list.add("Go to work");

    // test duplicate + empty inputs
    list.add("buy milk");
    list.add("   ");

    // test marking complete
    list.complete("Buy eggs");
    list.complete("Not a real task");

    // test showing all
    std::cout << "\n ALL TASKS: \n";
    list.all();

    // test showing completed
    std::cout << "\n COMPLETED TASKS: \n";
    list.complete();

    // test showing incomplete
    std::cout << "\n INCOMPLETE TASKS: \n";
    list.incomplete();

    // test clearing
    std::cout << "\nCLEAR LIST: \n";
    list.clear();
    list.all();

    return 0;
}



