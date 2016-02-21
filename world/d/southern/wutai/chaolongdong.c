//Cracked by Roath
// ajax

inherit ROOM;

void create()
{
set("short", "秘魔岩窟");
set("long", @LONG
    
　　传说文殊菩萨当年就将来此滋事的小龙关在这朝龙洞里。
文殊菩萨命众龙在此好好修行，并说要派弟子来朝拜和供养他
们，因此这个秘魔岩窟又叫＂“朝龙洞”。传说朝拜者各见境
界不一，善良人见佛、菩萨；邪恶人见不到欢乐境界。真可谓
万人万境。而且有“朝五台山，若不朝拜朝龙洞只算朝拜了半
个五台山”的说法。

LONG );


set("exits", ([
  "east"   : __DIR__"qlsi_shanlu4",
 
]));


set("objects", ([
]));



set("outdoors", 1);

setup();
}
