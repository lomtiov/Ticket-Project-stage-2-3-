#ifndef TICKETREGISTRY_H
#define TICKETREGISTRY_H

#include <map>
#include <memory>
#include <stdexcept>
#include "Ticket.h"

class TicketRegistry {
private:
    std::map<int, std::unique_ptr<Ticket>> tickets;

public:
    // Конструктор по умолчанию
    TicketRegistry() = default;

    // Копирующий конструктор
    TicketRegistry(const TicketRegistry& other);

    // Оператор присваивания
    TicketRegistry& operator=(const TicketRegistry& other);

    // Добавление билета
    void addTicket(std::unique_ptr<Ticket> ticket);

    // Проверка билета и обработка попытки прохода
    std::string processPassAttempt(int ticketNumber, int currentTime);
};

#endif // TICKETREGISTRY_H