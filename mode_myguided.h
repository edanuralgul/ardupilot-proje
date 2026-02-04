#pragma once

// Görev 2.3 — Yeni Flight Mode
// Guided mantığında örnek mode sınıfı

class ModeMyGuided {
public:
    bool init();
    void run();

private:
    int step;      // davranış adımı
    float timer;   // süre sayacı
};
