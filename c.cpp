#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed main(){
  string s=string("55 55 55 55 55 55 55 d5 ")
    +      string("ff ff ff ff ff ff 3c 97 ")
    +      string("0e 0c a9 31 08 06 00 01 ")
    +      string("08 00 06 04 00 01 3c 97 ")
    +      string("0e 0c a9 31 c0 a8 01 02 ")
    +      string("00 00 00 00 00 00 c0 a8 ")
    +      string("01 03 00 00 00 00 00 00 ");
  int cnt=0;
  for(int i=0;i<(int)s.size();i++){
    if(s[i]==' '||s[i+1]==' ') continue;
    cout<<"0x"<<s[i+1]<<",0x"<<s[i]<<",";
    if(++cnt%8==0) cout<<endl;
  }
  cout<<endl;
  return 0;
}
