class Solution {
public:

    long long dp[1025][1025]; 

    
    long long binary_exponentiation(int a , long long x , int md){
        if(x == 0) return 1; 
        long long half = binary_exponentiation(a , x/2 , md)%md; 
        if(x%2 == 0){
            return ( half % md * half % md ) % md; 
        }
        return (a % md * half % md * half % md) % md; 
    }


    long long get_value(vector < long long > &v , int index , int mask , 
    map < long long , long long > & mp){

        int md = 1e9 + 7; 
        if(index == v.size()) return (mask > 0); 
        if(dp[index][mask] != -1) return dp[index][mask];
        // non _take
        long long a = get_value(v , index+1 , mask , mp) % md; 
        long long b = 0; 
        // Take (after checking)
        if( (mask & v[index]) == 0){
            b = ((mp[v[index]] % md)*(get_value(v , index+1 , mask | (v[index])  , mp) % md)%md) % md; 
        }
        return dp[index][mask] = (a%md + b%md)%md; 

    }

    void can_take(int x , int primes[] , map < long long , long long > & mp){

        bool check = true; 
        long long num = 0; 
        for(int i = 0 ; i< 10 ; i++){
            int cnt = 0;
            while(x % primes[i] == 0) {
                x /= primes[i]; 
                cnt++;
                // if duplicate is there than remove. 
                if(cnt > 1){
                    check = false; 
                    break; 
                }
            }
            if(cnt == 1) num |= (1<<i); 
        }
        if(check){
            mp[num]++; 
        }
    }
    int numberOfGoodSubsets(vector<int>& nums) {

        int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        vector < long long > v; 
        map < long long , long long > mp; 
        long long ones = 0; 
        for(auto  x : nums){
            // count ones
            if(x == 1) ones++; 
            // store number is term of bitmask that we have discussed. 
            else {
                can_take(x , primes , mp);      
            }
        }

        for(auto & x : mp) v.push_back(x.first); 
        memset(dp , -1 , sizeof(dp)); 
        int md = 1e9 + 7; 
        long long ans = get_value(v , 0 , 0 , mp) % md; 
        // binary exponentiation to find power. 
        long long power = binary_exponentiation(2 , ones , md) % md; 
        ans = ((ans%md)*power%md) % md; 
        return ans%md;  
    }
};