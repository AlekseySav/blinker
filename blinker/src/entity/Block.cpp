#include <pch.h>
#include <core.h>
#include <renderer/Renderer.h>
#include "Block.h"

#define SIZE 16.0f

static float vertices[] = {
	-SIZE,	 SIZE,  SIZE, -1.0f,  0.0f,  0.0f,
	-SIZE,	-SIZE,  SIZE, -1.0f,  0.0f,  0.0f,
	-SIZE,	 SIZE, -SIZE, -1.0f,  0.0f,  0.0f,
	-SIZE,	-SIZE, -SIZE, -1.0f,  0.0f,  0.0f,

	 SIZE,	-SIZE,  SIZE,  0.0f, -1.0f,  0.0f,
	-SIZE,	-SIZE,  SIZE,  0.0f, -1.0f,  0.0f,
	 SIZE,	-SIZE, -SIZE,  0.0f, -1.0f,  0.0f,
	-SIZE,	-SIZE, -SIZE,  0.0f, -1.0f,  0.0f,

	 SIZE,	 SIZE, -SIZE,  0.0f,  0.0f, -1.0f,
	-SIZE,	 SIZE, -SIZE,  0.0f,  0.0f, -1.0f,
	 SIZE,	-SIZE, -SIZE,  0.0f,  0.0f, -1.0f,
	-SIZE,	-SIZE, -SIZE,  0.0f,  0.0f, -1.0f,

	 SIZE,	 SIZE,  SIZE,  1.0f,  0.0f,  0.0f,
	 SIZE,	-SIZE,  SIZE,  1.0f,  0.0f,  0.0f,
	 SIZE,	 SIZE, -SIZE,  1.0f,  0.0f,  0.0f,
	 SIZE,	-SIZE, -SIZE,  1.0f,  0.0f,  0.0f,

	 SIZE,	 SIZE,  SIZE,  0.0f,  0.0f, 1.0f,
	-SIZE,	 SIZE,  SIZE,  0.0f,  0.0f, 1.0f,
	 SIZE,	-SIZE,  SIZE,  0.0f,  0.0f, 1.0f,
	-SIZE,	-SIZE,  SIZE,  0.0f,  0.0f, 1.0f,

	 SIZE,	 SIZE,  SIZE,  0.0f,  1.0f,  0.0f,
	-SIZE,	 SIZE,  SIZE,  0.0f,  1.0f,  0.0f,
	 SIZE,	 SIZE, -SIZE,  0.0f,  1.0f,  0.0f,
	-SIZE,	 SIZE, -SIZE,  0.0f,  1.0f,  0.0f
};

static uint32_t indices[] = {
	 0,  1,  3,  0,  2,  3,
	 4,  5,  7,  4,  6,  7,
	 8,  9, 10,  9, 10, 11,
	12, 13, 14, 13, 14, 15,
	16, 17, 18, 17, 18, 19,
	20, 21, 22, 21, 22, 23
};

Block::Block(const Material* material)
	: m_VertexBuffer(vertices, sizeof(vertices)), m_VertexArray(), 
	m_IndexBuffer(indices, sizeof(indices) / 4), m_Material(material)
{
	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(3);
	m_VertexArray.AddVertexBuffer(m_VertexBuffer, layout);
}

void Block::OnRender(const Renderer& renderer, const glm::vec3& position, const glm::vec3& color) const
{
	m_Material->m_Shader.SetUniform("u_Color", color);
	renderer.Draw(this, position);
}

void Block::OnUpdate()
{
}
