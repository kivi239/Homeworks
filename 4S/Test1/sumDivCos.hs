sumDivCos :: [Float] -> Float
sumOfNums :: [Float] -> Float -> Float
mulOfCos :: [Float] -> Float -> Float

sumDivCos xs = (sumOfNums xs 0) / (mulOfCos xs 1)

sumOfNums (x:xs) s = sumOfNums xs (x + s)
sumOfNums [] s = s

mulOfCos (x:xs) s = mulOfCos xs (s * cos(x))
mulOfCos [] s = s


