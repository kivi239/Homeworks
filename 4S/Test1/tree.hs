data Tree a = Leaf a | Branch (Tree a) a (Tree a)

findNegative :: Tree Int -> [Int]
findNegative t = findHelper t []

findHelper :: Tree Int -> [Int] -> [Int]
findHelper (Leaf a) l = if (a < 0) then (a : l)
						  else l
fnHelper (Branch l a r) list = if (a < 0) then fnHelper r (a : (fnHelper l list))
							else fnHelper r (fnHelper l list)

