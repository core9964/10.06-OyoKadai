#include "EnemyPool.h"

//==============================================================
// ‹ó‚¢‚Ä‚¢‚é“G‚ðŽæ“¾‚·‚é
//==============================================================
Enemy* EnemyPool::Acquire(const EnemyData& data)
{
    for (int i = 0; i < MAX_ENEMY; i++)
    {
        if (!enemies[i].IsActive())
        {
            enemies[i].Initialize(data);
            return &enemies[i];
        }
    }

    // ‹ó‚«‚ª‚È‚¯‚ê‚ÎŽæ“¾Ž¸”s
    return nullptr;
}

//==============================================================
// “G‚ðƒv[ƒ‹‚É–ß‚·
//==============================================================
void EnemyPool::Release(Enemy* enemy)
{
    if (enemy != nullptr)
    {
        enemy->Release();
    }
}
