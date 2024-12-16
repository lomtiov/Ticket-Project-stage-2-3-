#include <iostream>
#include <cassert>
#include <stdexcept>
#include "TimeLimitedTicket.h"

void TestTimeLimitedTicket() {
    TimeLimitedTicket ticket(1, 1000, 3600);  // Срок действия — 1 час
    assert(ticket.attemptPass(2000) == true);  // В пределах срока действия
    assert(ticket.attemptPass(5000) == false); // Срок истёк

    try {
        TimeLimitedTicket invalidTicket(1, 1000, -10);
        assert(false);  // Ожидаем выброс исключения
    } catch (std::invalid_argument& e) {
        assert(std::string(e.what()).find("Invalid validity period") != std::string::npos);
    }
}

int main() {
    TestTimeLimitedTicket();
    std::cout << "All tests passed for TimeLimitedTicket!" << std::endl;
    return 0;
}