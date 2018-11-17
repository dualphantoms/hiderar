#ifndef _filesss_H
#define _filesss_H
#include <vector>

namespace filesss {

	class fileIn {

		const char *filePath;
		long fileSize;
		

		unsigned long calcFileSize();
		

	public:
		fileIn();
		fileIn(const char *filePath);
		long getFileSize();
		const char* getFilePath();
		~fileIn();
	};

	int copyFileData(fileIn jpg, fileIn rar, std::string fname);
};
#endif