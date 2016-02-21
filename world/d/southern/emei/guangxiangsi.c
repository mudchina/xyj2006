//Cracked by Roath
// ajax

inherit ROOM;

void create()
{
set("short", "光相寺");
set("long", @LONG
    
    金顶过去有许多庙宇，其中有座祖殿，为峨嵋山古寺之一。汉时
叫普光殿，唐宋间又改为光相寺。明朝蜀藩捐资扩建。殿瓦、柱、门
、棂、窗和四壁皆铜质掺金。此殿在阳光照耀下金光闪闪，加上地势
高，山下四周可见，故名「金顶」。这就是峨嵋山金顶的由来。
LONG );


set("exits", ([
  "south"   : __DIR__"daochang",
 
]));


set("objects", ([
]));




setup();
}
