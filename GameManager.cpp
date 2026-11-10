#include <iostream>
#include "GameManager.h"
#include "EnemyData.h"

using namespace std;

//==============================================================
// コンストラクタ
//==============================================================
GameManager::GameManager()
    : currentState(GameState::TITLE),
    player(),
    enemyPool(),
    enemyFactory(enemyPool),
    currentEnemy(nullptr),
    nextEnemyId(0),
    lastDefeatedEnemyId(-1)
{
}

//==============================================================
// シングルトン
//==============================================================
GameManager& GameManager::Instance()
{
    static GameManager instance;
    return instance;
}

//==============================================================
// ゲームの実行
//==============================================================
void GameManager::Run()
{
    while (currentState != GameState::EXIT)
    {
        Update();
    }

    view.ShowExit();
}

//==============================================================
// 状態に応じて処理を切り替える（ステートマシン）
//==============================================================
void GameManager::Update()
{
    switch (currentState)
    {
    case GameState::TITLE:
        UpdateTitle();
        break;

    case GameState::GAME:
        UpdateGame();
        break;

    case GameState::CLEAR:
        UpdateClear();
        break;

    case GameState::GAMEOVER:
        UpdateGameOver();
        break;

    case GameState::EXIT:
        break;
    }
}

//==============================================================
// タイトル画面
//==============================================================
void GameManager::UpdateTitle()
{
    // タイトル画面を表示
    view.ShowTitle();

    // 入力を受け取る
    int input = view.GetTitleInput();

    if (input == 1)
    {
        // 新しくゲームを始めるときは初期化する
        player = Player();
        currentEnemy = nullptr;
        nextEnemyId = 0;          // スライム(0)から開始
        lastDefeatedEnemyId = -1;
        currentState = GameState::GAME;
    }
    else if (input == 2)
    {
        currentState = GameState::EXIT;
    }
}

//==============================================================
// ゲーム画面
//==============================================================
void GameManager::UpdateGame()
{
    // 敵がいなければ次の敵を生成（順番に）
    if (currentEnemy == nullptr)
    {
        currentEnemy = enemyFactory.CreateEnemy(nextEnemyId);
        // 次回は次のID
        nextEnemyId = (nextEnemyId + 1) % ENEMY_DATA_SIZE;
    }

    if (currentEnemy == nullptr)
    {
        view.ShowEnemyCreateError();
        currentState = GameState::GAMEOVER;
        return;
    }

    // ゲーム画面を表示
    view.ShowGame(
        player.GetHP(),
        currentEnemy->GetName(),
        currentEnemy->GetHP()
    );

    // 入力を受け取る
    int input = view.GetGameInput();


    if (input == 1)
    {
        // プレイヤーが敵を攻撃
        player.AttackEnemy(currentEnemy);

        // 敵を倒したか確認
        if (!currentEnemy->IsAlive())
        {
            // 倒した敵のIDを記録してからプールへ戻す
            lastDefeatedEnemyId = currentEnemy->GetID();

            enemyPool.Release(currentEnemy);
            currentEnemy = nullptr;

            // 戦利品の選択画面へ移行
            currentState = GameState::CLEAR;
            return;
        }

        // 敵の反撃
        view.ShowEnemyAttack(currentEnemy->GetName());

        player.Damage(currentEnemy->GetAttack());

        // プレイヤーが倒れたか確認
        if (!player.IsAlive())
        {
            currentState = GameState::GAMEOVER;
        }
    }
    else if (input == 2)
    {
        currentState = GameState::GAMEOVER;
    }
}

//==============================================================
// クリア（戦利品）画面
//  敵を倒した直後に来る。1: 拾う（HP+15） 2: 拾わない
//  最後の敵（ENEMY_DATA_SIZE-1）を倒したら「ゲームクリア」扱いにする
//==============================================================
void GameManager::UpdateClear()
{
    if (lastDefeatedEnemyId < 0 || lastDefeatedEnemyId >= ENEMY_DATA_SIZE)
    {
        // 安全処理：不正値ならタイトルへ戻す
        currentState = GameState::TITLE;
        return;
    }

    const std::string& name = enemyTable[lastDefeatedEnemyId].name;

    // 戦利品画面を表示
    view.ShowTreasure(name);

    // 入力を受け取る
    int input = view.GetTreasureInput();

    if (input == 1)
    {
        player.Heal(15);
    }

    // 最後の敵を倒したか？
    if (lastDefeatedEnemyId == ENEMY_DATA_SIZE - 1)
    {
        view.ShowFinalClear();

        int select = view.GetFinalClearInput();

        if (select == 1)
        {
            currentState = GameState::TITLE;
        }
        else
        {
            currentState = GameState::EXIT;
        }
    }
    else
    {
        // 次の敵と戦う
        currentState = GameState::GAME;
    }
}

//==============================================================
// ゲームオーバー画面
//==============================================================
void GameManager::UpdateGameOver()
{
    // ゲームオーバー画面を表示
    view.ShowGameOver();

    // 入力を受け取る
    int input = view.GetGameOverInput();


    if (input == 1)
    {
        // 使用中の敵をプールに戻す
        if (currentEnemy != nullptr)
        {
            enemyPool.Release(currentEnemy);
            currentEnemy = nullptr;
        }

        currentState = GameState::TITLE;
    }
    else if (input == 2)
    {
        // 終了時も敵をプールに戻す
        if (currentEnemy != nullptr)
        {
            enemyPool.Release(currentEnemy);
            currentEnemy = nullptr;
        }

        currentState = GameState::EXIT;
    }
}