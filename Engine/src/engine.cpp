//
//  engine.cpp
//  Engine
//
//  Created by Hayden Carr on 27/01/2025.
//

#include "engine.hpp"
#include "window/window_init.hpp"
#include "glew/glew_init.hpp"

void Engine::run(){
    init();
    
    mainLoop();
    
    cleanup();
}

void Engine::init(){
    window_init();
    glew_init();
}

void Engine::mainLoop(){
    
}

void Engine::cleanup(){
    
}
