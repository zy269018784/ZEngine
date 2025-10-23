﻿#include <RHIApplication.h>

RHIApplication::RHIApplication(GLFWwindow* InWindow)
    : Window(InWindow)
{
    std::cout << "RHIApplication" << std::endl;
#if USE_RHI_VULKAN
    pRHI = new VulkanRHI();
#else
    /*
        opengl需要
    */
    glfwMakeContextCurrent(InWindow);
    pRHI = new ES32RHI();
#endif
    HWND hwnd = glfwGetWin32Window(Window);
    HINSTANCE instacne = (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE);
    //RHIWindow_ = pRHI->RHICreateWindow(InWindow);
    RHIWindow_ = pRHI->RHICreateWindow(instacne, hwnd);

    std::cout << "RHIApplication End" << std::endl;
}

RHIApplication::~RHIApplication()
{
    delete VertexShader; 
    delete FragmengShader; 
    delete GeometryShader; 
    delete ComputeShader; 
    delete RHIVBO;
    delete RHIEBO;
    delete SRB;
    delete GraphicsPipeline;
    delete RHIWindow_;
    delete pRHI;
}

void RHIApplication::Run()
{
    Init();

    while (!glfwWindowShouldClose(Window))
    {
        RHIWindow_->RHIBeginFrame();
        RHIWindow_->RHIBeginRenderPass();
        Draw();
        RHIWindow_->RHIEndRenderPass();
        RHIWindow_->RHIEndFrame();
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(Window);
        glfwPollEvents();
    }
    RHIWindow_->WaitDeviceIdle();
}

void RHIApplication::Resize(int w, int h)
{
    glfwSetWindowSize(Window, w, h);
}

void RHIApplication::Init()
{

}

void RHIApplication::Draw()
{

}

void RHIApplication::Render()
{

}