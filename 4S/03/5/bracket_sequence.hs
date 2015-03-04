isCBS :: String -> Bool
isCBS str = isCBShelper str 0

signOfBracket :: Char -> Int
signOfBracket '(' = 1
signOfBracket ')' = -1

isCBShelper :: String -> Int -> Bool
isCBShelper [] x = (x == 0)
isCBShelper (c:str) x = if (x < 0) then False
					else isCBShelper str (x + signOfBracket c)