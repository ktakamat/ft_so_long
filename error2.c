/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machi <machi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:13:14 by machi             #+#    #+#             */
/*   Updated: 2024/04/05 19:20:09 by machi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "mlx/mlx.h"
// #include "so_long.h"

// // Eに到達できるかどうかを判定する関数
// int can_reach_end(t_game *game, size_t x, size_t y) {
//     // マップの範囲外に出た場合は到達不可能
//     if (x < 0 || y < 0 || x >= game->wid || y >= game->hei) {
//         return 0;
//     }

//     // 障害物にぶつかった場合は到達不可能
//     if (game->str_line[y * game->wid + x] == '1' || game->str_line[y * game->wid + x] == 'C') {
//         return 0;
//     }

//     // Eに到達した場合は到達可能
//     if (game->str_line[y * game->wid + x] == 'E') {
//         return 1;
//     }

//     // 訪れたマスを印 ('X') にする
//     game->str_line[y * game->wid + x] = 'X';

//     // 上下左右の隣接マスを調べる
//     int result = (can_reach_end(game, x + 1, y) || can_reach_end(game, x - 1, y) || can_reach_end(game, x, y + 1) || can_reach_end(game, x, y - 1));

//     // 再帰呼び出しの結果、ゴールに到達した場合以外は訪れたマスを元に戻す
//     if (!result) {
//         game->str_line[y * game->wid + x] = '0';
//     }

//     return result;
// }

// // Pの位置を探す関数
// void find_p_position(t_game *game, size_t *p_x, size_t *p_y) {
//     for (size_t y = 0; y < game->hei; y++) {
//         for (size_t x = 0; x < game->wid; x++) {
//             if (game->str_line[y * game->wid + x] == 'P') {
//                 *p_x = x;
//                 *p_y = y;
//                 return;
//             }
//         }
//     }
//     // Pが見つからない場合のエラー処理
//     printf("Error: P not found\n");
//     exit(EXIT_FAILURE);
// }

// // ゴールが達成不可能であることを示すエラーメッセージを出力してプログラムを終了させる関数
// void check_goal_reachable(t_game *game) {
//     size_t p_x, p_y;
//     // Pの位置を探す
//     find_p_position(game, &p_x, &p_y);

//     // PからEに到達できない場合にエラーメッセージを出力して終了
//     if (!can_reach_end(game, p_x, p_y)) {
//         printf("Goal unreachable: P cannot reach E\n");
//         exit(EXIT_FAILURE);
//     }
// }