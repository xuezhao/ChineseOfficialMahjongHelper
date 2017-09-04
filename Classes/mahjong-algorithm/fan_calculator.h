﻿/****************************************************************************
 Copyright (c) 2016-2017 Jeff Wang <summer_insects@163.com>

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
****************************************************************************/

#ifndef __MAHJONG_ALGORITHM__FAN_CALCULATOR_H__
#define __MAHJONG_ALGORITHM__FAN_CALCULATOR_H__

#include "tile.h"

#define SUPPORT_CONCEALED_KONG_AND_MELDED_KONG 1  // 支持明暗杠

namespace mahjong {

/**
 * @addtogroup calculator
 * @{
 */

/**
 * @brief 番种
 */
enum fan_t {
    FAN_NONE = 0,                       ///< 无效
    BIG_FOUR_WINDS,                     ///< 大四喜
    BIG_THREE_DRAGONS,                  ///< 大三元
    ALL_GREEN,                          ///< 绿一色
    NINE_GATES,                         ///< 九莲宝灯
    FOUR_KONGS,                         ///< 四杠
    SEVEN_SHIFTED_PAIRS,                ///< 连七对
    THIRTEEN_ORPHANS,                   ///< 十三幺

    ALL_TERMINALS,                      ///< 清幺九
    LITTLE_FOUR_WINDS,                  ///< 小四喜
    LITTLE_THREE_DRAGONS,               ///< 小三元
    ALL_HONORS,                         ///< 字一色
    FOUR_CONCEALED_PUNGS,               ///< 四暗刻
    PURE_TERMINAL_CHOWS,                ///< 一色双龙会

    QUADRUPLE_CHOW,                     ///< 一色四同顺
    FOUR_PURE_SHIFTED_PUNGS,            ///< 一色四节高

    FOUR_PURE_SHIFTED_CHOWS,            ///< 一色四步高
    THREE_KONGS,                        ///< 三杠
    ALL_TERMINALS_AND_HONORS,           ///< 混幺九

    SEVEN_PAIRS,                        ///< 七对
    GREATER_HONORS_AND_KNITTED_TILES,   ///< 七星不靠
    ALL_EVEN_PUNGS,                     ///< 全双刻
    FULL_FLUSH,                         ///< 清一色
    PURE_TRIPLE_CHOW,                   ///< 一色三同顺
    PURE_SHIFTED_PUNGS,                 ///< 一色三节高
    UPPER_TILES,                        ///< 全大
    MIDDLE_TILES,                       ///< 全中
    LOWER_TILES,                        ///< 全小

    PURE_STRAIGHT,                      ///< 清龙
    THREE_SUITED_TERMINAL_CHOWS,        ///< 三色双龙会
    PURE_SHIFTED_CHOWS,                 ///< 一色三步高
    ALL_FIVE,                           ///< 全带五
    TRIPLE_PUNG,                        ///< 三同刻
    THREE_CONCEALED_PUNGS,              ///< 三暗刻

    LESSER_HONORS_AND_KNITTED_TILES,    ///< 全不靠
    KNITTED_STRAIGHT,                   ///< 组合龙
    UPPER_FOUR,                         ///< 大于五
    LOWER_FOUR,                         ///< 小于五
    BIG_THREE_WINDS,                    ///< 三风刻

    MIXED_STRAIGHT,                     ///< 花龙
    REVERSIBLE_TILES,                   ///< 推不倒
    MIXED_TRIPLE_CHOW,                  ///< 三色三同顺
    MIXED_SHIFTED_PUNGS,                ///< 三色三节高
    CHICKEN_HAND,                       ///< 无番和
    LAST_TILE_DRAW,                     ///< 妙手回春
    LAST_TILE_CLAIM,                    ///< 海底捞月
    OUT_WITH_REPLACEMENT_TILE,          ///< 杠上开花
    ROBBING_THE_KONG,                   ///< 抢杠和

    ALL_PUNGS,                          ///< 碰碰和
    HALF_FLUSH,                         ///< 混一色
    MIXED_SHIFTED_CHOWS,                ///< 三色三步高
    ALL_TYPES,                          ///< 五门齐
    MELDED_HAND,                        ///< 全求人
    TWO_CONCEALED_KONGS,                ///< 双暗杠
    TWO_DRAGONS_PUNGS,                  ///< 双箭刻

    OUTSIDE_HAND,                       ///< 全带幺
    FULLY_CONCEALED_HAND,               ///< 不求人
    TWO_MELDED_KONGS,                   ///< 双明杠
    LAST_TILE,                          ///< 和牌张

