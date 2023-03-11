Assignment: Construct a PDA that accepts { x#y | x, y in {0, 1}* such that x ≠ y and xi = yi for some i, 1 ≤ i ≤ min(|x|, |y|) }.

Technically, the assignment says "input strings of length up to about 80 symbols" but these strings are 257 (128 0's/1's + # + 128 0's/1's).
Sets ending in 'r' should all reject, sets ending in 'a' should all accept. 

Set0r should reject because x = y  
Set1r should reject because xi != yi for every 1 <= i <= |x| (|x| == |y|)  
Set2r should reject because xi != yi for every 1 <= i <= |x| (|x| < |y|)  
Set3r should reject because xi != yi for every 1 <= i <= |y| (|x| > |y|)  

Set4a should accept with |x| == |y| (first 5: xi != yi for a singular i // second 5: xi == yi for a singular i)  
Set5a should accept with |x| < |y| (first 5: xi != yi for a singular i // second 5: xi == yi for a singular i)  
Set6a should accept with |x| < |y| and xi == xi for every 1 <= i <= |x|  
Set7a should accept with |x| > |y| (first 5: xi != yi for a singular i // second 5: xi == yi for a singular i)  
Set8a should accept with |x| > |y| and xi == xi for every 1 <= i <= |y|  
