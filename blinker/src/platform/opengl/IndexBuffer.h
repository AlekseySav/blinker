#pragma once

class IndexBuffer
{
public:
	IndexBuffer() = default;
	IndexBuffer(const uint32_t* data, uint32_t count);
	~IndexBuffer();
	void Bind() const;
	void Unbind() const;
	bool IsBinded() const;
	constexpr uint32_t GetCount() const { return m_Count; }
private:
	uint32_t m_RendererID;
	uint32_t m_Count;
};
