#include "EnemyFactory.h"

//==============================================================
// コンストラクタ
//==============================================================
EnemyFactory::EnemyFactory(EnemyPool& pool)
    : pool(pool)
{
}

//==============================================================
// 敵を生成する
//==============================================================
Enemy* EnemyFactory::CreateEnemy(int id)
{
    // IDが範囲内か確認
    if (id < 0 || id >= ENEMY_DATA_SIZE)
    {
        return nullptr;
    }

    // データテーブルから敵の情報を取得
    const EnemyData& data = enemyTable[id];

    // プールから敵を取得して初期化
    return pool.Acquire(data);
}
