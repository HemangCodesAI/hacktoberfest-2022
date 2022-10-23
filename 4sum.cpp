/*Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Signed-off-by: Anmol Johri ajohri_be20@thapar.edu*/


vector<vector<int>> fourSum(vector<int>& nums, long long target) {
        int n = nums.size();  
        sort(nums.begin() , nums.end());  // sort the array to use the two pointers method
        vector<vector<int>> ans; 
        set<vector<int>> store;   
		
        for(int i = 0 ; i < n; i++){
		
            for(int j = i + 1; j < n ; j++){
			
                long long new_target  =  target - nums[i] - nums[j];
                
                int x = j+1 , y = n-1;
                
                while(x < y){
				
                    long long sum = nums[x] + nums[y];
                    
                    if(sum > new_target) y--;
                    else if(sum < new_target ) x++;
                    else  {
                        store.insert({nums[i] , nums[j] , nums[x] , nums[y]});
                        // x++;
                        // y--;
                    int last_low_occurence = nums[x]; 
                    int last_high_occurence = nums[y];  
                    while(x < y && nums[x] == last_low_occurence){   
                        x++;
                    }
                    while(x < y && nums[y] == last_high_occurence){
                        y--;
                        }
                    }
                }
            }
        }
		
        for(auto i : store){
            ans.push_back(i);  // store the answers in an array(ans)
        }
		
        return ans;
    }
