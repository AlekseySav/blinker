#pragma once

struct Camera
{
	Camera(const glm::vec3& pos, float angle, const glm::vec3& vangle) 
		: ViewMatrix(glm::translate(glm::mat4(1.0f), pos)
			* glm::rotate(glm::mat4(1.0f), glm::radians(angle), vangle)), Position(pos), Angle(angle)
	{
		ViewMatrix = glm::inverse(ViewMatrix);
	}

	void Move(const glm::vec3& delta)
	{
		Position += delta;
		ViewMatrix = glm::translate(ViewMatrix, -delta);
	}

	glm::mat4 ViewMatrix;
	glm::mat4 ProjectionMatrix;
	float Angle;
	glm::vec3 Position;
};
