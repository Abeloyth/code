#include <bits/stdc++.h>

using namespace std;

class Rational
{
	public:
		Rational operator +(Rational rhs);
		Rational operator -(Rational rhs);
		Rational operator *(Rational rhs);
		Rational operator /(Rational rhs);
		Rational(int num, int denom);
	
	private:
		void normalize();
		
		int numerator;
		int denominator;
		// numerator·Ö×Ó    denominator·ÖÄ¸
		
		friend ostream& operator <<(ostream& os, Rational f);
};

Rational::Rational(int num, int denom)
{
	numerator = num;
	denominator = denom;
	
	normalize();
}

void Rational::normalize()
{
	if (denominator < 0)
	{
		numerator = -numerator;
		denominator = -denominator;
	}
	
	int a = abs(numerator);
	int b = abs(denominator);
	
	while (b > 0)
	{
		int t = a % b;
		a = b;
		b = t;
	}
	
	numerator /= a;
	denominator /= a;
}

Rational Rational::operator +(Rational rhs)
{
	int a = numerator;
	int b = denominator;
	int c = rhs.numerator;
	int d = rhs.denominator;
	
	return Rational(a * d + b * c, b * d);
}

Rational Rational::operator -(Rational rhs)
{
	int a = numerator;
	int b = denominator;
	int c = rhs.numerator;
	int d = rhs.denominator;
	
	return Rational(a * d - b * c, b * d);
	
	//rhs.numerator = -rhs.numerator;
	//return operator+(rhs);
}

Rational Rational::operator *(Rational rhs)
{
	int a = numerator;
	int b = denominator;
	int c = rhs.numerator;
	int d = rhs.denominator;
	
	return Rational(a * c, b * d);
}

Rational Rational::operator /(Rational rhs)
{
	swap(denominator, numerator);
	
	return operator *(rhs);
} 

ostream& operator <<(ostream& os, Rational rhs)
{
	os << rhs.numerator << "/" << rhs.denominator;
	
	return os;
}

int main()
{
	int a, b, c, d;
	cin >> a >> b;
	cout << "\n";
	cin >> c >> d;
	
	Rational r1(a, b);
	Rational r2(c, d);
	
	cout << r1 << " + " << r2 << " = " << (r1 + r2) << "\n";
	cout << r1 << " - " << r2 << " = " << (r1 - r2) << "\n";
	cout << r1 << " * " << r2 << " = " << (r1 * r2) << "\n";
	cout << r1 << " / " << r2 << " = " << (r1 / r2) << "\n";
	
 	return 0;
}

