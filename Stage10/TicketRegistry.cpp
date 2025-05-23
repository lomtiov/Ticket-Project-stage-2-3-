#include "TicketRegistry.h"

bool TicketRegistry::addTicket(const Ticket& ticket) {
    return storage.insert(ticket);
}

bool TicketRegistry::findTicket(int ticketId) const {
    return storage.search(ticketId);
}

size_t TicketRegistry::size() const {
    return storage.size();
}