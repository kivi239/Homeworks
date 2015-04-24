import System.Random
import Control.Monad.State

changeValues :: [Int] -> [Int]
changeValues' :: [Int] -> Int -> [Int]

getRand :: Int
getRand = let 
	g = mkStdGen 100
	a = randoms g :: [Int]
	in head a 

changeValues xs = changeValues' xs 0
changeValues' (x:y:xs) pos = x:(getRand):(changeValues xs)
changeValues' (xs) pos = xs

