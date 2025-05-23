#pragma once

#include "QuadTree.h"

class TicketRegistry {
public:
    bool addTicket(const Ticket& ticket);
    bool findTicket(int ticketId) const;
    size_t size() const;

private:
    QuadTree storage;
};