====================================================

$$$$$$$$$$PrefixSum$$$$$$$$$$$$$$$$$$$$$$$

++++ Introduce ++++
Assume we have an array A. Array A has n elements.
We want to caculate prefix sum of array A: S

S(0) = c
S(i) = S(i-1) + A(i-1) for 1 <= i <= n

++++ Implement code ++++

vector<int> buildPrefixSum(const vector<int>& a, int C = 0) {
    int n = (int)a.size();
    vector<int> prefixSum(n + 1);

    prefixSum[0] = C;

    for (int i = 0; i < n; i++)
        prefixSum[i + 1] = prefixSum[i] + a[i];

    return prefixSum;
}

++++ Use case ++++

We want to calculate sum of elements in A that in [l;r) position.
A(l) + A(l+1) + A(l+2) + ... + A(r-1) = S(r) - S(l)
=================================================

$$$$$$$$$Diferrence Array$$$$$$$$$$$$$$$

Assume D is Difference array of A

==> D(i) = A(i+1) - A(i) (0 <= i < n - 1)


+++ Code Implement ++++

vector<int> buildDifferenceArray(const vector<int>& a) {
    int n = (int)a.size();

    vector<int> differenceArray(n - 1);

    for (int i = 0; i < n - 1; i++)
        differenceArray[i] = a[i + 1] - a[i];

    return differenceArray;
}


+++ Use case ++++

Assume we need to add K in subarray [l,r] of an array A. Instead of doing sum each
element with O(n) we can use D(A) with O(1). 

If
	+ A(i) and A(i+1) is inside [l, r] => Value of two is same => D(i) is same
	+ A(i) and A(i+1) is outside [l,r] => Value of two is not add K => D(i) same
	+ One of two in inside [l, r] but other is outside 
	  => value of 1 element is same but value of another is added K
	  => D(i) change

Only last case we need to change D. Only if i = l-1 or i = r, we just need change
D(l-1) and D(r). After that we S(D,A(0)) = A to get the final value of A

================================================

$$$$$$$$$Characteristic$$$$$$$$$$$$$$

A has n elements

S has n+1 elements if follow above formular

D has n-1 elements if follow above formular

===============================================

More about prefix sum, please refer to this link:
https://wiki.vnoi.info/algo/data-structures/prefix-sum-and-difference-array.md
