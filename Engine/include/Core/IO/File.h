#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <string>

namespace Engine
{
	class File
	{
	public:
		File(const std::string& filename);
		~File();

		bool Open(const std::string& filename, std::ios::openmode mode);
		void Write(const std::string& data);
		std::string Read();
		void Close();

		bool IsOpen() const { return file.is_open(); };
		bool IsGood() const { return file.good(); };
		std::string GetFilename() const { return filename; };

	private:
		std::fstream file;
		std::string filename;

	};
}

#endif
