% База данных билетов
ticket(1, 1000, 5).  % Номер билета, время продажи, оставшиеся поездки
ticket(2, 2000, 2).
ticket(3, 3000, 0).
ticket(4, 1500, 7).
ticket(5, 1800, 1).

% Правило поиска билетов
find_tickets(MinNumber, MinTrips, StartTime, EndTime, TicketNumber) :-
    ticket(TicketNumber, SaleTime, RemainingTrips),
    TicketNumber > MinNumber,
    RemainingTrips >= MinTrips,
    SaleTime >= StartTime,
    SaleTime =< EndTime.