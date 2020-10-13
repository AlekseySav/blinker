#pragma once

class VertexBufferLayout
{
public:
	struct Element
	{
		uint32_t type;
		uint32_t size;
		uint32_t count;
	};
public:
	VertexBufferLayout();

	template<typename T>
	void Push(uint32_t count)
	{
		static_assert(false);
	}

	constexpr const std::vector<Element>& Elements() const { return m_Elements; }
	constexpr uint32_t GetStride() const { return m_Stride; }
private:
	uint32_t m_Stride;
	std::vector<Element> m_Elements;
};

template<>
void VertexBufferLayout::Push<float>(uint32_t count);
