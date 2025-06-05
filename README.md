### Number Walks:

This C++ program processes multiple test cases to compute **the minimum total cost to build a sequence of numbers from 1 to K** using a given array `A` of length `N`. The sequence must be built by picking positions in the array where the values appear in increasing order (`1 → 2 → ... → K`), and the cost is defined by the total absolute distance between adjacent numbers' positions in the array.

---

### 🔍 **How it works:**

* First, it groups positions of each number `1` through `K` using `pos[i]`.
* Then, using dynamic programming (`dp[i][j]`), it stores the **minimum cost** to build the sequence from number `i` starting at the `j`-th occurrence of `i` in the array.
* It calculates costs from `K` down to `1` by checking the closest positions of the next number (`i+1`) using `lower_bound` (binary search).
* Finally, for every starting index `s` in the array, it tries to begin the sequence from there (if `A[s] == 1`) and prints the minimal cost to complete the full `1→2→…→K` sequence from that point.

---

Here’s an even more simplified version of the pseudocode, focusing just on the main logic:

---

### Pseudocode
For each test case:
    Read N, K
    Read array A of size N

    For each number 1 to K:
        Save all positions of that number in pos[number]

    Initialize dp[K] = 0 for each position in pos[K]

    For i from K-1 down to 1:
        For each position x in pos[i]:
            Find nearest positions y in pos[i+1]
            dp[i][x] = min(abs(x - y) + dp[i+1][y])  for closest y values

    For each index s in 0 to N-1:
        If A[s] == 1:
            Use closest position in pos[1] to s
            ans = abs(s - x) + dp[1][x]
        Else:
            ans = 0
        Print ans
```

---

