//Cracked by Roath
// ajax

inherit ROOM;

void create()
{
set("short", "山路");
set("long", @LONG
    

　　走在山中，只见四处鲜花灿烂，四周的岩石都有深深的
纹路，据说当年文殊菩萨从龙宫取得歇龙石后，那些外出的
小龙王回来时，发现歇龙石不在了，怨气冲天，便追到这里，
四处对找。气急败坏的小龙王，用龙尾把五个峰扫成了平台；
用利爪把岩石刨得乱七八糟，至今这些石块还遍布满山，人
称“龙翻石”。

LONG );


set("exits", ([
  "east"   : __DIR__"qlsi_shanlu3",
  "west"   : __DIR__"chaolongdong",
 
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
