#include <iostream>
#include <string>
#include <GLUT/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctime>

using namespace std;

class Player
{
	public:
		int HP; 	//playerのHP
		int uxm;//プレイヤーの移動値判定値
		int play_x;
		int play_y;//Playerの座標
		int p_v[4] = {10, -25, -10, 25};
		int change[4];
		double size;
		Player();
		void move_player(int& uxm);
		void s_move(int Num);
		void player(int& uxm, int WindowNum, int bull, int& ch);
		void setting();
};

class Enemy1
{
	public:
		int ene1X;//Enemyの先頭のx座標
		int ene1Y;//Enemyの最上列のy座標
		int L_R;//0が右、１が左
		float enexm;
		int enex[4];
		int el[4] = {1, 1, 1, 1};
		int e_v[4] = {20, 15, -20, -15};
		int e_t;
		Enemy1();
		void enemy1();
		void move_enemy1(); 
		void hit_e(int Num);
		void setting();
};

class Ballet_p
{
	public:
		int vertexX[2];//弾のx座標
		int vertexY;//弾のy座標
		double balletr;//弾の半径
		int hit;
		Ballet_p();
		void Ballet(int& bull, Player p, Enemy1 e1, int& h_Num);
		void hit_cheak_P(Enemy1 e1,int Num);
		void setting();
};



class Ene1_Ballet
{
	public:
		int enebull_x; //Enemyの弾のx座標
		int enebull_y;//Enemyの弾のy座標
		int ene_shot_judge;
		int Bcop;
		int sei;
		int b1,b2,b3,b4,b5,b6,b7,b8; 
		int ene_shot[4];
		int hit_E1;
		int a_j1;
		Ene1_Ballet();
		void ene1_ballet(Enemy1 e1, Player p);
		void shot(Enemy1 e1 , Player p);
		void hit_cheak_E1(Player p);
		void setting();
};

class Enemy2
{
	public:
		int ene2x[2] = {0,645};
		int ene2y[2] = {470,335};
		void enemy2();
};

class Ene2_Ballet
{
	public:
		int La_Ra = 0;//０で左から攻撃。１で右から攻撃
		int ene2bull_x[3] = {0,645,0};
		int ene2bull_y[3] = {470,335,470};
		int side_cheak;
		int rand_cheack;
		int side_shot; 
		int hit_E2;
		int a_j2;
		Ene2_Ballet();
		void ene2_ballet(Enemy2 e2, Player p);
		void shot(Enemy2 e2, Player p);
		void hit_cheak_E2(Player p, int Num);
		void setting();
};

class Obstacle
{
	public:
		int obs_judge;
		int obs_x[5] = {180, 260, 340, 420, 500};
		int obs_y;
		int obs_num;//障害物の数
		int obs_pop[5];
		int hit_o;
		int a_j3;
		int fall_cheack;
		Obstacle();
		void obstacle( int x, int y);
		void move_obs(Player p);
		void hit_cheak_O(Player p, int Num);
		void setting();
};

class HP_bar
{
	public:
		int b_x;
		int b_y;
		int f_x;
		int f_y;
		int d;
		int e_d[5];
		void damage(int Num);
		void hp_bar(int d);
		void setting();
		void damage(int Num, Enemy1 e1);
		void e_hp_bar(int d, Enemy1 e1, int m);
		void e_damage(int& s,int Num, Enemy1 e1, int m);
		HP_bar();
};

