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
    float r = 0.2f;
    float g = 0.3f;
    float b = 0.3f;
    while (!glfwWindowShouldClose(window)) {
        // input
        check_input(window);
        
        // render
        glClearColor(r, g, b, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // swap buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Engine::cleanup(){
    glfwTerminate();
}
