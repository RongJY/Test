#pragma once
//shader�����������Կ��ϵ�һ������
//�ص��о�����shader vertex Shader ��fragment Shader Ƭ����ɫ����������������ɫ����
//ÿ���������һ�ζ�����ɫ��
//������ͼ���ж��ٸ����أ��ͻ���ö��ٸ�������ɫ��
#include <iostream>



class LearnShader
{
public:
	LearnShader();
	~LearnShader();
	int CreateShader(const std::string& VertexShader,const std::string& FragmentShader);
protected:
	unsigned int ComplieShader(unsigned int Type, const std::string& source);
};

