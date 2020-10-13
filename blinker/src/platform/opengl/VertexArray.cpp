#include <pch.h>
#include <core.h>
#include "core.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "VertexArray.h"

static const VertexArray* binded = nullptr;

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_RendererID);
}

VertexArray::~VertexArray()
{
	if(m_RendererID) glDeleteVertexArrays(1, &m_RendererID);
}

void VertexArray::operator=(VertexArray&& va)
{
	m_RendererID = va.m_RendererID;
	va.m_RendererID = 0;
}

void VertexArray::Bind() const
{
	if (!IsBinded()) {
		glBindVertexArray(m_RendererID);
		binded = this;
	}
}

void VertexArray::Unbind() const
{
#ifdef _DEBUG
	if (IsBinded()) {
		glBindVertexArray(0);
		binded = nullptr;
	}
#endif
}

bool VertexArray::IsBinded() const
{
	return binded == this;
}

void VertexArray::AddVertexBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	Bind();
	vb.Bind();
	const std::vector<VertexBufferLayout::Element>& elements = layout.Elements();
	const uint32_t& stride = layout.GetStride();
	const char* ptr = nullptr;
	for (uint32_t i = 0; i < elements.size(); i++) {
		const auto& e = elements[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, e.count, e.type, GL_FALSE, stride, ptr);
		ptr += (size_t)e.count * e.size;
	}
}
