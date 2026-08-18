#pragma once
///=====================================================
///定数
///=====================================================

//カードの総枚数 
const int TOTAL_CARD = 28;
//1グループのカード枚数
const int GROUP_CARD = 7;
//カードの総枚数
const int MAX_NUMBER = 7;
///=====================================================
///関数
///=====================================================

//28枚のカード作成

/// <summary>
///28枚のカード作成 
/// </summary>
/// <param name="cards"></param>
void createCard(int cards[]);

//カードをシャッフル

/// <summary>
/// カードをシャッフル
/// </summary>
/// <param name="cards"></param>
void shuffleCard(int cards[]);
//カードを表示

/// <summary>
/// カードを表示
/// </summary>
/// <param name="cards"></param>
void showCard(int cards[]);
//カードを伏せて表示



/// <summary>
/// カードを伏せて表示
/// </summary>
/// <param name="cards"></param>
void showHiddenCard(int cards[]);