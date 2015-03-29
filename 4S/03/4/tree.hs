data Tree a = Leaf a | Branch (Tree a) a (Tree a)

treeHeight :: Tree a -> Int
treeHeightHelper :: Tree a -> Int -> Int
treeHeight t = treeHeightHelper t 0
treeHeightHelper (Leaf x) h = h
treeHeightHelper (Branch l x r) h = 1 + max (treeHeightHelper l h) (treeHeightHelper r h) 

minDistToLeaf :: Tree a -> Int
minDistToLeafHelper :: Tree a -> Int -> Int
minDistToLeaf t = minDistToLeafHelper t 0
minDistToLeafHelper (Leaf a) d = d
minDistToLeafHelper (Branch l x r) d = 1 + min (minDistToLeafHelper l d) (minDistToLeafHelper r d)