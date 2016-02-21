
inherit ROOM;

void create ()
{
   set ("short", "山路");
   set ("long", @LONG
        
　　由此上山就到清凉寺了，前面一大石，便是传说中文殊
菩萨从龙宫得来的清凉石(stone)。
LONG);

   set("item_desc", (["stone" : "此石石长五米，宽二米半， 厚两，围十五米，石面青色，有
云纹，人坐其上，顿生凉意。\n", ]));
   //for look something.
   

   set("exits", 
   ([ //sizeof() == 4
      "southdown" : __DIR__"shanlu2",
     "north" : __DIR__"door",
     
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
     //__DIR__"npc/***" : 1,
   ]));


   set("outdoors", "/d/nanhai");

   setup();
}

