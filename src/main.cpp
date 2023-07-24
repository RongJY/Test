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
    float positions[6]{
        -0.5f, 0.5f,
        0.0f, 0.5f,
        0.5f, -0.5f
    };

    unsigned int buffer;
    //申请Buffers缓冲区地址
    glGenBuffers(1, &buffer);
    //绑定buffers缓冲区的类型
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    //将数据放入到缓冲区中
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);




    std::cout << glGetString(GL_VERSION) << std::endl;
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