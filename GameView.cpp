#include <iostream>
#include "GameView.h"

using namespace std;

//==============================================================
// タイトル画面
//==============================================================
void GameView::ShowTitle()
{
    cout << endl;
    cout << "==============================" << endl;
    cout << "             RPG              " << endl;
    cout << "==============================" << endl;
    cout << "1 : ゲーム開始" << endl;
    cout << "2 : ゲーム終了" << endl;
}

int GameView::GetTitleInput()
{
    int input;
    cin >> input;

    return input;
}

//==============================================================
// ゲーム画面
//==============================================================
void GameView::ShowGame(int playerHP, const string& enemyName, int enemyHP)
{
    cout << endl;
    cout << "========== GAME ==========" << endl;
    cout << "勇者 HP : " << playerHP << endl;
    cout << enemyName << " HP : " << enemyHP << endl;

    cout << "1 : 攻撃" << endl;
    cout << "2 : ゲームオーバーにする" << endl;
}

int GameView::GetGameInput()
{
    int input;
    cin >> input;

    return input;
}

//==============================================================
// 敵の攻撃画面
//==============================================================
void GameView::ShowEnemyAttack(const std::string& enemyName)
{
    cout << endl;
    cout << enemyName << " の攻撃！" << endl;
}


//==============================================================
// 戦利品画面
//==============================================================
void GameView::ShowTreasure(const string& enemyName)
{
    cout << endl;
    cout << "==============================" << endl;
    cout << enemyName << " を倒した！" << endl;
    cout << "戦利品を拾いますか？" << endl;
    cout << "1 : 拾う" << endl;
    cout << "2 : 拾わない" << endl;
}

int GameView::GetTreasureInput()
{
    int input;
    cin >> input;

    return input;
}

//==============================================================
// 敵生成エラー画面
//==============================================================
void GameView::ShowEnemyCreateError()
{
    cout << endl;
    cout << "==============================" << endl;
    cout << "敵を生成できませんでした。" << endl;
    cout << "==============================" << endl;
}


//==============================================================    
// 最終クリア画面
//==============================================================
void GameView::ShowFinalClear()
{
    cout << endl;
    cout << "==============================" << endl;
    cout << "        全ての敵を撃破！       " << endl;
    cout << "          GAME CLEAR          " << endl;
    cout << "==============================" << endl;
    cout << "1 : タイトルに戻る" << endl;
    cout << "2 : ゲーム終了" << endl;
}

int GameView::GetFinalClearInput()
{
    int input;
    cin >> input;

    return input;
}

//==============================================================
// ゲームオーバー画面
//==============================================================
void GameView::ShowGameOver()
{
    cout << endl;
    cout << "==============================" << endl;
    cout << "          GAME OVER           " << endl;
    cout << "==============================" << endl;
    cout << "1 : タイトルに戻る" << endl;
    cout << "2 : ゲーム終了" << endl;
}

int GameView::GetGameOverInput()
{
    int input;
    cin >> input;

    return input;
}

//==============================================================
// ゲーム終了メッセージ
//==============================================================
void GameView::ShowExit()
{
    cout << "ゲームを終了します。" << endl;
}