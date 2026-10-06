#pragma once

#include "Enemy.h"

//==============================================================
// オブジェクトプール
//==============================================================
class EnemyPool
{
private:
    static const int MAX_ENEMY = 3;

    Enemy enemies[MAX_ENEMY];

public:
    // 空いている敵を取得する
    Enemy* Acquire(const EnemyData& data);

    // 敵をプールに戻す
    void Release(Enemy* enemy);
};
