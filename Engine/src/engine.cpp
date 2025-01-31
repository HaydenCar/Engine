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
#include "renderer/renderer.hpp"

Renderer renderer;

void Engine::run(){
    init();
    
    mainLoop();
    
    cleanup();
}

void Engine::init(){
    window = window_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Engine");
    glew_init();
    renderer.create_render_data();
}

void Engine::mainLoop(){
    while (!glfwWindowShouldClose(window)) {
        // input
        check_input(window);
        
        //render
        renderer.render_frame();
        
        // swap buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Engine::cleanup(){
    glfwTerminate();
}
