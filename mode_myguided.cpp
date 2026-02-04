#include "mode_myguided.h"
#include <iostream>

// Mode başlatma fonksiyonu
// Mode aktif olduğunda bir kez çağrılır
bool ModeMyGuided::init()
{
    step = 0;
    timer = 0;

    std::cout << "ModeMyGuided baslatildi" << std::endl;
    return true;
}


// Ana kontrol fonksiyonu
// Mode aktif olduğu sürece sürekli çağrılır
void ModeMyGuided::run()
{
    // Her çağrıda zamanı artır (100 ms)
    timer += 0.1;

    float vx = 0;        // ileri hız referansı
    float yaw_rate = 0;  // dönüş hız referansı


    // -------- DURUMLAR --------

    // ADIM 0 → ileri git
    if (step == 0)
    {
        vx = 1.0;

        if (timer > 5) {
            step = 1;
            timer = 0;
        }
    }

    // ADIM 1 → dur
    else if (step == 1)
    {
        vx = 0;

        if (timer > 2) {
            step = 2;
            timer = 0;
        }
    }

    // ADIM 2 → sağa dön
    else if (step == 2)
    {
        yaw_rate = 30;

        if (timer > 3) {
            step = 0;
            timer = 0;
        }
    }


    // Debug çıktısı
    std::cout << "Adim: " << step
              << " | Hiz: " << vx
              << " | Donus: " << yaw_rate
              << std::endl;
}
             
