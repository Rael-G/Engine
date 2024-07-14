#include <RenderMap.hpp>

std::unordered_map<std::string, std::unique_ptr<IRenderUnit>> RenderMap::m_renderMap;

void RenderMap::add(const std::string& id, std::unique_ptr<IRenderUnit> unit) {
    m_renderMap.emplace(id, std::move(unit));
}

void RenderMap::remove(const std::string& id) {
    auto it = m_renderMap.find(id);
    if (it != m_renderMap.end()) {
        m_renderMap.erase(it);
    }
}

void RenderMap::render(const std::string& id) {
    auto it = m_renderMap.find(id);
    if (it != m_renderMap.end()) {
        it->second->render();
    }
}