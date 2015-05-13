import Control.Monad
import Test.HUnit

findLocalMax :: [Int] -> Maybe Int
findLocalMax [] = Nothing
findLocalMax [x] = Nothing
findLocalMax [x, y] = Nothing
findLocalMax (x:y:z:xs) = if (x < y && y > z) then Just y
                          else findLocalMax (y:z:xs)

testInc = TestCase $ assertEqual "[1..100]" Nothing $ findLocalMax [1..100]
testWithMax = TestCase $ assertEqual "[1, 2, 1, 3, 2]" (Just 2) $ findLocalMax [1, 2, 1, 3, 2]

tests = TestList [TestLabel "test for increasing sequence" testInc, TestLabel "test with maximum" testWithMax]

main = runTestTT tests