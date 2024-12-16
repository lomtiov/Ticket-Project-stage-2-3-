#ifndef UNLIMITEDTICKET_H
#define UNLIMITEDTICKET_H

#include "Ticket.h"

class UnlimitedTicket : public Ticket {
private:
    std::string reason;     // Основание для выдачи
    int lastPassTime;       // Время последнего прохода (инициализация: -1)

public:
    UnlimitedTicket(int ticketNumber, int saleTime, const std::string& reason);

    bool attemptPass(int currentTime) override;
};

#endif // UNLIMITEDTICKET_H