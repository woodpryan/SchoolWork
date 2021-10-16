/*
Interpolation Search. Much like binary search except that the list
is divided not by half, but by an integer more relevant to the data
*/

/*
X1, Y1 - Y1, Y2, looking for xy
left of array,    right of array

a[L] a[R] 

x is value we are looking for

equation of a line is x = x1 + ((y-y1)(x2 - x1)/(y2 - y1))
l is lefthand subscript
x = l + (((v - a[l]) * (r - l))/ (a[r] - a[l]))

interpolation search is effective for large amounts of data

access slow device
data should be relatively incrementing
*/
