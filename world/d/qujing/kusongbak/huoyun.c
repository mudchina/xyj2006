inherit ROOM;

void create ()
{
  set ("short", "火云堂");
  set ("long", @LONG

这里就是火云洞的中心－火云堂。正前方一把黑虎皮的软椅高高
在上，椅后一把玄色大锦旗，上面绣着“圣婴大王”四个金子。
两旁小妖林立，头顶几十把松油灯把堂上照的雪亮。
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yongdao7",
  "west" : __DIR__"jin",
  "east" : __DIR__"tu",
  "northeast" : __DIR__"huo",
  "northwest" : __DIR__"mu",
  "north" : __DIR__"shui", 
]));

  set("objects", ([ /* sizeof() == 1*/
  __DIR__"npc/honghaier" : 1,    
]));


  setup();
}


