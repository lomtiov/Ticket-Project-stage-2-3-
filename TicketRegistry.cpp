#include "TicketRegistry.h"

// Копирующий конструктор
TicketRegistry::TicketRegistry(const TicketRegistry& other) {
    for (const auto& [key, ticket] : other.tickets) {
        tickets[key] = std::unique_ptr<Ticket>(ticket->clone());
    }
}

// Оператор присваивания
TicketRegistry& TicketRegistry::operator=(const TicketRegistry& other) {
    if (this != &other) {
        tickets.clear(); // Очищаем текущий объект
        for (const auto& [key, ticket] : other.tickets) {
            tickets[key] = std::unique_ptr<Ticket>(ticket->clone());
        }
    }
    return *this;
}

// Добавление билета
void TicketRegistry::addTicket(std::unique_ptr<Ticket> ticket) {
    int ticketNumber = ticket->getTicketNumber();
    if (tickets.find(ticketNumber) != tickets.end()) {
        throw std::invalid_argument("Ticket number already exists in registry");
    }
    tickets[ticketNumber] = std::move(ticket);
}

// Проверка билета и обработка попытки прохода
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