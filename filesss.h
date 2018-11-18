#ifndef _filesss_H
#define _filesss_H
#include <vector>

namespace filesss {

	class fileIn {

		//var
		const char *filePath;
		long fileSize;
		//func
		unsigned long calcFileSize();
		
	public:
		//var 
		bool badfile;
		char type = 'x';
		//func
		fileIn();
		fileIn(const char *filePath);
		void check(const char*);
		long getFileSize();
		const char* getFilePath();
		~fileIn();
	};

	void copyFileData(fileIn jpg, fileIn rar, std::string fname);
};
#endif