#pragma once

class Shader
{
public:
	Shader() = default;
	Shader(const std::string& file);
	~Shader();
	void Bind() const;
	void Unbind() const;
	bool IsBinded() const;

	template<typename T>
	void SetUniform(const std::string& name, const T& value)
	{
		Bind();
		int32_t location = GetUniformLocation(name);
		if (location >= 0)
			SetLocatedUniform(location, value);
	}
private:
	template<typename T>
	void SetLocatedUniform(int32_t location, const T& value)
	{
		static_assert(false);
	}
	int32_t GetUniformLocation(const std::string& name) const;
private:
	mutable std::unordered_map<std::string, uint32_t> m_UniformCache;
	uint32_t m_RendererID;
	std::string m_File;
};

template<>
void Shader::SetLocatedUniform(int32_t location, const glm::mat4& value);
template<>
void Shader::SetLocatedUniform(int32_t location, const glm::vec3& value);
