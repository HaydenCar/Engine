//
//  create_shader_program.cpp
//  Engine
//
//  Created by Hayden Carr on 28/01/2025.
//

#include "create_shader_program.hpp"
#include "vert_shader.hpp"
#include "frag_shader.hpp"

void create_shader_program(){
    unsigned int shaderProgram = glCreateProgram();
    uint32_t vert = create_vert_shader();
    uint32_t frag = create_frag_shader();
    
    glAttachShader(shaderProgram, vert);
    glAttachShader(shaderProgram, frag);
    glLinkProgram(shaderProgram);
    
    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    
    glUseProgram(shaderProgram);
    glDeleteShader(vert);
    glDeleteShader(frag);
}
