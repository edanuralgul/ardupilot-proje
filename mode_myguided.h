#pragma once

// Görev 2.3 — Örnek Flight Mode Sınıfı

class ModeMyGuided {
public:
    bool init();   // mode başlatma
    void run();    // sürekli çalışan kontrol fonksiyonu

private:
    int step;      // davranış aşaması
    float timer;   // zaman sayacı
};
