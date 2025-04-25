module QTree
    ( QTree
    , emptyQTree
    , insert
    , search
    , size
    , showTree
    ) where

-- Пример структуры данных QTree
data QTree a = Leaf a | Node (QTree a) (QTree a) (QTree a) (QTree a)
    deriving (Show, Eq)

-- Пустое дерево
emptyQTree :: QTree a
emptyQTree = error "QTree is not fully implemented."

-- Вставка элемента
insert :: a -> QTree a -> QTree a
insert = error "Insert is not implemented."

-- Поиск элемента
search :: Eq a => a -> QTree a -> Bool
search = error "Search is not implemented."

-- Размер дерева
size :: QTree a -> Int
size = error "Size is not implemented."

-- Печать дерева
showTree :: Show a => QTree a -> String
showTree = error "ShowTree is not implemented."