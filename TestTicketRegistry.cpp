#include <iostream>
#include <cassert>
#include "TicketRegistry.h"
#include "NumTicket.h"
#include "TimeLimitedTicket.h"
#include "UnlimitedTicket.h"

void TestTicketRegistry() {
    TicketRegistry registry;

    // Добавляем билеты
    registry.addTicket(std::make_unique<NumTicket>(1, 1000, 3));
    registry.addTicket(std::make_unique<TimeLimitedTicket>(2, 2000, 3600));
    registry.addTicket(std::make_unique<UnlimitedTicket>(3, 3000, "Lifetime pass"));

    // Проверяем работу
    assert(registry.processPassAttempt(1, 1100) == "Pass granted.");   // NumTicket
    assert(registry.processPassAttempt(1, 1200) == "Pass granted.");
    assert(registry.processPassAttempt(1, 1300) == "Pass granted.");
    assert(registry.processPassAttempt(1, 1400) == "Pass denied.");    // Больше поездок нет

    assert(registry.processPassAttempt(2, 2500) == "Pass granted.");   // TimeLimitedTicket
    assert(registry.processPassAttempt(2, 6000) == "Pass denied.");    // Истёк срок действия

    assert(registry.processPassAttempt(3, 3100) == "Pass granted.");   // UnlimitedTicket
    assert(registry.processPassAttempt(3, 3200) == "Pass denied.");    // Меньше 3 минут
    assert(registry.processPassAttempt(3, 4000) == "Pass granted.");   // Прошло больше 3 минут

    assert(registry.processPassAttempt(999, 5000) == "ALARM: Ticket not found!");  // Несуществующий билет

    std::cout << "All tests passed for TicketRegistry!" << std::endl;
}

int main() {
    TestTicketRegistry();
    return 0;
}