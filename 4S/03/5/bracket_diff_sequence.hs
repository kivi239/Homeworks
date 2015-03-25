isCBS :: String -> Bool
isCBS str = isCBShelper str []

isCBShelper :: String -> String -> Bool
isCBShelper [] st = ((length st) == 0)
isCBShelper ('(':s) st = isCBShelper s ('(':st)
isCBShelper ('[':s) st = isCBShelper s ('[':st)
isCBShelper ('{':s) st = isCBShelper s ('{':st)
isCBShelper (')':s) ('(':st) = isCBShelper s st
isCBShelper (']':s) ('[':st) = isCBShelper s st
isCBShelper ('}':s) ('{':st) = isCBShelper s st
isCBShelper (')':s) st = False
isCBShelper (']':s) st = False
isCBShelper ('}':s) st = False