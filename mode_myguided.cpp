#include "Copter.h"
#include "mode_myguided.h"
#include <AP_HAL/AP_HAL.h>

bool ModeMyGuided::init(bool ignore_checks)
{
    step = 0;
    step_start_ms = AP_HAL::millis();
    return ModeGuided::init(ignore_checks);
}

void ModeMyGuided::run()
{
    // takeoff sürerken sadece base çalışsın
    if (submode() == SubMode::TakeOff || is_taking_off()) {
        ModeGuided::run();
        return;
    }

    if (!started_after_takeoff) {
        step_start_ms = AP_HAL::millis();
        started_after_takeoff = true;
    }

    const uint32_t now_ms = AP_HAL::millis();
    const float elapsed_s = (now_ms - step_start_ms) * 0.001f;

    Vector3f vel_ned_ms{ 0.0f, 0.0f, 0.0f };

    if (step == 0) {
        vel_ned_ms.x = 3.0f;
        set_vel_NED_ms(vel_ned_ms, false, 0.0f, false, 0.0f, false, true);

        if (elapsed_s >= 3.0f) { step = 1; step_start_ms = now_ms; }
        ModeGuided::run();
        return;
    }

    if (step == 1) {
        const float yaw_rate = radians(45.0f);
        set_vel_NED_ms(vel_ned_ms, false, 0.0f, true, yaw_rate, false, true);

        if (elapsed_s >= 2.0f) { step = 2; step_start_ms = now_ms; }
        ModeGuided::run();
        return;
    }

    if (step == 2) {
        vel_ned_ms.x = 1.0f;
        set_vel_NED_ms(vel_ned_ms, false, 0.0f, false, 0.0f, false, true);

        if (elapsed_s >= 3.0f) { step = 3; step_start_ms = now_ms; }
        ModeGuided::run();
        return;
    }

    hold_position();
    ModeGuided::run();
}


