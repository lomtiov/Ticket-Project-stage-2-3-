module Main where

import TicketRegistry
import Ticket

main :: IO ()
main = do
    let registry = emptyRegistry
    let ticket1 = Ticket 1 "Flight to NYC" "2025-12-01"
    let ticket2 = Ticket 2 "Concert Ticket" "2025-11-15"
    let updatedRegistry = addTicket ticket1 (addTicket ticket2 registry)
    putStrLn $ "Registry size: " ++ show (sizeRegistry updatedRegistry)
    putStrLn $ "Is ticket1 in registry? " ++ show (findTicket ticket1 updatedRegistry)