check :: (a -> Bool) -> [a] -> Bool
check cond (x:xs) = if (cond x) then check cond xs
                    else False
check cond _ = True
