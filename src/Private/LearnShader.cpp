#include "../Public/LearnShader.h"
#include "iostream"
#include <string.h>
#include<GL/glew.h>
#include <GLFW/glfw3.h>


int LearnShader::CreateShader(const std::string VertexShader, const std::string FragmentShader)
{
	//创建一个新的空的 对象程序 并返回他的program
	unsigned int Program =glCreateProgram();
	unsigned int vs =ComplieShader(GL_VERTEX_SHADER, VertexShader);
	unsigned int fs =ComplieShader(GL_FRAGMENT_SHADER, FragmentShader);
	return 0;
}

unsigned int LearnShader::ComplieShader(unsigned int Type, const std::string& source)
{
	//创建一个空的着色器对象 并返回一个 id
	unsigned int id  = glCreateShader(Type);
	const char* src = source.c_str();
	// glShaderSource ---- 给 shader 对象指定源码。
	// 参数一  shader 指定需要设置源码的shader对象
	// 参数二  count 指定源码脚本的数量
	// 参数三  string 指定用于装在的shader源码
	// 参数四  length 指定string源码数组的长度
	glShaderSource(id, 1, &src, nullptr);
	//编译一个着色器对象 
	glCompileShader(id);
	//从你要查询的着色器类型中 返回消息
	//参数一 shader 输入你要查询的着色器
	//参数二 pname 指定要查询的内容类型 GL_SHADER_TYPE, GL_DELETE_STATUS, GL_COMPILE_STATUS, 
	//GL_INFO_LOG_LENGTH, GL_SHADER_SOURCE_LENGTH. 有这几种类型
	//参数三 params 返回请求对象的参数
	int result;
	glGetShaderiv(id,GL_COMPILE_STATUS,&result);
	if (result==GL_FALSE)
	{
		int lenght;
		
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &lenght);
		//动态申请堆空间
		char* message = (char*)alloca(lenght*sizeof(char));
		//获取着色器log数据
		//参数二 用于存储返回字符的大小
		glGetShaderInfoLog(id, lenght, &lenght, message);
		std::cout << &message << std::endl;

		//删除创建的着色器对象，类似与new出来的对象 
		glDeleteShader(id);
		return 0;
	}


	return id;
}
