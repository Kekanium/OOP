#include "Figure.h"


Figure::Figure(const char* inp)
{
	_position[0] = inp[0];
	_position[1] = inp[1];
}

Figure::Figure()
{
}

int Figure::deskout(char* pos)
{
	if(strlen(pos)==2)
		return (pos[0] > 'h') || (pos[0] < 'a') || (pos[1] < '1') || (pos[1] > '8');
	return 1;
}

void Figure::printBoard()
{
	char s[3];
	s[2] = '\0';
	const char* mark = ".+x";       // маркер позиции (безопасная / под атакой)
	std::cout << "  A B C D E F G H\n";  // верхняя строка
	for (int i = 8; i > 0; i--) {   // цикл по строкам
		std::cout << i << ' ';             // номер строки доски слева
		s[1] = '0' + i;               // текущая позиция по горизонтали
		for (int j = 0; j < 8; j++) { // цикл по столбцам
			s[0] = 'a' + j;             // текущая позиция по вертикали
			// если позиция не совпадает с положением фигуры, то вывести маркер
			char m = (*this != s) ? mark[attack(s)] : isA();
			std::cout << m << ' ';
		}
		std::cout << i << "\n"; // номер строки доски справа
	}
	std::cout << "  A B C D E F G H\n"; // нижняя строка
}

Figure& Figure::operator=(char* p)
{
	_position[0] = p[0];
	_position[1] = p[1];
	return *this;
}

int Figure::operator!=(char* p)
{
	return (_position[0] != p[0]) || (_position[1] != p[1]);

}

int Figure::operator==(char* p)
{
	return((_position[0] == p[0]) && (_position[1] == p[1]));
}

std::ostream& operator<<(std::ostream& out, Figure& f)
{
	return out << f.isA() << f._position[0] << f._position[1];
}

std::istream& operator>>(std::istream& in, Figure& f)
{
	char s[3];
	//std::cin.unsetf(std::ios::skipws);
	in >> s[0] >> s[1];
	s[2] = '\0';
	in.ignore(64, '\n');
	if (Figure::deskout(s) || (f.attack(s) == 0) || f == s)
		in.setstate(std::ios::failbit);
	//if ( || (f == s)) // if(f.deskout(s))
	//	in.clear(std::ios::failbit | in.rdstate());
	f = s;
	return in;
}
