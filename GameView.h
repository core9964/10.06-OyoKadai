#pragma once

#include <string>

class GameView
{
public:
    // タイトル画面
    void ShowTitle();
    int GetTitleInput();

    // ゲーム画面
    void ShowGame(int playerHP, const std::string& enemyName, int enemyHP);
    int GetGameInput();

	// 敵の攻撃画面
    void ShowEnemyAttack(const std::string& enemyName);

    // 戦利品画面
    void ShowTreasure(const std::string& enemyName);
    int GetTreasureInput();

    // 敵生成エラー画面
    void ShowEnemyCreateError();

    // 最終クリア画面
    void ShowFinalClear();
    int GetFinalClearInput();

    // ゲームオーバー画面
    void ShowGameOver();
    int GetGameOverInput();

    // ゲーム終了メッセージ
    void ShowExit();
};