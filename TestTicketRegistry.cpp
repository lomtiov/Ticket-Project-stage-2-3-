#include <iostream>
#include <cassert>
#include "TicketRegistry.h"
#include "NumTicket.h"
#include "TimeLimitedTicket.h"
#include "UnlimitedTicket.h"

void TestTicketRegistryCopy() {
    TicketRegistry registry1;

    // Добавляем билеты
    registry1.addTicket(std::make_unique<NumTicket>(1, 1000, 3));
    registry1.addTicket(std::make_unique<TimeLimitedTicket>(2, 2000, 3600));
    registry1.addTicket(std::make_unique<UnlimitedTicket>(3, 3000, "Lifetime pass"));

    // Копируем
    TicketRegistry registry2 = registry1;

    // Проверяем, что копия независима
    assert(registry2.processPassAttempt(1, 1100) == "Pass granted.");
    assert(registry1.processPassAttempt(1, 1200) == "Pass granted.");
}

int main() {
    TestTicketRegistryCopy();
    std::cout << "All tests passed for TicketRegistry (copy & assign)!" << std::endl;
    return 0;
}