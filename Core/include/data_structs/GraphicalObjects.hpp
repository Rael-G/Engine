#pragma once

#include <GraphicalObject.hpp>
#include <string>
#include <map>

class GraphicalObjects {
private:
    static std::map<std::string, GraphicalObject*>  m_graphicalObjects;

public:
    static void add(const std::string& id, GraphicalObject* obj);

    static void remove(const std::string& id);

    static void render();
};