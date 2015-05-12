printPartition :: Int -> IO()
printPartition' :: [[Int]] -> IO()

printPartition n = printPartition' (partition n)
printPartition' [x] = printList x
printPartition' (x:xs) = do
						printList x
						printPartition' xs

printList :: [Int] -> IO()
printList [n] = print n
printList (x:xs) = do
				putStr . show $ x
				putChar '+'
				printList xs

partition :: Int -> [[Int]]
partition n = partition' n 1

partition' 0 summ = [[]]
partition' n summ = if (summ > n) then []
                    else map (summ:) (partition' (n - summ) summ) ++ partition' n (summ + 1)