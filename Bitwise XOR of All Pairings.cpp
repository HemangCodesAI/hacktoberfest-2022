 #include<bits/stdc++.h>
 using namespace std;
  int xorAllNums(vector<int> &nums1, vector<int> &nums2)
        {
            int m=nums1.size();
            int n=nums2.size();
            int ans=0;
            int a=0;
                for(int i=0;i<m;i++)   
                   a^=nums1[i]  ;
                
            
            int b=0;
             for(int i=0;i<n;i++)
                 b^=nums2[i];
          
            
            ans=(m%2)*b xor (n%2)*a;
            
            cout<< ans;
          return 0;
        }
   int main()
 {
    int m,n;
    cin>>m>>n;
    vector<int>nums1(m);
    vector<int>nums2(n);
    
    for(int i=0;i<m;i++)
    {
        cin>>nums1[i];
    }
      for(int i=0;i<n;i++)
    {
        cin>>nums2[i];
    }
 
   xorAllNums(nums1,nums2);
  return 0;
  
 
   
 }