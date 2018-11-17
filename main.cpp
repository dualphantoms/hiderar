#include <iostream>
#include <string>
#include "filesss.h"

using namespace filesss;

std::string fileName() {
	//ask'em
	std::string fname;
	std::cout << "Enter file name, no extension: ";
	std::cin >> fname;

	//add'em
	fname = fname + ".jpg";
	
	return fname;
};



int main(int argc, char* argv[])
{
	std::string fname;

	if (argc == 1) {
		std::cerr << "*** Missing JPEG File! ***\n";
		std::cerr << "Usage: " << argv[0] << " <JPGFILE>";
		prompt();
	}
	else if (argc == 2) {
		std::cerr << "*** Missing RAR File! ***\n";
		std::cerr << "Usage: " << argv[0] << " " << argv[1] << " <RARFILE>";
		prompt();
	}
	else if (argc == 3) {
		fname = fileName();
	}
	else if (argc == 4) {
		fname = argv[3];
		std::size_t found = fname.find(".jpg");
		if (found == std::string::npos) {
			fname = fname + ".jpg";
		};
	}
	else if (argc == !4) {
		std::cerr << "*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " " << argv[1] << " " << argv[3] << " <whywouldyoudothis?>";
		prompt();
	};

	//load'em
	fileIn jpgfile(argv[1]);
	if (jpgfile.getFileSize() == 0) {
		prompt();
		return 2;
	};
	fileIn rarfile(argv[2]);

	//hide'em
	copyFileData(jpgfile, rarfile, fname);
	
	//tell'em
	std::cout << "Done.";

	//leave'em
	return 0;
};