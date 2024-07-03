#include <data_structs/GraphicalObjects.hpp>

std::map<std::string, GraphicalObject*> GraphicalObjects::m_graphicalObjects;

void GraphicalObjects::add(const std::string& id, GraphicalObject* obj) {
    m_graphicalObjects.emplace(id, std::move(obj));
    obj->start();
}

void GraphicalObjects::remove(const std::string& id) {
    auto it = m_graphicalObjects.find(id);
    if (it != m_graphicalObjects.end()) {
        it->second->free();
        m_graphicalObjects.erase(it);
    }
}

void GraphicalObjects::render() {
    for (auto& pair : m_graphicalObjects) {
        pair.second->render();
    }
}