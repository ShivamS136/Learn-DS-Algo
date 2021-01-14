# Algorithms
In this folder we'll see implementation of many important algorithmic problems using `C++`.

<!-- MarkdownTOC autolink="true" -->

- [List of problems:](#list-of-problems)
	- [LeetCode: May Challenge:](#leetcode-may-challenge)
		- [May 1: Find first bad version went on production](#may-1-find-first-bad-version-went-on-production)
		- [May 3: Ransom Note Problem: Check if Ransom Note is generatable from magazine](#may-3-ransom-note-problem-check-if-ransom-note-is-generatable-from-magazine)
		- [May 5: Find index of first Unique Character in a String](#may-5-find-index-of-first-unique-character-in-a-string)
		- [May 7: Check if values are cousins in Binary Tree](#may-7-check-if-values-are-cousins-in-binary-tree)
		- [May 8: Check if given points are colinear \(Make a straight line\)](#may-8-check-if-given-points-are-colinear-make-a-straight-line)
		- [May 9: Check if given number is a valid square\(Without using `sqrt`\)](#may-9-check-if-given-number-is-a-valid-squarewithout-using-sqrt)
		- [May 11: Flood Fill image](#may-11-flood-fill-image)
		- [May 12: Find element occuring only once in a sorted array while others are occuring twice](#may-12-find-element-occuring-only-once-in-a-sorted-array-while-others-are-occuring-twice)
	- [Codechef:](#codechef)
		- [Find minimum bombs to blast N 1-D kingdoms](#find-minimum-bombs-to-blast-n-1-d-kingdoms)
	- [Miscellaneous:](#miscellaneous)
		- [Coin Change Problem: Find minimum number of coins that make a given value](#coin-change-problem-find-minimum-number-of-coins-that-make-a-given-value)
		- [Paranthesis checker](#paranthesis-checker)
		- [Print next larger element in array](#print-next-larger-element-in-array)
		- [Count and Say sequence](#count-and-say-sequence)
		- [Minimum Operations to Reduce X to Zero](#minimum-operations-to-reduce-x-to-zero)

<!-- /MarkdownTOC -->


## List of problems:

### LeetCode: May Challenge:

#### May 1: Find first bad version went on production
* **File:** [firstBadVersion.cpp](firstBadVersion.cpp)
* **Complexity:** *Time:* O(logn), *Space:* O(1)
* **Reference:** [Leetcode: First Bad Version](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3316/)

#### May 3: Ransom Note Problem: Check if Ransom Note is generatable from magazine
* **File:** [ransomNote.cpp](ransomNote.cpp)
* **Complexity:** *Time:* O(m+n), *Space:* O(m)
* **Reference:** [Leetcode: Ransome Note](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3318/)

#### May 5: Find index of first Unique Character in a String
* **File:** [firstUniqChar.cpp](firstUniqChar.cpp)
* **Complexity:** *Time:* O(n), *Space:* O(n)
* **Reference:** [First Unique Character in a String](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3320/) 

#### May 7: Check if values are cousins in Binary Tree
* **File:** [checkTreeCousins.cpp](checkTreeCousins.cpp)
* **Complexity:** *Time:* O(n), *Space:* O(1)
* **Reference:** [Cousins in Binary Tree](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/) 

#### May 8: Check if given points are colinear (Make a straight line)
* **File:** [checkPointsColinear.cpp](checkPointsColinear.cpp)
* **Complexity:** *Time:* O(n), *Space:* O(1)
* **Reference:** [Check If It Is a Straight Line](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3323/) 
* **Reference:** [Formula used: All points on same line has same slope](https://stackoverflow.com/a/3813723/8494462)  

#### May 9: Check if given number is a valid square(Without using `sqrt`)
* **File:** [validSquare.cpp](validSquare.cpp)
* **Complexity:** *Time:* O(log n), *Space:* O(1)
* **Reference:** [Valid Perfect Square](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3324/)

#### May 11: Flood Fill image
* **File:** [floodFill.cpp](floodFill.cpp)
* **Complexity:** *Time:* O(n), *Space:* O(1)
* **Reference:** [Flood Fill](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3326/)
* **Reference:** [Wiki: Flood Fill](https://en.wikipedia.org/wiki/Flood_fill)

#### May 12: Find element occuring only once in a sorted array while others are occuring twice
* **File:** [onceInSortedArr.cpp](onceInSortedArr.cpp)
* **Complexity:** *Time:* O(log n), *Space:* O(1)
* **Reference:** [Single Element in a Sorted Array](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3327/)

### Codechef:

#### Find minimum bombs to blast N 1-D kingdoms
* **File:** [minBomb.cpp](minBomb.cpp)
* **Complexity:** *Time:* O(N) [+O(NlogN), if sorting needed], *Space:* O(1)
* **Reference:** [One Dimensional Kingdoms](https://www.codechef.com/problems/ONEKING) 


### Miscellaneous:

#### Coin Change Problem: Find minimum number of coins that make a given value
* **File:** [coinChange.cpp](coinChange.cpp)
* **Complexity:** *Time:* O(mV), *Space:* O(V)
* **Reference:** [GFG: Find minimum number of coins that make a given value - Method 2](https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/) 

#### Paranthesis checker
* **File:** [checkParanthesis.cpp](checkParanthesis.cpp)
* **Complexity:** *Time:* O(n), *Space:* O(n)
* **Reference:** [GFG: Examine whether the pairs and the orders of paranthesis are correct in exp](https://practice.geeksforgeeks.org/problems/parenthesis-checker/0) 

#### Print next larger element in array
* **File:** [nextLarger.cpp](nextLarger.cpp)
* **Complexity:** *Time:* O(n), *Space:* O(n)
* **Reference:** [GFG: Find the next greater element for each element of the array in order of their appearance in the array](https://practice.geeksforgeeks.org/problems/next-larger-element/0) 
* **Reference:** [GFG: Find the next greater element for each element of the array](https://www.geeksforgeeks.org/next-greater-element/) 

#### Count and Say sequence
* **File:** [countAndSay.cpp](countAndSay.cpp)
* **Complexity:** *Time:* O(n), *Space:* O(1)
* **Reference:** [GFG: Look-and-Say Sequence](https://www.geeksforgeeks.org/look-and-say-sequence/)

#### Minimum Operations to Reduce X to Zero
* **File:** Naive DP Solution: [reduceXToZero_NaiveDP.cpp](reduceXToZero_NaiveDP.cpp)
* **Complexity:** *Time:* O(2^(10^5)), *Space:* O(2 * 10^5)
* **File:** [reduceXToZero.cpp](reduceXToZero.cpp)
* **Complexity:** *Time:* O(n), *Space:* O(1)
* **Reference:** [Leetcode: Minimum Operations to Reduce X to Zero](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero)

