#pragma once

class VertexBuffer
{
public:
	VertexBuffer() = default;
	VertexBuffer(const void* data, uint32_t size);
	~VertexBuffer();
	void Bind() const;
	void Unbind() const;
	bool IsBinded() const;
private:
	uint32_t m_RendererID;
};
