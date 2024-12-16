#ifndef TICKETREGISTRY_H
#define TICKETREGISTRY_H

#include <map>
#include <memory>
#include <stdexcept>
#include "Ticket.h"

class TicketRegistry {
private:
    std::map<int, std::unique_ptr<Ticket>> tickets;  // Хранилище билетов

public:
    TicketRegistry() = default;

    // Добавление билета
    void addTicket(std::unique_ptr<Ticket> ticket);

    // Проверка билета и обработка попытки прохода
    std::string processPassAttempt(int ticketNumber, int currentTime);
};

#endif // TICKETREGISTRY_H