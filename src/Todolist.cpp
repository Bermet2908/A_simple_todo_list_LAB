#include <iostream>
#include <cctype>
#include "Todolist.hpp"

static std::string toLower(std::string s) {
    for (char& c : s) c = std::tolower(static_cast<unsigned char>(c));
    return s;
}

static std::string trim(const std::string& s) {
    size_t a = 0, b = s.size();
    while (a < b && std::isspace(static_cast<unsigned char>(s[a]))) ++a;
    while (b > a && std::isspace(static_cast<unsigned char>(s[b - 1]))) --b;
    return s.substr(a, b - a);
}

bool TodoList::add(const std::string& text) {
    std::string t = trim(text);
    if (t.empty()) {
        std::cout << "Cannot add an empty task.\n";
        return false;
    }
    std::string key = toLower(t);
    for (const std::string& existing : tasks) {
        if (toLower(trim(existing)) == key) {
            std::cout << "Task already exists.\n";
            return false;
        }
    }
    tasks.push_back(t);
    done.push_back(false);
    return true;
}

bool TodoList::complete(const std::string& name) {
    std::string key = toLower(trim(name));
    for (size_t i = 0; i < tasks.size(); ++i) {
        if (toLower(trim(tasks[i])) == key) {
            if (done[i]) {
                std::cout << "Task already complete.\n";
                return false;
            }
            done[i] = true;
            std::cout << "Marked complete: " << tasks[i] << "\n";
            return true;
        }
    }
    std::cout << "Task not found.\n";
    return false;
}

bool TodoList::complete(size_t number) {
    if (number == 0 || number > tasks.size()) {
        std::cout << "Invalid task number.\n";
        return false;
    }
    size_t idx = number - 1;
    if (done[idx]) {
        std::cout << "Task already complete.\n";
        return false;
    }
    done[idx] = true;
    std::cout << "Marked complete: " << tasks[idx] << "\n";
    return true;
}

void TodoList::all() const {
    if (tasks.empty()) {
        std::cout << "The to-do list is empty.\n";
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << (i + 1) << ". " << tasks[i];
        if (done[i]) std::cout << " (done)";
        std::cout << "\n";
    }
}

void TodoList::complete() const {
    bool any = false;
    for (size_t i = 0; i < tasks.size(); ++i) {
        if (done[i]) {
            std::cout << (i + 1) << ". " << tasks[i] << "\n";
            any = true;
        }
    }
    if (!any) std::cout << "No completed tasks yet.\n";
}

void TodoList::incomplete() const {
    bool any = false;
    for (size_t i = 0; i < tasks.size(); ++i) {
        if (!done[i]) {
            std::cout << (i + 1) << ". " << tasks[i] << "\n";
            any = true;
        }
    }
    if (!any) std::cout << "No incomplete tasks — good job!\n";
}

void TodoList::clear() {
    tasks.clear();
    done.clear();
    std::cout << "All tasks cleared.\n";
}
