sumOfDigits :: Int -> Int
sumOfDigits 0 = 0
sumOfDigits n = (mod n 10) + sumOfDigits(div n 10)
