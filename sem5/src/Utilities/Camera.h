#pragma once
#include "GLM/glm/glm.hpp"
#include "GLm/glm/gtc/matrix_transform.hpp"
enum CameraMovement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};



class Camera
{
public:
	float Zoom, yaw, pitch;
	glm::vec3 cameraPos, cameraFront, cameraUp;

	Camera(glm::vec3 pos) {
		cameraPos = pos;
		cameraFront = glm::vec3(0.0, 0.0, -1.0f);
		cameraUp = glm::vec3(0.0, 1.0, 0.0f);
		Zoom = 45.0f;
		yaw = -90.0f;
		pitch = 0.0f;
	}

	glm::mat4 GetViewMatrix() {
		return glm::lookAt(cameraPos, cameraFront + cameraPos, cameraUp);
	}

	void KeyboardProcess(CameraMovement direction, float deltime)
	{
		const float cameraSpeed = deltime * 8;
		if(direction==FORWARD) cameraPos += cameraFront * cameraSpeed;

		if (direction == BACKWARD) cameraPos -= cameraFront * cameraSpeed;

		if (direction == LEFT) cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp))* cameraSpeed;

		if (direction == RIGHT) cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp))*cameraSpeed;
	}
	void MouseProcess(float xoffset,float yoffset)
	{
		float sensitivity = 0.1f; // change this value to your liking
		xoffset *= sensitivity;
		yoffset *= sensitivity;

		yaw += xoffset;
		pitch += yoffset;

		// make sure that when pitch is out of bounds, screen doesn't get flipped
		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;

		glm::vec3 front;
		front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		front.y = sin(glm::radians(pitch));
		front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		cameraFront = glm::normalize(front);
	}
	void MouseScrollProcess(float yoffset)
	{
		if (Zoom >= 1.0f && Zoom <= 45.0f)
			Zoom -= yoffset;
		if (Zoom <= 1.0f)
			Zoom = 1.0f;
		if (Zoom >= 45.0f)
			Zoom = 45.0f;
	}



};