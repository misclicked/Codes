var s = readline().split(' ');
n=s[0];
r=s[1];
var s = readline().split(' ');
var ans=r+"";
var vec=[];
vec[0]=Number(r);
for(i=1;i<n;i++){
	hit = false;
	vec[i]=Number(-1);
	for(j=i-1;j>=0;j--){
		if(Math.abs(s[i]-s[j])>r*2)continue;
		hit=true;
		vec[i]=Math.max(vec[i],(Math.sqrt(Math.pow(r*2,2)-Math.pow(Math.abs(s[i]-s[j]),2))+Number(vec[j])));
	} 
	if(hit===false){
		vec[i]=Number(r);
	}
	ans+=" "+vec[i];
}
print(ans);