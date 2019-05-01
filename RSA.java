import java.io.*;
import java.util.*;
import java.lang.*;
class RSA{
	public double getGCD(double a,double b){
		double small;
		if(a > b)
			small = b;
		else
			small = a;
		for(double i = small;i>=0;i--){
			if(a % i == 0 && b % i == 0)
				return i;
		}
		return 0.0;

	}
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		RSA r1 = new RSA();
		double n,fn,p,q,d,e,message,cipher,ans,dummy;
		System.out.println("Enter the value of p and q");
		p = sc.nextDouble();
		q = sc.nextDouble();
		n = p * q;
		fn = (p - 1) * (q - 1);
		//finding e
		e = 2;
		while(true){
			if(r1.getGCD(e,fn) == 1)
				break;
			else
				e++;
		}
		System.out.println("e : "+e);
		//finding d
		System.out.println("Possibile Values of D are : ");
		int temp = 1,k = 0;
		boolean flag = true;
		while(flag){
			temp += fn;
			if(temp % e == 0){
				if(k == 0)
					d = temp / e;
				dummy = temp / e;
				if(k == 5)
					flag = false;
				System.out.println(dummy);
				k++;
			}
		}
		System.out.println("Enter the value of D");
		d = sc.nextDouble();
		System.out.println(d);
		//encryption
		System.out.println("Enter the Message");
		message = sc.nextDouble();
		System.out.println((Math.pow(message,d) % n));
		
		//decryption
		System.out.println("Enter the Cipher");
		cipher = sc.nextDouble();
		System.out.println((Math.pow(cipher,d) % n));
		
	}
}