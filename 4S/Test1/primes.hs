primes = 2 : [p | p <- [3..] , isPrime p]

isPrime :: Int -> Bool
isPrimeHelper :: Int -> Int -> Bool
isPrime n = isPrimeHelper n (n - 1)
isPrimeHelper n 1 = True
isPrimeHelper n d = if ((n `mod` d) == 0) then False
					else isPrimeHelper n (d - 1)