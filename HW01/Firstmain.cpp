// HW1.cpp : 定義主控台應用程式的進入點。
#include <iostream>
#include <string>

using namespace std;

void input(string sMessage, string &sInputString)
{
	cout << sMessage << endl;
	cin >> sInputString;

	return;
}

void writeBackwardI(string s)
{
	int length = s.size();

	if ( length == 0 )  // base case 
		return;

	for ( int i = length - 1; i >= 0; i-- )
		cout << s[i];
}

void writeBackwardR1(string s)
{
	int length = s.size();

	if (length == 0)  // base case 
		return;

	cout << s[length - 1];
	writeBackwardR1(s.substr(0, length - 1));
}

void writeBackwardR2(string s)
{
	int length = s.size();

	if (length == 0)  // base case 
		return;

	writeBackwardR2(s.substr(1, length - 1));
	cout << s[0];
}


int countI(string s, char c)
{
	int length = s.size();
	int count = 0;
	/*for (char i : s) {
		if (i == c) {
			count++;
		}
	}*/
	for(int i = 0 ; i < length ; i++)
		if(s[i] == c)
			count++;
	return count;
}

int countR(string s, char c)
{
	int length = s.size();
	int count=0;
	if (length == 0) {
		return 0;
	}
	if (s[length - 1] == c) {
		count++;
	}
	return count + countR(s.substr(0,length-1), c);
}

unsigned char findI(string s)
{
	int length = s.size();
	char small;
	small = s[0];
	for (int i = 1; i < s.size(); i++) {
		if (small > s[i]) {
			small = s[i];
			}
	}
	return small;
}

char findR(string s)
{
	int length = s.size();
	if (length == 1) {
		return s[length - 1];
	}
	if (findR(s.substr(0, length - 1)) > s[length - 1]) {
		return s[length - 1];
	}
	else {
		return findR(s.substr(0, length - 1));
	}
}

string removeI(string s)
{
	int length = s.size();
	string str;
	int i = 0;
	while (i < length) {
		str = str + s[i];
		while (i + 1 < length && s[i] == s[i + 1]) {
			i++;
		}
		i++;
	}
	return str;
}

string removeR(string s)
{
	int length = s.size();

	if (length == 1) {
		return s.substr(0, 1);
	}
	string str = removeR(s.substr(0, length - 1));

	if (s[length - 1] != s[length - 2]) {
		str += s[length - 1];
	}
	return str;
}

int TI( int m, int n)
{
	int sum=0;//a*b a+a+aa+a+

	if (m > n) {
		for (int i = 0; i < abs(n); i++) {   
			sum = sum - abs(m);
		}
	}
	else {
		for (int j = 0; j < abs(m); j++) {
			sum = sum - abs(n);
		}
	}
	if (m < 0 && n < 0) {
		sum *= -1;
	}
	return sum;
}

int TR( int m, int n)
{
	if (m == 0 && n == 0) {
		return 0;
	}
	if (n == 1) {
		return m;
	}
	if (m < 0 && n < 0) {
		return TR(abs(m), abs(n));
	}
	if (m > n) {//5 4
		if (m > 0 && n > 0) {
			return m + TR(m, n - 1);
		}
		else {//5 -4
			return n + TR(m - 1, n);
		}
	}
	else {//n<m 4 5
		if (m > 0 && n > 0) {
			return n + TR(m - 1, n);
		 }
		else {//-4 5
			return m + TR(m, n - 1);
		}
	}
}

int main()
{
	string commandStr;	
	string inputStr, appendStr;
	char inputChr;
	int m, n;

	while (1) {
		input( "\nEnter command: "
			"\n I to input a string, A to append a string, B to write the string backward, "
			"\n C to count the given character , F to find the smallest character,"
			"\n R to remove the repeated characters, T to compute, and X to Exit", commandStr );
	
		if ( commandStr == "I"  || commandStr == "i" ) {
			cout << "\nInput the string: ";
			cin >> inputStr;
		} 
		else if ( commandStr == "A"  || commandStr == "a" ) {
			cout << "\nInput the string: ";
			cin >> appendStr;
			inputStr += appendStr;
			cout << "\nThe new string: " << inputStr << endl;
		} 
		else if ( commandStr == "B" || commandStr == "b" ) {
			if ( inputStr.length() > 0 ) {
				cout << endl;
				writeBackwardI( inputStr );
				cout << endl;
				writeBackwardR1( inputStr );
				cout << endl;
				writeBackwardR2( inputStr );
				cout << endl;
			}
		}
		else	if ( commandStr == "C"  || commandStr == "c" ) {
			if ( inputStr != "" ) {
				cout << "\nInput the character: ";
				cin >> inputChr;
				cout << "\nCount of " << inputChr <<": " << countI( inputStr, inputChr );
				cout << "\nCount of " << inputChr <<": " << countR( inputStr, inputChr ) << endl;
			}
		}
		else if ( commandStr == "R" || commandStr == "r" ) {
			if ( inputStr != "" ) {
				cout << endl << "Repeated characters removed: " << removeI( inputStr ) ;
				cout << endl << "Repeated characters removed: " << removeR( inputStr ) << endl;;
			}
		}
		else if ( commandStr == "F" || commandStr == "f" ) {
			if ( inputStr != "" ) {
				cout << endl << "Smallest character found: " << findI( inputStr );
				cout << endl << "Smallest character found: " << findR( inputStr ) << endl;
			}
		}
		else  if ( commandStr == "T" || commandStr == "t" ) 
		{
			cout << "\nInput two values, m and n: ";
			cin >> m >> n;
			cout << endl << "The result is " << TI( m, n );
			cout << endl << "The result is " << TR( m, n ) << endl;
		}
		else  if ( commandStr == "X" || commandStr == "x" ) 
			return 0;	
		else
			cout << "\nUnknown command!";
	}
  	return 0;
}

