import Test.QuickCheck

newtype Polynom = Polynom [Int] deriving (Eq)

sumPoly :: Polynom -> Polynom -> Polynom
sum' :: [Int] -> [Int] -> [Int]
sum' [] q = q
sum' p [] = p
sum' (x:p) (y:q) = (x + y) : (sum' p q)
sumPoly (Polynom []) (Polynom q) = Polynom q
sumPoly (Polynom p) (Polynom []) = Polynom p
sumPoly (Polynom p) (Polynom q) = Polynom (sum' p q)

invPoly :: Polynom -> Polynom
invPoly' :: [Int] -> [Int]
invPoly' [] = []
invPoly' (x:p) = (-x):invPoly'(p)
invPoly (Polynom p) = Polynom (invPoly' p)

diffPoly :: Polynom -> Polynom -> Polynom
diffPoly p q = sumPoly p (invPoly(q))


first :: [Int] -> Int -> [Int]
first p n = if (n > length p) then p ++ (replicate (n - length p) 0)         
            else take n p

multPoly :: Polynom -> Polynom -> Polynom
multPoly (Polynom p) (Polynom q) = Polynom [sum $ zipWith (*) (first p n) (reverse (first q n)) | n <- [1..(length p + length q)]]


poly1 = Polynom [1, 2, 3]
poly2 = Polynom [0, 1]


signOfCoeff :: Int -> String
signOfCoeff k = if (k > 0) then "+"
                else ""

printMono :: Int -> Int -> String
printMono 0 d = ""
printMono k 0 = show k
printMono 1 1 = "+x"
printMono k 1 = signOfCoeff(k) ++ show k ++ "x"
printMono 1 d = "+x^" ++ show d
printMono k d = signOfCoeff(k) ++ show k ++ "x^" ++ show d

cutPluses :: String -> String
cutPluses ('+':s) = cutPluses s
cutPluses s = s

printPoly :: [Int] -> String
printPoly' :: [Int] -> Int -> String
printPoly' [] d = ""
printPoly' (k:p) d = (printMono k d) ++ printPoly' p (d + 1) 

printPoly p = cutPluses (printPoly' p 0)

instance Show Polynom where
	show (Polynom p) = printPoly p

main = do
	print $ show (sumPoly poly1 poly2)  -- "1 + 3x + 3x^2"
	print $ show (diffPoly poly1 poly2) -- "1 + x + 3x^2"
	print $ show (multPoly poly1 poly2) -- "x + 2x^2 + 3x^3"
