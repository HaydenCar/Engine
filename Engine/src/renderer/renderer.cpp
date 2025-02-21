//
//  renderer.cpp
//  Engine
//
//  Created by Hayden Carr on 31/01/2025.
//
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "renderer.hpp"
#include "../shaders/shader.hpp"
#include <filesystem>

// Constructor
Renderer::Renderer() {
    VBO = 0;
    VAO = 0;
    EBO = 0;
}

// Destructor
Renderer::~Renderer() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

// Method to create render data
void Renderer::create_render_data() {
    float vertices[] = {
            // positions         // colors
             0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
             0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top
    };
    
    float texCoords[] = {
        0.0f, 0.0f,  // lower-left corner
        1.0f, 0.0f,  // lower-right corner
        0.5f, 1.0f   // top-center corner
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // pos attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // wireframe mode
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;

}

// Method to render a frame
void Renderer::render_frame() {
    Shader ourShader("src/shaders/shader.vert", "src/shaders/shader.frag");
    static float r = 0.2f, g = 0.3f, b = 0.3f;

    glClearColor(r, g, b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Use the shader program when rendering
    ourShader.use();

    // render the triangle
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glBindVertexArray(0);
}

