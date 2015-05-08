list123 :: Int -> [[Int]]
list123' :: Int -> [[Int]]
list123 n = map reverse (list123' n)
list123' 0 = [[]]
list123' n = concatMap (\x -> [1:x, 2:x, 3:x]) (list123' (n - 1))
