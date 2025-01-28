//
//  engine.cpp
//  Engine
//
//  Created by Hayden Carr on 27/01/2025.
//

#include "engine.hpp"
#include "window/window_init.hpp"
#include "glew/glew_init.hpp"
#include "check_input.hpp"
#include "shaders/create_shader_program.hpp"

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

void Engine::run(){
    init();
    
    mainLoop();
    
    cleanup();
}

void Engine::init(){
    window = window_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Engine");
    glew_init();
}

void Engine::mainLoop(){
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    
    // copy our vertices array in a buffer for OpenGL to use
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    // then set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    float r = 0.2f;
    float g = 0.3f;
    float b = 0.3f;
    while (!glfwWindowShouldClose(window)) {
        // input
        check_input(window);
        
        // render
        glClearColor(r, g, b, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // use our shader program when we want to render an object
        create_shader_program();
        glBindVertexArray(VAO);
        // triangle
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        // swap buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Engine::cleanup(){
    glfwTerminate();
}
