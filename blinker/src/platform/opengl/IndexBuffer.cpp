#include <pch.h>
#include "core.h"
#include "IndexBuffer.h"

static const IndexBuffer* binded = nullptr;

IndexBuffer::IndexBuffer(const uint32_t* data, uint32_t count) : m_Count(count)
{
	glGenBuffers(1, &m_RendererID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &m_RendererID);
}

void IndexBuffer::Bind() const
{
	if (!IsBinded()) {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
		binded = this;
	}
}

void IndexBuffer::Unbind() const
{
#ifdef _DEBUG
	if (IsBinded()) {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		binded = nullptr;
	}
#endif
}

bool IndexBuffer::IsBinded() const
{
	return binded == this;
}
