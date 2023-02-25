# The Role of Algorithms in Computing

^229144

## Algorithms
An **algorithm** is any well-defined computational procedure that takes some value, or a set of values, as **input** and produces some value, or a set of values, as **output**. <br>
It can be viewed as a tool for solving a well-specifed ***computational problem***. <br>
In general, an ***instance of a problem*** consists of the input needed to compute a solution to the problem.<br>
An algorithm is said to be **correct** if, for every input instance, it halts with the correct output. We say that a correct algorithm ***solves*** the given computational problem.<br>
Incorrect algorithms can also be useful, if we control their error rate.
### Data Structure
A ***data structure*** is a way to store an organize data in order to facilitate access and modifications.
## Algorithms as a technology
### Efficiency
Different algorithms devised to solve the same problem often differe dramatically in their efficieny. These differences can be much more significant than differences due to hardware and software.
# Getting Started
## Insertion Sort
> Input: A sequence of n numbers {a<sub>1</sub>, a<sub>2</sub>, a<sub>3</sub>,...,a<sub>n</sub>}
> Output: A permutation (reordering) {a'<sub>1</sub>,a'<sub>2</sub>,a'<sub>3</sub>,a'<sub>4</sub>,...a'<sub>n</sub>} of the input sequence such that a'<sub>1</sub>&le;a'<sub>2</sub>&le;a'<sub>3</sub>&le;...&le;a'<sub>n</sub>

The numbers that we wish to sort are also known as the ***keys***.<br> 
Insertion sort works the way many people sort a hand of playing cards. We start with an empty left hand and the cards face down on the table. We then remove one card at a time from the table and insert it into the correct position in the left hand. To find the correct position for a card, we compare it with each of the cards already in the hand, from right to left. At all times, the cards in the left hand are sorted, and thes cards were originally the top cards of the pile on the table.<br>
The algorithm sorts the input numbers ***in-place***: it rearranges the numbers within the array A, with atmost a constant number of then stored outside the array at any time.
```cpp
INSERTION_SORT(A)
1 for j = 2 to A.length
2	key = A[j]
3	// Insert A[j] into the sorted sequence A[1...j-1]
4	i = j - 1
5	while ( i>0 && A[i]>key )
6		A[i+1] = A[i]
7		i = i-1
8	A[i+1] = key
```
### **Loop invariants and the correctness of insertion sort**
At the beginning of each iteration of the `for` loop, which is indexed by j, the subarray consisting of elements `A[1...j-1]` constitutes the currently sorted hand, and the remaining subarray `A[j+1...n]` corresponds to the pile of cards still on the table. In fact elements `A[1...j-1]` are the elements *originally* in positions 1 through *j-1*, but now in sorted order. We state these properties of `A[1...j-1]` formally as a ***loop invariant***:<br>
At the start of each iteration of the `for` loop of lines 1-8, the subarray `A[1...j-1]` consists of the elements originally in `A[1...j-1]`, but in sorted order.<br>
We use loop invariants to help us understand why an algorithm is correct. We must show three things about a loop invariant:
> **Initialization:** If it is true prior to the first iteration of the loop.
> **Maintenance:** If it is true before an iteration of the loop, it remains true before the next iteration.
> **Termination:** When the loop terminates, the invariant gives us a useful property that helps show that the algorithm is correct.