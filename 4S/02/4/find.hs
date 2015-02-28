findInList :: Int -> [Int] -> Int
findInList a xs = findInListHelper a xs 0
findInListHelper :: Int -> [Int] -> Int -> Int
findInListHelper a [] id = -1
findInListHelper a (x:xs) id = if (a == x) then id
	                  else findInListHelper a xs (id + 1)