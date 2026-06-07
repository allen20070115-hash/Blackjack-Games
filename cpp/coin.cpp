#include "coin.h"

Coin::Coin() { value = 0; }

Coin::Coin(int v) { value = v; }

int Coin::getValue() const { return value; }

void Coin::setValue(int v) { value = v; }
