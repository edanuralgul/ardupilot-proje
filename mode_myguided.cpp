#include "mode_myguided.h"
#include <iostream>

bool ModeMyGuided::init(bool ignore_checks)
{
    if (!ModeGuided::init(ignore_checks)) {
        return false;
    }

    adim = 0;
    zamanlayici = 0;
    std::cout << "Ozel Mod Aktif" << std::endl;
    return true;
}

void ModeMyGuided::run()
{
    ModeGuided::run();
    zamanlayici += 0.02f; 

    float ileri_hiz = 0;  
    float donus_hizi = 0; 

    if (adim == 0) {         // İlerleme adımı
        ileri_hiz = 1.0f;
        if (zamanlayici > 5) { adim = 1; zamanlayici = 0; }
    }
    else if (adim == 1) {    // Durma adımı
        ileri_hiz = 0;
        if (zamanlayici > 2) { adim = 2; zamanlayici = 0; }
    }
    else if (adim == 2) {    // Dönme adımı
        donus_hizi = 30.0f;
        if (zamanlayici > 3) { adim = 0; zamanlayici = 0; }
    }

    
    Vector3f hedef_hiz(ileri_hiz * 100.0f, 0, 0); 
    set_velocity_target_cms(hedef_hiz);
    set_yaw_rate_target(donus_hizi * 100.0f);

    
    if (int(zamanlayici * 10) % 10 == 0) {
        std::cout << "Adim:" << adim << " Hiz:" << ileri_hiz << " Donus:" << donus_hizi << std::endl;
    }
}
