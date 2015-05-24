import Test.HUnit

data BinaryTree a = Empty | Node a (BinaryTree a) (BinaryTree a)
                    deriving (Eq, Show)

add :: (Ord a) => a -> BinaryTree a -> BinaryTree a
add x Empty = Node x Empty Empty
add x (Node y l r) = if (x < y) then Node y (add x l) r
	                 else if (x > y) then Node y l (add x r)
                     else Node y l r

mostLeft :: (Ord a) => BinaryTree a -> a
mostLeft (Node x Empty r) = x
mostLeft (Node x l r) = mostLeft l

remove :: (Ord a) =>  a -> BinaryTree a -> BinaryTree a
remove x Empty = Empty
remove x (Node y l r) = 
    if (x > y) then Node y l (remove x r)
    else if (x < y) then Node y (remove x l) r
    else if (l == Empty) then r
    else if (r == Empty) then l
    else Node ml l (remove ml r) where ml = mostLeft l
		
height :: BinaryTree a -> Int		
height Empty = 0
height (Node x l r) = 1 + (max (height l) (height r))

size :: BinaryTree a -> Int
size Empty = 0
size (Node x l r) = 1 + (size l) + (size r) 

find :: (Ord a) => a -> BinaryTree a -> Bool
find x Empty = False
find x (Node y l r) = if (x < y) then find x l
	                  else if (x > y) then find x r
					  else True  

tree = add 4 (add 1 (add 2 (add 3 Empty)))

main = do
    print $ show (remove 2 tree) -- "Node 3 (Node 1 Empty Empty) (Node 4 Empty Empty)"
    print $ height tree -- 3 
    print $ find 4 tree -- True
    print $ find 2 (remove 2 tree) -- False
