module QTreeTest where

import Test.HUnit
import QTree

testInsert :: Test
testInsert = TestCase $ do
    let tree = foldr insert emptyQTree [5, 3, 8, 2, 4]
    assertEqual "Test size after insert" 5 (size tree)
    assertBool "Test search existing value" (search 3 tree)
    assertBool "Test search non-existing value" (not $ search 10 tree)

testEmpty :: Test
testEmpty = TestCase $ do
    let tree = emptyQTree :: QTree Int
    assertEqual "Test size of empty tree" 0 (size tree)
    assertBool "Test search in empty tree" (not $ search 1 tree)

testShowTree :: Test
testShowTree = TestCase $ do
    let tree = foldr insert emptyQTree [5, 3, 8]
    let expectedOutput = "5\n  3\n  8\n"
    assertEqual "Test show tree" expectedOutput (show tree)

runQTreeTests :: IO ()
runQTreeTests = do
    _ <- runTestTT $ TestList [testInsert, testEmpty, testShowTree]
    return ()