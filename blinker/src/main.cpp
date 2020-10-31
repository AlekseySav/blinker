#include <pch.h>
#include <core.h>
#include <platform/opengl/core.h>
#include <renderer/Renderer.h>

#include <entity/Block.h>

int main(int argc, char* argv[])
{
	if (!glfwInit()) LOG_ERROR("GLFW Init failed\n");

	Window window("Blinker", 1280, 960);
	if (glewInit() != GLEW_OK) LOG_ERROR("GLEW Init failed\n");
	LogInitialize();
	Keyboard::Initialize(window);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	Camera camera(glm::vec3(0.0f, 120.0f, 100.0f), -50.0f, glm::vec3(1, 0, 0));
	camera.ProjectionMatrix = glm::perspective(glm::radians(60.0f), 4.0f / 3.0f, 0.1f, 1000.0f);

	Renderer renderer;
	Shader shader("res/shaders/1.shader");
	shader.SetUniform("u_View", camera.ViewMatrix);
	shader.SetUniform("u_Projection", camera.ProjectionMatrix);
	shader.SetUniform("u_LightPosition", glm::vec3(0.0f, 50.0f, 30.0f));
	shader.SetUniform("u_LightColor", glm::vec3(0.5f, 0.5f, 0.5f));

	BlockMaterial material(shader);
	Block block(&material);

	Timer tm;
	Timer updates;
	uint32_t ups = 0, fps = 0;

#define UPS		60
#define UPD_MS	1000 / UPS

	float gfactor = 0.1f, gadd = 0.003f;

	while (!window.IsClosed()) {
		if (updates.SynchronizedPassed(UPD_MS)) {
			Keyboard::OnUpdate();
			updates += UPD_MS;
			ups++;

			float z = 0.0f;
			float x = 0.0f;
			if (Keyboard::Left()) x--;
			if (Keyboard::Right()) x++;
			if (Keyboard::Up()) z--;
			if (Keyboard::Down()) z++;
			
			camera.Move(glm::vec3(x, 0, z));
			shader.SetUniform("u_View", camera.ViewMatrix);
			shader.SetUniform("u_LightPosition", glm::vec3(camera.Position.x, 60.0f, camera.Position.z - 50.0f));
			gfactor += gadd;
			if (gfactor >= 0.4f || gfactor <= 0.1f)
				gadd = -gadd;

			block.OnUpdate();
			material.OnUpdate();
		}
		
		renderer.Clear();

		float zz = (float)((int)camera.Position.z / 120) * 120;
		float xx = (float)((int)camera.Position.x / 120) * 120;
		for (float z = zz - 450.0f; z < zz + 200.0f; z += 40.0f)
			for (float x = xx - 400.0f; x < xx + 400.0f; x += 40.0f) {
				float rfactor = x / 800.0f + 0.5f - (gfactor / 2);
				float bfactor = 1.0f - gfactor - rfactor;
				glm::vec3 color = glm::vec3(rfactor, gfactor, bfactor);
				block.OnRender(renderer, glm::vec3(x, 0.0f, z), color);
			}
		window.SwapBuffers();

		fps++;
		if (tm.SynchronizedPassed(1000)) {
			LOG("%d fps, %d ups\r", fps, ups);
			tm += 1000;
			fps = 0;
			ups = 0;
		}
	}
	
	Terminate();
	return 0;
}
