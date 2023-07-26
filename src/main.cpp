#pragma once
#include<GL/glew.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include<string>




void OpenGLTest() {

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return;//-1;


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return;//-1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cout << "error" << std::endl;
    }
    float positions[12]{
        -0.5f, 0.5f,
        0.0f, 1.f,
        0.5f, -0.5f,
         1.f, 0.5f,
        0.0f, 1.f,
        1.f, -0.5f
    };

    unsigned int buffer;
    //申请Buffers缓冲区地址
    glGenBuffers(1, &buffer);
    //绑定buffers缓冲区的类型
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    //将数据放入到缓冲区中
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);
    //启用顶点数组
    glEnableVertexAttribArray(0);
    
    //(const void*)
    //参数一 对应着着色器里面的索引位置的 索引0是 顶点位置，1是颜色这种。。。
    //参数二 size对应着你的维数 1是一维，2是二维，以此类推
    //参数三 是你的参数类型
    //参数四 定义我们是否希望数据被标准化(Normalize)。如果我们设置为GL_TRUE，所有数据都会被映射到0（对于有符号型signed数据是-1）到1之间。我们把它设置为GL_FALSE。
    //参数五 Stride叫做步长，就是多少个元素为一组，但是一旦我们有了更多的顶点属性的时候，我们一般
    //设置成0让OpenGL来决定具体步长是多少
    //参数六 类型是void* 这个值一般受绑定的缓冲区地址影响，大概指的是偏移量
    glVertexAttribPointer(0, 2, GL_FLOAT,GL_FALSE,sizeof(float)*2,0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);



    //std::cout << glGetString(GL_VERSION) << std::endl;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        /* glBegin(GL_TRIANGLES);
         glVertex2f(-0.5f, 0.5f);
         glVertex2f(0.0f, 0.5f);
         glVertex2f(0.5f, -0.5f);
         glVertex2f(-0.5f, -0.5f);
         glVertex2f(-1.0f, 0.5f);
         glVertex2f(-0.5f, 1.f);
         glEnd();*/
        //绘画三角形，但是目前没有与自己申请的Buffers进行绑定，所以画不出来
        glDrawArrays(GL_TRIANGLES, 0, 3);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return;//0;
}

class LOG
{
public:
   // int 

private:

    int m_LogWarnLevel;
    
public:
    void setLevel(int LogWarnLevel) {
        m_LogWarnLevel = LogWarnLevel;
    }

    void Error(const char* Warn) {
        std::cout << Warn << std::endl;
    }
};


//单例模式
class RJYTestStatic {
public:
    static RJYTestStatic& Get() {
        static RJYTestStatic RJYTestStaticInstance;
        return RJYTestStaticInstance;
    }
protected:
    int i = 0;
public:
   
    void Hello() {
        i++;
    }

    void SayHello() {
        std::cout << i << std::endl;
    }

};


template<typename T>
T RJYPrint(T& param) {
    std::cout << param << std::endl;
    return param;
}



int main(void)
{   
    /*int x = 7;
    const int cx = x;
    const int& rx = cx;
    std::string t = "hello,world";
    RJYPrint(x);
    RJYPrint(cx);
    RJYPrint(rx);
   auto s = RJYPrint(t);
   auto z = RJYPrint(x);
   std::cout << sizeof(z) << std::endl;*/

    OpenGLTest();

    std::cin.get();
}