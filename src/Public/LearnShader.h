#pragma once
//shader就是运行在显卡上的一个程序
//重点研究两种shader vertex Shader 和fragment Shader 片段着色器（类似与像素着色器）
//每个顶点调用一次顶点着色器
//所画的图形有多少个像素，就会调用多少个像素着色器
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

