#pragma once

#include <string>

struct Ticket {
    int id;
    std::string description;

    Ticket(int id, const std::string& description)
        : id(id), description(description) {}

    bool operator==(const Ticket& other) const {
        return id == other.id;
    }
};
