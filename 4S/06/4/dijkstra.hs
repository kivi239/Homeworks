import Control.Monad.State
import Test.QuickCheck


data Graph v e = Graph [(Int, v)] [(Int, Int, e)]

inf = maxBound :: Int

replace :: [(Int, Int)] -> (Int, Int) -> [(Int, Int)]
replace e (l, r) = map (\(x, y) -> if (x == l) then (l, r) else (x, y)) e

findNextVert :: [(Int, Int)] -> (Int, Int)

findNextVert' :: (Int, Int) -> [(Int, Int)] -> (Int, Int) 
findNextVert' v [] = v 
findNextVert' (cx, cy) ((x, y):xs) = if y < cy then findNextVert' (x, y) xs 
                                     else findNextVert' (cx, cy) xs 

findNextVert (x:xs) = findNextVert' x xs

dijkstra' :: [(Int,Int)] -> [(Int,Int,Int)] -> Int -> [(Int, Int)]
dijkstra' v e s = if (length v == 1) then v
                  else 
                      case (lookup s v) of
                      Nothing -> v
                      Just mark -> let dij ((f, t, c):es) = if (s == f) then do
                                                                    new <- get
                                                                    case (lookup t new) of
                                                                        Nothing -> dij es
                                                                        Just m  -> if m < (mark + c)
                                                                                       then dij es
                                                                                   else do
                                                                                       put $ replace new (t, mark + c)
                                                                                       dij es
                                                            else dij es
                                       dij [] = return []
                                   in
                                   let newV = filter (\(x,y) -> x /= s) (execState (dij e) v) in
                                   let p = findNextVert newV in (findNextVert v):(dijkstra' newV e (fst p))

dijkstra :: Graph v Int -> Int -> [(Int, Int)]
dijkstra (Graph v e) src = dijkstra' (map (\(x,y) -> if x == src then (x, 0) else (x, inf)) v) e src


graph = Graph [(1, 0), (2, inf), (3, inf)] [(1, 2, 100), (2, 3, 200), (1, 3, 450)] :: Graph Int Int

main = quickCheck (dijkstra graph 1 == [(1, 0), (2, 100), (3, 300)])
