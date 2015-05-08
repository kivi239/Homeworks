evenFilter :: [Int] -> Int
evenFilter l = length $ filter (\x -> (x `mod` 2 == 0)) l

evenFoldr :: [Int] -> Int
evenFoldr l = foldr (\x y -> y + ((x + 1) `mod` 2)) 0 l 

evenMap :: [Int] -> Int
evenMap l = sum $ map (\x -> (x+1) `mod` 2) l