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
	int def;// 防御力
    bool active;

public:
    // コンストラクタ
    Enemy();

    // 敵のデータを設定する
    void Initialize(const EnemyData& data);

    // ダメージ処理
    void Damage(int damage);
	void Damage(int damage, int def); // 防御力を考慮したダメージ処理

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

	int GetDef() const; // 防御力を取得する関数
};
