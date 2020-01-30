#pragma once
#include "Element.h"
#include <iostream>
#include <list>

namespace Board {
	struct Board {
	private:
		Element::Element** board = 0;
		int size = 0;
		bool* isInit = new bool(0);
		std::list<int>* closedElements = 0;
		
	public:
		Board() {
			*isInit = false;
		}

		bool initialize(int s) {
			if (s < 3 || s > 10) {
				size = 0;
				board = 0;
				*isInit = false;
				return *isInit;
			}

			if (*isInit) {
				delete board;
				delete closedElements;
			}

			closedElements = new std::list<int>();
			size = s + 2;
			board = new Element::Element * [size];
			for (int i = 0; i < size; i++) {
				board[i] = new Element::Element[size];
			}
			for (int i = 1; i < size - 1; i++) {
				for (int j = 1; j < size - 1; j++) {
					board[i][j].setFields(j, i, 'B');
					if (i == 1) board[i][j].setClosed("top", true);
					if (i == size - 2) board[i][j].setClosed("bot", true);
					if (j == 1) board[i][j].setClosed("left", true);
					if (j == size - 2) board[i][j].setClosed("right", true);
				}
			}
			*isInit = true;
			return *isInit;
		}

		int getSize() {
			int a = size;
			a = a - 2;
			return a;
		}

		bool isCreated() {
			return *isInit;
		}

		void turnOver(int posY, int posX) {
			if (posX<1 || posX>=size - 1 || posY < 1 || posY>=size - 1) return;
			else {
				board[posY][posX].turnOver();
				addClosedElement(posY, posX);
				board[posY - 1][posX].setClosed("bot", true);
				board[posY + 1][posX].setClosed("top", true);
				board[posY][posX + 1].setClosed("left", true);
				board[posY][posX - 1].setClosed("right", true);
				addClosedElement(posY - 1, posX);
				addClosedElement(posY + 1, posX);
				addClosedElement(posY, posX + 1);
				addClosedElement(posY, posX - 1);
			}
		}
	private:
		void addClosedElement(int y, int x) {
			if (board[y][x].getState()) {
				add(y, x);
			}
			else {
				remove(y, x);
			}
		}

		void add(int y, int x) {
			int pos = y * size + x;
			closedElements->push_back(pos);
		}

		void remove(int y, int x) {
			int pos = y * size + x;
			closedElements->remove(pos);
		}

		int getClosedCount() {
			return closedElements->size();
		}

	public:
		void printBoard() {
			// Print current board
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size ; j++) {
					std::cout << board[i][j].getColor() << " ";
				}
				std::cout << std::endl;
			}
		}

		void printClosedCount() {
			// Print curren state of board count of 'closed' elements
			// Element is closed when TOP and BOT and LEFT and RIGHT elements of it 
			//		have another color
			std::cout << getClosedCount() << std::endl;
		}
	};
}
