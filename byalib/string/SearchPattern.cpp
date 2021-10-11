#include <bits/stdc++.h>

using namespace std;

/**************************************
     KMP法：文字列探索
         - 計算量：O(n)
         - ずらし表(部分マッチ用 / Prefix Table) を利用し比較位置を決める
         - LPS("Longest proper Prefix which is also Suffix")
         - パターン自体の部分マッチの位置を事前に用意する
     ref:
         - https://algoful.com/Archive/Algorithm/KMPSearch
         -
 http://www.btechsmartclass.com/data_structures/knuth-morris-pratt-algorithm.html
         - https://www.codespeedy.com/knuth-morris-pratt-kmp-algorithm-in-c/
 ***************************************/

vector<int> initPrefixTable(string txt) {
    vector<int> lps(txt.length());
    int len = 0;
    int i = 1;
    while (i < txt.length()) {
        if (txt[i] == txt[len]) {
            len++;
            lps[i] = len;
            i++;
            continue;
        } else {
            if (len == 0) {
                lps[i] = 0;
                i++;
                continue;
            } else {
                len = lps[len - 1];
                continue;
            }
        }
    }
    return lps;
}

// found: return index of the text
// not found: -1
int KMP(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    // This function constructs the Lps array.
    vector<int> Lps = initPrefixTable(pattern);

    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        // If there is a match continue.
        if (j == m) {
            // if j==m it is confirmed that we have found
            return i - m;
            j = Lps[j - 1];
        }
        // If there is a mismatch
        else if (i < n && pattern[j] != text[i]) {
            // if j becomes 0 then simply increment the index i
            if (j == 0) i++;

            // Update j as Lps of last matched character
            else
                j = Lps[j - 1];
        }
    }

    // not found
    return -1;
}

int main() {
    cout << KMP("ababcdabcb", "abc") << endl;
    cout << KMP("ababcdabcb", "abd") << endl;
    return 0;
}
