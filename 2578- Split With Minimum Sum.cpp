class Solution {
public:
    int splitNum(int num) {
       string n = to_string(num);
       sort(n.begin(),n.end());
       string n1="";string n2 ="";
       for(int i=0;i<n.size();i++)
       {
          if(i%2==0)
          {
            n1+=n[i];
          }
          else
          {
            n2+=n[i];
          }
       }
       return stoi(n1)+stoi(n2);
    }
};
