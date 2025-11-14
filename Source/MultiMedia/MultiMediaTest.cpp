#include "MultiMedia/ImageFile/ImageFile.h"
#include <iostream>
int MultiMediaTest(int argc, char** argv)
{
	if (argc < 2)
		return 0;
	auto f1 = ImageFile::Read(argv[1]);
	std::cout << f1->NChannels() << std::endl;
	std::cout << (int)f1->GetFormat() << std::endl;
	for (int i = 2; i < argc; i++)
	{
		std::cout << argv[i] << std::endl;
		f1->Write(argv[i]);
	}
	return 0;
}	