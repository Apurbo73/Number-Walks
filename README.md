### Number Walks

This C++ program processes multiple test cases to compute **the minimum total cost to build a sequence of numbers from 1 to K** using a given array `A` of length `N`. The sequence must be built by picking positions in the array where the values appear in increasing order (`1 → 2 → ... → K`), and the cost is defined by the total absolute distance between adjacent numbers' positions in the array.

---

### 🔍 **How it works:**

* First, it groups positions of each number `1` through `K` using `pos[i]`.
* Then, using dynamic programming (`dp[i][j]`), it stores the **minimum cost** to build the sequence from number `i` starting at the `j`-th occurrence of `i` in the array.
* It calculates costs from `K` down to `1` by checking the closest positions of the next number (`i+1`) using `lower_bound` (binary search).
* Finally, for every starting index `s` in the array, it tries to begin the sequence from there (if `A[s] == 1`) and prints the minimal cost to complete the full `1→2→…→K` sequence from that point.

---

