#pragma once

#include "Enemy.h"

//==============================================================
// プレイヤークラス
//==============================================================
class Player
{
private:
    static const int MAX_HP = 100;
    int hp;
    int attack;

public:
    // コンストラクタ
    Player();

    // 敵を攻撃する
    void AttackEnemy(Enemy* enemy);

    // ダメージを受ける
    void Damage(int damage);

    // 回復
    void Heal(int amount);

    // 生存確認
    bool IsAlive() const;

    // HP取得
    int GetHP() const;
};