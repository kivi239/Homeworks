import Test.HUnit

areDiff :: (Eq a) => [a] -> Bool
areDiff [] = True
areDiff (x:xs) = if (elem x xs) then False
                 else areDiff xs

test1 = TestCase $ assertEqual "[2, 2]" False $ areDiff [2, 2]
test2 = TestCase $ assertEqual "[1..10]" True $ areDiff [1..10]
test3 = TestCase $ assertEqual "[0, 1, 0]" False $ areDiff [0, 1, 0]
test4 = TestCase $ assertEqual "[239]" True $ areDiff [239]

tests = TestList [TestLabel "test1" test1, TestLabel "test2" test2, TestLabel "test3" test3, TestLabel "test4" test4]

main = runTestTT tests
