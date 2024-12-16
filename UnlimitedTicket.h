#ifndef UNLIMITEDTICKET_H
#define UNLIMITEDTICKET_H

#include "Ticket.h"

class UnlimitedTicket : public Ticket {
private:
    std::string reason;
    int lastPassTime;

public:
    UnlimitedTicket(int ticketNumber, int saleTime, const std::string& reason);

    bool attemptPass(int currentTime) override;

    // Реализация клонирования
    UnlimitedTicket* clone() const override;
};

#endif // UNLIMITEDTICKET_H