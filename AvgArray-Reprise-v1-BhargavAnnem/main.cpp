#include <iostream>
using namespace std;
float average(float a[], int n) {
	float tot = 0;
	for(int i = 0; i < n; i++){
		tot += a[i];
	}
	return tot / (float)n;
}

int main() {
// Create variables
// Create array named 'num' of type float of size 100 elements.
	int n, i;
	cout << "Enter the numbers of data:";
	cin >> n;
	cout << endl;
	float num[n];
	while (n > 100 || n <= 0){
		cout << "Error! number should in range of (1 to 100)." << endl;
		cout << "Enter the number again: ";
		cin >> n;
	}
	cout << "Enter list of numbers separated by a space:" << endl;
	for(i = 0; i < n; ++i) {
		cin >> num[i];
	}
	cout << "Average = " << average(num, n) << "\n";
	return 0;

}