// mon 10/10/98 

inherit ROOM;

#define OUTROOM __DIR__"exit"

void create ()
{
  set ("short", "枯骨洞");
  set ("long", @LONG

周围阴森黑暗，只有遍地的白骨丛中间或有一点点幽暗的
荧光闪烁。借着这微弱的光亮，你发觉自己置身在一个纵
横交错的庞大洞穴之中。

LONG);

  set("objects", ([
//        __DIR__"npc/yaomo"  : random(2),
      ]));
  
  if(random(3)==0) {
      object sheli;
      seteuid(getuid());
      sheli=new(__DIR__"obj/shelizi");
      sheli->set_amount(1+random(5));
      sheli->move(this_object());
  }

  set("cave",1);
  setup();
}

int clean_up ()
{
  return 0;
}
