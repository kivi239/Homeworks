data Tree a = Leaf a | Branch (Tree a) a (Tree a)

findNegative :: Tree Int -> [Int]
findHelper :: Tree Int -> [Int] -> [Int]

findNegative t = findHelper t []

findHelper (Leaf a) l = if (a < 0) then (a : l)
                        else l
findHelper (Branch l a r) list = if (a < 0) then findHelper r (a : (findHelper l list)
                                 else findHelper r (findHelper l list)

