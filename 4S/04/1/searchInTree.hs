import Test.HUnit

data Tree a = Leaf a | Branch (Tree a) a (Tree a)

findElement :: (a -> Bool) -> Tree a -> [a]

findElement cond (Leaf n) = if (cond n) then [n]
							else []

findElement cond (Branch l n r) = if (cond n) then (n : findElement cond l) ++ findElement cond r
								  else (findElement cond l) ++ (findElement cond r)

tree = Branch (Branch (Leaf (-4)) 2 (Leaf (-5))) 1 (Branch (Leaf 6) 3 (Leaf 7))

testForEven = TestCase $ assertEqual "\\x -> (mod x 2) == 0" [2, -4, 6] $ findElement (\x -> (mod x 2) == 0) tree
testForNegative = TestCase $ assertEqual "\\x -> x < 0" [-4, -5] $ findElement (\x -> x < 0) tree 

tests = TestList [TestLabel "test for even" testForEven, TestLabel "test for negative" testForNegative]

main = runTestTT tests
