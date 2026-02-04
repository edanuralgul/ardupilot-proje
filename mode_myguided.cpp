#include "mode_myguided.h"
#include <iostream>

// Mode başlatılırken bir kez çalışır
bool ModeMyGuided::init(bool ignore_checks)
{
    // Guided init çağır
    if (!ModeGuided::init(ignore_checks)) {
        return false;
    }

    step = 0;
    timer = 0;

    std::cout << "ModeMyGuided basladi" << std::endl;
    return true;
}


// Scheduler tarafından sürekli çağrılır
void ModeMyGuided::run()
{
    ModeGuided::run();   // temel guided davranış

    timer += 0.1;

    float vx = 0;        // ileri hız
    float yaw_rate = 0;  // dönüş hızı


    // ileri git
    if (step == 0) {
        vx = 1.0;
        if (timer > 5) {
            step = 1;
            timer = 0;
        }
    }

    // dur
    else if (step == 1) {
        vx = 0;
        if (timer > 2) {
            step = 2;
            timer = 0;
        }
    }

    // dön
    else if (step == 2) {
        yaw_rate = 30;
        if (timer > 3) {
            step = 0;
            timer = 0;
        }
    }

    // debug çıktı
    std::cout << "step:" << step
              << " vx:" << vx
              << " yaw:" << yaw_rate
              << std::endl;
}
