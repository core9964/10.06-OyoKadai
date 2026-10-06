#pragma once

#include <string>
#include "EnemyData.h"

//==============================================================
// 敵クラス
//==============================================================
class Enemy
{
private:
    int id;
    std::string name;
    int hp;
    int attack;
    bool active;

public:
    // コンストラクタ
    Enemy();

    // 敵のデータを設定する
    void Initialize(const EnemyData& data);

    // ダメージ処理
    void Damage(int damage);

    // 生存確認
    bool IsAlive() const;

    // 使用中かどうか
    bool IsActive() const;

    // 使用終了
    void Release();

    // 情報取得
    int GetID() const;
    const std::string& GetName() const; // コピーを避けるため参照で返すように変更
    int GetHP() const;
    int GetAttack() const;
};
