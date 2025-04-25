module Ticket where

data Ticket = Ticket
    { ticketNumber :: Int
    , saleTime     :: String
    , remainingTrips :: String
    } deriving (Show, Eq)

createTicket :: Int -> String -> String -> Ticket
createTicket number time trips = Ticket number time trips