#ifndef _filesss_H
#define _filesss_H

namespace filesss {

	class fileIn {

		const char *filePath;
		long fileSize;


	public:
		fileIn();
		fileIn(const char *filePath);
		long getFileSize();
		~fileIn();
	};

};
#endif