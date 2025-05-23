module TicketRegistry (
    TicketRegistry,
    emptyRegistry,
    addTicket,
    findTicket,
    sizeRegistry
) where

import Ticket
import QTree (QTree, emptyQTree, insertQTree, searchQTree, sizeQTree)

type TicketRegistry = QTree Ticket

emptyRegistry :: TicketRegistry
emptyRegistry = emptyQTree

addTicket :: Ticket -> TicketRegistry -> TicketRegistry
addTicket = insertQTree

findTicket :: Ticket -> TicketRegistry -> Bool
findTicket = searchQTree

sizeRegistry :: TicketRegistry -> Int
sizeRegistry = sizeQTree