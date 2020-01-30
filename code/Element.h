#pragma once
#include <string>

namespace Element {
	struct Element {
	private:
		int x = 0;
		int y = 0;
		char color = 'W';
		bool top = false;
		bool bot = false;
		bool right = false;
		bool left = false;

	public:
		Element(int posX, int posY, char c) {
			x = posX;
			y = posY;
			color = c;
		}

		Element() {
			x = 0;
			y = 0;
			color = 'W';
		}

		void setFields(int posX, int posY, char c) {
			x = posX;
			y = posY;
			color = c;
		}

		void turnOver() {
			if (color == 'W') {
				color = 'B';
			}
			else if (color == 'B') {
				color = 'W';
				top = false;
				bot = false;
				right = false;
				left = false;
			}
		}

		bool getState() {
			if (color == 'W') return false;
			return (top && bot && right && left);
		}

		bool setClosed(std::string where, bool isClosed) {
			if (color == 'W') return false;
			if ("top" == where) top = isClosed;
			if ("bot" == where) bot = isClosed;
			if ("right" == where) right = isClosed;
			if ("left" == where) left = isClosed;
			return getState();
		}

		char getColor() {
			return color;
		}

		std::string getFields() {
			std::string s{};
			s += "x = " + std::to_string(x);
			s += "\ny = " + std::to_string(y);
			s += "\ntop = " + std::to_string(top);
			s += "\nbot = " + std::to_string(bot);
			s += "\nright = " + std::to_string(right);
			s += "\nleft = " + std::to_string(left);
			s += "\n";
			return s;
		}
	};
}
