#include <iostream>
#include<string>
#define size 6
using namespace std;

void in(int array[],int number)
{
	int ans = number;
	int temp;
	for (int i = 0; i < size; i++) {
		if (array[i] == ' '||ans<array[i]) {
			for (int j = i; j < size; j++) {
				temp = array[j];
				array[j] = ans;
				ans = temp;
			}	
			break;
		}
	}
	return;
}
void de(int array[],int number)
{
	for (int i = 0; i < size; i++) {
		if (array[i] == ' ') {
			for (int j = i; j < size; j++) {
				if (j + 1 == size) {
					array[j] = ' ';
				}
				else {
					array[j] = array[j + 1];
				}
			}
		}
	}
	return;
}
void print(int array[])
{
	for (int i = 0; i < size; i++) {
		if (array[i] != ' ') {
			cout << array[i] << " ";
		}
	}
	cout << " " << endl;
	return;
}
int main()
{
	char q;
	int i=0;
	int n;
	int  k[size]; 
	
	
	for (i = 0; i < size; i++) {
		k[i] = ' ';
	}
	while (1) {
		cout << "input or delete" << endl;
		cin >> q;
		switch (q) {
			case 'i':case 'I':
				cout << "input a integer" << endl;
				cin >> n;
				in(k, n);
				print(k);
				break;
			case 'd':case 'D':
				cout << "delete a integer" << endl;
				cin >> n;
				de(k, n);
				print(k);
				break;
			default:
				break;
		}
	}
	return 0;
}

