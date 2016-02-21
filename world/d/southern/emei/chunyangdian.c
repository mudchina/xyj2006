//Cracked by Roath
// ajax

inherit ROOM;

void create()
{
set("short", "纯阳殿");
set("long", @LONG
    
　　殿正中的雕像，就是自称回道人的吕洞宾的像了。枋上有一联曰：
「稳睡为何因，遍游天下，未得缘人说妙道；醉眼无别事，厌闻世况，
掀开记卷乐长生」。吕纯阳唐朝京兆人。他两举进士不第，浪游江湖，
曾隐居终南山等地修道。後游历各地，自称回道人。为八仙之一，道
教全真道尊他为北五祖之一。
LONG );


set("exits", ([
  "north"   : __DIR__"shanlu4",
 
]));


set("objects", ([
]));


setup();
}
