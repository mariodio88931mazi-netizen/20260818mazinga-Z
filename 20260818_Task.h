#pragma once
//定数
const int ATTCK = 20;
const int HEAL = 30;
const int STATE_HP = 100;

/// <summary>
/// ダメージ
/// </summary>
/// <param name="hp"></param>
void Damage(int* hp);

/// <summary>
/// ヒール
/// </summary>
/// <param name="hp"></param>
void Heal(int* hp);
