reverseLinear l = rev l where
	rev [] l = l
	rev (x:xs) l = rev xs (x:l)