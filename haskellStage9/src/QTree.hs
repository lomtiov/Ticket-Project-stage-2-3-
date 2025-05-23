module QTree (
    QTree,
    emptyQTree,
    insertQTree,
    searchQTree,
    sizeQTree
) where

data QTree a = Empty | Node a (QTree a) (QTree a) (QTree a) (QTree a)
    deriving (Show, Eq)

emptyQTree :: QTree a
emptyQTree = Empty

insertQTree :: Eq a => a -> QTree a -> QTree a
insertQTree x Empty = Node x Empty Empty Empty Empty
insertQTree x (Node root nw ne sw se) = Node root (insertQTree x nw) ne sw se

searchQTree :: Eq a => a -> QTree a -> Bool
searchQTree _ Empty = False
searchQTree x (Node root nw ne sw se)
    | x == root = True
    | otherwise = searchQTree x nw || searchQTree x ne || searchQTree x sw || searchQTree x se

sizeQTree :: QTree a -> Int
sizeQTree Empty = 0
sizeQTree (Node _ nw ne sw se) = 1 + sizeQTree nw + sizeQTree ne + sizeQTree sw + sizeQTree se
