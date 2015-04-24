angleMatrix :: Int -> [[Int]]

angleMatrix n = angleMatrix' n 0
angleMatrix' n num = if (n == num + 1) then [(makeRow n (n - 1))]
					 else (makeRow n num):(angleMatrix' n (num + 1))

makeRow :: Int -> Int -> [Int]
makeRow' :: Int -> Int -> Int -> [Int]
makeRow n num = makeRow' n num 0
makeRow' n num pos = if (pos == n) then []
	                 else 
	                     if (pos <= num) then ((num + 1):(makeRow' n num (pos + 1)))
					     else ((pos + 1):(makeRow' n num (pos + 1)))	