import Test.HUnit

data Tree a = Leaf a | Branch (Tree a) a (Tree a)

treeFold :: (a -> a -> a) -> a -> Tree a -> a
treeFold f s (Leaf n) = f s n
treeFold f s (Branch l n r) = treeFold f (treeFold f (f s n) l) r

tree = Branch (Branch (Leaf (-4)) 2 (Leaf (-5))) 1 (Branch (Leaf 6) 3 (Leaf 7))

testMult = TestCase $ assertEqual "\\x y -> x * y, s = 1" 5040 $ treeFold (\x y -> x * y) 1 tree
testSum = TestCase $ assertEqual "\\x y -> x + y, s = 0" 10 $ treeFold (\x y -> x + y) 0 tree

tests = TestList [TestLabel "test multiplication" testMult, TestLabel "test addition" testSum]

main = runTestTT tests 