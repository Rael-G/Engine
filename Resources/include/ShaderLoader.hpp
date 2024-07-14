#pragma once

#include <fstream>
#include <iostream>

class ShaderLoader {
public:
    static Shader read(const std::string& filename) {
        std::ifstream file(filename);
        std::string content;
        std::string line;

        if (!file.is_open())
           std::cout << "Unable to open file: " + filename << std::endl;
        
        while (std::getline(file, line)) {
            content += line + "\n";
        }
        file.close();
        Shader shader{};
        shader.source = content;

        return shader;
    }
};