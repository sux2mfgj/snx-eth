#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed main(){
  string s=string("55 55 55 55 55 55 55 d5 ") // pri
    +      string("ff ff ff ff ff ff ")       // dstmac
    +      string("3c 97 0e 0c a9 31 ")       // srcmac
    +      string("08 06 ")                   // type
    +      string("00 01 ")                   // hwtype
    +      string("08 00 ")                   // protocoltype
    +      string("06 ")                      // hwsize
    +      string("04 ")                      // protocolsize
    +      string("00 01 ")                   // opecode
    +      string("3c 97 0e 0c a9 31 ")       // srcmac
    +      string("c0 a8 01 02 ")             // srcip
    +      string("00 00 00 00 00 00 ")       // dstmac
    +      string("c0 a8 01 03 ")             // dstip
    +      string("00 00 00 00 00 00 ")       // padding
    +      string("00 00 00 00 00 00 ")       // padding
    +      string("00 00 00 00 00 00 ")       // padding
    +      string("e7 0b b1 97 ");            // FCS
  int cnt=0;
  for(int i=0;i<(int)s.size();i++){
    if(s[i]==' '||s[i+1]==' ') continue;
    cout<<"0x"<<s[i+1]<<",0x"<<s[i]<<",";
    if(++cnt%8==0) cout<<endl;
  }
  cout<<endl;
  cout<<cnt<<endl;
  return 0;
}
