class Solution {
public:
    string getHint(string& secret, string& guess) {
        int n = secret.size();
        int bull = 0;
        int shit = 0;

        for(int i=0; i<n; i++) {
            if(secret[i] == guess[i]) {
                bull++;
                secret[i] = '#';
                guess[i] = '*';
            }
        }
        for(int i=0; i<n; i++) {
            if(secret[i] != guess[i]) {
                int index = secret.find(guess[i]);
                if(index != -1) {
                    shit++;
                    secret[index] = '#';
                }
            }
        }

        return std::to_string(bull) + "A" + std::to_string(shit) + "B";
    }
};