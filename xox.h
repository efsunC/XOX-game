#ifndef GAME_H
#define GAME_H

void initialize_Game_Board(char board[][3]);
int update_Game_Board(char board[][3], int player, int position);
void show_Game_Board(char board[][3]);
int check_for_Win(char board[][3]);
void start_Game();

#endif
