#pragma once

#include "Player.h"
#include "EnemyFactory.h"

//==============================================================
// ゲームの状態
//==============================================================
enum class GameState
{
    TITLE,
    GAME,
    CLEAR,
    GAMEOVER,
    EXIT
};

//==============================================================
// ゲーム管理クラス
//==============================================================
class GameManager
{
private:
    // シングルトン用のコンストラクタ
    GameManager();

    // コピー禁止
    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;

    // ゲームの状態
    GameState currentState;

    // プレイヤー
    Player player;

    // 敵の管理
    EnemyPool enemyPool;
    EnemyFactory enemyFactory;

    // 現在戦っている敵
    Enemy* currentEnemy;

    // 次に生成する敵のID（0..ENEMY_DATA_SIZE-1）
    int nextEnemyId;

    // 最後に倒した敵のID（照会用）
    int lastDefeatedEnemyId;

    // 各画面の処理
    void Update();
    void UpdateTitle();
    void UpdateGame();
    void UpdateClear();
    void UpdateGameOver();

public:
    // インスタンスを取得する
    static GameManager& Instance();

    // ゲームを開始する
    void Run();
};