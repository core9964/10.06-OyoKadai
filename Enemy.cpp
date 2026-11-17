#include "Enemy.h"

//==============================================================
// コンストラクタ
//==============================================================
Enemy::Enemy()
    : id(-1),
    name(""),
    hp(0),
    attack(0),
    active(false)
{
}

//==============================================================
// 敵のデータを設定する
//==============================================================
void Enemy::Initialize(const EnemyData& data)
{
    id = data.id;
    name = data.name;
    hp = data.hp;
    attack = data.attack;
    def = data.def;
    active = true;
}

//==============================================================
// ダメージ処理
//==============================================================
void Enemy::Damage(int damage)
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

    if (hp == 0)
    {
        active = false;
    }
}
// 防御あり
void Enemy::Damage(int damage, int def)
{
    if (damage < 0 || damage > 100)
    {
        return;
    }
    if (def < 0 || def > 100)
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
}

//==============================================================
// 生存確認
//==============================================================
bool Enemy::IsAlive() const
{
    return hp > 0;
}

//==============================================================
// 使用中かどうか
//==============================================================
bool Enemy::IsActive() const
{
    return active;
}

//==============================================================
// 使用終了
//==============================================================
void Enemy::Release()
{
    active = false;
}

//==============================================================
// 情報取得
//==============================================================
int Enemy::GetID() const
{
    return id;
}

const std::string& Enemy::GetName() const // 参照で返す（コピーを避ける）
{
    return name;
}

int Enemy::GetHP() const
{
    return hp;
}

int Enemy::GetAttack() const
{
    return attack;
}

int Enemy::GetDef() const
{
    return def;
}
