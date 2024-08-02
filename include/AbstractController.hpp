#pragma once

class AbstractController {
public:
    virtual void handleInput(int keyCode) = 0;
    virtual ~AbstractController() = default;
};
