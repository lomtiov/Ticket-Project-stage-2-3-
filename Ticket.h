#ifndef TICKET_H
#define TICKET_H

#include <stdexcept>
#include <string>

class Ticket {
protected:
    int ticketNumber;      // Уникальный номер билета
    int saleTime;          // Время продажи (в секундах)

public:
    Ticket(int ticketNumber, int saleTime);
    virtual ~Ticket() = default;  // Виртуальный деструктор для полиморфизма

    int getTicketNumber() const;
    int getSaleTime() const;

    // Чисто виртуальная функция для проверки возможности прохода
    virtual bool attemptPass(int currentTime) = 0;

    // Виртуальные операторы сравнения
    virtual bool operator==(const Ticket& other) const;
    virtual bool operator<(const Ticket& other) const;
};

#endif // TICKET_H