import Control.Monad.State

data HashTable key value = HashTable {hash :: (key -> Int), table :: [(Int, value)]}

findByKey :: key -> HashTable key value -> [value]

findByKey' :: Int -> [(Int, value)] -> [(value)]
findByKey' k [] = []
findByKey' k ((x, y) : xs) = if (k == x) then y:(findByKey' k xs)
                             else findByKey' k xs
findByKey k (HashTable h t) = findByKey' (h(k)) t 


findInList :: (Eq value) => value -> [value] -> Bool
findInList v [] = False
findInList v (x:xs) = if (v == x) then True
                      else findInList v xs

addValue :: (Eq value) => key -> value -> HashTable key value -> HashTable key value
addValue k v (HashTable h t) = if (findInList v (findByKey k (HashTable h t))) then HashTable h t
                               else HashTable h ((h(k), v):t)


add' :: (Eq value) => key -> value -> State (HashTable key value) (HashTable key value)
add' k v = do
        x <- get
        put (addValue k v x)
        return x

add :: (Eq value) => key -> value -> HashTable key value -> HashTable key value
add k v (HashTable h t) = snd (runState (add' k v) (HashTable h t))


removeRec :: (Eq value) => key -> value -> HashTable key value -> HashTable key value

removeRec' :: (Eq value) => Int -> value -> [(Int, value)] -> [(Int, value)]
removeRec' k v [] = []
removeRec' k v ((x, y):xs) = if (k == x && v == y) then xs
                             else (x, y):(removeRec' k v xs) 

removeRec k v (HashTable h t) = if (findInList v (findByKey k (HashTable h t))) then HashTable h (removeRec' (h(k)) v t)
                                else HashTable h t

remove' :: (Eq value) => key -> value -> State (HashTable key value) (HashTable key value)
remove' k v = do
         x <- get
         put (removeRec k v x)
         return x

remove :: (Eq value) => key -> value -> HashTable key value -> HashTable key value
remove k v (HashTable h t) = snd (runState (remove' k v) (HashTable h t))
