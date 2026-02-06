#pragma once

#include "mode.h"

class ModeMyGuided : public ModeGuided {
public:
    using ModeGuided::ModeGuided;

    bool init(bool ignore_checks) override;
    void run() override;

protected:
    const char* name() const override { return "MyGuided"; }
    const char* name4() const override { return "MYGD"; }

private:
    uint8_t step = 0;
    uint32_t step_start_ms = 0;
    bool started_after_takeoff = false;

    float target_yaw_rad = 0.0f;
};

