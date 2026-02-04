#pragma once

#include "mode_guided.h"

class ModeMyGuided : public ModeGuided
{
public:
    bool init(bool ignore_checks) override;
    void run() override;

private:
    int step = 0;
    float timer = 0;
};
