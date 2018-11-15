#include <stdio.h>
#include <iostream>
#include "filesss.h"

namespace filesss {

	fileIn::fileIn() {
	
		filePath = nullptr;
		fileSize = 0;

	};

	long fileIn::getFileSize(FILE *file) {
	
		long lCurPos, lEndPos;
		lCurPos = ftell(file);
		fseek(file, 0, 2);
		lEndPos = ftell(file);
		fseek(file, lCurPos, 0);
		fileSize = lEndPos;
		return lEndPos;

	}

	fileIn::fileIn(const char *fileInPath) {
	
		filePath = fileInPath;
	
	};

	fileIn::~fileIn(){
		delete[] filePath;
		filePath = nullptr;
	};

};