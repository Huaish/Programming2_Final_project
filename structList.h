#pragma once

#include <stdbool.h>
#include <stdlib.h>
typedef void (*Skill) ( void *this, void* argv );

/* 角色狀態
* -設定, -自身回合, -他人回合, -死亡*/
typedef enum _role_mode
{
    SET,
    JUDGE,
    GET_CARD,
    PLAY_CARD,
    DISCARD_CARD,
    MINUS_HP,
    FIGHT,
    IS_ATTACKED,
    FINISH_TIHS_TURN,
    IS_DEAD
} RMode; 

/* 遊戲狀態
* -尚未開始, -正在遊戲, -結束*/
typedef enum _game_mode
{
    NOT_YET_START,
    IN_ROUND,
    END
} GMode; 

/* 身分 
* -警長, -副警長, -歹徒, -叛徒*/
typedef enum _identity_kind
{
    Sheriff, 
    Deputies,
    Outlaws,
    Renegade
} Identity;

/* 角色*/
typedef enum _role_kind
{
    Bart_Cassidy, Black_Jack, Calamity_Janet, El_Gringo, 
    Jesse_Jones, Jourdonnais, Kit_Carlson, Lucky_Duke,
    Paul_Regret, Pedro_Ramirez, Rose_Doolan, Sid_Ketchum,
    Slab_the_Killer, Suzy_Lafayette, Vulture_Sam, Willy_the_Kid
} Role;

/* 消耗牌+裝備牌*/
typedef enum _card_kind
{
    BANG, MISSED, GATLING, INDIANS, PANIC, 
    CAT, STAGECOACH, WELLS, STORE, BEER, 
    SALOOW, DUEL, BARREL, SCOPE, MUSTANG, 
    JAIL, DYNAMITE, VOLCANIC, SCHOFIELD, 
    REMINGTON, REV, WINCHEDTER
} Kind;


typedef struct _card Card;
struct _card
{    
    int kind;
    int sticker;
    bool is_orange; //消耗 or 裝備
    int suit; //(0~3)
    int number; //(1~13)
    int attribute; // 主動(1) or 被動(2)
    // 這張牌是否可以主動被出出來
};

typedef struct {
    size_t size;
    size_t allocate_size;
    Card *data;
} Card_vector;

typedef struct _player_list
{
    int id;
    // bool    dynamite;
    // bool    jail;
    int     hp;
    int     handcard_num;
    Card_vector* equipment;
    Card_vector* judgeCards;
    Card_vector* handcard;
    char    name[1000];    
    Role    role;
    RMode   state;    
    Identity identity;
    int numOfBang;
} Player;