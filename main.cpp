#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <string>
#include "filesss.h"

using namespace filesss;


int prompt() {

	std::cout << "\n\nPress any key to continue...";
	std::cin.get();
	return 0;
};

int main(int argc, char* argv[])
{
	if (argc == 1) {
		std::cerr << "*** Missing JPEG File! ***\n";
		std::cerr << "Usage: " << argv[0] << " <JPGFILE>";
		prompt();
		return 1;
	}
	else if (argc == 2) {
		std::cerr << "*** Missing RAR File! ***\n";
		std::cerr << "Usage: " << argv[0] << " " << argv[1] << " <RARFILE>";
		prompt();
		return 1;
	}
	else if (argc != 3) {
		std::cerr << "*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " " << argv[1] << " " << argv[3] << " <whywouldyoudothis?>";
		prompt();
		return 2;
	};

	fileIn jpgfile(argv[1]);
	fileIn rarfile(argv[2]);

	//jpgfile.visualizeData();
	//rarfile.visualizeData();

	std::string fname;
	std::cout << "Enter file name, no extension: ";
	std::cin >> fname;

	fname = fname + ".jpg";

	copyFileData(jpgfile, rarfile, fname);

	std::cout << "Done.";

	return 0;
};