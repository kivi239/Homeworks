powersOfTwo :: Int -> [Int]
powersOfTwo n = [2^m | m <- [0..n]]