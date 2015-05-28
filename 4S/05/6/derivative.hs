import Test.QuickCheck

data Expr = X | Const Int | Expr :+: Expr | Expr :*: Expr | Expr :-: Expr | Expr :^: Int
            deriving (Eq)

takeDerivative :: Expr -> Expr
takeDerivative (X) = Const 1
takeDerivative (Const c) = Const 0
takeDerivative (expr1 :+: expr2) = (takeDerivative expr1) :+: (takeDerivative expr2)
takeDerivative (expr1 :-: expr2) = (takeDerivative expr1) :-: (takeDerivative expr2)
takeDerivative (expr1 :*: expr2) = ((takeDerivative expr1) :*: expr2) :+: (expr1 :*: (takeDerivative expr2))
takeDerivative (expr :^: n) = (Const n) :*: (expr :^: (n - 1)) 

simplify' :: Expr -> Expr
simplify' (Const 0 :+: expr) = expr
simplify' (Const 1 :*: expr) = expr
simplify' (Const 0 :*: expr) = Const 0
simplify' (Const 0 :^: n) = Const 0
simplify' (expr :+: Const 0) = expr
simplify' (expr :*: Const 1 ) = expr
simplify' (expr :*: Const 0) = Const 0
simplify' (expr :^: 0) = Const 1
simplify' (expr :^: 1) = expr
simplify' (Const n :+: Const m) = Const (n + m)
simplify' (Const n :*: Const m) = Const (n * m)
simplify' (Const n :-: Const m) = Const (n - m)
simplify' (Const n :^: m) = Const (n ^ m)
simplify' expr = expr

simplify :: Expr -> Expr
simplify (expr1 :+: expr2) = simplify' (simplify expr1 :+: simplify expr2)
simplify (expr1 :*: expr2) = simplify' (simplify expr1 :*: simplify expr2)
simplify (expr1 :-: expr2) = simplify' (simplify expr1 :-: simplify expr2)
simplify (expr :^: n) = simplify' (simplify expr :^: n)
simplify expr = expr

calculate :: Expr -> Int -> Int
calculate (Const c) x = c
calculate (X) x = x
calculate (expr1 :+: expr2) x = (calculate expr1 x) + (calculate expr2 x)
calculate (expr1 :*: expr2) x = (calculate expr1 x) * (calculate expr2 x)
calculate (expr1 :-: expr2) x = (calculate expr1 x) - (calculate expr2 x)
calculate (expr :^: n) x = (calculate expr x) ^ n

testExpr1 = (Const 1) :+: ((Const 2) :*: X) :+: ((Const 3) :*: X :*: X)
testExpr2 = (Const 2) :+: ((Const 6) :*: X)

main = do
    quickCheck (\s -> calculate (takeDerivative testExpr1) s == calculate testExpr2 s)
