import Control.Monad.Cont

mapWithCont :: (a -> b) -> [a] -> Cont r [b]
mapWithCont f [] = return []
mapWithCont f (x:xs) = mapWithCont f xs >>= return . (f x :)

filterCont :: (a -> Bool) -> [a] -> Cont r [a]
filterCont f [] = return []
filterCont f (x:xs) = if (f(x)) then filterCont f xs >>= return . (x :)
                      else filterCont f xs >>= return