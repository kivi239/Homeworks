import System.Random
import Control.Monad.State

changeValues :: [Int] -> [Int]

getRand :: Int
getRand = let 
	g = mkStdGen 100
	a = randoms g :: [Int]
	in head a 

changeValues (x:y:xs) = x:(getRand):(changeValues xs)
changeValues (xs) = xs

