//
//  window_init.hpp
//  Engine
//
//  Created by Hayden Carr on 27/01/2025.
//

#ifndef window_init_hpp
#define window_init_hpp
#include <GLFW/glfw3.h>

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void window_init();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

#endif /* window_init_hpp */
