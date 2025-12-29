class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
     { vector<int> freq_mag(26,0);
      int n=magazine.length();
      for(int i=0;i<n;i++)
        freq_mag[magazine[i]-'a']++;
      for(int i=0;i<ransomNote.length();i++)
      { 
        int ch=ransomNote[i]-'a';
        if(freq_mag[ch]!=0)
          freq_mag[ch]--;
        else
         return false;
      }
      return true;
    }
};