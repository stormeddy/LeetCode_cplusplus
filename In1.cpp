#include<unordered_set>
#include<algorithm>
#include<iostream>

using namespace std;

class In1 {
public:
	int help1(int m, int n, int k){
		//http://blog.csdn.net/xiaqunfeng123/article/details/51765987
		//代码和网上的不同
		//		解题思路 
		//		简单来说，就是不停的从量杯m往n中倒水，然后n清空的过程。 
		//		如果此时m == k，结束； 
		//		若不相等，从m中倒水到n中直至n满，或者直至m空； 
		//		若n满，m != k，则清空n，重复上述动作。
		int a = 0, b = 0;
		int res = 0;
		unordered_set<int> s;//跟踪a中水当前高度，若出现重复，则无解

		//初始化情形
		a = m; ++res;//倒满a
		if (a == k) {
			return res;
		}
		s.insert(a);
		a = m - n; b = n; ++res;//a向b加水直到b满
		if (a == k) {
			return res;
		}
		s.insert(a);

		while (a != k){

			//			while(a>n){
			//				b=0;++res;//倒空b
			//				b=n;a-=n;++res;//a向b加水直到b满
			//				if (a==k) {
			//					return res;
			//				}
			//				if (s.contains(a)) {
			//					return -1;
			//				}
			//				s.add(a);
			//				
			//			}

			//这一段和上面的注释部分等价，但是因为知道k<n，直接用除法即可
			if (a>n) {
				int c = a / n;
				a = a%n;
				if (a == 0) {//针对a是n的倍数情况
					a = n; --c;
				}
				res += c * 2;
				if (a == k) {
					return res;
				}
				if (s.find(a)!=s.end()) {
					return -1;
				}
				s.insert(a);
			}



			b = 0; ++res;//倒空b
			b = a; a = 0; ++res;//a全部倒给b
			a = m; ++res;//倒满a
			a -= n - b; b = n; ++res;//a向b加水直到b满
			if (s.find(a)!=s.end()) {
				return -1;
			}
			s.insert(a);
		}
		return res;
	}

	int help2(int m, int n, int k){
		int a = 0, b = 0;
		int res = 0;
		unordered_set<int> s;//跟踪a中水当前高度，若出现重复，则无解

		//初始化情形
		a = m; ++res;//倒满a
		if (a == k) {
			return res;
		}
		s.insert(a);
		a = m - n; b = n; ++res;//a向b加水直到b满
		if (a == k) {
			return res;
		}
		s.insert(a);

		while (a != k){

			while (a>n){
				b = 0; ++res;//倒空b
				b = n; a -= n; ++res;//a向b加水直到b满
				if (a == k) {
					return res;
				}
				if (s.find(a)!=s.end()) {
					return -1;
				}
				s.insert(a);

			}
			//			if (a>n) {
			//				int c=a/n;
			//				a=a%n;
			//				if (a==0) {
			//					a=n;--c;
			//				}
			//				res+=c*2;
			//				if (a==k) {
			//					return res;
			//				}
			//				if (s.contains(a)) {
			//					return -1;
			//				}
			//				s.add(a);
			//			}


			b = 0; ++res;//倒空b
			b = a; a = 0; ++res;//a全部倒给b
			a = m; ++res;//倒满a
			a -= n - b; b = n; ++res;//a向b加水直到b满
			if (s.find(a)!=s.end()) {
				return -1;
			}
			s.insert(a);
		}
		return res;
	}

	int MinSteps(int m, int n, int k){
		//负数或0
		if (m < 0 || n < 0 || k < 0)
			return -1;

		//m不是最大的
		if (m < n || m < k)
			return -1;

		//m 和 k相等，只需要一次操作即可
		if (m == k){
			if (k == 0) return 0;
			else return 1;
		}

		// 不断加满n，然后倒入m
		if (k%n == 0)
			return min(2 * (k / n), help2(m, n, k));

		if (k<n) {
			//help1 和 help2不同的只在注释掉的部分
			//k<n时直接用除法解决，否则，要不断地从a中减掉n
			return help1(m, n, k);
		}
		else {
			return help2(m, n, k);
		}
	}
};

void main_In1(){
	In1 in1;
	//int m = 13, n = 7, k = 2;
	int m = 9, n = 8, k = 4;
	cout << in1.MinSteps(m, n, k) << endl;
}