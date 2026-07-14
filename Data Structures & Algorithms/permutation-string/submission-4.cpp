class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int arr1[26]={0};
        int arr2[26]={0};
        for(int i=0;i<s1.size();i++){
            arr1[s1[i]-'a']+=1;
            arr2[s2[i]-'a']+=1;
        }
        int matches=0;
        for(int i=0;i<26;i++){
            if(arr1[i]==arr2[i]){
                matches+=1;
            }
        }
        int left=0;
        for(int right= s1.size();right<s2.size();right++){
            if(matches==26){
                return true;
            }
            int index = s2[right]-'a';
            arr2[index]+=1;
            if(arr2[index]==arr1[index]){
                matches+=1;
            }
            else if(arr1[index]+1==arr2[index]){
                matches-=1;
            }
            index = s2[left]-'a';
            arr2[index]-=1;
            if(arr2[index]==arr1[index]){
                matches+=1;
            }else if(arr1[index]-1==arr2[index]){
                matches-=1;
            }
            left++;
        }
        return matches==26;
    }
};
