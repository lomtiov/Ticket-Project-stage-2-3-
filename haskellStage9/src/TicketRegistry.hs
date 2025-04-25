module TicketRegistry (
    TicketRegistry,
    emptyRegistry,
    addTicket,
    findTicket,
    sizeRegistry
) where

import Ticket
import QTree (QTree, emptyQTree, insert, search, size)

type TicketRegistry = QTree Ticket

emptyRegistry :: TicketRegistry
emptyRegistry = emptyQTree

addTicket :: Ticket -> TicketRegistry -> TicketRegistry
addTicket = insert

findTicket :: Ticket -> TicketRegistry -> Bool
findTicket = search

sizeRegistry :: TicketRegistry -> Int
sizeRegistry = size