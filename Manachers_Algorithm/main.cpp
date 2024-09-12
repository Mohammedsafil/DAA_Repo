class Solution {
public:
    string preProcessing(string s){
        string str = "#";
        for(char c : s){
            str += c + string("#");
        }
        return str;
    }
    string longestPalindrome(string s) {
        s = preProcessing(s);
        int n = s.size();
        int p[n];
        for(int i=0;i<n;i++){
            p[i] = 0;
        }

        int c =0 ,r = 0;

        for(int i=1;i<n-1;i++){
            int mirror = 2*c -i;
            if(i<r){
                p[i] = min(r-i,p[mirror]);
            }
            while(s[i+1+p[i]] == s[i-1-p[i]]){
                p[i]++;
            }
            if(p[i]+i > r ){
                c = i;
                r = p[i] +i;
            }

        }

        int max = 0;
        int cent = 0;
        int start = 0;

        for(int i=1;i<n-1;i++){
            if(p[i]>max){
                max = p[i];
                cent = i;
            }
        }
        start = (cent - max) / 2;
        return s.substr(start,max);
    }
};