//Cracked by Roath
// ajax

inherit ROOM;

void create()
{
set("short", "金顶");
set("long", @LONG
    
    峨嵋金顶有四大奇观：云海、日出、佛光和佛灯。其中又以佛光
最为有名。在云平风静的午後，总会出现在云层的一个虚明若镜、极
其艳丽约五彩光环。观看光环时，可见镜中暗影与观者影形一样。但
每个人只能看见自己的身影，不能看见他人身影。后人作诗咏赞：「
非云非雾起层空，异彩奇辉迥不同。试向岩石高处望，人人都在佛光
中。」

LONG );


set("exits", ([
  "west"   : __DIR__"sheshenyan",
  "eastdown"   : __DIR__"daochang",
 
]));


set("objects", ([
"/d/southern/emei/npc/dashizhi": 1,
]));



set("outdoors", 1);

setup();
}
