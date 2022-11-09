#include <iostream>

int main(int argc, char **argv) {
	int i;
	int j;
	const char one_argc[40] = "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	
	i = 0;
	if (argc == 1) {
		while (one_argc[i] != '\0')
			std::cout << one_argc[i++];
		return 0;
	}
	i = 1;
	while (argv[i]) {
		j = 0;
		while (argv[i][j] != '\0') 
			std::cout << (char)std::toupper(argv[i][j++]);
		i++;
	}
	std::cout << std::endl;
	return argc;
}
