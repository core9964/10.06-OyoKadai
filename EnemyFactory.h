#pragma once

#include "EnemyPool.h"

//==============================================================
// 敵生成クラス
//==============================================================
class EnemyFactory
{
private:
    EnemyPool& pool;

public:
    // コンストラクタ
    explicit EnemyFactory(EnemyPool& pool);

    // 敵を生成する
    Enemy* CreateEnemy(int id);
};
