#include "MultiMedia/ImageFile/ImageFile.h"
#include <iostream>

#include <ft2build.h>
#include FT_FREETYPE_H

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

int FreetypeTest(int argc, char** argv)
{
	// FreeType
   // --------
	FT_Library ft;
	// All functions return a value different than 0 whenever an error occurred
	if (FT_Init_FreeType(&ft))
	{
		std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
		return -1;
	}


	// find path to font
	std::string font_name = "fonts/Antonio-Bold.ttf";
	if (font_name.empty())
	{
		std::cout << "ERROR::FREETYPE: Failed to load font_name" << std::endl;
		return -1;
	}

	// load font as face
	FT_Face face;
	if (FT_New_Face(ft, font_name.c_str(), 0, &face)) {
		std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
		return -1;
	}
	else
	{
		// set size to load glyphs as
		FT_Set_Pixel_Sizes(face, 0, 48);
		// load first 128 characters of ASCII set
		for (unsigned char c = 0; c < 128; c++)
		{
			// Load character glyph 
			if (FT_Load_Char(face, c, FT_LOAD_RENDER))
			{
				std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
				continue;
			}
			unsigned char* pix = new unsigned char[3 * face->glyph->bitmap.width * face->glyph->bitmap.rows];
			for (int i = 0; i < face->glyph->bitmap.rows; i++)
			{
				for (int j = 0; j < face->glyph->bitmap.width; j++)
				{
					int offset  = (i * face->glyph->bitmap.width + j);
					int offset2 = 3 * (i * face->glyph->bitmap.width + j);
					pix[offset2 + 0] = 0;
					pix[offset2 + 1] = 0;
					pix[offset2 + 2] = 0;
					if (face->glyph->bitmap.buffer[offset])
					{
						pix[offset2 + 0] = 255;
						pix[offset2 + 1] = 0;
						pix[offset2 + 2] = 0;
					}
				}
			}
			std::cout
				<< face->glyph->bitmap.width	<< " "
				<< face->glyph->bitmap.rows		<< " "
				<< std::endl;;
			Vector2u Res(face->glyph->bitmap.width, face->glyph->bitmap.rows);
			auto f = new ImageFile(Res, ImageFile::PixelFormat::PF_R8G8B8_UINT, pix);
			f->Write(std::string("font_") + std::to_string((int)c) + ".webp");

			delete [] pix;
		}
	}

	// destroy FreeType once we're finished
	FT_Done_Face(face);
	FT_Done_FreeType(ft);

	return 0;
}