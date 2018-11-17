#define _CRT_SECURE_NO_DEPRECATE
#include <fstream> 
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <climits> 
#include "filesss.h"
#define maxfilesize ULONG_MAX/2

// An unsigned char can store 1 Bytes (8bits) of data (0-255)
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
	};

	ulong fileIn::calcFileSize() {

		ulong length = 0;
		std::ifstream is(filePath, std::fstream::in);


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
		};

		return length;
	}

	int copyFileData(fileIn jpg, fileIn rar, std::string fname) {

		uint Jsize = jpg.getFileSize();
		uint Rsize = rar.getFileSize();
		uint size = (Jsize) + (Rsize-1) + 1;

		std::vector<char> jbuffer(Jsize);
		std::vector<char> rbuffer(Rsize);
		

		std::ifstream inJfile(jpg.getFilePath(), std::ios::in | std::ios_base::binary);
		std::ifstream inRfile(rar.getFilePath(), std::ios::in | std::ios_base::binary);
		
		
		inJfile.read((char*)&jbuffer[0], Jsize);
		inRfile.read((char*)&rbuffer[0], Rsize);

		std::vector<char> buffer = jbuffer;
		buffer.insert(buffer.end(), rbuffer.begin(), rbuffer.end());


		std::ofstream outfile(fname, std::ios::out | std::ofstream::binary);

		outfile.write((char*)&buffer[0], size);
		
		// release dynamically-allocated memory
		outfile.close();
		inJfile.close();
		inRfile.close();
		return 0;
	};

	long fileIn::getFileSize() {

		return fileSize;

	};

	const char* fileIn::getFilePath() {

		return filePath;

	};

	fileIn::~fileIn(){
		//delete[] filePath;
		filePath = nullptr;
	};

};