#include <iostream>
#include <vector>
using namespace std;

// Function to preprocess the pattern and build the LPS (Longest Prefix Suffix) array
void computeLPSArray(string pattern, int M, vector<int>& lps) {
    int length = 0;  // length of the previous longest prefix suffix
    lps[0] = 0;      // lps[0] is always 0

    int i = 1;
    while (i < M) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {  // (pattern[i] != pattern[length])
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP algorithm for pattern searching
void KMPSearch(string pattern, string text) {
    int M = pattern.length();
    int N = text.length();

    // Create lps[] that will hold the longest prefix suffix values for the pattern
    vector<int> lps(M);

    // Preprocess the pattern to build the lps array
    computeLPSArray(pattern, M, lps);

    int i = 0;  // index for text[]
    int j = 0;  // index for pattern[]

    while (i < N) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == M) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    KMPSearch(pattern, text);
    return 0;
}
