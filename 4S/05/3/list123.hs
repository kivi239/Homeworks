list123 :: Int -> [[Int]]

list123 0 = [[]]
list123 n = concatMap (\x -> [x ++ [1], x ++ [2], x ++ [3]]) (list123 (n - 1))
