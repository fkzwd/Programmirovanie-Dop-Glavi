#include <iostream>
#include "Element.h"
#include "Board.h"
#include "User.h"

using namespace std;

int main() {
	Board::Board* b = new Board::Board();
	while (!b->isCreated()) {
		b->initialize(User::getInt());
	}
	int* numbers = new int[2];

	int size = b->getSize();
	for (int i = 0; i < size*size; i++) {
		int* userNumbers = User::getInts(2);
		numbers[0] = userNumbers[0];
		numbers[1] = userNumbers[1];
		delete userNumbers;
		b->turnOver(numbers[0], numbers[1]);
		b->printClosedCount();
	}

	delete[] numbers;

	return 0;
}
