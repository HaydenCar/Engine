//
//  renderer.hpp
//  Engine
//
//  Created by Hayden Carr on 31/01/2025.
//
#ifndef renderer_hpp
#define renderer_hpp
#define GL_SILENCE_DEPRECATION
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>
#include <string>

// Renderer class so easy to reuse
class Renderer {
public:
    Renderer();
    ~Renderer();

    void create_render_data();
    void render_frame();
    void loadData(const std::string& filename);
private:
    unsigned int VBO, VAO, EBO;
};

#endif /* renderer_hpp */
