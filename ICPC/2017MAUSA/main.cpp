#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1026;
int P[maxn][26],n,k,to[maxn*1000];
char now;
int ne[maxn*1000],hd[maxn],num,ans,F[maxn];
inline void add(int x,int y){ to[++num]=y,ne[num]=hd[x],hd[x]=num;}
void dp(int x){
	if(F[x]) return;
	for(int i=hd[x];i;i=ne[i]) dp(to[i]),F[x]=max(F[x],F[to[i]]);
	F[x]++;
}
int main(){
	cin >> n >> k;
	for(int i=0;i<k;i++)
	    for(int j=1;j<=n;j++) {
	    	cin >> now;
	    	P[now-'A'][i]=j;
	    }
	for(int i=1;i<=n;i++) {
	    for(int j=1,o;j<=n;j++){
	    	for(o=0;o<k;o++) if(P[i][o]>=P[j][o]) break;
	    	if(o==k) add(i,j);
		}
	}
	
	for(int i=1;i<=n;i++) dp(i),ans=max(ans,F[i]);
	cout << ans << endl;
	return 0;
}