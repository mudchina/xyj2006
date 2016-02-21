inherit ROOM;

void create()
{
  set ("short", "长安武馆");
  set ("long", @LONG

长安武馆的内堂，一切都安安静静，屋里没有点烛，什么也看不清楚。
隐约看到两排长椅，正面墙上挂一大旗(qi)。
LONG);
set("item_desc",(["qi":"
        ＊＊＊＊＊＊＊＊
        ＊＊拳盖三省＊＊
        ＊＊无人能敌＊＊
        ＊＊＊＊＊＊＊＊\n"
]));
        set("objects", ([
                __DIR__"npc/fan": 1, 
                                                
]));
        set("exits", ([ /* sizeof() == 2 */
        "west" : __DIR__"wuguan",
]));
  setup();
}

