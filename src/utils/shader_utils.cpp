#include "shader_utils.h"

Shader::Shader(const char *vertexPath, const char *fragmentPath)
{
    std::string vertexCode = this->readShader(vertexPath);
    std::string fragmentCode = this->readShader(fragmentPath);

    unsigned int vertexShader = this->compileShader(GL_VERTEX_SHADER, vertexCode.c_str());
    unsigned int fragmentShader = this->compileShader(GL_FRAGMENT_SHADER, fragmentCode.c_str());

    shaderProgramID = glCreateProgram();
    glAttachShader(shaderProgramID, vertexShader);
    glAttachShader(shaderProgramID, fragmentShader);
    glLinkProgram(shaderProgramID);

    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgramID, 512, NULL, infoLog);
        std::cerr << "ERROR: Shader program linking failed\n"
                  << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::Shader()
{
    shaderProgramID = glCreateProgram();
    glLinkProgram(shaderProgramID);

    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgramID, 512, NULL, infoLog);
        std::cerr << "ERROR: Shader program linking failed\n"
                  << infoLog << std::endl;
    }
}

std::string Shader::readShader(const char *filePath)
{
    std::ifstream shaderFile(filePath);
    if (!shaderFile.is_open())
    {
        std::cerr << "Failed to open shader file: " << filePath << std::endl;
        exit(-1);
    }

    std::stringstream shaderStream;
    shaderStream << shaderFile.rdbuf();
    shaderFile.close();
    return shaderStream.str();
}

unsigned int Shader::compileShader(unsigned int type, const char *source)
{
    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cerr << "ERROR: Failed to compile shader\n"
                  << infoLog << std::endl;
    }

    return shader;
}

void Shader::useShader()
{
    glUseProgram(shaderProgramID);
}