#include "TicketRegistry.h"

void TicketRegistry::addTicket(std::unique_ptr<Ticket> ticket) {
    int ticketNumber = ticket->getTicketNumber();
    if (tickets.find(ticketNumber) != tickets.end()) {
        throw std::invalid_argument("Ticket number already exists in registry");
    }
    tickets[ticketNumber] = std::move(ticket);
}

std::string TicketRegistry::processPassAttempt(int ticketNumber, int currentTime) {
    auto it = tickets.find(ticketNumber);
    if (it == tickets.end()) {
        return "ALARM: Ticket not found!";
    }

    Ticket* ticket = it->second.get();
    if (ticket->attemptPass(currentTime)) {
        return "Pass granted.";
    } else {
        return "Pass denied.";
    }
}