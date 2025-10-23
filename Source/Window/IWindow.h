#pragma once

enum class GraphicsAPI {
	OpenGL330,
	OpenGL460,
	ES32,
	ES31,
	ES30,
	ES20,
	Vulkan,
	D3D12,
	D3D11,
	D3D10,
	D3D9,
	Metal
};

class IWindow
{
public:
	IWindow() = default;
	virtual ~IWindow() = default;
public:
	virtual void Resize(int W, int H) = 0;
};