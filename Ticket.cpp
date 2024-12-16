#include "Ticket.h"

Ticket::Ticket(int ticketNumber, int saleTime) 
    : ticketNumber(ticketNumber), saleTime(saleTime) 
{
    if (ticketNumber <= 0) throw std::invalid_argument("Invalid ticket number");
}

int Ticket::getTicketNumber() const {
    return ticketNumber;
}

int Ticket::getSaleTime() const {
    return saleTime;
}

bool Ticket::operator==(const Ticket& other) const {
    return ticketNumber == other.ticketNumber;
}

bool Ticket::operator<(const Ticket& other) const {
    return ticketNumber < other.ticketNumber;
}