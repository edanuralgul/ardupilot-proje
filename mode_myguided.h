#pragma once

#include "mode_guided.h"

class ModeMyGuided : public ModeGuided
{
public:
    bool init(bool ignore_checks) override;
    void run() override;

private:
    int adim = 0;
    float zamanlayici = 0;
};
