import Test.HUnit

data Tree a = Node (Tree a) a (Tree a) | Empty

treeToStr :: Tree Char -> String
treeToStr' :: Tree Char -> String -> String

treeToStr t = treeToStr' t ""

treeToStr' Empty s = 'e':s
treeToStr' (Node left x right) s = 'n':x:(treeToStr' left (treeToStr' right s))


strToTree :: String -> Tree Char
strToTree' :: String -> (Tree Char, String)

strToTree s = fst $ strToTree' s

strToTree' ('e':xs) = (Empty, xs)
strToTree' ('n':xs) = 
              let 
                  a = strToTree' $ tail xs
                  l = fst a
                  ls = snd a
                  b = strToTree' ls
                  r = fst b
                  rs = snd b
              in (Node l (head xs) r, rs)  


string = "nanbeencee"
tree = (Node (Node Empty 'b' Empty) 'a' (Node Empty 'c' Empty))
testStr = TestCase $ assertEqual "tree" "nanbeencee" $ treeToStr tree
testTree = TestCase$ assertEqual "string" "nanbeencee" $ treeToStr(strToTree "nanbeencee")
tests = TestList [TestLabel "test tree to string" testStr, TestLabel "test string to tree" testTree]

main = runTestTT tests