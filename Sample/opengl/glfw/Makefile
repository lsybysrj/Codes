glfwtest:glfwtest.o
	clang++  -oglfwtest glfwtest.o -framework OpenGL -L/usr/local/lib -lglfw3
glfwtest.o:glfwtest.cpp
	clang++ -g -c -I/usr/local/include glfwtest.cpp
clean:
	-rm glfwtest glfwtest.o
