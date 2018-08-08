///https://stackoverflow.com/questions/22394257/how-to-count-integers-between-large-a-and-b-with-a-certain-property/22394258#22394258
Indeed, there is an approach to this pattern which turns out to work quite often. It can also be used to enumerate all the X with the given property, provided that their number is reasonably small. You can even use it to aggregate some associative operator over all the X with the given property, for example to find their sum.

To understand the general idea, let us try to formulate the condition X ≤ Y in terms of the decimal representations of X and Y.

Say we have X = x1 x2 ... xn - 1 xn and Y = y1 y2 ... yn - 1 yn, where xi and yi are the decimal digits of X and Y. If the numbers have a different length, we can always add zero digits to the front of the shorter one.

Let us define leftmost_lo as the smallest i with xi < yi. We define leftmost_lo as n + 1 if there is no such i. Analogously, we define leftmost_hi as the smallest i with xi > yi, or n + 1 otherwise.

Now X ≤ Y is true if and exactly if leftmost_lo <= leftmost_hi. With that observation it becomes possible to apply a dynamic programming approach to the problem, that "sets" the digits of X one after another. I will demonstrate this with your example problems:

Compute the number f(Y) of integers X with the property X ≤ Y and X has the digit sum 60
Let n be the number of Y's digits and y[i] be the i-th decimal digit of Y according to the definition above. The following recursive algorithm solves the problem:


count(i, sum_so_far, leftmost_lo, leftmost_hi):
    if i == n + 1:
        # base case of the recursion, we have recursed beyond the last digit
        # now we check whether the number X we built is a valid solution
        if sum_so_far == 60 and leftmost_lo <= leftmost_hi:
            return 1
        else:
            return 0
    result = 0
    # we need to decide which digit to use for x[i]
    for d := 0 to 9
        leftmost_lo' = leftmost_lo
        leftmost_hi' = leftmost_hi
        if d < y[i] and i < leftmost_lo': leftmost_lo' = i
        if d > y[i] and i < leftmost_hi': leftmost_hi' = i
        result += count(i + 1, sum_so_far + d, leftmost_lo', leftmost_hi')
    return result



///Now we have f(Y) = count(1, 0, n + 1, n + 1) and we have solved the problem. We can add memoization to the function to make it fast. The runtime is O(n4) for this particular implementation. In fact we can cleverly optimize the idea to make it O(n). This is left as an exercise to the reader (Hint: You can compress the information stored in leftmost_lo and leftmost_hi into a single bit and you can prune if sum_so_far > 60). The solution can be found at the end of this post.

Compute the number f(Y) of integers X with the property X ≤ Y and X is palindromic
This one is slightly tougher. We need to be careful with leading zeroes: The mirror point of a palindromic number depends on how many leading zeroes we have, so we would need to keep track of the number of leading zeroes.

There is a trick to simplify it a bit though: If we can count the f(Y) with the additional restriction that all numbers X must have the same digit count as Y, then we can solve the original problem as well, by iterating over all possible digit counts and adding up the results.

So we can just assume that we don't have leading zeroes at all:

count(i, leftmost_lo, leftmost_hi):
    if i == ceil(n/2) + 1: # we stop after we have placed one half of the number
        if leftmost_lo <= leftmost_hi:
            return 1
        else:
            return 0
    result = 0
    start = (i == 1) ? 1 : 0    # no leading zero, remember?
    for d := start to 9
        leftmost_lo' = leftmost_lo
        leftmost_hi' = leftmost_hi
        # digit n - i + 1 is the mirrored place of index i, so we place both at
        # the same time here
        if d < y[i]     and i     < leftmost_lo': leftmost_lo' = i
        if d < y[n-i+1] and n-i+1 < leftmost_lo': leftmost_lo' = n-i+1
        if d > y[i]     and i     < leftmost_hi': leftmost_hi' = i
        if d > y[n-i+1] and n-i+1 < leftmost_hi': leftmost_hi' = n-i+1
        result += count(i + 1, leftmost_lo', leftmost_hi')
    return result
The result will again be f(Y) = count(1, n + 1, n + 1).

UPDATE: If we don't only want to count the numbers, but maybe enumerate them or compute some aggregate function from them which does not expose group structure, we need to enforce the lower bound on X as well during the recursion. This adds a few more parameters.

UPDATE 2: O(n) Solution for the "digit sum 60" example:

In this application we place the digits from left to right. Since we are only interested in whether leftmost_lo < leftmost_hi holds true, let us add a new parameter lo. lo is true iif leftmost_lo < i and false otherwise. If lo is true, we can use any digit for the position i. If it is false, we can only use the digits 0 to Y[i], since any larger digit would cause leftmost_hi = i < leftmost_lo and can thus not lead to a solution. Code:

def f(i, sum_so_far, lo):
    if i == n + 1: return sum_so_far == 60
    if sum_so_far > 60: return 0
    res = 0
    for d := 0 to (lo ? 9 : y[i]):
         res += f(i + 1, sum + d, lo || d < y[i])
    return res
Arguably, this way of looking at it is somewhat simpler, but also a bit less explicit than the leftmost_lo/leftmost_hi approach. It also doesn't work immediately for somewhat more complicated scenarios like the palindrome problem (although it can be used there as well).