    DRAGON_PUNG,                        ///< 箭刻
    PREVALENT_WIND,                     ///< 圈风刻
    SEAT_WIND,                          ///< 门风刻
    CONCEALED_HAND,                     ///< 门前清
    ALL_CHOWS,                          ///< 平和
    TILE_HOG,                           ///< 四归一
    DOUBLE_PUNG,                        ///< 双同刻
    TWO_CONCEALED_PUNGS,                ///< 双暗刻
    CONCEALED_KONG,                     ///< 暗杠
    ALL_SIMPLES,                        ///< 断幺

    PURE_DOUBLE_CHOW,                   ///< 一般高
    MIXED_DOUBLE_CHOW,                  ///< 喜相逢
    SHORT_STRAIGHT,                     ///< 连六
    TWO_TERMINAL_CHOWS,                 ///< 老少副
    PUNG_OF_TERMINALS_OR_HONORS,        ///< 幺九刻
    MELDED_KONG,                        ///< 明杠
    ONE_VOIDED_SUIT,                    ///< 缺一门
    NO_HONORS,                          ///< 无字
    EDGE_WAIT,                          ///< 边张
    CLOSED_WAIT,                        ///< 嵌张
    SINGLE_WAIT,                        ///< 单钓将
    SELF_DRAWN,                         ///< 自摸

    FLOWER_TILES,                       ///< 花牌

#if SUPPORT_CONCEALED_KONG_AND_MELDED_KONG
    CONCEALED_KONG_AND_MELDED_KONG,     ///< 明暗杠
#endif

