class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1=version1.size(),n2=version2.size();
        int i=0,j=0;
        while(i<n1 || j<n2)
        {
            int idx1=i,idx2=j;
            string comp1="",comp2="";
            while(idx1<n1 && version1[idx1]!='.')
            {
                comp1+=version1[idx1++];
            }
            i=idx1+1;
            while(idx2<n2 && version2[idx2]!='.')
            {
                comp2+=version2[idx2++];
            }
            j=idx2+1;
            int num1=comp1.empty() ? 0:stoi(comp1);
            int num2=comp2.empty() ? 0:stoi(comp2);
            if(num1<num2) return -1;
            if(num1>num2) return 1;
        }
        return 0;
    }
};