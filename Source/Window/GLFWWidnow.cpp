#include "GLFWWidnow.h"

GLFWWidnow::GLFWWidnow(int Width, int Height, const char* Title, GraphicsAPI API)
{
	/*
		初始化glfw
	*/
	glfwInit();

	/*
		窗口可以Resize
	*/
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
	switch (API)
	{
	case GraphicsAPI::OpenGL330:
		glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		break;
	case GraphicsAPI::OpenGL460:
		glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		break;
	case GraphicsAPI::ES32:
		glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		break;
	case GraphicsAPI::ES31:
		glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		break;
	case GraphicsAPI::ES30:
		glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		break;
	case GraphicsAPI::ES20:
		glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		break;
	case GraphicsAPI::Vulkan:
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		break;
	case GraphicsAPI::D3D12:
		break;
	case GraphicsAPI::D3D11:
		break;
	case GraphicsAPI::D3D10:
		break;
	case GraphicsAPI::D3D9:
		break;
	case GraphicsAPI::Metal:
		break;
	default:
		break;
	}

	/*
	创建窗口
*/
	Handle = glfwCreateWindow(Width, Height, Title, nullptr, nullptr);
}

GLFWWidnow::~GLFWWidnow()
{
	glfwDestroyWindow(Handle);
}

GLFWwindow* GLFWWidnow::GetHandle() const
{
	return Handle;
}

GLFWkeyfun GLFWWidnow::SetKeyCallback(GLFWkeyfun Callback)
{
	return glfwSetKeyCallback(Handle, Callback);
}

GLFWmousebuttonfun 	GLFWWidnow::SetMouseButtonCallback(GLFWmousebuttonfun Callback)
{
	return glfwSetMouseButtonCallback(Handle, Callback);
}

GLFWcursorposfun 	GLFWWidnow::SetCursorPosCallback(GLFWcursorposfun Callback)
{
	return glfwSetCursorPosCallback(Handle, Callback);
}

void GLFWWidnow::Resize(int Width, int Height)
{
	glfwSetWindowSize(Handle, Width, Height);
}