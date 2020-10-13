#pragma once

class Renderer
{
public:
	void Draw(const class Block* block, const glm::vec3& position) const;
	void Clear() const;
};
