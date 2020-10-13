#include <pch.h>
#include "core.h"
#include "VertexBufferLayout.h"

VertexBufferLayout::VertexBufferLayout() : m_Stride(0)
{
}

template<>
void VertexBufferLayout::Push<float>(uint32_t count)
{
	m_Elements.push_back({ GL_FLOAT, sizeof(float), count });
	m_Stride += count * sizeof(float);
}
