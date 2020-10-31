#pragma once

class Block
{
public:
	Block(const Material* material);
	void OnRender(const Renderer& renderer, const glm::vec3& position, const glm::vec3& color) const;
	void OnUpdate();
private:
	VertexBuffer m_VertexBuffer;
	VertexArray m_VertexArray;
	IndexBuffer m_IndexBuffer;
	const Material* m_Material;
	friend class Renderer;
};
