class Solution {

public:
    string convert(string s, int numRows) {
        // Edge case
        if (numRows == 1 || numRows >= s.length())
            return s;

       vector<string> arr(numRows,"");
       int direction=1;
       int index=0;
       string res="";
       for(auto ch:s)
       {   
          arr[index]+=ch;
           if(index==numRows-1) //last row
            direction=-1;  //move upwards
           else if(index==0)
            direction=1;
          index+=direction;  //whihc row to add character next
        }
        for(auto s:arr)
         res+=s;
        return res;
}
};

       
