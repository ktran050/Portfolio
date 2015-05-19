Stability
A) My selection sort would be stable. If the smallest value at the ith element to be sorted
is equal to the ith element then I don't swap, thus if we had
{2,2,3(the first one),4,3(the second one),5,6}

and we were on the third element, after looking for the smallest element(3)
nothing would change AND we wouldn't swap 3 and 3.

On the next iteration, 3 and 4 are swapped and the first three stays ahead
{2,2,3(the first one),3(the second one),4,5,6}

B) The program would look something like:
Create a class with member of type int
Push members of the class with letters of the alphabet into a vector ( while taking care to push two letters with the same value )
Call selectionsort
Output it and show that its stable
