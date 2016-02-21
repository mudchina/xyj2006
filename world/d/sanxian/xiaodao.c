inherit ROOM;
void create()
{
        set("short", "小道");
        set("long", @LONG
这条小小的地道大约有七八尺，刚好可以容得下一个人的身子。
LONG
  );
  set("exits",([
        "out" : __DIR__"fangbian",
        "east" : __DIR__"chapeng",
      ]));  
set("objects", ([ /* sizeof() == 1 */
        __DIR__"bslong" : 1,
      ])); 
        set("no_magic",1);
        
        setup();
} 
