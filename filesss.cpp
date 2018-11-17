#include <iostream>
#include <fstream> 
#include <vector>
#include <climits> 
#include "filesss.h"

#define maxfilesize ULONG_MAX/2

typedef unsigned char BYTE;
typedef unsigned long ulong;
typedef unsigned int uint;

namespace filesss {

	fileIn::fileIn() {
	
		filePath = nullptr;
		fileSize = 0;

	};

	fileIn::fileIn(const char *fileInPath) {
	
		filePath = fileInPath;
		fileSize = calcFileSize();

		if (fileSize == 0) {
			
		};

	};

	ulong fileIn::calcFileSize() {

		ulong length = 0;
		std::ifstream is(filePath, std::fstream::in);
		if (!is) {
			std::cerr << "\n***Failed to open file " << filePath << " ***\n";
			return 0;
		};

		if (is) {
			// get length of file:
			is.seekg(0, is.end);
			length = static_cast<long>(is.tellg());
			is.seekg(0, is.beg);
		}

		is.close();
		
		if (length > maxfilesize) {
			length = 0;
			std::cerr << "<" << filePath << "> file too big\n";
			return 0;
		};

		return length;
	}

	void copyFileData(fileIn jpg, fileIn rar, std::string fname) {

		uint Jsize = jpg.getFileSize();
		uint Rsize = rar.getFileSize();
		uint size = (Jsize) + (Rsize-1) + 1;

		std::vector<char> jbuffer(Jsize);
		std::vector<char> rbuffer(Rsize);
		

		std::ifstream inJfile(jpg.getFilePath(), std::ios::in | std::ios_base::binary);
		if (!inJfile) {
			std::cerr << "\n***Failed to open file " << jpg.getFilePath() << " ***\n";
			return;
		};

		std::ifstream inRfile(rar.getFilePath(), std::ios::in | std::ios_base::binary);
		if (!inRfile) {
			std::cerr << "\n***Failed to open file " << rar.getFilePath() << " ***\n";
			return;
		};
		
		inJfile.read((char*)&jbuffer[0], Jsize);
		inRfile.read((char*)&rbuffer[0], Rsize);

		std::vector<char> buffer = jbuffer;
		buffer.insert(buffer.end(), rbuffer.begin(), rbuffer.end());


		std::ofstream outfile(fname, std::ios::out | std::ofstream::binary);
		if (outfile) {
			char *cstr = &fname[0u];
			std::cerr << "\n***Failed to open file " << cstr;
			return;
		};

		outfile.write((char*)&buffer[0], size);
		
		// release dynamically-allocated memory
		outfile.close();
		inJfile.close();
		inRfile.close();

	};

	long fileIn::getFileSize() {

		return fileSize;

	};

	const char* fileIn::getFilePath() {

		return filePath;

	};

	fileIn::~fileIn(){
		filePath = nullptr;
		fileSize = 0;
	};

	void prompt() {
		std::cout << "\n\nPress any key to continue...";
		std::cin.get();
		return;
	};
};