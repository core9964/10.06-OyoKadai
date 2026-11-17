#include <iostream>
#include "Player.h"

using namespace std;

//==============================================================
// コンストラクタ
//==============================================================
Player::Player()
    : hp(MAX_HP),
    attack(20),
    def(3)
{
}

//==============================================================
// 敵を攻撃する
//==============================================================
void Player::AttackEnemy(Enemy* enemy)
{
    if (enemy == nullptr || !enemy->IsAlive())
    {
        return;
    }

    cout << "勇者の攻撃！" << endl;
    cout << enemy->GetName()
        << "に"
        << attack - enemy->GetDef()
        << "ダメージ！"
        << endl;

    enemy->Damage(attack,enemy->GetDef());
}

//連続
void Player::ApplyHit(Enemy* enemy,int atk_count)
{
    if (enemy == nullptr || !enemy->IsAlive())
    {
        return;
    }
    int atk = 0;
    for (int i = 0; i < atk_count; i++)
    {
        atk += attack - enemy->GetDef();
    }
    cout << "勇者の連続攻撃！" << endl;
    cout << enemy->GetName()
        << "に"
        << atk
        << "ダメージ！"
        << endl;
    enemy->Damage(atk);
}

//==============================================================
// ダメージを受ける
//==============================================================
void Player::Damage(int damage)
{
    if (damage < 0)
    {
        return;
    }

    hp -= damage;

    if (hp < 0)
    {
        hp = 0;
    }

    cout << "勇者は"
        << damage
        << "ダメージ受けた！"
        << endl;
}
//防御あり
void Player::Damage(int damage, int def)
{
    if (damage < 0||damage>100)
    {
        return;
    }
    if (def < 0 || def>100)
    {
        return;
    }
    // 防御力を考慮してダメージを計算
    int actualDamage = damage - def;
    if (actualDamage < 0)
    {
        actualDamage = 0; // ダメージが負になる場合は0にする
    }
    hp -= actualDamage;
    if (hp < 0)
    {
        hp = 0;
    }
    cout << "勇者は"
        << actualDamage
        << "ダメージ受けた！"
        << endl;
}
//連続ダメージ
void Player::ApplyDamage(int damage, int def, int damage_count)
{
    //ダメージを回数分足してから反映する
}

//==============================================================
// 回復
//==============================================================
void Player::Heal(int amount)
{
    if (amount <= 0)
    {
        return;
    }

    hp += amount;
    if (hp > MAX_HP)
    {
        hp = MAX_HP;
    }

    cout << "勇者は"
        << amount
        << "回復した！ 現在 HP : "
        << hp
        << endl;
}

//==============================================================
// 生存確認
//==============================================================
bool Player::IsAlive() const
{
    return hp > 0;
}

//==============================================================
// HP取得
//==============================================================
int Player::GetHP() const
{
    return hp;
}

//
int Player::GetDef() const
{
    return def;
}