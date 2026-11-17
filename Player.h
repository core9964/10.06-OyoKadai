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

    int def;// 防御力

public:
    // コンストラクタ
    Player();

    // 敵を攻撃する
    void AttackEnemy(Enemy* enemy);
    //連続攻撃
    void ApplyHit(Enemy* enemy,int atk_count);

    // ダメージを受ける
    void Damage(int damage);
    void Damage(int damage, int def);
    //連続ダメージ
    void ApplyDamage(int damage, int def, int damage_count);

    // 回復
    void Heal(int amount);

    // 生存確認
    bool IsAlive() const;

    // HP取得
    int GetHP() const;

    int GetDef() const;
};