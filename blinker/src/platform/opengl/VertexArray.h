#pragma once

class VertexArray
{
public:
	VertexArray();
	~VertexArray();
	void operator=(VertexArray&& va);
	void Bind() const;
	void Unbind() const;
	bool IsBinded() const;
	void AddVertexBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
private:
	uint32_t m_RendererID;
};
