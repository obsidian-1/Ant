#pragma once
#include "../deps.h"
namespace ant
{
	class Texture2D
	{
	private:
		GLuint id;
		int width;
		int height;
		unsigned int type = GL_TEXTURE_2D;
		int streams;

	public:
		Texture2D(const char *fileName, GLenum type);
		Texture2D(){}
		~Texture2D();
		inline GLuint getID() const { return this->id; }
		void bind(const GLint texture_unit);
		void unbind();
	};
}