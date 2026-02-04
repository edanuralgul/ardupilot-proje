#include "mode_myguided.h"
#include <iostream>

// Mode başlatma fonksiyonu
bool ModeMyGuided::init()
{
    step = 0;
    timer = 0;

    std::cout << "ModeMyGuided baslatildi" << std::endl;
    return true;
}

// Her kontrol döngüsünde çalışan fonksiyon
void ModeMyGuided::run()
{
    // zaman artışı 
    timer += 0.1;

    float vx = 0;        // ileri hız
    float yaw_rate = 0;  // dönüş hızı

    

    // Adım 0 → ileri hareket
    if (step == 0) {
        vx = 1.0;

        if (timer > 5) {
            step = 1;
            timer = 0;
        }
    }

    // Adım 1 → durma
    else if (step == 1) {
        vx = 0;

        if (timer > 2) {
            step = 2;
            timer = 0;
        }
    }

    // Adım 2 → sağa dönüş
    else if (step == 2) {
        yaw_rate = 30;

        if (timer > 3) {
            step = 0;
            timer = 0;
        }
    }

    // Referans çıktısını yazdır
    std::cout << "Adim: " << step
              << " Hiz: " << vx
              << " Donus: " << yaw_rate
              << std::endl;
}
