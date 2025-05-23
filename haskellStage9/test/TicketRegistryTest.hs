module TicketRegistryTest where

import Test.HUnit
import Ticket
import TicketRegistry

testAddTicket :: Test
testAddTicket = TestCase $ do
    let registry = addTicket (createTicket 1 1000 5) emptyRegistry
    assertEqual "Test add ticket size" 1 (sizeRegistry registry)

testFindTicket :: Test
testFindTicket = TestCase $ do
    let registry = addTicket (createTicket 1 1000 5) emptyRegistry
    assertBool "Test find existing ticket" (findTicket (createTicket 1 1000 5) registry)
    assertBool "Test find non-existing ticket" (not $ findTicket (createTicket 2 1000 5) registry)

runTests :: IO ()
runTests = do
    _ <- runTestTT $ TestList [testAddTicket, testFindTicket]
    return ()