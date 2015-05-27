import Control.Exception.Base
import Data.Char

talkToUser :: IO()
talkToUser = do
	putStrLn "Please, enter the command:"
	putStrLn "0 - exit"
	putStrLn "1 - add name and phone number"
	putStrLn "2 - find phone number by name"
	putStrLn "3 - find name by phone number"
	putStrLn "4 - save phonebook to file"
	putStrLn "5 - read data from file"

type PhoneBook = [(String, Int)]

findName :: String -> PhoneBook -> Int
findName _ [] = -1
findName name ((a,b):xs) = if (name == a) then b
                           else findName name xs
findNumber :: Int -> PhoneBook -> String
findNumber _ [] = "-1"
findNumber num ((a,b):xs) = if (num == b) then a
                            else findNumber num xs

add :: (String, Int) -> PhoneBook -> PhoneBook
add (name, num) book = if (findName name book == -1 && findNumber num book == "-1") then (name, num):book
                       else book

stringToInt :: String -> Int
stringToInt' :: String -> Int -> Int
stringToInt s = stringToInt' s 0
stringToInt' (s:xs) x = stringToInt' xs (x * 10 + digitToInt(s))
stringToInt' _ x = x

commands :: PhoneBook -> IO()
commands book = do
    talkToUser
    command <- getLine
    case (command) of 
        "0" -> return ()
        "1" -> do 
               args <- getLine
               case (words args) of
                   [name, number] -> commands (add (name, stringToInt number) book)
                   _ -> fail "Wrong arguments"
        "2" -> do 
               args <- getLine
               case (words args) of
                   [name] -> do 
                    	  let num = findName name book
                    	  if (num == -1) then putStrLn "No numbers found"
                    	  else putStrLn $ show num
                          commands book
                   _ -> fail "Wrong arguments"
        "3" -> do 
               args <- getLine
               case (words args) of
                    [number] -> do 
                           let name = findNumber (stringToInt number) book
                           if (name == "-1") then putStrLn "Nobody found"
                           else putStrLn $ show name
                           commands book
                    _ -> fail "Wrong arguments"
        "4" -> do 
               args <- getLine
               case (words args) of
                   [file] -> do 
                          writeFile file (show book)
                          commands book
                   _ -> fail "Wrong arguments"
        "5" -> do
               args <- getLine
               file <- readFile (args)
               bookToPrint <- readIO file :: IO PhoneBook
               commands bookToPrint
        _   -> fail $ "Wrong command"
    `catch` (\e -> do putStrLn (show (e :: IOError)); commands book)

main = commands []