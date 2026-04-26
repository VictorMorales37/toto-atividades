#Victor Matheus Marques Morales

# Integer to Roman

Seven different symbols represent Roman numerals with the following values:

| Symbol | Value |
|--------|-------|
| I      | 1     |
| V      | 5     |
| X      | 10    |
| L      | 50    |
| C      | 100   |
| D      | 500   |
| M      | 1000  |

Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

- If the value does not start with 4 or 9, select the symbol of the maximal value that is less than or equal to the value, subtract that value from the input, convert the remainder to a Roman numeral, and append the symbol to the result.
- If the value starts with 4 or 9, select the symbol of the maximal value that is less than the value, subtract that value from the input, convert the remainder to a Roman numeral, and append the symbol to the result. Then, prepend the symbol that represents the difference between the selected symbol and the current value.

Given an integer, convert it to a Roman numeral.

**Example 1:**

```
Input: num = 3749
Output: "MMMDCCXLIX"
Explanation:
3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
 700 = DCC as 500 (D) + 100 (C) + 100 (C)
  40 = XL as 50 (L) - 10 (X) = 40
   9 = IX as 10 (X) - 1 (I) = 9
```

**Example 2:**

```
Input: num = 58
Output: "LVIII"
Explanation:
50 = L
 8 = VIII
```

**Example 3:**

```
Input: num = 1994
Output: "MCMXCIV"
Explanation:
1000 = M
 900 = CM
  90 = XC
   4 = IV
```

**Constraints:**

- `1 <= num <= 3999`