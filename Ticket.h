#ifndef TICKET_H
#define TICKET_H

#include <stdexcept>
#include <string>

class Ticket {
protected:
    int ticketNumber;
    int saleTime;

public:
    Ticket(int ticketNumber, int saleTime);
    virtual ~Ticket() = default;

    int getTicketNumber() const;
    int getSaleTime() const;

    virtual bool attemptPass(int currentTime) = 0;

    // Клонирование
    virtual Ticket* clone() const = 0;

    virtual bool operator==(const Ticket& other) const;
    virtual bool operator<(const Ticket& other) const;
};

#endif // TICKET_H