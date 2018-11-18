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

void prompt() {
	std::cout << "\n\nPress any key to continue...";
	std::cin.get();
	exit(EXIT_FAILURE);
};

int main(int argc, char* argv[])
{
	std::string fname;
	fileIn jpgfile;
	bool flagem = false;

	//std::cout << "\nCommand Line : ";
	//for (int i = 0; i < argc; i++) {
	//	std::cout << argv[i] << ' ';
	//}

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
		//load'em
		jpgfile = fileIn(argv[1]);
		if (jpgfile.getFileSize() == 0 || jpgfile.type != 'j') {
			std::cerr << "*** Missing JPEG File! ***\n";
			std::cerr << "Usage: " << argv[0] << " <JPGFILE>";
			prompt();
		};

		flagem = true;
	}
	else if (argc == 4) {
		jpgfile = fileIn(argv[1]);
		if (jpgfile.getFileSize() == 0 || jpgfile.type != 'j') {
			std::cerr << "*** Missing JPEG File! ***\n";
			std::cerr << "Usage: " << argv[0] << " <JPGFILE>";
			prompt();
		};

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


	//load'em 2: electric rarfileloo
	fileIn rarfile(argv[2]);
	if (rarfile.getFileSize() == 0 || rarfile.type != 'r') {
		std::cerr << "*** Missing RAR File! ***\n";
		std::cerr << "Usage: " << argv[0] << " " << argv[1] << " <RARFILE>";
		prompt();
	};


	
	//validate'em
	if (jpgfile.badfile == false && rarfile.badfile == false) {
		
		if (flagem) { 
			fname = fileName(); 
		};

		//hide'em
		copyFileData(jpgfile, rarfile, fname);
	};
	

	//leave'em
	return 0;
};