#include <pch.h>
#include <core.h>
#include "core.h"
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Renderer.h"

#include <entity/Material.h>
#include <entity/Block.h>

void Renderer::Draw(const class Block* block, const glm::vec3& position) const
{
	block->m_VertexArray.Bind();
	block->m_IndexBuffer.Bind();
	block->m_Material->m_Shader.Bind();
	block->m_Material->m_Shader.SetUniform("u_Model", glm::translate(glm::mat4(1.0f), position));
	glDrawElements(GL_TRIANGLES, block->m_IndexBuffer.GetCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::Clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
