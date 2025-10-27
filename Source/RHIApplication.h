#pragma once
#include "ES32RHI.h"
#define USE_RHI_VULKAN 1
#if USE_RHI_VULKAN
#include <VulkanRHI.h>
#endif

//#include <iostream>
//#include <fstream>
//#include <stdexcept>
//#include <algorithm>
//#include <vector>
//#include <cstring>
//#include <cstdlib>
//#include <cstdint>
//#include <limits>
//#include <optional>
//#include <set>
//#include <RHI.h>


#define GLFW_EXPOSE_NATIVE_WIN32
#if USE_RHI_VULKAN
#define GLFW_INCLUDE_VULKAN
#endif
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>




class RHIApplication
{
public:
    RHIApplication(GLFWwindow* Window);
    virtual ~RHIApplication();
    virtual void Run();
    virtual void Resize(int w, int h);
private:
    virtual void Init();
    virtual void Draw();
    virtual void Render();
protected:
    /*
        GLFW窗口
    */
    GLFWwindow* Window = nullptr;
    RHIWindow* RHIWindow_ = nullptr;
    /*
        RHI
    */
    RHI* pRHI = nullptr;
    /*
        VBO
    */
    RHIBuffer* RHIVBO = nullptr;
    /*
        EBO
    */
    RHIBuffer* RHIEBO = nullptr;
    /*
        Pipeline
    */
    RHIGraphicsPipeline* GraphicsPipeline = nullptr;
    /*
       顶点输入
    */
    std::vector<RHICommandBuffer::VertexInput> VertexInputs;
    /*
        着色器资源绑定
    */
    RHIShaderResourceBindings* SRB = nullptr;
    /*
        着色器
    */
    RHIShader* VertexShader = nullptr;
    RHIShader* FragmengShader = nullptr;
    RHIShader* GeometryShader = nullptr;
    RHIShader* ComputeShader = nullptr;
};
