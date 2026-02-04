#pragma once

#include "mode_guided.h"

// Guided'dan türetilen özel mode
class ModeMyGuided : public ModeGuided
{
public:
    bool init(bool ignore_checks) override; // mode başlangıcı
    void run() override;                    // ana döngü fonksiyonu

private:
    int step = 0;     // davranış adımı
    float timer = 0;  // zaman sayacı
};
