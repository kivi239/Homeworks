data Tree a = Leaf a | Branch (Tree a) a (Tree a)

treeHeight :: Tree a -> Int
treeHeightHelper :: Tree a -> Int -> Int
treeHeight t = treeHeightHelper t 0
treeHeightHelper (Leaf x) h = h
treeHeightHelper (Branch l x r) h = 1 + max (treeHeightHelper l h) (treeHeightHelper r h) 