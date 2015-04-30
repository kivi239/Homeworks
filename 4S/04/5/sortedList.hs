import Data.Char

talkToUser :: IO()
talkToUser = do
    putStrLn "Please, enter the command:"
    putStrLn "0 - exit"
    putStrLn "1 - add value to sorted list"
    putStrLn "2 - remove value from sorted list"
    putStrLn "3 - print list"

add :: Int -> [Int] -> [Int]
add v [] = [v]
add v (x:xs) = if (v <= x) then (v:x:xs)
               else (x:(add v xs))

remove :: Int -> [Int] -> [Int]
remove v [] = []
remove v (x:xs) = if (v == x) then xs
                  else if (v < x) then (x:xs)
                       else (x:(remove v xs))

stringToInt :: String -> Int
stringToInt' :: String -> Int -> Int
stringToInt s = stringToInt' s 0
stringToInt' (s:xs) x = stringToInt' xs (x * 10 + digitToInt(s))
stringToInt' _ x = x

commands :: [Int] -> IO()
commands l = do
    talkToUser
    com <- getLine
    case com of 
        "0" -> return ()
        "1" -> do
            v <- getLine
            commands (add (stringToInt v) l)
        "2" -> do
            v <- getLine
            commands (remove (stringToInt v) l)
        "3" -> do
            putStrLn (show l)
            commands (l) 
        _ -> do
            putStrLn "wrong command"
            commands l

main = do 
	commands []
