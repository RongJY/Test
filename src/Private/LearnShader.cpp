#include "../Public/LearnShader.h"
#include "iostream"
#include <string.h>
#include<GL/glew.h>
#include <GLFW/glfw3.h>


int LearnShader::CreateShader(const std::string VertexShader, const std::string FragmentShader)
{
	//����һ���µĿյ� ������� ����������program
	unsigned int Program =glCreateProgram();
	unsigned int vs =ComplieShader(GL_VERTEX_SHADER, VertexShader);
	unsigned int fs =ComplieShader(GL_FRAGMENT_SHADER, FragmentShader);
	return 0;
}

unsigned int LearnShader::ComplieShader(unsigned int Type, const std::string& source)
{
	//����һ���յ���ɫ������ ������һ�� id
	unsigned int id  = glCreateShader(Type);
	const char* src = source.c_str();
	// glShaderSource ---- �� shader ����ָ��Դ�롣
	// ����һ  shader ָ����Ҫ����Դ���shader����
	// ������  count ָ��Դ��ű�������
	// ������  string ָ������װ�ڵ�shaderԴ��
	// ������  length ָ��stringԴ������ĳ���
	glShaderSource(id, 1, &src, nullptr);
	//����һ����ɫ������ 
	glCompileShader(id);
	//����Ҫ��ѯ����ɫ�������� ������Ϣ
	//����һ shader ������Ҫ��ѯ����ɫ��
	//������ pname ָ��Ҫ��ѯ���������� GL_SHADER_TYPE, GL_DELETE_STATUS, GL_COMPILE_STATUS, 
	//GL_INFO_LOG_LENGTH, GL_SHADER_SOURCE_LENGTH. ���⼸������
	//������ params �����������Ĳ���
	int result;
	glGetShaderiv(id,GL_COMPILE_STATUS,&result);
	if (result==GL_FALSE)
	{
		int lenght;
		
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &lenght);
		//��̬����ѿռ�
		char* message = (char*)alloca(lenght*sizeof(char));
		//��ȡ��ɫ��log����
		//������ ���ڴ洢�����ַ��Ĵ�С
		glGetShaderInfoLog(id, lenght, &lenght, message);
		std::cout << &message << std::endl;

		//ɾ����������ɫ������������new�����Ķ��� 
		glDeleteShader(id);
		return 0;
	}


	return id;
}
