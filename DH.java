import java.io.*;
import java.util.*;
import java.lang.*;
class DH{
	public static void main(String args[]){
		double a,b,p,q,ap,bp,x,y;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter p and q");
		p = sc.nextDouble();
		q = sc.nextDouble();

		System.out.println("Enter a and b");
		a = sc.nextDouble();
		b = sc.nextDouble();

		ap = Math.pow(q,a) % p;
		bp = Math.pow(q,b) % p;
		System.out.println("Public Key"+ap+" & "+bp);

		x = Math.pow(bp,a) % p;
		y = Math.pow(ap,b) % p;
		System.out.println("Shared Secret Key : "+x+" & "+y);			
	}
}