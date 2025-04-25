module Main where

import TicketRegistry (emptyRegistry, addTicket, findTicket, sizeRegistry)
import Ticket (Ticket(..))
import QTree (showTree)

main :: IO ()
main = do
    let registry = emptyRegistry
        ticket1 = Ticket 1 "Concert" "Alice"
        ticket2 = Ticket 2 "Movie" "Bob"
        updatedRegistry = addTicket ticket1 . addTicket ticket2 $ registry
    putStrLn "Current Registry:"
    putStrLn (showTree updatedRegistry)
    putStrLn "Searching for ticket with ID 1:"
    print (findTicket ticket1 updatedRegistry)
    putStrLn "Total tickets in registry:"
    print (sizeRegistry updatedRegistry)