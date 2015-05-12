import Test.HUnit

pairProduct :: Int -> [Int]

pairProduct n = [1..n] >>= (\x -> map (*x) [1..n])

testForOne = TestCase $ assertEqual "1" [1] $ pairProduct 1
testForThree = TestCase $ assertEqual "3" [1, 2, 3, 2, 4, 6, 3, 6, 9] $ pairProduct 3

tests = TestList [TestLabel "test for one" testForOne, TestLabel "test for three" testForThree]

main = runTestTT tests