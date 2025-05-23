module Ticket (
    Ticket(..)
) where

data Ticket = Ticket
    { ticketId :: Int
    , description :: String
    , date :: String
    } deriving (Show, Eq)