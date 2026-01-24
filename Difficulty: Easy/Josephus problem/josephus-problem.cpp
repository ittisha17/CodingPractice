class Solution {
  public:
    int jos(int n,int k)
    {
        if(n==0) //1 person remains
         return 0;
        return((jos(n-1,k)+k)%n);
    }
  
    int josephus(int n, int k) {
        // code here
        return(jos(n,k)+1);
        
    }
};