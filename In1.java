<<<<<<< HEAD
package huawei;

import java.util.HashSet;
import java.util.Set;

public class In1 {

	private int help1(int m,int n,int k){
		//http://blog.csdn.net/xiaqunfeng123/article/details/51765987
		//��������ϵĲ�ͬ
//		����˼· 
//		����˵�����ǲ�ͣ�Ĵ�����m��n�е�ˮ��Ȼ��n��յĹ��̡� 
//		�����ʱm == k�������� 
//		������ȣ���m�е�ˮ��n��ֱ��n��������ֱ��m�գ� 
//		��n����m != k�������n���ظ�����������
		int a=0,b=0;
		int res=0;
		Set<Integer> s=new HashSet<Integer>();//����a��ˮ��ǰ�߶ȣ��������ظ������޽�
		
		//��ʼ������
		a=m;++res;//����a
		if (a==k) {
			return res;
		}
		s.add(a);
		a=m-n;b=n;++res;//a��b��ˮֱ��b��
		if (a==k) {
			return res;
		}
		s.add(a);
		
		while(a!=k){
			
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
				int c=a/n;
				a=a%n;
				if (a==0) {//���a��n�ı������
					a=n;--c;
				}
				res+=c*2;
				if (a==k) {
					return res;
				}
				if (s.contains(a)) {
					return -1;
				}
				s.add(a);
			}
			
			
					
			b=0;++res;//����b
			b=a;a=0;++res;//aȫ������b
			a=m;++res;//����a
			a-=n-b;b=n;++res;//a��b��ˮֱ��b��
			if (s.contains(a)) {
				return -1;
			}
			s.add(a);
		}
		return res;
	}
	
	private int help2(int m,int n,int k){
		int a=0,b=0;
		int res=0;
		Set<Integer> s=new HashSet<Integer>();//����a��ˮ��ǰ�߶ȣ��������ظ������޽�
		
		//��ʼ������
		a=m;++res;//����a
		if (a==k) {
			return res;
		}
		s.add(a);
		a=m-n;b=n;++res;//a��b��ˮֱ��b��
		if (a==k) {
			return res;
		}
		s.add(a);
		
		while(a!=k){
			
			while(a>n){
				b=0;++res;//����b
				b=n;a-=n;++res;//a��b��ˮֱ��b��
				if (a==k) {
					return res;
				}
				if (s.contains(a)) {
					return -1;
				}
				s.add(a);
				
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
			
					
			b=0;++res;//����b
			b=a;a=0;++res;//aȫ������b
			a=m;++res;//����a
			a-=n-b;b=n;++res;//a��b��ˮֱ��b��
			if (s.contains(a)) {
				return -1;
			}
			s.add(a);
		}
		return res;
	}
	
	public int MinSteps(int m,int n,int k){
		//������0
	    if (m <= 0 || n <= 0 || k <= 0)
	        return -1;

	    //m��������
	    if (m <= n || m < k)
	        return -1;

	    //m �� k��ȣ�ֻ��Ҫһ�β�������
	    if (m == k)
	        return 1;
	    
	    // ���ϼ���n��Ȼ����m
	    if (k%n==0)
	        return Math.min(2*(k/n),help2(m, n, k));
	    
	    if (k<n) {
	    	//help1 �� help2��ͬ��ֻ��ע�͵��Ĳ���
	    	//k<nʱֱ���ó������������Ҫ���ϵش�a�м���n
			return help1(m, n, k);
		}else {
			return help2(m, n, k);
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		In1 i=new In1();
//		int m=4,n=3,k=2;
//		int m=13,n=7,k=2;
//		int m=9,n=8,k=4;
//		int m=6,n=3,k=2;
//		int m=5,n=3,k=2;
//		int m=3,n=2,k=1;
		int m=100,n=2,k=60;
		System.out.println(i.MinSteps(m, n, k));
	}

}
=======
package huawei;

import java.util.HashSet;
import java.util.Set;

public class In1 {

	private int help1(int m,int n,int k){
		//http://blog.csdn.net/xiaqunfeng123/article/details/51765987
		//��������ϵĲ�ͬ
//		����˼· 
//		����˵�����ǲ�ͣ�Ĵ�����m��n�е�ˮ��Ȼ��n��յĹ��̡� 
//		�����ʱm == k�������� 
//		������ȣ���m�е�ˮ��n��ֱ��n��������ֱ��m�գ� 
//		��n����m != k�������n���ظ�����������
		int a=0,b=0;
		int res=0;
		Set<Integer> s=new HashSet<Integer>();//����a��ˮ��ǰ�߶ȣ��������ظ������޽�
		
		//��ʼ������
		a=m;++res;//����a
		if (a==k) {
			return res;
		}
		s.add(a);
		a=m-n;b=n;++res;//a��b��ˮֱ��b��
		if (a==k) {
			return res;
		}
		s.add(a);
		
		while(a!=k){
			
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
				int c=a/n;
				a=a%n;
				if (a==0) {//���a��n�ı������
					a=n;--c;
				}
				res+=c*2;
				if (a==k) {
					return res;
				}
				if (s.contains(a)) {
					return -1;
				}
				s.add(a);
			}
			
			
					
			b=0;++res;//����b
			b=a;a=0;++res;//aȫ������b
			a=m;++res;//����a
			a-=n-b;b=n;++res;//a��b��ˮֱ��b��
			if (s.contains(a)) {
				return -1;
			}
			s.add(a);
		}
		return res;
	}
	
	private int help2(int m,int n,int k){
		int a=0,b=0;
		int res=0;
		Set<Integer> s=new HashSet<Integer>();//����a��ˮ��ǰ�߶ȣ��������ظ������޽�
		
		//��ʼ������
		a=m;++res;//����a
		if (a==k) {
			return res;
		}
		s.add(a);
		a=m-n;b=n;++res;//a��b��ˮֱ��b��
		if (a==k) {
			return res;
		}
		s.add(a);
		
		while(a!=k){
			
			while(a>n){
				b=0;++res;//����b
				b=n;a-=n;++res;//a��b��ˮֱ��b��
				if (a==k) {
					return res;
				}
				if (s.contains(a)) {
					return -1;
				}
				s.add(a);
				
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
			
					
			b=0;++res;//����b
			b=a;a=0;++res;//aȫ������b
			a=m;++res;//����a
			a-=n-b;b=n;++res;//a��b��ˮֱ��b��
			if (s.contains(a)) {
				return -1;
			}
			s.add(a);
		}
		return res;
	}
	
	public int MinSteps(int m,int n,int k){
		//������0
	    if (m <= 0 || n <= 0 || k <= 0)
	        return -1;

	    //m��������
	    if (m <= n || m < k)
	        return -1;

	    //m �� k��ȣ�ֻ��Ҫһ�β�������
	    if (m == k)
	        return 1;
	    
	    // ���ϼ���n��Ȼ����m
	    if (k%n==0)
	        return Math.min(2*(k/n),help2(m, n, k));
	    
	    if (k<n) {
	    	//help1 �� help2��ͬ��ֻ��ע�͵��Ĳ���
	    	//k<nʱֱ���ó������������Ҫ���ϵش�a�м���n
			return help1(m, n, k);
		}else {
			return help2(m, n, k);
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		In1 i=new In1();
//		int m=4,n=3,k=2;
//		int m=13,n=7,k=2;
//		int m=9,n=8,k=4;
//		int m=6,n=3,k=2;
//		int m=5,n=3,k=2;
//		int m=3,n=2,k=1;
		int m=100,n=2,k=60;
		System.out.println(i.MinSteps(m, n, k));
	}

}
>>>>>>> 4c6441a23067a69854787b6d71c6670a7d3fef3b
