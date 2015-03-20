maxSum :: [Int] -> Int
maxSumHelper :: [Int] -> Int -> Int -> Int -> Int
maxSumHelper (x:y:xs) sum pos cur = if (x + y > sum) then maxSumHelper (y:xs) (x + y) (cur) (cur + 1)
									else maxSumHelper (y:xs) sum pos (cur + 1)
maxSumHelper (x:xs) sum pos cur = pos

maxSum xs = maxSumHelper xs 0 1 1									