// GLEW
#define GLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW\glfw3.h>

#include <iostream>

//// Define the function's prototype
//typedef void(*GL_GENBUFFERS) (GLsizei, GLuint*);
//// Find the function and assign it to a function pointer
//GL_GENBUFFERS glGenBuffers = (GL_GENBUFFERS)wglGetProcAddress("glGenBuffers");
//// Function can now be called as normal
//GLuint buffer;
//glGenBuffers(1, &buffer);

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Start one", nullptr, nullptr);
	if (!window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	glfwSetKeyCallback(window, keyCallback);

	GLclampf red = 0.01f;
	GLclampf green = 0.002f;
	GLclampf blue = 0.003f;

	while (!glfwWindowShouldClose(window))
	{
		if (red > 0.9f)
			red = 0.0f;

		if (green > 1)
			green = 0.0f;

		if (blue > 1)
			blue = 0.0f;

		glfwPollEvents();
		glClearColor(red, green, blue, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);

		//red += 0.001f;
		green += 0.005f;
		//blue += 0.003f;
	}

	glfwTerminate();


    return 0;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}