#pragma once

#include <string>
#include <vector>

class TodoList {
private:
    std::vector<std::string> tasks;
    std::vector<bool> done;

public:
    bool add(const std::string& text);
    bool complete(const std::string& name);
    bool complete(size_t number);

    void all() const;
    void complete() const;
    void incomplete() const;

    void clear();
};




