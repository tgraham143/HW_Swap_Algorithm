#include <iostream>
#include <string>
#include <sstream>;
#include <vector>

using namespace std;

// Variable - START
//	define variables that are global between the two Variable markers

// Variable - END

// Function/Method Declaration - START
//	define function/method declaration signatures between the two markers

void sort(string item_array[], int number_of_items, char datatype);

// Function/Method Declaration - END

int main() {
	char datatype;
	string input_line;

	cout << "What is your base datatype to be sorted, (s)tring or (n)umeric? ";
	cin >> datatype;

	cout << "Enter values to be sorted, separated by a space: ";
	cin.ignore(1000, '\n');
	getline(cin, input_line);

	stringstream input_stream(input_line);
	string input_array[1000];
	string value;
	int number_of_items = 0;
	while (getline(input_stream, value, ' ')) {
		input_array[number_of_items] = value;
		number_of_items++;
	}
	sort(input_array, number_of_items, datatype);

	for (int i = 0; i < number_of_items; i++)
		cout << input_array[i] << " ";
	cout << endl;
}

// Function/Method Definition - START
//	define function/method declaration signatures between the two markers
void sort(string item_array[], int number_of_items, char datatype) {
	for (int current_placement_index = 0; current_placement_index < number_of_items - 1; current_placement_index++) {
		for (int checking_index = current_placement_index + 1; checking_index < number_of_items; checking_index++)
			if (datatype == 'n' || datatype == 'N') {
				if (stod(item_array[checking_index]) < stod(item_array[current_placement_index])) {
					string temp = item_array[checking_index];
					item_array[checking_index] = item_array[current_placement_index];
					item_array[current_placement_index] = temp;
				}
			}
			else {
				if (item_array[checking_index].compare(item_array[current_placement_index]) < 0) {
					string temp = item_array[checking_index];
					item_array[checking_index] = item_array[current_placement_index];
					item_array[current_placement_index] = temp;
				}
			}
	}
}

// Function/Method Definition - END
