        #include<stdio.h>
        long long ab(long long a) {
        	return (a>=0?a:-a);
        }
        int main(){
        	long long a,b,c,d,max;
        	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        	long long m1=a*c;
        	long long m2=a*d;
        	long long m3=b*c;
        	long long m4=b*d;
        	max=(m1+m2+ab(m1-m2))/2;
        	max=(max+m3+ab(max-m3))/2;
        	max=(max+m4+ab(max-m4))/2;
        	printf("%lld",max);
        }