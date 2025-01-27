#ifndef SHADER_H
#define SHADER_H

#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <sstream>

class Shader
{
public:
    Shader(const char *vertexPath, const char *fragmentPath);
    Shader();

    std::string readShader(const char *filePath);
    unsigned int compileShader(unsigned int type, const char *source);
    void useShader();

    unsigned int shaderProgramID;

private:
};

#endif