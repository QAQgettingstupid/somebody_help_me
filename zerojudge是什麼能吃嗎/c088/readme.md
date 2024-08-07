## 另解

    #include <bits/stdc++.h>

    using namespace std;
    
    map<int,int> mp;
    
    void f(int a){
        int p=2;
        while(a>1){
            while(a%p==0){
                mp[p]++;
                a=a/p;
            }
            p++;
        }
    }
    
    int main()
    {
        string s,s1;
        int x,y,num,result;
        while(getline(cin,s)){
            if(s[0]=='0')
                break;
            num=1;
            stringstream ss(s);
            while(ss>>s1){
                result=1;
                x=stoi(s1);
                ss>>s1;
                y=stoi(s1);
                for(int i=0;i<y;i++)
                    result*=x;
                num*=result;
            }
            num--;
            f(num);
            for(auto it=mp.cend();it!=mp.cbegin();){
                it--;
                cout<<it->first<<" "<<it->second<<" ";
            }
            cout<<'\n';
            mp.clear();
        }
        return 0;
    }
