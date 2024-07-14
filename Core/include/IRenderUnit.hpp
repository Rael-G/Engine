#pragma once

class IRenderUnit {
public:
    virtual ~IRenderUnit() = default;
    virtual void render() const = 0;
};
