import System.Random
import Data.Time.Clock.POSIX

data Tree a = Leaf a | Branch (Tree a) a (Tree a)
              deriving (Show)
										
getRand :: Int -> Int
getRand x = let 
	g = mkStdGen x
	a = randoms g :: [Int]
	in (head a) `mod` 100 

randomTree :: Tree Int -> Tree Int
randomTree (Leaf x) = (Leaf $ getRand x)
randomTree (Branch l x r) = (Branch (randomTree l) (getRand(x)) (randomTree r))

tree = Branch (Branch (Leaf (-4)) 2 (Leaf (-5))) 1 (Branch (Leaf 6) 3 (Leaf 7))

main = do
	print $ show $ randomTree tree