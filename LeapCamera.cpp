#include "stdafx.h"
#include <iostream>
// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// Other Libs
#include <SOIL/SOIL.h>

// Other includes
#include "Shader.h"
#include "Leap.h"

// header for main
#include "LeapCamera.h"


using namespace Leap;


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);


LeapCamera::LeapCamera(){



}

LeapCamera::~LeapCamera(){




}
void LeapCamera::run(){
		// Init GLFW
		glfwInit();
		// Set all the required options for GLFW
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		// Create a GLFWwindow object that we can use for GLFW's functions
		GLFWwindow* window = glfwCreateWindow(800, 640, "LeapCamera", nullptr, nullptr);
		glfwMakeContextCurrent(window);

		// Set the required callback functions
		glfwSetKeyCallback(window, key_callback);

		// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
		glewExperimental = GL_TRUE;
		// Initialize GLEW to setup the OpenGL Function pointers
		glewInit();

		// Game loop
		while (!glfwWindowShouldClose(window))
		{
			// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
			glfwPollEvents();

			// Render
			// Clear the colorbuffer
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			render();

			// Swap the screen buffers
			glfwSwapBuffers(window);
		}

		glfwTerminate();


}


void LeapCamera::render(){

	std::cout << "Render has been establed" << std::endl;

}

void LeapCamera::update(){




}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS){

	}
}