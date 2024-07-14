#pragma once

#include <RenderUnit.hpp>
#include <string>
#include <unordered_map>
#include <memory>
#include <IRenderUnit.hpp>

class RenderMap {
private:
    static std::unordered_map<std::string, std::unique_ptr<IRenderUnit>> m_renderMap;

public:
    static void add(const std::string& id, std::unique_ptr<IRenderUnit> unit);

    static void remove(const std::string& id);

    template<typename TData>
    static void update(const std::string& id, TData data);

    static void render(const std::string& id);
};

template<typename TData>
void RenderMap::update(const std::string& id, TData data) {
    auto it = m_renderMap.find(id);
    if (it != m_renderMap.end()) {
        RenderUnit<TData>* unit = dynamic_cast<RenderUnit<TData>*>(it->second.get());
        if (unit) {
            unit->set_data(data);
        }
    }
}
