#include<unordered_set>
#include<algorithm>
#include<iostream>

using namespace std;

class In1 {
public:
	int help1(int m, int n, int k){
		//http://blog.csdn.net/xiaqunfeng123/article/details/51765987
		//��������ϵĲ�ͬ
		//		����˼· 
		//		����˵�����ǲ�ͣ�Ĵ�����m��n�е�ˮ��Ȼ��n��յĹ��̡� 
		//		�����ʱm == k�������� 
		//		������ȣ���m�е�ˮ��n��ֱ��n��������ֱ��m�գ� 
		//		��n����m != k�������n���ظ�����������
		int a = 0, b = 0;
		int res = 0;
		unordered_set<int> s;//����a��ˮ��ǰ�߶ȣ��������ظ������޽�

		//��ʼ������
		a = m; ++res;//����a
		if (a == k) {
			return res;
		}
		s.insert(a);
		a = m - n; b = n; ++res;//a��b��ˮֱ��b��
		if (a == k) {
			return res;
		}
		s.insert(a);

		while (a != k){

			//			while(a>n){
			//				b=0;++res;//����b
			//				b=n;a-=n;++res;//a��b��ˮֱ��b��
			//				if (a==k) {
			//					return res;
			//				}
			//				if (s.contains(a)) {
			//					return -1;
			//				}
			//				s.add(a);
			//				
			//			}

			//��һ�κ������ע�Ͳ��ֵȼۣ�������Ϊ֪��k<n��ֱ���ó�������
			if (a>n) {
				int c = a / n;
				a = a%n;
				if (a == 0) {//���a��n�ı������
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



			b = 0; ++res;//����b
			b = a; a = 0; ++res;//aȫ������b
			a = m; ++res;//����a
			a -= n - b; b = n; ++res;//a��b��ˮֱ��b��
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
		unordered_set<int> s;//����a��ˮ��ǰ�߶ȣ��������ظ������޽�

		//��ʼ������
		a = m; ++res;//����a
		if (a == k) {
			return res;
		}
		s.insert(a);
		a = m - n; b = n; ++res;//a��b��ˮֱ��b��
		if (a == k) {
			return res;
		}
		s.insert(a);

		while (a != k){

			while (a>n){
				b = 0; ++res;//����b
				b = n; a -= n; ++res;//a��b��ˮֱ��b��
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


			b = 0; ++res;//����b
			b = a; a = 0; ++res;//aȫ������b
			a = m; ++res;//����a
			a -= n - b; b = n; ++res;//a��b��ˮֱ��b��
			if (s.find(a)!=s.end()) {
				return -1;
			}
			s.insert(a);
		}
		return res;
	}

	int MinSteps(int m, int n, int k){
		//������0
		if (m < 0 || n < 0 || k < 0)
			return -1;

		//m��������
		if (m < n || m < k)
			return -1;

		//m �� k��ȣ�ֻ��Ҫһ�β�������
		if (m == k){
			if (k == 0) return 0;
			else return 1;
		}

		// ���ϼ���n��Ȼ����m
		if (k%n == 0)
			return min(2 * (k / n), help2(m, n, k));

		if (k<n) {
			//help1 �� help2��ͬ��ֻ��ע�͵��Ĳ���
			//k<nʱֱ���ó������������Ҫ���ϵش�a�м���n
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