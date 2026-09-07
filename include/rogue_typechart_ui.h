#ifndef GUARD_ROGUE_TYPECHART_UI_H
#define GUARD_ROGUE_TYPECHART_UI_H

// タイプ相性・てもちの弱点・攻撃範囲を まとめて見る画面。
// フィールドでもバトル中でも R ボタンで開く。

void Rogue_OpenTypeChartFromField(void);
void Rogue_OpenTypeChartFromBattle(void);
bool8 Rogue_IsViewingTypeChart(void);

#endif // GUARD_ROGUE_TYPECHART_UI_H
