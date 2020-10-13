#include <pch.h>
#include <core.h>
#include "core.h"
#include "Shader.h"

static const Shader* binded = nullptr;

static void CompileShader(uint32_t program, const std::string& source, uint32_t type)
{
	const char* csrc = source.c_str();
	uint32_t shader = glCreateShader(type);
	glShaderSource(shader, 1, &csrc, nullptr);
	glCompileShader(shader);
	glAttachShader(program, shader);
	glDeleteShader(shader);
}

Shader::Shader(const std::string& file) : m_File(file)
{
	enum class ShaderType {
		None = -1,
		Vertex = 0,
		Fragment = 1
	};

	std::ifstream is(m_File);
	std::string line;
	std::string shaders[2];
	ShaderType type = ShaderType::None;

	while (getline(is, line)) {
		if (line[0] == '#') {
			const char* str = line.c_str() + 1;
			if (!std::strncmp(str, "shader", 6)) {
				str += 6;
				while (isspace(*str)) str++;
				if (!std::strncmp(str, "vertex", 6))
					type = ShaderType::Vertex;
				else if (!std::strncmp(str, "fragment", 8))
					type = ShaderType::Fragment;
				else type = ShaderType::None;
				continue;
			}
		}
		if ((int)type >= 0)
			shaders[(int)type] += line + "\n";
	}
	
	m_RendererID = glCreateProgram();
	CompileShader(m_RendererID, shaders[0], GL_VERTEX_SHADER);
	CompileShader(m_RendererID, shaders[1], GL_FRAGMENT_SHADER);
	glLinkProgram(m_RendererID);
	glValidateProgram(m_RendererID);
}

Shader::~Shader()
{
	glDeleteProgram(m_RendererID);
}

void Shader::Bind() const
{
	if (!IsBinded()) {
		glUseProgram(m_RendererID);
		binded = this;
	}
}

void Shader::Unbind() const
{
#ifdef _DEBUG
	if (IsBinded()) {
		glUseProgram(0);
		binded = nullptr;
	}
#endif
}

bool Shader::IsBinded() const
{
	return binded == this;
}

int32_t Shader::GetUniformLocation(const std::string& name) const
{
	const auto& finded = m_UniformCache.find(name);
	if (finded != m_UniformCache.end())
		return finded->second;

	int32_t location = glGetUniformLocation(m_RendererID, name.c_str());
	if (location < 0)
		LOG_WARNING("Trying to access unexisting Uniform '%s' (in '%s')\n", name.c_str(), m_File.c_str());
	m_UniformCache[name] = location;
	return location;
}

template<>
void Shader::SetLocatedUniform(int32_t location, const glm::mat4& value)
{
	glUniformMatrix4fv(location, 1, GL_FALSE, &value[0][0]);
}

template<>
void Shader::SetLocatedUniform(int32_t location, const glm::vec3& value)
{
	glUniform3fv(location, 1, &value[0]);
}
