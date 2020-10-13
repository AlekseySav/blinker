#include <pch.h>
#include "core.h"
#include "VertexBuffer.h"

static const VertexBuffer* binded = nullptr;

VertexBuffer::VertexBuffer(const void* data, uint32_t size)
{
	glGenBuffers(1, &m_RendererID);
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_RendererID);
}

void VertexBuffer::Bind() const
{
	if (!IsBinded()) {
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
		binded = this;
	}
}

void VertexBuffer::Unbind() const
{
#ifdef _DEBUG
	if (IsBinded()) {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		binded = nullptr;
	}
#endif
}

bool VertexBuffer::IsBinded() const
{
	return binded == this;
}
