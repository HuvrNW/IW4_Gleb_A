#include <iostream>
#include <ctime>
#include <cstdlib>

//Task 1 Zeroing arr
template <typename T>
void fill_arr(T arr[], const int length, int a, int b);
template <typename T>
void show_arr(T arr[], const int length);
template <typename T>
void clear_arr(T arr[], const int length, int zero);

//Task 2 Index_sum
int index_sum(int arr[], int arr1[], const int length, const int length2, int index);

//Task 3 Mean_arr
template <typename T>
double mean_arr(T arr[], const int length);

//Task 4 Prime_range
void prime_range(int n1, int n2);

int main() {
	setlocale(LC_ALL, "Russian");
	int n, x;

	//Task 1 Zeroing arr
	/*std::cout << "\t\tTask 1.\n Zeroing arr.\n Original array --> ";
	const int size1 = 10;
	int arr1[size1];
	fill_arr(arr1, size1, 1, 3);
	show_arr(arr1, size1);
	std::cout << " Enter the number --> ";
	std::cin >> n;
	clear_arr(arr1, size1, n);
	std::cout << " New array --> ";
	show_arr(arr1, size1);
	*/
	//Task 2 Index_sum
	std::cout << "\n\t\tTask 2.\n Index_sum.\n";
	const int size21 = 7;
	const int size22 = 7;
	int arr21[size21];
	int arr22[size22];
	std::cout << " First array --> ";
	fill_arr(arr21, size21, 9, 99);
	show_arr(arr21, size21); 
	std::cout << "\n Second array --> ";
	fill_arr(arr22, size22, 8, 88);
	show_arr(arr22, size22);
	std::cout << " Enter the ¹ of index --> ";
	std::cin >> n;
	std::cout << " Sum of "<< n << " indexs = " << index_sum(arr21, arr22, size21, size22, n);
	
	//Task 3 Mean_arr
	std::cout << "\n\n\t\tTask 3.\n Mean_arr.\n Array --> ";
	const int size3 = 10;
	int arr3[size3];
	fill_arr(arr3, size3, 1, 50);
	show_arr(arr3, size3);
	std::cout << mean_arr(arr3, size3);
	
	//Task 4 Prime_range
	/*std::cout << "\n\n\t\tTask 4.\n Prime_range.\n Enter two numbers --> ";
	std::cin >> n >> x;
	std::cout << " Simple numbers in the range from " << n << " to " << x << " --> ";
	prime_range(n, x);
	*/

	return 0;
}

//Task 1 Zeroing arr
template <typename T>
void fill_arr(T arr[], const int length, int a, int b) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (b + 1 - a) + a;
}
template <typename T>
void show_arr(T arr[], const int length) {
	std::cout << "[";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
template <typename T>
void clear_arr(T arr[], const int length, int zero) {
	for (int i = 0; i < length; i++)
		if (arr[i] == zero)
			arr[i] = 0;

}

//Task 2 Index_sum
int index_sum(int arr[], int arr1[], const int length, const int length2, int index) {
	if (index >= length && index >= length2) {
		std::cout << " Error.\n";
		return 0;
	}

	return arr[index] + arr1[index];

}

//Task 3 Mean_arr
template <typename T>
double mean_arr(T arr[], const int length) {
	double max, min;
	max = arr[0];
	min = arr[0];
	for (int i = 1; i < length; i++) {
		 arr[i] > max ? arr[i] = max : arr[0] = max;
		arr[i] < min ? arr[i] = min : arr[0] = min;
	}
	std::cout << " Avrg --> ";
	return ((double)max + (double)min) / 2.0;
}

//Task 4 Prime_range
void prime_range(int n1, int n2){
	int x = 0, y = 0, count = 0;
	if (n1 > n2) {
		x = n1;
		y = n2;
	}
	else {
		x = n2;
		y = n1;
	}
	for (int i = y; i <= x; i++) {
		for (int j = 1; j <= i ; j++)
			if (i % j == 0)
				count++;
		if (count == 2)
			std::cout << i << ", ";
		count = 0;
	}
	std::cout << "\b\b.\n";
}