    FAN_TABLE_SIZE
};

/**
 * @brief 风（用来表示圈风门风）
 */
enum class wind_t {
    EAST, SOUTH, WEST, NORTH
};

/**
 * @brief 和牌标记
 */
typedef uint8_t win_flag_t;

/**
 * @name win flag
 * @{
 */
#define WIN_FLAG_DISCARD    0   ///< 点和
#define WIN_FLAG_SELF_DRAWN 1   ///< 自摸
#define WIN_FLAG_4TH_TILE   2   ///< 绝张
#define WIN_FLAG_ABOUT_KONG 4   ///< 关于杠，复合点和时为枪杠和，复合自摸则为杠上开花
#define WIN_FLAG_WALL_LAST  8   ///< 牌墙最后一张，复合点和时为海底捞月，复合自摸则为妙手回春
/**
 * @}
 */

/**
 * @name error codes
 * @{
 */
#define ERROR_WRONG_TILES_COUNT -1              ///< 错误的张数
#define ERROR_TILE_COUNT_GREATER_THAN_4 -2      ///< 某张牌出现超过4枚
#define ERROR_NOT_WIN -3                        ///< 没和牌
/**
 * @}
 */

/**
 * @brief 检查算番的输入是否合法
 *
 *
 * @param [in] hand_tiles 手牌
 * @param [in] win_tile 和牌张
 * @retval 0 成功
 * @retval ERROR_WRONG_TILES_COUNT 错误的张数
 * @retval ERROR_TILE_COUNT_GREATER_THAN_4 某张牌出现超过4枚
 */
int check_calculator_input(const hand_tiles_t *hand_tiles, tile_t win_tile);

/**
 * @brief 附加信息
 */
struct extra_condition_t {
    win_flag_t win_flag;    ///< 和牌标记
    wind_t prevalent_wind;  ///< 圈风
    wind_t seat_wind;       ///< 门风
};

/**
 * @brief 算番参数
 */
struct calculate_param_t {
    hand_tiles_t hand_tiles;    ///< 手牌
    tile_t win_tile;            ///< 和牌张
    int flower_count;           ///< 花牌数
    extra_condition_t ext_cond; ///< 附加信息
};

/**
 * @brief 番表
 */
typedef long fan_table_t[FAN_TABLE_SIZE];

/**
 * @brief 算番
 *
 * @param [in] calculate_param 算番参数
 * @param [out] fan_table 番表，当有某种番时，相应的会设置为这种番出现的次数
 * @retval >0 番数
 * @retval ERROR_WRONG_TILES_COUNT 错误的张数
 * @retval ERROR_TILE_COUNT_GREATER_THAN_4 某张牌出现超过4枚
 * @retval ERROR_NOT_WIN 没和牌
 */
int calculate_fan(const calculate_param_t *calculate_param, fan_table_t &fan_table);

#if 0

/**
 * @brief 番名（英文）
 */
static const char *fan_name[] = {
    "None",
    "Big Four Winds", "Big Three Dragons", "All Green", "Nine Gates", "Four Kongs", "Seven Shifted Pairs", "Thirteen Orphans",
    "All Terminals", "Little Four Winds", "Little Three Dragons", "All Honors", "Four Concealed Pungs", "Pure Terminal Chows",
    "Quadruple Chow", "Four Pure Shifted Pungs",
    "Four Pure Shifted Chows", "Three Kongs", "All Terminals and Honors",
    "Seven Pairs", "Greater Honors and Knitted Tiles", "All Even Pungs", "Full Flush", "Pure Triple Chow", "Pure Shifted Pungs", "Upper Tiles", "Middle Tiles", "Lower Tiles",
    "Pure Straight", "Three-Suited Terminal Chows", "Pure Shifted Chows", "All Five", "Triple Pung", "Three Concealed Pungs",
    "Lesser Honors and Knitted Tiles", "Knitted Straight", "Upper Four", "Lower Four", "Big Three Winds",
    "Mixed Straight", "Reversible Tiles", "Mixed Triple Chow", "Mixed Shifted Pungs", "Chicken Hand", "Last Tile Draw", "Last Tile Claim", "Out with Replacement Tile", "Robbing The Kong",
    "All Pungs", "Half Flush", "Mixed Shifted Chows", "All Types", "Melded Hand", "Two Concealed Kongs", "Two Dragons Pungs",
    "Outside Hand", "Fully Concealed Hand", "Two Melded Kongs", "Last Tile",
    "Dragon Pung", "Prevalent Wind", "Seat Wind", "Concealed Hand", "All Chows", "Tile Hog", "Double Pung",
    "Two Concealed Pungs", "Concealed Kong", "All Simples",
    "Pure Double Chow", "Mixed Double Chow", "Short Straight", "Two Terminal Chows", "Pung of Terminals or Honors", "Melded Kong", "One Voided Suit", "No Honors", "Edge Wait", "Closed Wait", "Single Wait", "Self-Drawn",
    "Flower Tiles"
#if SUPPORT_CONCEALED_KONG_AND_MELDED_KONG
    , "Concealed Kong and Melded Kong"
#endif
};

#else

#ifdef _MSC_VER
#pragma execution_character_set("utf-8")
#endif

/**
 * @brief 番名（简体中文）
 */
static const char *fan_name[] = {
    "无",
    "大四喜", "大三元", "绿一色", "九莲宝灯", "四杠", "连七对", "十三幺",
    "清幺九", "小四喜", "小三元", "字一色", "四暗刻", "一色双龙会",
    "一色四同顺", "一色四节高",
    "一色四步高", "三杠", "混幺九",
    "七对", "七星不靠", "全双刻", "清一色", "一色三同顺", "一色三节高", "全大", "全中", "全小",
    "清龙", "三色双龙会", "一色三步高", "全带五", "三同刻", "三暗刻",
    "全不靠", "组合龙", "大于五", "小于五", "三风刻",
    "花龙", "推不倒", "三色三同顺", "三色三节高", "无番和", "妙手回春", "海底捞月", "杠上开花", "抢杠和",
    "碰碰和", "混一色", "三色三步高", "五门齐", "全求人", "双暗杠", "双箭刻",
    "全带幺", "不求人", "双明杠", "和绝张",
    "箭刻", "圈风刻", "门风刻", "门前清", "平和", "四归一", "双同刻", "双暗刻", "暗杠", "断幺",
    "一般高", "喜相逢", "连六", "老少副", "幺九刻", "明杠", "缺一门", "无字", "边张", "嵌张", "单钓将", "自摸",
    "花牌"
#if SUPPORT_CONCEALED_KONG_AND_MELDED_KONG
    , "明暗杠"
#endif
};

#endif

/**
 * @brief 番值
 */
static const int fan_value_table[FAN_TABLE_SIZE] = {
    0,
    88, 88, 88, 88, 88, 88, 88,
    64, 64, 64, 64, 64, 64,
    48, 48,
    32, 32, 32,
    24, 24, 24, 24, 24, 24, 24, 24, 24,
    16, 16, 16, 16, 16, 16,
    12, 12, 12, 12, 12,
    8, 8, 8, 8, 8, 8, 8, 8, 8,
    6, 6, 6, 6, 6, 6, 6,
    4, 4, 4, 4,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1
#if SUPPORT_CONCEALED_KONG_AND_MELDED_KONG
    , 5
#endif
};

/**
 * @brief 判断立牌是否包含和牌
 * 如果是，则必然不是和绝张
 *
 * @param [in] standing_tiles 立牌
 * @param [in] standing_cnt 立牌数
 * @param [in] win_tile 和牌张
 * @return bool
 */
bool is_standing_tiles_contains_win_tile(const tile_t *standing_tiles, long standing_cnt, tile_t win_tile);

/**
 * @brief 统计和牌在副露中出现的张数
 * 如果出现3张，则必然和绝张
 *
 * @param [in] fixed_pack 副露牌组
 * @param [in] fixed_cnt 副露牌组数
 * @param [in] win_tile 和牌张
 * @return size_t
 */
size_t count_win_tile_in_fixed_packs(const pack_t *fixed_pack, long fixed_cnt, tile_t win_tile);

/**
 * end group
 * @}
 */

}

#endif
