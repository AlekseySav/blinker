#pragma once

class Material
{
public:
	Material(Shader& sh) : m_Shader(sh) { }
	virtual void OnUpdate() { }
protected:
	Shader& m_Shader;
	friend class Renderer;
	friend class Block;
};

class BlockMaterial : public Material
{
public:
	BlockMaterial(Shader& sh) : Material(sh), m_Color(0.2f, 0.3f, 0.8f), m_ColorAdd(0.003f, 0.002f, -0.001f)
	{
		m_Shader.SetUniform("u_Color", m_Color);
	}

	virtual void OnUpdate() override
	{
	/*	for (int i = 0; i < 3; i++) {
			if (m_Color[i] > 0.6f && m_ColorAdd[i] > 0 || m_Color[i] < 0.2f && m_ColorAdd[i] < 0)
				m_ColorAdd[i] = -m_ColorAdd[i];
			m_Color[i] += m_ColorAdd[i];
		}
		m_Shader.SetUniform("u_Color", m_Color);*/
	}
private:
	glm::vec3 m_Color;
	glm::vec3 m_ColorAdd;
};
